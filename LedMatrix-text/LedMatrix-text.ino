// Remember to add the FastLED_NeoMatrix library
#include <Adafruit_GFX.h>
#include <FastLED.h>
#include <FastLED_NeoMatrix.h>


#define PIN 5 // digital pin

#define BRIGHTNESS 40
#define mw 8 //matrix width
#define mh 8 //matrix height
#define NUMMATRIX (mw*mh) // Matrixsize

// Defining the matrix
CRGB matrixleds[NUMMATRIX]; 

// Defining the adressing of the matrix
FastLED_NeoMatrix *matrix = new FastLED_NeoMatrix(matrixleds, mw, mh, mw/8, 1, 
  NEO_MATRIX_TOP     + NEO_MATRIX_RIGHT +
    NEO_MATRIX_ROWS + NEO_MATRIX_ZIGZAG );
    
// ----------------------------------------------------------------------

// Simple colors
const uint16_t colors[] = {
  matrix->Color(255, 0, 0), matrix->Color(0, 255, 0), matrix->Color(0, 0, 255) };


void setup() {
  Serial.begin(115200);
  FastLED.addLeds<NEOPIXEL,PIN>(matrixleds, NUMMATRIX);  // setting up the leds
  matrix->begin();
  matrix->setTextWrap(false);
  matrix->setBrightness(BRIGHTNESS);
  matrix->setTextColor(colors[0]);
}

int x    = mw;
int pass = 0;


void loop() {
  matrix->fillScreen(1);
  matrix->setCursor(x, 0);
  matrix->print(F("Eik Lab"));
  if(--x < -36) {
    x = matrix->width();
    if(++pass >= 3) pass = 0;
    matrix->setTextColor(colors[pass]);
  }
  matrix->show();
  delay(100);
}
