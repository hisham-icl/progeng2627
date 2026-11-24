#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

int main(){
    std::vector<int> bsearch = {};
    int in = 1;
    while (in != 0){
        std::cin >> in;
        bsearch.push_back(in);
    }
    bsearch.pop_back();
    for (int x : bsearch)
        std::cout << x << " ";
    std::cout << std::endl;
    std::sort(bsearch.begin(), bsearch.end());
    for (int x : bsearch)
        std::cout << x << " ";
    std::cout << std::endl;
    int target,ptr,high,low;
    high = bsearch.size()-1;
    low = 0;
    std::cin >> target;
    ptr = round(bsearch.size()/2);
    while (bsearch[ptr] != target){
        if (bsearch[ptr] > target){
            high = ptr;
        }
        else {
            low = ptr;
        }
        ptr = round((high +low)/2);
    }
    std::cout << ptr << std::endl;

}
