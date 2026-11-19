#include <iostream>
#include <cmath>

int main(){
    int guess,low,high, level, state  =0;
    std::cout << "Enter the upper bound"<<std::endl;std::cin >> high; 
    std::cout << "Enter the lower bound"<<std::endl;std::cin  >> low;
    while (state == 0){
        guess = round((high + low)/2);
        std::cout << "My guess is ";std::cout <<  guess << std::endl;
        std::cout << "Enter 0 if the guess was wrong and 1 if it was correct" << std:: endl;
        std::cin >> state;
        if (state == 0){
            std::cout << "Enter 1 if my guess is higher or 0 if the guess was lower" << std::endl;
            std::cin >> level;
            if (level){
                high = guess;
            }
            else{
                low = guess;
            }
        }
    }
}