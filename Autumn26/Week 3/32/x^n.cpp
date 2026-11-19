#include <iostream>

int main(){
    int n,i = 0;
    int var,num = 1;
    std:: cin >> n;
    std:: cin >> num;
    var = num;
    for (i = 0; i < (n-1); i++){
        num = num * var;
    };
    std::cout << num << std::endl;
}
