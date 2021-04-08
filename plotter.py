import numpy as np
import matplotlib.pyplot as plt
import matplotlib as mpl

 
file = open("input.txt")
data = np.loadtxt(file, delimiter=" ") 
x, y = data.T
plt.scatter(x,y)

file1 = open("param.txt")
param = np.loadtxt(file1, delimiter=" ",usecols=range(2))
print(param)
C= param[0]
error = param[1]

plt.title('Line Fitting Problem  ( C : ' + str(int(C)) + ", Error : "+ str(error) + ")")

file2 = open("lines.txt")
segment = np.loadtxt(file2, delimiter=" ")

if segment.ndim == 1:
    x_values = segment[0], segment[2]
    y_values = segment[1], segment[3]
    plt.plot(x_values, y_values)
else:
    for s in segment:    
        x_values = [s[0], s[2]]
        y_values = [s[1], s[3]]
        plt.plot(x_values, y_values)

plt.xlabel('x', color='#1C2833')
plt.ylabel('y', color='#1C2833')


plt.grid()
plt.show()
 
