#include<stdio.h>
#include<stdlib.h>

void setarray(double *p, int d);
void printmatrix(double *p[], int d);
void printarray(double *p, int d);
int main(int argc, char* argv[]){
	int dim = atoi(argv[1]);
	int i,j,k;
	double *A[dim];
	double x[dim];
	/*
	double a[4][4]={{1, -2, 1, -1},
					{1, 2, -1, 1},
					{2, -1, 3, -2},
					{-1, 3, -2, 3}};
	*/
	double *L[dim];
	double *U[dim];
	for(i=0;i<dim;i++){
		A[i]=(double *)malloc(sizeof(double)*dim);
		L[i]=(double *)malloc(sizeof(double)*dim);
		U[i]=(double *)malloc(sizeof(double)*dim);
	}
		/*
	for(i=0;i<dim;i++){
		for(j=0;j<dim;j++){
			A[i][j]=a[i][j];
		}
	}
	*/
	for(i=0;i<dim;i++){
		for(j=0;j<=i;j++){
			L[i][j]=1;
		}
	}
	double b[dim];
	//double b[]={4,-2,7,-5};
	printf("A\n");
	for(i=0;i<dim;i++){
		printf("Row %d\n", i);
		for(j=0;j<dim;j++){
			scanf("%lf", &A[i][j]);
		}
	}
	
	puts("\n");
	printf("b\n");
	for(i=0;i<dim;i++){
		scanf("%lf", &b[i]);
	}
	puts("A");
	printmatrix(A, dim);
	puts("b");
	printarray(b,dim);
	//LU bunkai
	for(i=0;i<dim;i++){
		for(j=0;j<dim;j++){
			if(i>j){
			L[i][j] = A[i][j];
				for(k=0;k<=j-1;k++){
					if(i>j){
						L[i][j]-=L[i][k]*U[k][j];
					}
				}
			L[i][j] /= U[j][j];
			}else{
				U[i][j] = A[i][j];
				for(k=0;k<=i-1;k++){
					U[i][j]-=L[i][k]*U[k][j];
				}
			}
		}
	}
	double c[dim];
	//solution
	for(i=0;i<dim;i++){
		c[i]=b[i];
		for(j=0;j<i;j++){
			c[i]-=L[i][j]*c[j];
		}
	}
	for(i=dim-1;i>=0;i--){
		x[i]=c[i];
		for(j=dim-1;j>i;j--){
			x[i]-=U[i][j]*x[j];
		}
		x[i]/=U[i][i];
	}
	
	puts("L");
	printmatrix(L, dim);
	puts("U");
	printmatrix(U, dim);
	puts("c");
	printarray(c,dim);
	puts("x");
	printarray(x,dim);
	for(i=0;i<dim;i++){
            free(A[i]);
            free(L[i]);
            free(U[i]);
	}
    }

	return 0;
}
void printmatrix(double *p[], int d){
	int i,j;
	for(i=0;i<d;i++){
		for(j=0;j<d;j++){
			printf("%.4f ", p[i][j]);
		}
		printf("\n");
	}
}

void printarray(double *p, int d){
	int i;
	for(i=0;i<d;i++){
		printf("%.4f ", p[i]);
	}
	printf("\n");
}
	
