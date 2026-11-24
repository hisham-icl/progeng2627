#include <iostream>
#include <map>
#include <fstream>
#include <vector>
#include <string>

std::map <std::string, int> countocc(const std::vector <std::string> &wordlist,const std::vector <std::string> &headers){
    std::map <std::string, int> dict = {};
    for (std::string item: headers){
        dict[item] = 0;
    }
    for (std::string word: wordlist){
        for (std::string item: headers){
            if (item == word){
                dict[item] = dict[item]+1;
            }
        }
    }
    return dict;

}

int main(){
    std::vector <std::string> wordlist;
    std::vector <std::string> headers;

    std::ifstream wordreader;
    wordreader.open("words.txt");
    std::ifstream textreader;
    textreader.open("text.txt");
    std::ofstream outfile;
    outfile.open("output.txt");
    if (!textreader.is_open() or !wordreader.is_open() or !outfile.is_open()){
        std::cout << "error opening files" << std::endl;
        return EXIT_FAILURE;
    }

    std::string tmp;

    while (wordreader >> tmp) {
        headers.push_back(tmp);
    }
    while (textreader >> tmp) {
        wordlist.push_back(tmp);
    }
    std::map <std::string, int> dict = countocc(wordlist,headers);
    for (std::string item : headers){
        outfile << item << ": " << dict[item] <<std::endl;
    }
}