#include <iostream>

int main(){
    int max = 0;
    int entry = 1;
    while (entry != 0){
        std::cin >> entry;
        if (entry > max){
            max = entry;
        }
        std::cout << "Max: "; std::cout << max << std::endl;
    }
}