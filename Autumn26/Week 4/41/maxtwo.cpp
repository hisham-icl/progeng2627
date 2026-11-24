#include <iostream>

double maxtwo(double first, double second){
    return first > second ? first:second;
}

int main(){
    int test1, test2;
    std::cin >> test1;
    std::cin >> test2;
    std::cout << maxtwo(test1,test2)<< std::endl;
}