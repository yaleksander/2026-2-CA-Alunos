# baixe o arquivo https://cdn.tse.jus.br/estatistica/sead/odsele/votacao_secao/votacao_secao_2026_BR.zip
# e extraia o csv para a mesma pasta do script

import csv
import os
import matplotlib.pyplot as plt

with open(os.path.dirname(__file__) + "/votacao_secao_2026_BR.csv", encoding = "latin-1") as csvfile:
	arquivo = csv.reader(csvfile, delimiter = ";")
	cabecalho = next(arquivo)
	estados = ["ES", "MG", "RJ", "SP"]
	votos = {}
	for estado in estados:
		votos[estado] = {}
	'''
	Usando o vetor dicionario "votos" declarado acima, faca um grafico de barras onde o eixo
	y indica a quantidade de votos e o eixo x indica cada candidato a presidente no 1o turno.
    Faca subplots para 4 estados diferentes. Voce pode mudar os estados se quiser.
    Opcionalmente ordene os candidatos em ordem decrescente com base no numero de votos.
	Dica: para ordenar um dicionario, use dict(sorted(d.items())). Acrescente mais parametros
	para ordenar a lista em ordem decrescente (reversa) e por outro criterio. Use lambda.
	'''
	fig, axs = plt.subplots(2, 2, figsize = (10, 9))
	fig.suptitle("Votos para presidente no 1º turno")
	plt.subplots_adjust(bottom = 0.2, hspace = 1.1)
	for i in range(4):
		axs[int(i / 2), i % 2].bar(votos[estados[i]].keys(), votos[estados[i]].values())
		axs[int(i / 2), i % 2].tick_params("x", rotation = 45, rotation_mode = "xtick", labelsize = 7)
		axs[int(i / 2), i % 2].set_title(estados[i])
	plt.show()
