// NeoPixel Ring simple sketch (c) 2013 Shae Erisson
// released under the GPLv3 license to match the rest of the AdaFruit NeoPixel library

#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

// Which pin on the Arduino is connected to the NeoPixels?
// On a Trinket or Gemma we suggest changing this to 1
#define PIN            6

// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS      34
const int buttonPin 8;
int buttonState;
int lightNum = 0; 
// When we setup the NeoPixel library, we tell it how many pixels, and which pin to use to send signals.
// Note that for older NeoPixel strips you might need to change the third parameter--see the strandtest
// example for more information on possible values.
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel strip = Adafruit_NeoPixel(60, PIN, NEO_GRB + NEO_KHZ800);

int delayval = 150; // delay for half a second

void setup() {
  // This is for Trinket 5V 16MHz, you can remove these three lines if you are not using a Trinket
#if defined (__AVR_ATtiny85__)
  if (F_CPU == 16000000) clock_prescale_set(clock_div_1);
#endif
  // End of trinket special code
  Serial.begin(9600);
  pinMode(buttonPin, INPUT);
  strip.begin();
  strip.setBrightness(50);
  pixels.begin(); // This initializes the NeoPixel library.
}

void loop() {
  buttonChange();
  Serial.print(lightNum);
}

void CMYK_SoftPulse(){
//  for(int j=0;j<256;j++){
      strip.Color(255,0,255);
//  }
  strip.show();
}

void CMYK_Pulse(){
  for(int i=0;i<NUMPIXELS;i++){
    pixels.setPixelColor(i, pixels.Color(0,255,242));
    pixels.show();
  }
  delay(500);
  for(int i=0;i<NUMPIXELS;i++){
    pixels.setPixelColor(i, pixels.Color(250,255, 12));
    pixels.show();
  }
  delay(500);
  for(int i=0;i<NUMPIXELS;i++){
    pixels.setPixelColor(i, pixels.Color(250,0,255));
    pixels.show();
  }
  delay(500);
}

void CMYK_WhiteWipe(){
  for(int i=0;i<NUMPIXELS;i++){
    pixels.setPixelColor(i, pixels.Color(0,255,242));
    pixels.show();
  }
  delay(500);
  for(int i=0;i<NUMPIXELS;i++){
    for(int j=0;j<256;j++){
      pixels.setPixelColor(i, pixels.Color(255,j,255));
      pixels.show();
    }
  }
  for(int i=0;i<NUMPIXELS;i++){
    pixels.setPixelColor(i, pixels.Color(255,255, 12));
    pixels.show();
  }
  delay(500);
  for(int i=0;i<NUMPIXELS;i++){
    for(int j=0;j<256;j++){
      pixels.setPixelColor(i, pixels.Color(255,255,j));
      pixels.show();
    }
  }
  for(int i=0;i<NUMPIXELS;i++){
    pixels.setPixelColor(i, pixels.Color(250,0,255));
    pixels.show();
  }
  delay(500);
  for(int i=0;i<NUMPIXELS;i++){
    for(int j=0;j<256;j++){
      pixels.setPixelColor(i, pixels.Color(255,j, 255));
      pixels.show();
    }
  }
}


void CMYK_Cycle(){
    for(int i=0;i<NUMPIXELS;i++){

    // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
    pixels.setPixelColor(i, pixels.Color(0,255,242)); // Cyan

    pixels.show(); // This sends the updated pixel color to the hardware.

    delay(delayval); // Delay for a period of time (in milliseconds).

  }
  for(int i=0;i<NUMPIXELS;i++){
    pixels.setPixelColor(i, pixels.Color(250,255, 12)); // Yellow

     pixels.show(); // This sends the updated pixel color to the hardware.

    delay(delayval); // Delay for a period of time (in milliseconds).
    
  }
  for(int i=0;i<NUMPIXELS;i++){
    pixels.setPixelColor(i, pixels.Color(250,0,255)); // Magenta
    
    pixels.show(); // This sends the updated pixel color to the hardware.

    delay(delayval); // Delay for a period of time (in milliseconds).
  }
}

void buttonChange(){
  buttonState = digitalRead(buttonPin);
  if (buttonState == HIGH){
    if lightNum > 3{
      lightNum = 0
    }
    else {
      lightNum ++
    }
  }
}

