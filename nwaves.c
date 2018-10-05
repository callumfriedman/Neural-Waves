#include <stdio.h>
#include <math.h>
#include <stdlib.h>

//Iterate the void functions to avoid errors describing implicit function declaration (invalid in c99)
void read_input_data(double *L, int *N, double *tf, double *tD, double *u0, double *v0, double *A, double *omega, double *alpha, double *beta);

int main() {

	FILE * output;
	output = fopen("output.txt", "w");

	// First define pointers for all of the variables, to pass them to the input function

	double 	L; 		double 	*pL 		= &L;		// right x boundary of domain
	int 	N; 		int 	*pN 		= &N;		// number of grid points
	double 	tf; 	double 	*ptf 		= &tf;		// length of time to run for
	double 	tD; 	double 	*ptD 		= &tD;		// timestep for diagnostic output
	double 	u0; 	double 	*pu0 		= &u0;		// initial condition parameter
	double 	v0; 	double 	*pv0 		= &v0;		// initial condition parameter
	double 	A; 		double 	*pA 		= &A;		// boundary parameter (amplitude of ocsillation) 
	double 	omega; 	double 	*pomega 	= &omega;	// boundary parameter (frequency of oscillation) 
	double 	alpha; 	double 	*palpha 	= &alpha;	// firing parameter
	double 	beta; 	double 	*pbeta 		= &beta;	// relaxation parameter

	//Read in from file
	read_input_data(pL, pN, ptf, ptD, pu0, pv0, pA, pomega, palpha, pbeta);
	// Then set the grid spacing that will be used in the finite difference method of solving the PDEs
	double dx = L/(N-1);
	// Set the small timestep for the finite difference method
	double dt = 0.001*dx; // where dt is less than 2/k, where k is a constant as stated in workshop.

    // Setting up grid storage
    double *v, *v_next;  //v at current and next timestep
    double *u, *u_next;  //u at current and next timestep.

    // Allocate memory according to size of N
    v       = malloc(N*sizeof(double));
    u       = malloc(N*sizeof(double));
    v_next  = malloc(N*sizeof(double));
    u_next  = malloc(N*sizeof(double));

    int j;
    double x;

    //****************
    // INITIALISATION
    //****************

    //Given by the initial conditions in the specification
    for(j=0;j<N;j++) {
        v[j]=v0;
        u[j]=u0;
    }
    
    double next_output_time = tD;
    double ctime = 0.0;
    double d2vdx2;
    int jp, jm;

	for (j=0;j<N;j++) {			// We don't output the last value as it is erroneous due to using the centered finite difference scheme
        x = j*dx;
        printf("%lf %lf %lf %lf \n",ctime,x,u[j],v[j]);
        fprintf(output,"%lf %lf %lf %lf \n",ctime,x,u[j],v[j]);
    }

    //Loop over timesteps
    while (ctime<tf) {
    	
    	// Firstly for j=0
    	jp=1; //Due to Neumann boundary conditions
		
		v[0]=A*sin(omega*ctime)+v0;
		//d2vdx2 = (v[jp]-(2*v[0]))/(dx*dx);

        u_next[0] = u[0] + dt*beta*v[0];
        u[0] = u_next[0];

        for (j=1;j<(N-1);j++) { 					//for j=1 -> N-2
        	jp = j+1; jm = j-1;

            d2vdx2 = (v[jp]+v[jm]-(2*v[j]))/(dx*dx);
            v_next[j] = v[j] + dt*((d2vdx2)+(v[j]*(alpha-v[j])*(v[j]-1))-u[j]);
        	u_next[j] = u[j] + dt*beta*v[j];

        	v[j] = v_next[j];
        	u[j] = u_next[j];

        }

        // for j=nx-1
        jm = N-2;
        
        d2vdx2 = (v[jm]-(v[j]))/(dx*dx); //Due to Neumann boundary condition
        v_next[N-1] = v[N-1] + dt*((d2vdx2)+(v[N-1]*(alpha-v[N-1])*(v[N-1]-1))-u[N-1]);
        u_next[N-1] = u[N-1] + dt*beta*v[N-1];

        v[N-1] = v_next[N-1];
        u[N-1] = u_next[N-1];


        // Output the results MUST WRITE AND OUTPUT TO TXT FILE
        if (ctime>next_output_time) {
            for (j=0;j<N;j++) {			// We don't output the last value as it is erroneous due to using the centered finite difference scheme
                x = j*dx;
                printf("%lf %lf %lf %lf \n",ctime,x,u[j],v[j]);
                fprintf(output,"%lf %lf %lf %lf \n",ctime,x,u[j],v[j]);
            }
            next_output_time += tD;
        }
    	ctime+=dt;
    }
   
    // Free the heap memory that was occupied by the following variables
	free(v); free(u); free(v_next); free(u_next);
}

// Function to read the values for each of the parameters in input.txt
void read_input_data(double *L, int *N, double *tf, double *tD, double *u0, double *v0, double *A, double *omega, double *alpha, double *beta) {
   FILE *input;
   if(!(input=fopen("input.txt","r"))) {
       printf("Error opening input parameters file\n");
       exit(1);
   }
   if(10!=fscanf(input,"%lf %i %lf %lf %lf %lf %lf %lf %lf %lf",L,N,tf,tD,u0,v0,A,omega,alpha,beta)) {
       printf("Error reading parameters from file\n");
       exit(1);
   }
   fclose(input);
}
