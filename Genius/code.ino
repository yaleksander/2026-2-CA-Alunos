// github.com/yaleksander/2026-2-CA-Alunos
// Nome da pasta: Genius

#define TAM_SEQ 5
#define PAUSA_ENTRE_BOTOES 500
#define TEMPO_JOGADA_MAX 5000

// LEDs de uma unica cor:
// 0. vermelho, 1. verde, 2. azul, 3. amarelo
const byte LED[4] = { 5, 4, 3, 2 };

// Botoes correspondentes aos LEDs
const byte BOTAO[4] = { 13, 7, 8, 12 };

// LED RGB, o que fica embaixo no circuito
const byte LEDRGB[3] = { 11, 10, 6 };

// Cores pre definidas
// https://htmlcolorcodes.com/color-picker/
const byte corVezDoJogador[3] = { 0, 120, 50 };
const byte corVezDaMaquina[3] = { 200, 90, 0 };
const byte corVitoria[3] = { 0, 255, 80 };
const byte corDerrota[3] = { 255, 0, 0 };
const byte corDerrotaTempo[3] = { 255, 120, 0 };

// Sequencia com as cores corretas (de 0 a 4)
byte sequenciaCorreta[TAM_SEQ];

// Sequencia com as cores inseridas pelo jogador
byte sequenciaJogador[TAM_SEQ];

// Valor 0 ou 1 que indica se o jogo foi iniciado
byte jogoIniciado;

// Quantidade de acertos do jogador, pra marcar o turno do jogo
byte acertos;

void setup()
{
	// funcao para deixar o jogo aleatorio
	randomSeed(analogRead(0));
	
	// setup das portas
	for (byte i = 0; i < 4; i++)
	{
		pinMode(LED[i], OUTPUT);
		pinMode(BOTAO[i], INPUT_PULLUP);
	}
	for (byte i = 0; i < 3; i++)
		pinMode(LEDRGB[i], OUTPUT);
	
	// jogoIniciado comeca como false ou 0 porque sera iniciado apenas na funcao iniciarJogo
	jogoIniciado = false;
}

// funcao auxiliar para piscar as cores e marcar o termino do jogo, seja vitoria ou derrota
void fimDeJogo(byte rgb[3])
{
	// repete 5 vezes arbitrariamente
	for (byte i = 0; i < 5; i++)
	{
		// acende as cores
		for (byte j = 0; j < 4; j++)
			digitalWrite(LED[j], 1);
		for (byte j = 0; j < 3; j++)
			analogWrite(LEDRGB[i], rgb[i]);
		delay(200);
		
		// apaga as cores
		for (byte j = 0; j < 4; j++)
			digitalWrite(LED[j], 0);
		for (byte j = 0; j < 3; j++)
			analogWrite(LEDRGB[i], 0);
		delay(200);
	}
	// espera um pouco antes de prosseguir
	delay(2000);
	
	// reinicia o jogo
	jogoIniciado = false;
}

void iniciarJogo()
{
	// reinicia a sequencia correta
	for (byte i = 0; i < TAM_SEQ; i++)
		sequenciaCorreta[i] = random(4);
	
	// volta o valor de acertos pra 0, reiniciando os turnos
	acertos = 0;
	
	// marca o jogo como iniciado
	jogoIniciado = true;
}

void mostrarSequencia()
{
	// indica que o jogador nao pode jogar ainda
	for (byte i = 0; i < 3; i++)
		analogWrite(LEDRGB[i], corVezDaMaquina[i]);
	delay(500);
	
	// mostra as cores APENAS ate o turno corrente
	for (byte i = 0; i <= acertos; i++)
	{
		digitalWrite(LED[sequenciaCorreta[i]], 1);
		delay(PAUSA_ENTRE_BOTOES);
		digitalWrite(LED[sequenciaCorreta[i]], 0);
		delay(PAUSA_ENTRE_BOTOES);
	}
	delay(500);
}

byte lerSequencia()
{
	// indica que o jogador deve jogar
	for (byte i = 0; i < 3; i++)
		analogWrite(LEDRGB[i], corVezDoJogador[i]);
	
	// conta o numero de jogadas executadas na rodada
	byte jogadas = 0;
	
	// marcador de tempo
	uint32_t marcador = millis();

	// continua ate atingir o limite de jogadas da rodada
	while (jogadas <= acertos)
	{
		// verifica se os botoes de 0 a 4 foram pressionados
		for (byte i = 0; i < 4; i++)
		{
			if (!digitalRead(BOTAO[i]))
			{
				// acende o LED correspondente
				digitalWrite(LED[i], 1);
				
				// anota qual botao foi pressionado
				sequenciaJogador[jogadas] = i;
				
				// reinicia o marcador de tempo
				marcador = millis();
				
				// enquanto jogador mantiver o botao pressionado, espera
				while (!digitalRead(BOTAO[i]))
				{
					// se passou do tempo maximo, retorna 2 indicando que perdeu por tempo
					delay(16);
					if (marcador + TEMPO_JOGADA_MAX < millis())
						return 2;
				}
				// apaga o LED
				digitalWrite(LED[i], 0);
				
				// se o botao pressionado estiver errado, retorna 1 indicando que perdeu o jogo
				if (sequenciaJogador[jogadas] != sequenciaCorreta[jogadas])
					return 1;
				
				// se chegou no maximo de jogadas, retorna 0 indicando a vitoria
				if (++jogadas == TAM_SEQ)
					return 0;
			}
		}
		// se passou do tempo maximo, retorna 2 indicando que perdeu por tempo
		delay(16);
		if (marcador + TEMPO_JOGADA_MAX < millis())
			return 2;
	}
	// numero de acertos sempre soma +1 na rodada
	acertos++;
	
	// retorna qualquer numero diferente de 0, 1 ou 2 pra indicar que o jogo segue
	return 255;
}

void loop()
{
	if (!jogoIniciado)
		iniciarJogo();
	mostrarSequencia();
	byte estado = lerSequencia();
	if (estado == 0)
		fimDeJogo(corVitoria);
	else if (estado == 1)
		fimDeJogo(corDerrota);
	else if (estado == 2)
		fimDeJogo(corDerrotaTempo);
}
