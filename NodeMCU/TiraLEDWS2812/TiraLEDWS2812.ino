#include <Adafruit_NeoPixel.h>      //Librerias necesaria para utilizar las tiras LED WS2812.
#ifdef __AVR__
  #include <avr/power.h>
#endif

#define PIN            D1           //Numero De PIN
#define NUMPIXELS      15           //Cantidad De LED

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

int delayval = 500; // Tiempo para enceder cada LED

void setup() {
  
#if defined (__AVR_ATtiny85__)
  if (F_CPU == 16000000) clock_prescale_set(clock_div_1);
#endif

  pixels.begin(); // Se inicializa la libreria NeoPixel
}

void loop() {

  for(int i=0;i<NUMPIXELS;i++){

    // Valores RGB de cada LED
    pixels.setPixelColor(i, pixels.Color(0,150,0)); // Color Verde, El valor indica la intensidad de brillo del LED.

    pixels.show();

    delay(delayval);

  }
}
