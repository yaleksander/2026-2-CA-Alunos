#define LED_R 3
#define LED_G 5
#define LED_B 6
#define POT_R A0
#define POT_G A1
#define POT_B A2

void setup()
{
	pinMode(POT_R, INPUT);
	pinMode(POT_G, INPUT);
	pinMode(POT_B, INPUT);
	pinMode(LED_R, OUTPUT);
	pinMode(LED_G, OUTPUT);
	pinMode(LED_B, OUTPUT);
}

void loop()
{
	// as portas de entrada analogicas A0-A5 lidam com valores
	// de 0 a 1023. Ja as portas de saida PWM lidam com valores
	// de 0 a 255. Por isso a necessidade da conversao:
	analogWrite(LED_R, (analogRead(POT_R) / 1023.0) * 255);
	analogWrite(LED_G, (analogRead(POT_G) / 1023.0) * 255);
	analogWrite(LED_B, (analogRead(POT_B) / 1023.0) * 255);
}
