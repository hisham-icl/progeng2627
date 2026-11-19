#include <iostream>

int main(){
    int num,i, j = 0;
    std:: cin >> num;
    for (i=0; i < (num); i++){
        for(j=0;j<(num); j++){
            std:: cout << "*";
        }
        std::cout << std::endl;
    }
}