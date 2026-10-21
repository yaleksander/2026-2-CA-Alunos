const byte PIN_BOTAO = 6;
const byte PIN_LED7 = 7;
const byte DIGITOS[10][7] =
{
	{ 1, 1, 1, 1, 1, 1, 0 }, // 0
	{ 0, 1, 1, 0, 0, 0, 0 }, // 1
	{ 1, 1, 0, 1, 1, 0, 1 }, // 2
	{ 1, 1, 1, 1, 0, 0, 1 }, // 3
	{ 0, 1, 1, 0, 0, 1, 1 }, // 4
	{ 1, 0, 1, 1, 0, 1, 1 }, // 5
	{ 1, 0, 1, 1, 1, 1, 1 }, // 6
	{ 1, 1, 1, 0, 0, 0, 0 }, // 7
	{ 1, 1, 1, 1, 1, 1, 1 }, // 8
	{ 1, 1, 1, 0, 0, 1, 1 }  // 9
};

byte num;

void setup()
{
	num = 0;
	pinMode(PIN_BOTAO, INPUT_PULLUP);
	for (byte i = 0; i < 7; i++)
		pinMode(PIN_LED7 + i, OUTPUT);
	for (byte i = 0; i < 7; i++)
		digitalWrite(PIN_LED7 + i, DIGITOS[num][i]);
}

void loop()
{
	// o input pullup retorna falso (equivalente a 0) quando o
	// botao esta pressionado, por isso o "!"
	if (!digitalRead(PIN_BOTAO))
	{
		num = (num + 1) % 10;
		for (byte i = 0; i < 7; i++)
			digitalWrite(PIN_LED7 + i, DIGITOS[num][i]);

		// precisamos esperar o usuario soltar o botao
		while (!digitalRead(PIN_BOTAO))
			delay(16);
	}
}
