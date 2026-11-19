#include <iostream>
#include <vector>

// we can define a function that returns a bool

bool leap_year(int year){
    bool ly;

    // TODO: check whether the year is a leap year or not
    // store result in variable ly
    if ((year%4 == 0)&& ((year%100 != 0) || (year%400 == 0))){
        ly = true;
    }
    else {
        ly = false;
    }

    return ly;
    // we *do not print* anything in the function
}

int main(){
    std::vector <int> years = {2001, 2003, 2012, 2024, 1900, 2100, 2200, 2000, 2400, 1600, 4, 100};


    // a function returning a bool 
    // can be used directly in the condition
    // of an if statement 
    for (int input_year : years) {
        if(leap_year(input_year)){
            std::cout << input_year << " is a leap year" << std::endl;
        }
        else{
            std::cout << input_year << " is not a leap year" << std::endl;
        }
    }
    
}