#define TAM_SEQ 5
#define PAUSA_ENTRE_BOTOES 500
#define TEMPO_JOGADA_MAX 5000

const byte LED[4] = { 5, 4, 3, 2 };
const byte BOTAO[4] = { 13, 7, 8, 12 };
const byte LEDRGB[3] = { 11, 10, 6 };
const byte corVezDoJogador[3] = { 0, 120, 50 };
const byte corVezDaMaquina[3] = { 200, 90, 0 };

uint32_t marcador;
byte sequenciaCorreta[TAM_SEQ];
byte sequenciaJogador[TAM_SEQ];
byte jogoIniciado;

void setup()
{
	randomSeed(analogRead(0));
	for (byte i = 0; i < 4; i++)
	{
		pinMode(LED[i], OUTPUT);
		pinMode(BOTAO[i], INPUT_PULLUP);
	}
	for (byte i = 0; i < 3; i++)
		pinMode(LEDRGB[i], OUTPUT);
	jogoIniciado = false;
}

/*
 * Dica: implementar outras funcoes alem das
 * indicadas pode economizar tempo e deixar seu
 * codigo mais limpo e legivel.
 */

void iniciarJogo()
{
	/*
	 * Implementar o setup inicial do jogo. Dica:
	 * Use a funcao random(4) p/ atribuir um valor
	 * de 0 a 3 para cada elemento do array:
	 * [...]
	 * sequenciaCorreta[i] = random(4);
	 * [...]
	 */
}

void mostrarSequencia()
{
	/*
	 * Implementar um codigo para mostrar a
	 * sequencia correta de cores, mas so ate o
	 * proximo passo. O jogador acerta 1 cor,
	 * a maquina mostra 2 cores. O jogador acerta 2
	 * cores, a maquina mostra 3, e assim por
	 * diante ate o jogador acertar todas.
	 */
}

byte lerSequencia()
{
	/*
	 * Implementar um codigo para ler uma sequencia
	 * de botoes. A funcao deve retornar 0 caso o
	 * jogador tenha acertado a sequencia completa,
	 * 1 caso tenha errado, 2 caso o tempo de
	 * espera tenha ultrapassado o limite (definido
	 * por TEMPO_JOGADA_MAX) e qualquer outro valor
	 * caso tenha acertado a sequencia mas o jogo
	 * ainda nao tiver terminado.
	 */
}

void loop()
{
	if (!jogoIniciado)
		iniciarJogo();
	mostrarSequencia();
	byte estado = lerSequencia();
	/*
	 * Implementar um pisca alerta pra vitoria, pra
	 * derrota, e pra derrota por tempo. Dica: nao
	 * ha necessidade de implementar nada caso o
	 * jogador tenha acertado a sequencia parcial,
	 * o jogo segue normalmente.
	 */
}

