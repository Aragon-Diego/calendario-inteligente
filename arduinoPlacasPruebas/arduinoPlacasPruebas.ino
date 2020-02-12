#include <LedControl.h> //  need the library
LedControl lc0= LedControl(52,51,53, 4); //din,clk,cs
LedControl lc1 = LedControl(50,48,49, 4); //
LedControl lc2= LedControl(47,46,45, 4); //
LedControl lc3 = LedControl(44,43,42, 4); //
// pin 12 is connected to the MAX7219 pin 1 labelled DIN
// pin 11 is connected to the CLK pin 13 labelled CLK
// pin 10 is connected to LOAD pin 12 labelled as CS
// 1 as we only have 1 MAX 7219 atatched
void setup(){
  // the zero refers to the MAX7219 number
  for (int i = 0; i < 4; i++){
    lc0.shutdown(i, false); // turn off power saving
    lc0.setIntensity(i, 0); // sets brightness (0~15 possible values)
    lc0.clearDisplay(i);// clear screen
    lc1.shutdown(i, false); // turn off power saving
    lc1.setIntensity(i, 0); // sets brightness (0~15 possible values)
    lc1.clearDisplay(i);// clear screen
    lc2.shutdown(i, false); // turn off power saving
    lc2.setIntensity(i, 0); // sets brightness (0~15 possible values)
    lc2.clearDisplay(i);// clear screen
    lc3.shutdown(i, false); // turn off power saving
    lc3.setIntensity(i, 0); // sets brightness (0~15 possible values)
    lc3.clearDisplay(i);// clear screen
  }
  borde();
  letras();
  
}
void borde(){
  for(int i=0;i<4;i++){
    for(int row=0;row<8;row++){
      lc0.setLed(i,7,row, true);
      lc3.setLed(i,0,row,true);
      lc3.setLed(i,7,row,true);
    }
  }
  for(int col=0;col<8;col++){
    lc0.setLed(0,col,7, true);
    lc1.setLed(0,col,7, true);
    lc2.setLed(0,col,7, true);
    lc3.setLed(0,col,7, true);
    lc0.setLed(3,col,0, true);
    lc1.setLed(3,col,0, true);
    lc2.setLed(3,col,0, true);
    lc3.setLed(3,col,0, true);
    lc0.setLed(2,col,2, true);
    lc1.setLed(2,col,2, true);
    lc2.setLed(2,col,2, true);
    lc3.setLed(2,col,2, true);
  }
  lc1.setLed(2,1,1, true);
  lc1.setLed(2,1,0, true);
  for(int row=0;row<8;row++){
    lc1.setLed(3,1,row, true);
  }
  for(int col=0;col<8;col++){
    lc3.setLed(1,col,4, true);
    lc3.setLed(3,col,5, true);
  }
}
void letras(){
  for(int col=0;col<6;col++){
    lc0.setLed(0,col,2, true);
  }
  lc0.setLed(0,0,0, true);
  lc0.setLed(0,0,1, true);
  lc0.setLed(1,5,0, true);
  lc0.setLed(1,5,3, true);
  lc0.setLed(1,5,4, true);
  lc0.setLed(1,4,2, true);
  lc0.setLed(1,4,5, true);
  lc0.setLed(1,3,2, true);
  lc0.setLed(1,2,3, true);
  lc0.setLed(1,1,4, true);
  for(int row=2;row<6;row++)
    lc0.setLed(1,0,row, true);
  for(int col=0;col<6;col++){
    lc0.setLed(2,col,7, true);
  }
  for(int col=1;col<6;col++){
    lc0.setLed(3,col,7, true);
    lc0.setLed(3,col,3, true);
  }
  lc0.setLed(3,4,6, true);
  lc0.setLed(3,4,4, true);
  lc0.setLed(3,3,5, true);

  lc3.setLed(0,5,3, true);
  lc3.setLed(0,4,3, true);
  lc3.setLed(0,3,3, true);
  lc3.setLed(0,3,5, true);
  lc3.setLed(0,2,4, true);

  lc3.setLed(1,5,0, true);
  lc3.setLed(1,4,0, true);
  lc3.setLed(1,3,0, true);
  lc3.setLed(1,5,2, true);
  lc3.setLed(1,4,2, true);
  lc3.setLed(1,3,2, true);
  lc3.setLed(1,2,1, true);

  lc3.setLed(2,5,0, true);
  lc3.setLed(2,4,0, true);
  lc3.setLed(2,2,0, true);
  lc3.setLed(3,5,7, true);
  lc3.setLed(3,3,7, true);
  lc3.setLed(3,2,7, true);

  lc3.setLed(3,5,2, true);
  lc3.setLed(3,5,3, true);
  lc3.setLed(3,4,1, true);
  lc3.setLed(3,4,3, true);
  lc3.setLed(3,3,1, true);
  lc3.setLed(3,3,3, true);
  lc3.setLed(3,2,2, true);
  lc3.setLed(3,2,3, true);

  lc2.setLed(3,7,2, true);
  lc2.setLed(3,5,2, true);
  lc2.setLed(3,4,2, true);
  lc2.setLed(3,3,2, true);
  for(int col=3;col<8;col++){
    lc2.setLed(2,col,0, true);
    lc2.setLed(3,col,4, true);
  }
  lc2.setLed(3,5,6, true);
  lc2.setLed(3,6,5, true);
  lc2.setLed(3,6,7, true);
  
}
void loop(){
  /*
  for (int row = 0; row < 8; row++){
    for (int col = 0; col < 8; col++){
      for (int i = 0; i < 1; i++){
        lc0.setLed(i, col, row, true); // turns on LED at col, row
        lc1.setLed(i, col, row, true); // turns on LED at col, row
        lc2.setLed(i, col, row, true); // turns on LED at col, row
        lc3.setLed(i, col, row, true); // turns on LED at col, row

      }
      delay(50);
    }
  }
  for (int row = 0; row < 8; row++){
    for (int col = 0; col < 8; col++){
      for (int i = 0; i < 1; i++){
        lc0.setLed(i, col, row, false); // turns off LED at col, row
        lc1.setLed(i, col, row, false); // turns off LED at col, row
        lc2.setLed(i, col, row, false); // turns off LED at col, row
        lc3.setLed(i, col, row, false); // turns off LED at col, row
      }
      delay(50);
    }
  }
  */
}
