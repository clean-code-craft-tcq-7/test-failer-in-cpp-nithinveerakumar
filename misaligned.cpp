#include <iostream>
#include <assert.h>
#include <sstream>
#include <map>
#include<cstring>
using namespace std;
const char* majorColor[] = {"White", "Red", "Black", "Yellow", "Violet"};
const char* minorColor[] = {"Blue", "Orange", "Green", "Brown", "Slate"};

map <int,string> printColorMap() {
    map <int,string> colorMap;
    int i = 0, j = 0;
    for(i = 0; i < 5; i++) {
        for(j = 0; j < 5; j++) {
            std::ostringstream oss;
            std::cout << i * 5 + j + 1 << " | " << majorColor[i] << " | " << minorColor[i] << "\n";
            oss<< i * 5 + j + 1 << " | " << majorColor[i] << " | " << minorColor[i] << "\n";
            cout<<oss.str();
            colorMap.insert(pair<int,string>(i*5+j+1,oss.str()));
        }
    }
    return colorMap;
}

int main() {
    map <int,string> result = printColorMap();
    assert(result.size() == 25);
    int pairNumber=1; 
    //test for pairNumber 1
    assert(strcmp(result[pairNumber].c_str(),"1 | White | Blue\n")==0);
    //test for pairNumber 2
    pairNumber=2;
    assert(strcmp(result[pairNumber].c_str(),"2 | White | Orange\n")==0);
    //test for pairNumber 12
    pairNumber=12;
    assert(strcmp(result[pairNumber].c_str(),"12 | Black | Orange\n")==0);
    std::cout << "All is well (maybe!)\n";
    return 0;
}