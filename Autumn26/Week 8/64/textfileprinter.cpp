#include <fstream>
#include <iostream>
#include <vector>
#include <string>



int main(int argc, char* argv[]){
    std::cout << argc <<std::endl;
    
    if (argc !=2){
        std::cout << "invalid number of arguments";
        return EXIT_FAILURE;
    }
    std::ifstream filereader;
    filereader.open(argv[1]);
    std::string item;
    while (filereader >> item){
        std::cout << item << " ";
    }
    filereader.close();
      
}