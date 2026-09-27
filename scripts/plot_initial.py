import numpy as np
import matplotlib.pyplot as plt

data = np.loadtxt("output/initial.csv",delimiter=",",skiprows=1)

x = data[:,0]
u = data[:,1]

plt.plot(x,u,marker="o")
plt.xlabel("x")
plt.ylabel("u")
plt.title("Hat function")

plt.savefig("images/intial_condition.png",dpi=150)
plt.show()



