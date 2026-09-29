import numpy as np
import matplotlib.pyplot as plt

nx_values = [41, 81, 161, 321]

data = np.loadtxt("output/convection_nx321.csv", delimiter=",", skiprows=1)
plt.plot(data[:, 0], data[:, 1], "k--", label="Initial (t = 0)")

# Plot the final shape for each resolution
for nx in nx_values:
    data = np.loadtxt(f"output/convection_nx{nx}.csv", delimiter=",", skiprows=1)
    x = data[:, 0]
    u = data[:, 2]
    plt.plot(x, u, label=f"nx = {nx}")

plt.xlabel("x")
plt.ylabel("u")
plt.title("Grid refinement: linear convection")
plt.legend()

plt.savefig("images/grid_refinement.png", dpi=150)
plt.show()