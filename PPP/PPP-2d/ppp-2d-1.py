from matplotlib import rcParams
import matplotlib.pyplot as plt
import numpy as np
x = np.arange(-7, 7, 0.0001)

y_1=2*np.sqrt(-abs(abs(x)-1)*abs(3-abs(x))/((abs(x)-1)*(3-abs(x))))*(1+abs(abs(x)-3)/(abs(x)-3))*np.sqrt(1-(x/7)**2)+(5+0.97*(abs(x-0.5)+abs(x+0.5))-3*(abs(x-0.75)+abs(x+0.75)))*(1+abs(1-abs(x))/(1-abs(x)))
y_2=(2.71052+(1.5-0.5*abs(x))-1.35526*np.sqrt(4-(abs(x)-1)**2))*np.sqrt(abs(abs(x)-1)/(abs(x)-1))+0.9
y_3=-3*np.sqrt(1-(x/7)**2)*np.sqrt(abs(abs(x)-4)/(abs(x)-4))
y_4=abs(x/2)-0.0913722*(x**2)-3+np.sqrt(1-(abs(abs(x)-2)-1)**2)
plt.plot(x, y_1, color='b')
plt.plot(x, y_2, color='b')
plt.plot(x, y_3, color='b')
plt.plot(x, y_4, color='b')
plt.xlabel('Аргумент')
plt.ylabel('Функция')
plt.title('2D График')

plt.show()