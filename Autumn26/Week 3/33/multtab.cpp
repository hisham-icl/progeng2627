#include <iostream>

int main(){
    int num, i, j, var = 0;
    std::cin >> num;
    for (i = 1; i <= num; i++ ){
        for (j=1;j<=num;j++){
            var = i*j;
            std::cout << var;
            std::cout << "  ";
        }
        std::cout << std::endl;
    }
}