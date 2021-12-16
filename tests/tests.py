import os
import matplotlib.pyplot as plt
import numpy as np

input = []
with open('D:\projekty\DSP\signal\cos.txt') as f:
    input = f.readlines()

    signal = []
    for line in input:
        line = line.rstrip("\n")
        signal.append(float(line))

    plt.plot(signal)
    plt.show()