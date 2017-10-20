/*
 * Arduino code to show automatic counter (0-99) on two RGB LED matrices
 * Last updated 20171019
 * 
 * Code by Markus Lorenz Schilling
 * http://malosch.com/
 * 
 * GitHub
 * https://github.com/MaLoSch/LED-Matrix-Counter
*/

/* LIBRARIES */
#include "FastLED.h" // Include FastLED library http://fastled.io/

/* CONSTANT VARIABLES */
const int rgbLEDMatrixPin = 9; // Pin # where LED matrices are attached to
const int numPixelPerMatrix = 64; // # of pixels per LED matrix
const int numMatrices = 2; // # of LED matrices
const int totalPixels = numPixelPerMatrix * numMatrices; // calculate total number of pixels
byte numbers[10][8] = { // Array with digits from 0-10
  { // #0
    0b00111111,
    0b00111111,
    0b00110011,
    0b00110011,
    0b00110011,
    0b00110011,
    0b00111111,
    0b00111111,
  },
  { // #1
    0b00000011,
    0b00000011,
    0b00000011,
    0b00000011,
    0b00000011,
    0b00000011,
    0b00000011,
    0b00000011,
  },
  { // #2
    0b00111111,
    0b00111111,
    0b00000011,
    0b00111111,
    0b00111111,
    0b00110000,
    0b00111111,
    0b00111111,
  },
  { // #3
    0b00111111,
    0b00111111,
    0b00000011,
    0b00111111,
    0b00111111,
    0b00000011,
    0b00111111,
    0b00111111,
  },
  { // #4
    0b00110011,
    0b00110011,
    0b00110011,
    0b00111111,
    0b00111111,
    0b00000011,
    0b00000011,
    0b00000011,
  },
  { // #5
    0b00111111,
    0b00111111,
    0b00110000,
    0b00111111,
    0b00111111,
    0b00000011,
    0b00111111,
    0b00111111,
  },
  { // #6
    0b00111111,
    0b00111111,
    0b00110000,
    0b00111111,
    0b00111111,
    0b00110011,
    0b00111111,
    0b00111111,
  },
  { // #7
    0b00111111,
    0b00111111,
    0b00000011,
    0b00000011,
    0b00000011,
    0b00000011,
    0b00000011,
    0b00000011,
  },
  { // #8
    0b00111111,
    0b00111111,
    0b00110011,
    0b00111111,
    0b00111111,
    0b00110011,
    0b00111111,
    0b00111111,
  },
  { // #9
    0b00111111,
    0b00111111,
    0b00110011,
    0b00111111,
    0b00111111,
    0b00000011,
    0b00111111,
    0b00111111,
  }
};

/* LIGHT */
int c_hue = 0; // variable to store hue value of color
int c_sat = 255; // variable to store saturation value of color
int c_val = 0; // variable to store brightness value of color

/* OTHER */
int counter = 0; // variable to store number counting up

/* NEOPIXEL */
CRGB rgbLEDMatrix[totalPixels]; // LED array of the size totalPixels

/* NON BLOCKING */
unsigned long prevMillis = 0; // variable to store last time code was updated
unsigned long currentMillis = 0; // variable to store how long the code has been running for
const long interval = 1000; // variable to store interval in which code will be updated (could have more than one)

void setup() {
  FastLED.addLeds<WS2812B, rgbLEDMatrixPin, GRB>(rgbLEDMatrix, totalPixels); // assign rgbLEDMatrix to FastLED object
}

void loop() {
  currentMillis = millis(); // store time since sketch has been running (in milli seconds)
  if(currentMillis - prevMillis >= interval) { // condition if code gets updated
    prevMillis = currentMillis; // store time from currentMillis into prevMillis

    /* CODE UPDATES */
    if(counter >= 100) { // condition to reset counter
      counter = 0; // set counter back to 0
    }
    
    displayCounter(counter); // call function to show current counter on RGB LED Matrices
    counter++; // increase counter by 1
  }
}
