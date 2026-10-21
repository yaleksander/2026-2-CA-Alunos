# arquivo baixado de https://pynative.com/wp-content/uploads/2019/01/company_sales_data.csv

import csv
import os
import matplotlib.pyplot as plt
import numpy as np

with open(os.path.dirname(__file__) + ("/company_sales_data.csv")) as csvfile:
    reader = csv.reader(csvfile)
    for row in reader:
        print(row[0])
