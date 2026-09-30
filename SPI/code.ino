#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_ILI9341.h>
#include <MD_MAX72xx.h>
#include <MD_Parola.h>

#define CS_LEDMAT 4
#define CS_TFT1 3
#define CS_TFT2 2
#define DC_TFT 5

MD_Parola ledmat = MD_Parola(MD_MAX72XX::GENERIC_HW, CS_LEDMAT, 1);
Adafruit_ILI9341 tft1 = Adafruit_ILI9341(CS_TFT1, DC_TFT, -1);
Adafruit_ILI9341 tft2 = Adafruit_ILI9341(CS_TFT2, DC_TFT, -1);

void setup()
{
	Serial.begin(9600);
	ledmat.begin();
	tft1.begin();
	tft2.begin();

	digitalWrite(CS_LEDMAT, HIGH);
	digitalWrite(CS_TFT1, HIGH);
	digitalWrite(CS_TFT2, HIGH);

	digitalWrite(CS_TFT1, LOW);
	tft1.fillScreen(ILI9341_RED);
	tft1.setTextColor(ILI9341_WHITE);
	tft1.setCursor(10, 280);
	tft1.setTextSize(3);
	tft1.println("Hello World!");
	digitalWrite(CS_TFT1, HIGH);

	digitalWrite(CS_TFT2, LOW);
	tft2.fillScreen(ILI9341_GREEN);
	tft2.setTextColor(ILI9341_WHITE);
	tft2.setCursor(10, 280);
	tft2.setTextSize(3);
	tft2.println("Hello World!");
	digitalWrite(CS_TFT2, HIGH);
}

void loop()
{

}
