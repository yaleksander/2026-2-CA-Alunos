#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

Adafruit_SSD1306 display(128, 64, &Wire, -1);

void setup()
{
	Serial.begin(115200);
	if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C))
	{
		Serial.println(F("SSD1306 not found"));
		return;
	}
}

void loop()
{
	display.clearDisplay();
	display.setTextSize(2);
	display.setTextColor(SSD1306_WHITE);
	display.setCursor(10, 10);
	display.println("Hello,");
	display.setCursor(10, 30);
	display.println("world!");
	display.display();
	delay(500);
}