#include <bits/stdc++.h>
#include <iostream>
#include <time.h>
#include <iomanip>

#define MAX 100

using namespace std;

int main()
{
    ///1
    vector<vector<double> > A(MAX, vector<double>(MAX));
    vector<double> x(MAX);
    vector<double> y(MAX);
    //double A[MAX][MAX], x[MAX], y[MAX];
    /**Initialize A and x, assign y = 0*/
    for(int i = 0; i < MAX; i++){
        for(int j = 0; j < MAX; j++){
            A[i][j] = 1;
        }
        x[i] = i;
        y[i] = 0;
    }
    clock_t inicio1, fin1;
    /**First pair of loops*/
    cout << "First pair of loops: " << endl;
    inicio1 = clock();
    for(int i = 0; i < MAX; i++){
        for(int j = 0; j < MAX; j++){
            y[i] += A[i][j]*x[j];
        }
    }
    fin1 = clock();
    double tiempo1 = double(fin1 - inicio1) / double(CLOCKS_PER_SEC);
    cout << fixed << setprecision(5) << tiempo1 << " segundos" << endl;

    for (int i = 0; i < MAX; i++){
        y[i] = 0;
    }

    /**Second pair of loops*/
    clock_t inicio2, fin2;
    cout << "Second pair of loops: " << endl;
    inicio2 = clock();
    for(int j = 0; j < MAX; j++){
        for(int i = 0; i < MAX; i++){
            y[i] += A[i][j]*x[j];
        }
    }
    fin2 = clock();
    double tiempo2 = double(fin2 - inicio2) / double(CLOCKS_PER_SEC);
    cout << tiempo2 << " segundos" << endl;

    cout << "------------------------------------------------------------------------------" << endl;

    ///2
    cout << "Multiplicación de matrices clasico: " << endl;
    vector<vector<int> > mat1(MAX,vector<int>(MAX));
    vector<vector<int> > mat2(MAX,vector<int>(MAX));
    vector<vector<int> > mat3(MAX,vector<int>(MAX));
    for(int i = 0; i < MAX; i++){
        for(int j = 0; j < MAX; j++){
            mat1[i][j] = i;
            mat2[i][j] = j;
        }
    }
    clock_t inicio3, fin3;
    inicio3 = clock();
    for(int i = 0; i < MAX; i++){
        for(int j = 0; j < MAX; j++){
            mat3[i][j] = 0;
            for(int h = 0; h < MAX; h++){
                mat3[i][j] += mat1[i][h]*mat2[h][j];
            }
        }
    }
    fin3 = clock();
    double tiempo3 = double(fin3 - inicio3) / double(CLOCKS_PER_SEC);
    cout << tiempo3 << " segundos" << endl;


    cout << "------------------------------------------------------------------------------" << endl;

    ///3
    vector<vector<int> > mar1(MAX,vector<int>(MAX));
    vector<vector<int> > mar2(MAX,vector<int>(MAX));
    vector<vector<int> > mar3(MAX,vector<int>(MAX));
    for(int i = 0; i < MAX; i++){
        for(int j = 0; j < MAX; j++){
            mar1[i][j] = 2*i;
            mar2[i][j] = 2*j;
            mar3[i][j] = 0;
        }
    }
    cout << "Multiplicación de matrices por bloques: " << endl;
    clock_t inicio4, fin4;
    inicio4 = clock();
    int block = 6;
    for(int i = 0; i < MAX; i += block){
        for(int j = 0; j < MAX; j += block){
            for(int h = 0; h < MAX; h += block){
                for(int i_ = i; i < min(i+block,MAX); i_++){
                    for(int j_ = j; j < min(j+block,MAX); j_++){
                        for(int h_ = h; h < min(h+block,MAX); h_++){
                            mar3[i_][j_] += mar1[i_][h_]*mar2[h_][j_];
                        }
                    }
                }
            }
        }
    }
    fin4 = clock();
    double tiempo4 = double(fin4 - inicio4) / double(CLOCKS_PER_SEC);
    cout << tiempo4 << " segundos" << endl;


    return 0;
}
