from mpl_toolkits.mplot3d import Axes3D
import matplotlib.pyplot as plt
from matplotlib import cm
import numpy as np
from math import *
import pandas as pd
from PIL import Image

arr_frames = []
for frame_number in range(1, 10,1):
    frame = Image.open('frames/'+str(frame_number)+'.png')
    arr_frames.append(frame)
arr_frames[0].save(
    'animation.gif',
    save_all=True,
    append_images=arr_frames[1:],
    optimize=True,
    duration=100,
    loop=0
)