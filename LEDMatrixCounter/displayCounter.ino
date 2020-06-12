void displayCounter(int _counter) { //

  int counterTens = _counter/10; // store first digit of number
  int counterOnes = _counter - counterTens*10; // store second digit of counter
  
  for(int i=0; i<8; i++) { // for loop counting from 0-7
    for(int j=0; j<8; j++) { // for loop counting from 0-7

      // Tens
      if(bitRead(numbers[counterTens][i],j) == 1) { // read byte from number array [first digit] bit by bit
        c_val = brightness; // if bit equals 1 set c_val to 25
      } else {
        c_val = 0; // otherwise set c_val to 0
      } 
      rgbLEDMatrix[(i*8)+(7-j)] = CHSV(c_hue,c_sat,c_val); // set color of corresponding RGB LED pixel of previously read bit

      // Ones
      if(bitRead(numbers[counterOnes][i],j) == 1) { // read byte from number array [second digit] bit by bit
        c_val = brightness; // if bit equals 1 set c_val to 25
      } else {
        c_val = 0; // otherwise set c_val to 0
      } 
      rgbLEDMatrix[(i*8)+(7-j)+numPixelPerMatrix] = CHSV(c_hue,c_sat,c_val); // set color of corresponding RGB LED pixel of previously read bit
    }
  }
  
  FastLED.show(); // update RGB LED matrix
  c_val = 0; // set c_val to 0
}
