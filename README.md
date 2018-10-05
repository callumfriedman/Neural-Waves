# Neural Waves

This program simulates the propagation of electro-chemical waves down an axon that connects nerves together.

## Getting Started
To run this program, you must set up a C development environment on your machine. There are two main ways to do this:
1. Using an IDE (Integrated Development Environment), see https://fresh2refresh.com/c-programming/c-environment-setup/
2. Using a GCC compiler, see https://fresh2refresh.com/c-programming/c-environment-setup-using-gcc/

I personally prefer using the GCC method, but it is entirely up to you!

Once you have a C development environment, simply download the files from this repository.

### Prerequisites
* MATLAB; to visualise the output data over time

## Running the program

You can run the program by loading the file 'q4.c' in your IDE, and then clicking 'Compile and Run'.

Alternatively you can compile it in a GCC compiler using the command

```
gcc q4.c -Wall -Werror -std=c99 -lm
```

Then, export the output data to a .csv file using the command

```
./a.out>output.csv
```

Finally, using MATLAB, you can visualise the output data by running the file 'plotter.m'.

## How does it work?

A single axon is assumed to be very thin and long, and therefore one-dimensional. Specifically, the simulation is of the *membrane potential u(x, t)* and the *recovery variable v(x, t)*, as functions of distance along the axon *x*, in the domain [0, *L*], and time *t*, in the domain [0, *t<sub>f</sub>*]. A centred finite difference scheme is used to solve the following equations:

![](http://latex.codecogs.com/gif.latex?%5Cfrac%7B%5Cpartial%20v%7D%7B%5Cpartial%20t%7D%20%3D%20%5Cfrac%7B%5Cpartial%5E2%20v%7D%7B%5Cpartial%20x%5E2%7D&plus;f%28v%29-u)

![](http://latex.codecogs.com/gif.latex?%5Cfrac%7B%5Cpartial%20u%7D%7B%5Cpartial%20t%7D%3D%5Cbeta%20v)

where ![](http://latex.codecogs.com/gif.latex?f%28v%29%3Dv%28%5Calpha%20-v%29%28v-1%29)

The boundary conditions are 

![](http://latex.codecogs.com/gif.latex?v%280%2Ct%29%3DAsin%28%5Comega%20t%29&plus;v_0) 

and 

![](http://latex.codecogs.com/gif.latex?%5Cfrac%7B%5Cpartial%20v%7D%7B%5Cpartial%20x%7D%5Cbiggr%5Crvert_%7BX%3DL%7D%3D0) 

(for all *t*).

The program was written with reference to the following specification:

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

The code outputs simulation data into a file called ‘output.txt’ for every fixed interval in time, *t<sub>D</sub>*.

The time, *t*, *x*-coordinate and the values of *u(x, t)* and *v(x, t)* are written in a single output line for each gridpoint, at each output time.

## Acknowledgments
This program was for an academic assignment created by Prof. B. McMillan, Department of Physics, University of Warwick.
