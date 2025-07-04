#include<iostream>
#include"bits/stdc++.h"
using namespace std;

void inicializarA(vector<vector<double>> &A);
bool choleskyGaxpy(vector<vector<double>> &A);
void printaA(vector<vector<double>> &A);
int n = 20;

int main()
{
    vector<vector<double>> A(n,vector<double>(n,0.0));
    inicializarA(A);
    
    if(choleskyGaxpy(A)) {
        cout<< "A é simetrica definida positiva." << "\n\n\n";
        printaA(A);
    }
    
    return 0;
}

void inicializarA(vector<vector<double>> &A)
{
    for(int i = 0; i < n; i++) {

        int j = i;
        A[i][j] = 0.0;
        double cont = 1.0;
        for(int j = i-1; j >= 0; j--) {
            A[i][j] = cont;
            cont++;
        }
        cont = 1.0;
        for(int j =i+1; j < n; j++) {
            A[i][j] = cont;
            cont++;
        }
    }
}


bool choleskyGaxpy(vector<vector<double>> &A)
{
    

    for(int j = 0; j < n; j++) { //for j =1:n
        
        //A(j:n, j) = A(j:n, j) - A(j:n, 1:j-1) * A(j, 1:j-1)ᵀ
        for(int i = j; i <n; i++) {

            double soma = 0.0;

            for(int k = 0; k < j; k++) {
                soma = soma + A[i][k]*A[j][k];
            }

            A[i][j] = A[i][j] - soma;
        }
        

            if(A[j][j] <= 0) {
                cout <<"A matriz não é definida positiva." << endl;
                printaA(A);
                return false;
            }

            double diagonal_val = sqrt(A[j][j]);
            for(int i = j; i < n; i++) {
                A[i][j] = A[i][j]/diagonal_val;
            }
                
    }

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            A[i][j] = 0.0;
        }
    }


    return true;
     
}

void printaA(vector<vector<double>> &A) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << "|" << A[i][j] << "|"<< " ";
        }
        cout << "\n";
    }
}
