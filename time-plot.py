import numpy as np
import matplotlib.pyplot as plt
import matplotlib as mpl

 
# file = open("input.txt")
# data = np.loadtxt(file, delimiter=" ")
plt.title('Time analysis')
 
# x, y = data.T
# plt.scatter(x,y)

# x = np.linspace(-5,5,100)
# y = 2*x+1
# plt.plot(x, y, '-r', label='y=2x+1')


x_values = [6, 9,15, 50, 100, 200]
y_values = [0,1,1.1011,9.027,42.199,120.119]
plt.plot(x_values, y_values, '-r')


plt.scatter(x_values, y_values)


plt.xlabel('number of points', color='#1C2833')
plt.ylabel('time  (milli seconds)', color='#1C2833')
#plt.legend(loc='upper right')

plt.grid()
plt.show()
 



plt.title('Space analysis')
 
x_values = [6, 9,15, 50, 100,200]
y_values = [2.65,5.1912, 81,124.5,483,1885]
plt.plot(x_values, y_values, '-g')


plt.scatter(x_values, y_values)

plt.xlabel('number of points', color='#1C2833')
plt.ylabel('Space  (kilo bytes)', color='#1C2833')

plt.grid()
plt.show()

plt.title('Cost analysis')
 
x_values = [10, 100, 100000,8000000 ,10000000, 100000000]
y_values = [3,3,3,2,2,1]
plt.plot(x_values, y_values, '-y')


plt.scatter(x_values, y_values)

plt.xlabel('Cost for test 5', color='#1C2833')
plt.ylabel('Segments for test 5', color='#1C2833')

plt.grid()
plt.show()
 
