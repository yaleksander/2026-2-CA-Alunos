#include <FastLED.h>

#define LED_R 3
#define LED_G 5
#define LED_B 6

CRGB rgb;
CHSV hsv;

void setup()
{
	pinMode(LED_R, OUTPUT);
	pinMode(LED_G, OUTPUT);
	pinMode(LED_B, OUTPUT);
	hsv = CHSV(0, 255, 255);
}

void loop()
{
	hsv.h = millis() % 192;
	hsv2rgb_raw(hsv, rgb);
}
