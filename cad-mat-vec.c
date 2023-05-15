#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TIMES 6000

int main() {
    FILE *fp;
    // open file for writing
    fp = fopen("data_1.csv", "w");
    float t[6000];
    int tam[6000];
    int n = 28000;      // size of matrix A (n x n)
    int l = 0;

    while(n <= 60000) {
        float **A;             // matrix A
        A = (float **)malloc(n * sizeof(float *));
        for (int i = 0; i < n; i++) {
            A[i] = (float *)malloc(n * sizeof(float));
        }

        // initialize matrix A with some values
        srand(time(NULL));  // seed the random number generator with current time
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                float rand_num = (float)rand();  // generate random float between 0 and 1
                A[i][j] = rand_num;                // scale the random number by the factor
            }
        }

        // printf("A = \n");
        // for (int i = 0; i < m; i++) {
        //     for (int j = 0; j < n; j++) {
        //         printf("%.2f ", A[i][j]);
        //     }
        //     printf("\n");
        // }    
        
        float *x;              // vector x
        x = (float *)malloc(n * sizeof(float));
        // initialize vector x with some values

        float another_rand_num = (float)rand();
        for (int i = 0; i < n; i++) {
            x[i] = another_rand_num;
        }

        // // print vector x
        // printf("\nx = \n");
        // for (int i = 0; i < m; i++) {
        //     printf("%.2f\n", x[i]);
        // }

        clock_t start, end;    // variables to store CPU time
        double cpu_time_used;  // variable to store elapsed CPU time

        printf("\n\nPrestes a começar a operção com n = %d\n", n);

        start = clock();
        float *b;              // vector b
        b = (float *)malloc(n * sizeof(float));
        // perform matrix-vector multiplication: b = Ax
        for (int i = 0; i < n; i++) {
            b[i] = 0;
            for (int j = 0; j < n; j++) {
                b[i] += A[i][j] * x[j];
            }
        }
        end = clock();

        cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
        printf("\nTempo de operação Ax = b, com n = %d: %f segundos\n", n, cpu_time_used);

        tam[l] = n;
        t[l] = cpu_time_used;

        // // print vector b
        // printf("\n\nb = \n");
        // for (int i = 0; i < m; i++) {
        //     printf("%.2f\n", b[i]);
        // }

        // free memory allocated for matrix A, vector x, and vector b
        for (int i = 0; i < n; i++) {
            free(A[i]);
        }
        free(A);
        free(x);
        free(b);

        // write data to file in comma-separated format
        fprintf(fp, "%d,%f\n", tam[l], t[l]);
        printf("\nA essa altura ja escrevemos %d e %f no doc. \n", tam[l], t[l]);

        n += 2500;
        l++;
    }
    fclose(fp);
    return 0;
}
