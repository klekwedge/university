import matplotlib.pyplot as plt
import numpy as np
from math import *
from mpl_toolkits.mplot3d import Axes3D
from matplotlib import cm
xval = np.linspace(-2.5, 2.5, 300)
yval = np.linspace(-2.5, 2.5, 300)
x, y = np.meshgrid(xval, yval)
z = np.sin(x*x +y*y)/(abs(x*y)+1)
fig = plt.figure(figsize = (8, 8))
ax = fig.add_subplot(1, 1, 1, projection = '3d')
ax.set_xlabel('X')
ax.set_ylabel('Y')
ax.set_zlabel('Z')
ax.set_title('3D график')
surf = ax.plot_surface(x, y, z, rstride = 2,cstride = 2, cmap = cm.plasma)