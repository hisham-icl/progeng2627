#include <iostream>
#include <cmath>

int main(){
    int i,num = 0;
    int power, sum = 0;
    std::cin >> num;
    std::cin >> power;
    for (i=1;i<=power;i++){
        sum = sum + (std::pow(num,i));
    }
    std::cout << sum;
}