# arquivo baixado de https://pynative.com/wp-content/uploads/2019/01/company_sales_data.csv

import csv
import os
import matplotlib.pyplot as plt

with open(os.path.dirname(__file__) + "/company_sales_data.csv") as csvfile:
	reader = csv.reader(csvfile)
	headers = next(reader)
	n = len(headers)
	vendas = []
	for i in range(n):
		vendas.append([])
	for row in reader:
		for i in range(n):
			vendas[i].append(float(row[i]))
	fig, axs = plt.subplots(1, 2)
	for i in range(1, 7):
		axs[0].plot(vendas[0], vendas[i], label = headers[i])
	axs[0].legend()
	axs[0].set_title("Vendas")
	axs[0].set(xlabel = "Mes", ylabel = "Unidades vendidas")
	axs[0].set(xticks = vendas[0], yticks = range(0, 20001, 2000))
	axs[1].set_title("Lucro")
	axs[1].set(xlabel = "Mes", ylabel = "Lucro mensal")
	axs[1].set(xticks = vendas[0], yticks = range(100000, 500001, 50000))
	axs[1].plot(vendas[0], vendas[8], label = headers[7])
	plt.show()
