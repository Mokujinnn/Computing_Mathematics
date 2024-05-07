import pandas
import matplotlib.pyplot as plt

data1 = pandas.read_csv("./build/file.txt")

plt.plot(data1['i'], data1['n'], '-', label='v1')

# plt.plot(range(2,9),range(2,9),'-',c="blue",linewidth=0.5,label="Linear speedup")
plt.xlabel('День')
plt.ylabel('Выявленно')
plt.legend()
plt.grid(True)

plt.savefig("graphic.png", dpi=300)