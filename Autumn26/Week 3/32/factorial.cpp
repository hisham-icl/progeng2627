#include <iostream>

int main(){
    int num,i = 0;
    int sum = 1;
    std::cin >> num;

    for (i = 1; i <(num+1); i++){
        sum = sum * i;
    }
    std::cout << sum << std::endl;
}