# baixe o arquivo https://cdn.tse.jus.br/estatistica/sead/odsele/relatorio_resultado_totalizacao/Relatorio_Resultado_Totalizacao_2026_ES.zip
# e extraia o csv para a mesma pasta do script

import csv
import os
import matplotlib.pyplot as plt

with open(os.path.dirname(__file__) + "/votacao_secao_2026_ES.csv", encoding = "latin-1") as csvfile:
	arquivo = csv.reader(csvfile, delimiter = ";")
	cabecalho = next(arquivo)
	votos = {}
	'''
	Usando o dicionario "votos" declarado acima, faca um grafico de barras onde o eixo y
	indica a quantidade de votos e o eixo x indica cada candidato a senador
	'''
	fig, axs = plt.subplots(figsize = (10, 7))
	plt.subplots_adjust(bottom = 0.3)
	axs.bar(votos.keys(), votos.values())
	axs.tick_params("x", rotation = 45, rotation_mode = "xtick")
	axs.set_title("Votos para senador no ES")
	plt.show()
