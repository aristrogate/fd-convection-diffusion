import numpy as np
import matplotlib.pyplot as plt

# Load the solver output (skip the header row)
data = np.loadtxt("output/linear-convection.csv", delimiter=",", skiprows=1)

x = data[:, 0]
u_initial = data[:, 1]
u = data[:, 2]

# Initial condition dashed, final result solid
plt.plot(x, u_initial, marker="o", linestyle="--", label="Initial (t = 0)")
plt.plot(x, u, marker="o", label="After 25 time steps")

plt.xlabel("x")
plt.ylabel("u")
plt.title("1D linear convection: initial vs. after 25 steps")
plt.legend()

plt.savefig("images/linear-convection.png", dpi=150)
plt.show()