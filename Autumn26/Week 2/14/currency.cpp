#include <iostream>

int main(){
    int pounds;
    double rate,euros;

    std::cout << "How much GBP to exchange:" << std::endl;
    std:: cin >> pounds;

    std::cout << "What is the exchange rate to Euros (1 GBP = X Euros): " << std::endl;
    std:: cin >> rate;

    euros = pounds*rate;

    std::cout << "It is " << euros << " Euros" << std::endl;
}