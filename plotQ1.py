import matplotlib.pyplot as plt
import math

X_euler = []
Y_euler = []
X_segunda = []
Y_segunda = []
X_terceira = []
Y_terceira = []
X_quarta = []
Y_quarta = []
coordenadas = []

dados_euler = '0.000000,2.000000;0.100000,2.010000;0.200000,2.029000;0.300000,2.056100;0.400000,2.090490;0.500000,2.131441;0.600000,2.178297;0.700000,2.230467;0.800000,2.287420;0.900000,2.348678;1.000000,2.413811;'

coordenadas = dados_euler.split(';')

for coordenada in coordenadas:
    if coordenada != '':
        x, y = map(float, coordenada.split(','))
        X_euler.append(x)
        Y_euler.append(y)
        
coordenadas = []
        
dados_segunda = '0.000000,2.000000;0.100000,2.014500;0.200000,2.037123;0.300000,2.067096;0.400000,2.103722;0.500000,2.146368;0.600000,2.194463;0.700000,2.247489;0.800000,2.304978;0.900000,2.366505;1.000000,2.431687;'
        
coordenadas = dados_segunda.split(';')

for coordenada in coordenadas:
    if coordenada != '':
        x, y = map(float, coordenada.split(','))
        X_segunda.append(x)
        Y_segunda.append(y)

coordenadas = []

dados_terceira = '0.000000,2.000000;0.100000,2.014350;0.200000,2.036851;0.300000,2.066727;0.400000,2.103277;0.500000,2.145865;0.600000,2.193917;0.700000,2.246913;0.800000,2.304381;0.900000,2.365898;1.000000,2.431077;'

coordenadas = dados_terceira.split(';')

for coordenada in coordenadas:
    if coordenada != '':
        x, y = map(float, coordenada.split(','))
        X_terceira.append(x)
        Y_terceira.append(y)
        
coordenadas = []

dados_quarta = '0.000000,2.000000;0.100000,2.014354;0.200000,2.036858;0.300000,2.066737;0.400000,2.103288;0.500000,2.145878;0.600000,2.193931;0.700000,2.246927;0.800000,2.304396;0.900000,2.365913;1.000000,2.431092;'

coordenadas = dados_quarta.split(';')

for coordenada in coordenadas:
    if coordenada != '':
        x, y = map(float, coordenada.split(','))
        X_quarta.append(x)
        Y_quarta.append(y)

X = []
Y = []
i = 0.0

while i <= 1.0:
    X.append(float(i))
    i = i + 0.1
    
for x in X:
    y = math.exp(x*(-1)) + x + 1
    Y.append(y)

plt.title('Questao 1')
plt.xlabel('x')
plt.ylabel('y')

plt.plot(X, Y, c='red', lw = 4., marker='o', label = 'exata')
plt.plot(X_euler, Y_euler, c='blue', lw = 2., marker='o', ls='--', label = 'euler')
plt.plot(X_segunda, Y_segunda, c='gray', lw = 5., marker='o', ls='--', label = '2ª runge-kutta')
plt.plot(X_terceira, Y_terceira, c='purple', lw = 3., marker='o', ls='--', label = '3ª runge-kutta')
plt.plot(X_quarta, Y_quarta, c='pink', lw = 1., marker='o', ls='--', label = '4ª runge-kutta')

plt.legend()
plt.show()