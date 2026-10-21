#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <LiquidCrystal_AIP31068_I2C.h>

Adafruit_SSD1306 display(128, 64, &Wire, -1);

void setup()
{
	Serial.begin(9600);
	display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
	display.setTextSize(1);
	display.setTextColor(SSD1306_WHITE);
}

void loop()
{
	display.clearDisplay();
	display.setCursor(10, 10);
	display.print(F(" Ja se passaram"));
	display.setCursor(10, 20);
	display.print(F(" "));
	display.print(millis() / 1000);
	display.print(F(" segundos"));
	display.display();
}
