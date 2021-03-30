import numpy as np
import matplotlib.pyplot as plt
import matplotlib as mpl

 
file = open("Points.txt")
data = np.loadtxt(file, delimiter=",")
plt.title('Line Fitting Problem')
 
x, y = data.T
plt.scatter(x,y)

x = np.linspace(-5,5,100)
y = 2*x+1
plt.plot(x, y, '-r', label='y=2x+1')

plt.xlabel('x', color='#1C2833')
plt.ylabel('y', color='#1C2833')
plt.legend(loc='upper right')

plt.grid()
plt.show()
 
