#include <iostream>
using namespace std;



int main() {
    int N1, M1 , N2 , M2;
    cin >> N1 >> M1 >> N2 >> M2;
    int matrix1[N1][M1], matrix2[N2][M2], matrix3[N1][M2];
    for(int i = 0 ; i < N1 ; i++){
        for(int j = 0 ; j < M1 ; j++){
            cin >> matrix1[i][j];
        }
    }
    for(int i = 0 ; i < N2 ; i++){
        for(int j = 0 ; j < M2 ; j++){
            cin >> matrix2[i][j];
        }
    }
    for(int i = 0 ; i < N1 ; i++){
        for(int j = 0 ; j < M2 ; j++){
            int sum = 0;
            for(int k = 0 ; k < M1 ; k++){
                sum += matrix1[i][k] * matrix2[k][j];
            }
            matrix3[i][j] = sum;
        }
    }
    for(int i = 0 ; i < N1 ; i++){
        for(int j = 0 ; j < M2 ; j++){
            
            cout << matrix3[i][j] << " ";
        }
        cout << endl;
    }
   
    return 0;
}