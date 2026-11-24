#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <string>
#include <ranges>

std::map <std::string,std::string> makewordbank(std::ifstream& bankreader){
    std::string tmp1;
    std::string tmp;
    std::map <std::string,std::string> dict;
    while (bankreader >> tmp){
        bankreader >> tmp1;
        dict[tmp] = tmp1;
    }
    return dict;
}
void makeoutputfile(std::ofstream &outwriter, std::map <std::string,std::string>& wordbank, std::vector <std::string> &textvec){
    for (auto &item : textvec){
        for (std::string item2 : wordbank | std::views::keys){
            if (item == item2){
                item = wordbank[item2];
            }
        }
    }
    for(auto item: textvec){
        outwriter << item << " ";
    }
}
std::vector <std::string> makevector_string(std::ifstream& infile){
    std::vector <std::string> v;
    std::string tmp;
    while (infile >> tmp){
        v.push_back(tmp);
    }
    return v;
} 
int main(){
    std::ifstream bankreader;
    bankreader.open("wordbank.txt");
    std::ifstream textreader;
    textreader.open("faketext.txt");
    std::ofstream outwriter;
    outwriter.open("realmeaning.txt");
    if (!bankreader.is_open() or !textreader.is_open()){
        std::cout << "error opening files";
        return EXIT_FAILURE;
    }
    std::map <std::string,std::string> wordbank = makewordbank(bankreader);
    std::vector <std::string> textvec = makevector_string(textreader);
    makeoutputfile(outwriter,wordbank,textvec);
}
