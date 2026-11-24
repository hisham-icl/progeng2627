#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

// for std::pair
#include <utility>

std::string char_to_string(char c){
    std::string s;
    s.push_back(c);
    return s;
}
bool is_palindrome(std::string s){
    for (int i = (int)s.size() - 1; i >= 0; i--) {
        if (s[i] == ' ')
            s.erase(i, 1);
    }
    if (s.empty()){
        return false;
    }
    std::string s1;
    std::string s2;
    if (s.size() % 2 == 0){
        s1 = s.substr(0,s.size()/2);
        s2 = s.substr(s.size()/2,s.size()/2);
    }
    else{
        s1 = s.substr(0,s.size()/2);
        s2 = s.substr(s.size()/2+1,s.size()/2);
    }
    std::string s2rev = s2;
    std::reverse(s2rev.begin(), s2rev.end());   
    if (s2rev == s1){
        return true;
    }
    return false;
}

int main(){

    std::vector<std::pair<std::string, bool>> test_cases = 
    {
        {"a man a plan a canal panama", true}, 
        {"a man plan a canal panama", false},
        {"a toyota", true},
        {"never odd or even", true},
        {"never even or odd", false}
    };

    for(int i = 0; i < test_cases.size(); i++){
        // each variable of type std::pair has two fields called first and second

        bool test = is_palindrome(test_cases[i].first);

        if(test == test_cases[i].second){
            std::cout << "passed" << std::endl;
        }
        else{
            std::cout << "FAILED" << std::endl;
            std::cout << test_cases[i].first << std::endl;
            std::cout << "expected: " << test_cases[i].second << std::endl;
            std::cout << "got: " << test << std::endl;
        }
    }
}