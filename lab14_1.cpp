#include <iostream>
#include <cmath>
using namespace std;

void stat(const double[],int,double[]);

void ArithmeticMean(double A[], int N, double B[]);
int main(){
    double A[] = {1.2,3.5,6.9,7.8,12.5,0.5};
    int N = sizeof(A)/sizeof(A[0]);
    double B[6];
    stat(A,N,B);
    cout << "Arithmetic Mean = " << B[0];
    cout << "\nStandard Deviation = " << B[1];
    cout << "\nGeometric Mean = " << B[2];
    cout << "\nHarmonic Mean = " << B[3];
    cout << "\nMax = " << B[4];
    cout << "\nMin = " << B[5];
    return 0;
}

void stat(const double A[], int N,double B[] ){
    //ArithmeticMean
    double sum = 0;
    for(int j = 0; j < N; j++){
        sum += A[j];
    }
    B[0] = sum/N;

    //Harmonic Mean
    double HM_Sum = 0, HM;
    for(int b = 0;b < N; b++){
        HM_Sum += pow(A[b], -1);
    }
    B[3] = N/HM_Sum;
    

    //SD
    double SD_Sum = 0, SD;
    for(int k = 0; k < N; k++){
        SD_Sum += pow(A[k], 2);
    }
    SD = sqrt(((1.0/N)*SD_Sum) - pow(B[0], 2));
    B[1] = SD;

    
    //Geometric Mean   
    double GM_Sum = 1, GM;
    for(int a = 0; a < N; a++){
        GM_Sum *= A[a];
    }
    GM = pow(GM_Sum, 1.0/N);
    B[2] = GM;

    //Max Min
    double Max = A[0], Min = A[0];
    for(int i = 1; i < N; i++){
        if(A[i] > Max) Max = A[i];
        if(A[i] < Min) Min = A[i];
        B[4] = Max;
        B[5] = Min;
    }

    return;
}
