import numpy as np
import matplotlib.pyplot as plt
import matplotlib as mpl

 
file = open("input.txt")
data = np.loadtxt(file, delimiter=" ")
plt.title('Line Fitting Problem')
 
x, y = data.T
plt.scatter(x,y)

# x = np.linspace(-5,5,100)
# y = 2*x+1
# plt.plot(x, y, '-r', label='y=2x+1')

file2 = open("lines.txt")
segment = np.loadtxt(file2, delimiter=" ")
print(segment)
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
plt.legend(loc='upper right')

plt.grid()
plt.show()
 
