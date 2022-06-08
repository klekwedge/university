from matplotlib import rcParams
import matplotlib.pyplot as plt
import numpy as np

x_1 = np.arange(-7, 7, 0.001)
x_2 = np.arange(-6.8, -2, 0.001)
x_3 = np.arange(2, 6.8, 0.001)
x_4 = np.arange(-5.8, -2.8, 0.001)
x_5 = np.arange(2.8, 5.8, 0.001)
x_6 = np.arange(-4, 4, 0.001)
x_7 = np.arange(-5.2, 5.2, 0.001)
x_8 = np.arange(-7, -2.8, 0.001)
x_9 = np.arange(2.8, 7, 0.001)
x_10 = np.arange(-7, 0, 0.001)
x_11 = np.arange(0, 7, 0.001)
x_12 = np.arange(-7, -4.5, 0.001)
x_13 = np.arange(4.5, 7, 0.001)
x_14 = np.arange(-3, 3, 0.001)

y_1=-3/49*(x_1**2)+8
y_2=4/49*(x_1**2)+1

y_3=-0.75*((x_2+4)**2)+11
y_4=-0.75*((x_3-4)**2)+11

y_5=-((x_4+4)**2)+9
y_6=-((x_5-4)**2)+9

y_7=4/9*(x_6**2)-5
y_8=4/9*(x_7**2)-9

y_9=-1/16*((x_8+3)**2)-6
y_10=-1/16*((x_9-3)**2)-6

y_11=1/9*((x_10+4)**2)-11
y_12=1/9*((x_11-4)**2)-11

y_13=-((x_12+5)**2)
y_14=-((x_13-5)**2)

y_15=2/9*(x_14**2)+2

plt.plot(x_1, y_1, color='b')
plt.plot(x_1, y_2, color='b')
plt.plot(x_2, y_3, color='b')
plt.plot(x_3, y_4, color='b')
plt.plot(x_4, y_5, color='b')
plt.plot(x_5, y_6, color='b')
plt.plot(x_6, y_7, color='b')
plt.plot(x_7, y_8, color='b')
plt.plot(x_8, y_9, color='b')
plt.plot(x_9, y_10, color='b')
plt.plot(x_10, y_11, color='b')
plt.plot(x_11, y_12, color='b')
plt.plot(x_12, y_13, color='b')
plt.plot(x_13, y_14, color='b')
plt.plot(x_14, y_15, color='b')


plt.xlabel('Аргумент')
plt.ylabel('Функция')
plt.title('2D График')

plt.show()