#include <vector>
#include<iostream>

void merge_vectors_int(const std::vector<int>& v1, const std::vector<int>& v2, std::vector<int>& merged){
    int i,j = 0;
    bool flag = false;
    while (!flag){
        if (i == v1.size() or j == v2.size()){
            flag = true;
        }
        else if (v1[i] < v2[j]){
            merged.push_back(v1[i]);
            i++;
            std::cout << "hey" << std::endl;
        }
        else if (v2[j] < v1[i]){
            merged.push_back(v2[j]);
            j++;
            std::cout << "hi" << std::endl;

        }
        else if (v2[j] == v1[i]){
            merged.push_back(v2[j]);
            merged.push_back(v1[i]);
            i++;
            j++;
            std::cout << "bye" << std::endl;
        }
    }
    if(i < v1.size()){
        for (i; i < v1.size();i++){
            merged.push_back(v1[i]);
        }
    }
    else if (j < v2.size()){
        for (j; j<v2.size();j++){
            merged.push_back(v2[j]);
        }
    }
}

int main(){

    std::vector<int> v1;
    std::vector<int> v2;
    std::vector<int> out;

    std::vector<int> expected_output;

    v1 = {1, 3, 5, 6};
    v2 = {4, 6, 10};
    expected_output = {1, 3, 4, 5, 6, 6, 10};

    merge_vectors_int(v1, v2, out);

    if(out == expected_output){ // we can compare the content of vectors (at least in some cases)
        std::cout << "passed" << std::endl;
    }
    else{
        std::cout << "not passed" << std::endl;
    }
    for (int item : out){
        std::cout << item << " " << std::endl;
    }
}