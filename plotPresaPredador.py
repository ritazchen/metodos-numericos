import matplotlib.pyplot as plt
import math

X = []
Y_presa = []
Y_predador = []

arquivo_presa = open('dados_presa.txt', 'r')
dados_presa = arquivo_presa.read()
arquivo_presa.close()

arquivo_predador = open('dados_predador.txt', 'r')
dados_predador = arquivo_predador.read()
arquivo_predador.close()


coordenadas = dados_presa.split(';')

for coordenada in coordenadas:
    if coordenada != '':
        x, y = map(float, coordenada.split(','))
        X.append(x)
        Y_presa.append(y)

X = []

coordenadas = dados_predador.split(';')

for coordenada in coordenadas:
    if coordenada != '':
        x, y = map(float, coordenada.split(','))
        X.append(x)
        Y_predador.append(y)

plt.title('Questao 1')
plt.xlabel('População')
plt.ylabel('Tempo')

plt.plot(X, Y_presa, c='red', label = 'Presa')
plt.plot(X, Y_predador, c='blue', label = 'Predador')
#plt.plot(X, Y_predador, c='blue', marker='o', ls='--', label = 'Predador')

plt.legend()
plt.show()
