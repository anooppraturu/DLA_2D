# Diffusion Limited Aggregation in 2D
Some basic C code to simulate the formation of a diffusion limited aggregate in 2D with
periodic boundary conditions

## Parameters
dt: step size for random walk
L: the size of the simulation domain
eps: particle size
These 3 parameters can be modified in the defs.h file
The number of particles in the aggregate (N) can be modified by changing the length of the
loop in main.c

## Data
Simulation results are printed to a text file with the (x,y) coordinates of each point.
