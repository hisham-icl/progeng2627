#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <string> 
#include <algorithm>
void generate_intersection(const std::vector <std::string> &hold1,const std::vector <std::string> &hold2, std::vector <std::string> intersectioncheck, std::ofstream& intersectionfile){
        for(std::string item : hold1){
            for (std::string item2 : hold2){
                if ((item == item2) && (std::find(intersectioncheck.begin(),intersectioncheck.end(),item2)==intersectioncheck.end())){
                    intersectionfile << item;
                    intersectionfile << std::endl;
                    intersectioncheck.push_back(item);
                }
            }
        }
}

void generate_union(const std::vector <std::string> &hold1,const std::vector <std::string> &hold2, std::vector <std::string> unioncheck, std::ofstream& unionfile){
    std::vector <std::string> fullhold;
    std::copy(hold1.begin(),hold1.end(),std::back_inserter(fullhold));
    std::copy(hold2.begin(),hold2.end(),std::back_inserter(fullhold));
    for (std::string item : fullhold){
        if (std::find(unioncheck.begin(),unioncheck.end(),item) == unioncheck.end()){
            unionfile << item;
            unionfile << std::endl;
            unioncheck.push_back(item);

        }
    }
}

int main(){
    std::ifstream onefile;
    std::ifstream twofile;
    onefile.open("warehouse1.txt");
    twofile.open("warehouse2.txt");
    std::ofstream unionfile;
    std::ofstream intersectionfile;

    unionfile.open("union.txt");
    intersectionfile.open("intersection.txt");
    std::vector <std::string> hold1;
    std::vector <std::string> hold2;
    std::vector <std::string> intersectioncheck;
    std::vector <std::string> unioncheck;
    std::string tmp;

    while(onefile >> tmp)
        hold1.push_back(tmp);
    while(twofile >> tmp)
        hold2.push_back(tmp);
    
    generate_intersection(hold1,hold2,intersectioncheck,intersectionfile);
    generate_union(hold1,hold2,unioncheck,unionfile);

    intersectionfile.close();
    unionfile.close();
    onefile.close();
    twofile.close();

}