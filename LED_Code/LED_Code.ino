/*
 * To turn on the specific pixels, open the Serial monitor.
 * Then input the row number 1-30. Press Enter. 
 * Then Input the column number 1-30. Press Enter.
 * This will turn on// turn off the selected pixel.
 * If the user inputs 100 and 100, all pixels will turn on for 5 sec. This can be used to reset
 * all the pixels or to check if all the pixels work.
 */


#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

/*
 * Define every pin. Pin #0 and #1 on Arduino Mega don't work.
 */

#define PIN_1 24
#define PIN_2 25
#define PIN_3 2
#define PIN_4 3
#define PIN_5 4
#define PIN_6 5
#define PIN_7 6
#define PIN_8 7
#define PIN_9 8
#define PIN_10 9

#define PIN_11 10
#define PIN_12 11
#define PIN_13 12
#define PIN_14 13
#define PIN_15 14
#define PIN_16 15
#define PIN_17 16
#define PIN_18 17
#define PIN_19 18
#define PIN_20 19

#define PIN_21 20
#define PIN_22 21
#define PIN_23 22
#define PIN_24 23
#define PIN_25 A0
#define PIN_26 A1
#define PIN_27 A2
#define PIN_28 A3
#define PIN_29 A4
#define PIN_30 A5



// Parameter 1 = number of pixels in strip
// Parameter 2 = Arduino pin number (most are valid)
// Parameter 3 = pixel type flags, add together as needed:
//   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
//   NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
//   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
//   NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)

/*
 *Create an array  with 30 strips, using previously defined pins. 
 */
 
Adafruit_NeoPixel strips[]{
  
  Adafruit_NeoPixel(30, PIN_1, NEO_GRB + NEO_KHZ800),
  Adafruit_NeoPixel(30, PIN_2, NEO_GRB + NEO_KHZ800),
  Adafruit_NeoPixel(30, PIN_3, NEO_GRB + NEO_KHZ800),
  Adafruit_NeoPixel(30, PIN_4, NEO_GRB + NEO_KHZ800),
  Adafruit_NeoPixel(30, PIN_5, NEO_GRB + NEO_KHZ800),
  Adafruit_NeoPixel(30, PIN_6, NEO_GRB + NEO_KHZ800),
  Adafruit_NeoPixel(30, PIN_7, NEO_GRB + NEO_KHZ800),
  Adafruit_NeoPixel(30, PIN_8, NEO_GRB + NEO_KHZ800),
  Adafruit_NeoPixel(30, PIN_9, NEO_GRB + NEO_KHZ800),
  Adafruit_NeoPixel(30, PIN_10, NEO_GRB + NEO_KHZ800),
  
  Adafruit_NeoPixel(30, PIN_11, NEO_GRB + NEO_KHZ800),
  Adafruit_NeoPixel(30, PIN_12, NEO_GRB + NEO_KHZ800),
  Adafruit_NeoPixel(30, PIN_13, NEO_GRB + NEO_KHZ800),
  Adafruit_NeoPixel(30, PIN_14, NEO_GRB + NEO_KHZ800),
  Adafruit_NeoPixel(30, PIN_15, NEO_GRB + NEO_KHZ800),
  Adafruit_NeoPixel(30, PIN_16, NEO_GRB + NEO_KHZ800),
  Adafruit_NeoPixel(30, PIN_17, NEO_GRB + NEO_KHZ800),
  Adafruit_NeoPixel(30, PIN_18, NEO_GRB + NEO_KHZ800),
  Adafruit_NeoPixel(30, PIN_19, NEO_GRB + NEO_KHZ800),
  Adafruit_NeoPixel(30, PIN_20, NEO_GRB + NEO_KHZ800),
  
  Adafruit_NeoPixel(30, PIN_21, NEO_GRB + NEO_KHZ800),
  Adafruit_NeoPixel(30, PIN_22, NEO_GRB + NEO_KHZ800),
  Adafruit_NeoPixel(30, PIN_23, NEO_GRB + NEO_KHZ800),
  Adafruit_NeoPixel(30, PIN_24, NEO_GRB + NEO_KHZ800),
  Adafruit_NeoPixel(30, PIN_25, NEO_GRB + NEO_KHZ800),
  Adafruit_NeoPixel(30, PIN_26, NEO_GRB + NEO_KHZ800),
  Adafruit_NeoPixel(30, PIN_27, NEO_GRB + NEO_KHZ800),
  Adafruit_NeoPixel(30, PIN_28, NEO_GRB + NEO_KHZ800),
  Adafruit_NeoPixel(30, PIN_29, NEO_GRB + NEO_KHZ800),
  Adafruit_NeoPixel(30, PIN_30, NEO_GRB + NEO_KHZ800),
};

// IMPORTANT: To reduce NeoPixel burnout risk, add 1000 uF capacitor across
// pixel power leads, add 300 - 500 Ohm resistor on first pixel's data input
// and minimize distance between Arduino and first pixel.  Avoid connecting
// on a live circuit...if you must, connect GND first.

void setup() {
  // This is for Trinket 5V 16MHz, you can remove these three lines if you are not using a Trinket
    
  #if defined (__AVR_ATtiny85__)
    if (F_CPU == 16000000) clock_prescale_set(clock_div_1);
  #endif
  // End of trinket special code

  /*
   * Setup all the strips and Serial. 
   */
  Serial.begin(9600);
  for(int i = 0; i < sizeof(strips) / sizeof(*strips); i++){
    strips[i].begin();
    strips[i].setBrightness(60); // Brightness goes from 0 (off) to 255(max brightness).
    strips[i].show();
  }
}

void loop() {

  
  int loopUserPrompt1 = 1;
  int loopUserPrompt2 = 1;
  int row = 0;
  int column = 0;
  uint32_t blank = strips[0].Color(0, 0, 0);

  /*
   * These loops prompt the user for two numbers from 1 to 30. First the row(the strip to turn on), then the column. 
   * If user types 100 and then 100 all pixels will light up for 5 seconds.
   */
   
  Serial.println("Input Row: ");
  while(loopUserPrompt1 == 1){
    if (Serial.available() > 0) {
      int input = Serial.parseInt(); 
      //Serial.println(input);
      if(input == 100 || input > 0 && input < 31){
        row = input-1;
        Serial.println("Input Column: ");
        while(loopUserPrompt2 == 1){
          if (Serial.available() > 0) {
            int input2 = Serial.parseInt(); 
            //Serial.println(input2);
            if(input2 == 100 || input2 > 0 && input2 < 31){
              column = input2-1;
              loopUserPrompt1 = 0;
              loopUserPrompt2 = 0;
            }
           }
         }
       }
     }
  }   

  /*
   * If the user types in two 100s then turn on all the pixels then turn them all off in 5 seconds.
   */
  if(row == 99 && column == 99){
    for(int i = 0; i < sizeof(strips) / sizeof(*strips); i++){
      for(int j = 0;j<30;j++){                      //------------30 pixels per strip
        strips[i].setPixelColor(j, 0, 255, 0);
      }
      strips[i].show();
    }
    delay(5000);
    for(int i = 0; i < sizeof(strips) / sizeof(*strips); i++){
      for(int j = 0;j<30;j++){                      //------------30 pixels per strip
        strips[i].setPixelColor(j, 0, 0, 0);
      }
      strips[i].show();
    }


  /*
   *If the picked pixel in off, turn it on. If the pixel is on, then turn it off.
   */
  }else{
    if(strips[row].getPixelColor(column) == blank){
      strips[row].setPixelColor(column, 0, 255, 0);
      strips[row].show();
    }else{
      strips[row].setPixelColor(column, 0, 0, 0);
      strips[row].show();
    } 
  }
}



