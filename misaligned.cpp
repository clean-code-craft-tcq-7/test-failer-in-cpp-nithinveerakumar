#include <iostream>
#include <assert.h>
#include <map>
using namespace std;
const char* majorColor[] = {"White", "Red", "Black", "Yellow", "Violet"};
const char* minorColor[] = {"Blue", "Orange", "Green", "Brown", "Slate"};

struct ColorPair
{
    const char* majorColor;
    const char* minorColor;
};

map <int,ColorPair> printColorMap() {
    ColorPair colorPair;
    map <int,ColorPair> colorMap;
    int i = 0, j = 0;
    for(i = 0; i < 5; i++) {
        for(j = 0; j < 5; j++) {
            std::cout << i * 5 + j << " | " << majorColor[i] << " | " << minorColor[i] << "\n";
            colorPair.majorColor=majorColor[i];
            colorPair.minorColor=minorColor[i];
            colorMap.insert(pair<int, ColorPair>(i * 5 + j,colorPair));
        }
    }
    return colorMap;
}

int main() {
    map <int,ColorPair> result = printColorMap();
    assert(result.size() == 25);
    int pairNumber=0; 
    //test for pairNumber 0
    assert(result[pairNumber].majorColor==majorColor[0] && result[pairNumber].minorColor==minorColor[0]);
    pairNumber=1;
    assert(result[pairNumber].majorColor==majorColor[0] && result[pairNumber].minorColor==minorColor[1]);
    std::cout << "All is well (maybe!)\n";
    return 0;
}