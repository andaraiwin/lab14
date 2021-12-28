#include <iostream>
#include <cmath>
using namespace std;

const int N = 30;
const int M = 70;

void updateImage(bool [][M],int,int,int);

void showImage(const bool [][M]);

int main()
{
    bool image[N][M] = {};
    int s,x,y;
    do{
        showImage(image);
        cout << "Input your brush size and location: ";
        cin >> s >> x >> y;
        updateImage(image,s,x,y);
    }while(s != 0 || x != 0 || y != 0);
    return 0;
}

void showImage(const bool image[N][M]){
    cout << "------------------------------------------------------------------------";
    for(int i = 0; i < N; i++){
        cout << "\n" << '|';
        for(int j = 0 ;j < M; j++){
            if(image[i][j] == 0){
            cout << " ";
            }else if(image[i][j] == 1){
                cout << "*";
            }
        }
        cout << '|';
    }

    cout << "\n------------------------------------------------------------------------\n";
    return;
}

void updateImage(bool image[][M],int s,int x,int y){
    double C;
    for(int k = 0; k < N; k++){
        for(int l = 0; l < M; l++){
            C = sqrt(pow((k - x), 2) + pow((l - y), 2)) + 1;
            if(C <= s){
                image[k][l] = 1;
            }
        }
    }
    return;
}
