#include <iostream>

int main() {
    int celcius;
    double fahrenheit;

    std::cout << "Enter your temperature in degrees Celcius: " << std::endl;
    std:: cin >> celcius;

    fahrenheit = (celcius*1.8)+32;

    std::cout << "It is " << fahrenheit << " degrees Fahrenheit" << std::endl;
}