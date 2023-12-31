#include <iostream>

int main(){
    int a[2][2];
    int** b = new int*[2];
    for(int i = 0; i < 2; i++){
        b[i] = new int [2];
    }
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 2; j++){
            a[i][j] = i * j;
            b[i][j] = i * j;
        }
    }
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 2; j++){
            std::cout << b[i][j] << " ";
        }
        std::cout << std::endl;
    }

    
    return 0;
}
