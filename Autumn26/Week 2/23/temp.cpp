#include <iostream>

int main(){
    double temp_in,temp_out;
    bool flag;
    std::string unit_in, unit_out;

    std::cout << "What temperature unit in: " << std::endl;
    std::cin >> unit_in;

    std::cout << "What temperature: " << std::endl;
    std::cin >> temp_in;

    if (unit_in == "C"||unit_in == "c"){
        unit_out = "F";
        temp_out = (temp_in*1.8)+32;
        flag = true;
    }
    else if(unit_in =="F"||unit_in=="f"){
        unit_out = "C";
        temp_out = (temp_in-32)/1.8;
        flag = true;
    }
    if (not flag){
        std::cout << "Not a valid unit.";
    }
    else{
        std::cout << "The temperature is equal to " << temp_out << " " << unit_out << "." << std::endl;
    }
}