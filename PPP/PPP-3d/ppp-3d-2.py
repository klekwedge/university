import matplotlib.pyplot as plt
import numpy as np
from math import *
from mpl_toolkits.mplot3d import Axes3D
from matplotlib import cm
xval = np.linspace(-10, 10, 100).astype(int)
yval = np.linspace(-10, 10, 100).astype(int)
x, y = np.meshgrid(xval, yval)
z = np.sqrt(x*x+y*y)+3*np.cos(np.sqrt(x*x+y*y))+5
xval = np.linspace(-10, 10, 100).astype(int)
yval = np.linspace(-10, 10, 100).astype(int)
x, y = np.meshgrid(xval, yval)
z = 0.1*(np.cos(0.8*x)**2-np.sin(0.8*y)**2)
fig = plt.figure(figsize = (8, 8))
ax = fig.add_subplot(1, 1, 1, projection = '3d')
ax.set_xlabel('X')
ax.set_ylabel('Y')
ax.set_zlabel('Z')
ax.set_title('3D график')
surf = ax.plot_surface(x, y, z, rstride = 2,cstride = 2, cmap = cm.viridis)
