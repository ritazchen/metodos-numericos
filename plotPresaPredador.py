import matplotlib.pyplot as plt
import math

X = []
Y_presa_Euler = []
Y_predador_Euler = []
Y_presa_RK4 = []
Y_predador_RK4 = []

arquivo_presa_Euler = open('dados_presa.txt', 'r')
dados_presa_Euler = arquivo_presa_Euler.read()
arquivo_presa_Euler.close()

arquivo_predador_Euler = open('dados_predador.txt', 'r')
dados_predador_Euler = arquivo_predador_Euler.read()
arquivo_predador_Euler.close()

arquivo_presa_RK4 = open('dados_presa_4RK.txt', 'r')
dados_presa_RK4 = arquivo_presa_RK4.read()
arquivo_presa_RK4.close()

arquivo_predador_RK4 = open('dados_predador_4RK.txt', 'r')
dados_predador_RK4 = arquivo_predador_RK4.read()
arquivo_predador_RK4.close()

coordenadas = dados_presa_Euler.split(';')

for coordenada in coordenadas:
    if coordenada != '':
        x, y = map(float, coordenada.split(','))
        X.append(x)
        Y_presa_Euler.append(y)

X = []

coordenadas = dados_predador_Euler.split(';')

for coordenada in coordenadas:
    if coordenada != '':
        x, y = map(float, coordenada.split(','))
        X.append(x)
        Y_predador_Euler.append(y)

X = []

coordenadas = dados_presa_RK4.split(';')

for coordenada in coordenadas:
    if coordenada != '':
        x, y = map(float, coordenada.split(','))
        X.append(x)
        Y_presa_RK4.append(y)

X = []

coordenadas = dados_predador_RK4.split(';')

for coordenada in coordenadas:
    if coordenada != '':
        x, y = map(float, coordenada.split(','))
        X.append(x)
        Y_predador_RK4.append(y)

plt.title('Modelo Presa-Predador Euler e RK4')
plt.ylabel('População')
plt.xlabel('Tempo')

plt.plot(X, Y_presa_Euler, c='red', label = 'Presa Euler')
plt.plot(X, Y_predador_Euler, c='blue', label = 'Predador Euler')
plt.plot(X, Y_presa_RK4, c='green',  ls='--', label = 'Presa RK4')
plt.plot(X, Y_predador_RK4, c='black', ls='--', label = 'Predador RK4')

plt.legend()
plt.show()
