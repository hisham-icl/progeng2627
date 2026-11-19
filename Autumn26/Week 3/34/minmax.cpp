#include <iostream>

int main(){
    int entry,max,min = 1;
    std::cin >> entry;
    min = entry; max = entry;
    while (entry != 0){ 
        if (entry > max){
            max = entry;
        }
        if (entry < min){
            min = entry;
        }
        std::cout << "Max: "; std::cout << max << std::endl;
        std:: cout<< "Min: "; std::cout << min << std::endl;
        std::cin >> entry;
    }
}