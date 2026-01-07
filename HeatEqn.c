#include <stdio.h>
#include <math.h>
#include <stdlib.h>

// 1. The Exact Solution (To compare against)
// u(x,t) = e^(-pi^2 * t) * sin(pi * x)
double exact_solution(double x, double t) {
    return exp(-pow(M_PI, 2) * t) * sin(M_PI * x);
}

int main() {
    double L = 1.0;          // Length of the rod
    double T_final = 0.1;    // Final time to stop simulation
    double alpha = 1.0;      // Thermal diffusivity

    printf("   M   |  Max Error (L_inf) |  Order  \n");
    printf("-------|--------------------|---------\n");

    double prev_error = 0.0;

    // 2. The Loop: Double the Grid Points (M) each time like the table (8, 16, 32...)
    for (int M = 10; M <= 160; M *= 2) {
        
        double dx = L / M;           // Space step
        double dt = 0.5 * dx * dx;   // Time step (Stability condition: dt <= 0.5*dx^2)
        int time_steps = T_final / dt;

        // Allocate memory for Temperature arrays
        double *u = (double *)malloc((M + 1) * sizeof(double));
        double *u_new = (double *)malloc((M + 1) * sizeof(double));

        // Initialize with sin(pi * x) at t=0
        for (int i = 0; i <= M; i++) {
            u[i] = sin(M_PI * (i * dx));
        }

        // 3. FDM Solver (Explicit Scheme)
        for (int t = 0; t < time_steps; t++) {
            for (int i = 1; i < M; i++) {
                u_new[i] = u[i] + (dt / (dx * dx)) * (u[i+1] - 2*u[i] + u[i-1]);
            }
            // Update array
            for (int i = 1; i < M; i++) u[i] = u_new[i];
        }

        // 4. Calculate Max Error (L_infinity Norm)
        double max_error = 0.0;
        for (int i = 0; i <= M; i++) {
            double exact = exact_solution(i * dx, T_final);
            double error = fabs(u[i] - exact);
            if (error > max_error) max_error = error;
        }

        // 5. Calculate Order of Convergence
        // Order = log2(PrevError / CurrentError)
        double order = 0.0;
        if (prev_error != 0.0) {
            order = log2(prev_error / max_error);
        }

        // 6. Print the Row (Just like Prof. Natesan's Table)
        if (M == 10) {
             printf("  %3d  |  %1.4e  |    -    \n", M, max_error);
        } else {
             printf("  %3d  |  %1.4e  |  %.4f  \n", M, max_error, order);
        }

        prev_error = max_error;
        free(u);
        free(u_new);
    }

    return 0;
}