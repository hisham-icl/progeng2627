#include <iostream>
#include <cmath>

int main(){
    int weight;
    double height, bmi;

    std::cout << "What is your weight: " << std::endl;
    std:: cin >> weight;

    std::cout << "What is your height: " << std::endl;
    std:: cin >> height;

    bmi = weight *10/ (height*height);
    bmi = std::round(bmi)/10;

    std:: cout << "Your BMI is " << bmi << "." << std::endl;
}