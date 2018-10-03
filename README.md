# Neural Waves

This program simulates the propagation of electro-chemical waves down an axon that connects nerves together. A single axon is assumed to be very thin and long, and therefore one-dimensional.

More specifically, the simulation is of the *membrane potential u(x, t)* and the *recovery variable v(x, t)*, as functions 
of distance along the axon *x*, in the domain [*0*, *L*], and time *t*, in the domain [*0*, *t<sub>f</sub>*].

The following specification was used:

**Specification:**
The *x* grid has *N* grid points, including the end of the domain, *i.e.,* between *x<sub>0</sub>=0* to *x<sub>N-1</sub>=L*.

**Input:**
The input parameters must be read from a file called ‘input.txt’, which contain the parameters
  1. *L*, right *x* boundary of domain
  2. *N*, number of grid points
  3. *t<sub>f</sub>*, length of time to run for
  4. *t<sub>D</sub>*, timestep for diagnostic output
  5. *u<sub>0</sub>*, initial condition parameter
  6. *v<sub>0</sub>*, initial condition parameter
  7. *A*, boundary parameter (amplitude of ocsillation)
  8. *ω*, boundary parameter (frequency of oscillation)
  9. *α*, firing parameter
  10. *β*, relaxation parameter

The code outputs simulation data into a file called ‘output.txt’ at a fixed interval in time, *t<sub>D</sub>*.

The time, *t*, *x*-coordinate and the values of *u(x, t)* and *v(x, t)* are written in a single output line for each gridpoint, at each output time.

The program will compile with:

```
gcc q4.c -Wall -Werror -std=c99 -lm
```

To visualise the output, run the Matlab file, 'plotter.m'.


## Acknowledgments

* This program was for an academic assignment created by Prof. B. McMillan, Department of Physics, University of Warwick.
