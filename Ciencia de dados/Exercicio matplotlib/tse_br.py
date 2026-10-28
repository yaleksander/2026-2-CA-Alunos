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
	'''
	fig, axs = plt.subplots(2, 2, figsize = (10, 7))
	plt.subplots_adjust(bottom = 0.3)
    for i in range(len(estados)):
        axs[i].bar(votos[i].keys(), votos[i].values())
        axs[i].tick_params("x", rotation = 45, rotation_mode = "xtick")
        axs[i].set_title("Votos para presidente no 1º turno em: " + estados[i])
	plt.show()
