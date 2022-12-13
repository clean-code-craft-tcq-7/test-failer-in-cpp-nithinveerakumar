#include <iostream>
#include <assert.h>
#include <sstream>
#include <map>
#include<cstring>
using namespace std;
 const char* majorColorArray[] = {"White", "Red", "Black", "Yellow", "Violet"};
 const char* minorColorArray[] = {"Blue", "Orange", "Green", "Brown", "Slate"};

struct ColorPair{
    const char* majorColor;
    const char* minorColor;
    int PairNumber;
};

map <int,ColorPair> getColourMap() {
    map <int,ColorPair> colorMap;
    int i = 0, j = 0;
    for(i = 0; i < 5; i++) {
        for(j = 0; j < 5; j++) {
            ColorPair colorPair;
            colorPair.PairNumber = i* 5 + j + 1;
            colorPair.majorColor = majorColorArray[i];
            colorPair.minorColor = minorColorArray[j];
            colorMap.insert(pair<int,ColorPair>(i*5+j+1,colorPair));
        }
    }
    return colorMap;
}

string getFormattedColorPairString(ColorPair colorPair)
{
    string formattedString=std::to_string(colorPair.PairNumber)+ " | " + colorPair.majorColor + " | " + colorPair.minorColor;
    std::string s = std::to_string(colorPair.PairNumber);
    return formattedString;    
}

void printColorPairMap()
{   map<int, ColorPair> colorMap = getColourMap();
    for(map<int, ColorPair>::iterator itr=colorMap.begin();itr != colorMap.end(); ++itr)
    {
        cout << getFormattedColorPairString(itr->second)<<endl;
    }
}

int main() {
    printColorPairMap();
    map<int, ColorPair> colorMap = getColourMap();
    //test for pairNumber 1
    int pairNumber=1;
    assert(strcmp(colorMap[pairNumber].majorColor,"White")==0 && strcmp(colorMap[pairNumber].minorColor,"Blue")==0);
    assert(strcmp(getFormattedColorPairString(colorMap[pairNumber]).c_str(),"1 | White | Blue/0"));
   //test for pairNumber 2
    pairNumber=2;
    assert(strcmp(colorMap[pairNumber].majorColor,"White")==0 && strcmp(colorMap[pairNumber].minorColor,"Orange")==0);
    assert(strcmp(getFormattedColorPairString(colorMap[pairNumber]).c_str(),"1 | White | Orange/0"));
    //test for pairNumber 11
    pairNumber=11;
    assert(strcmp(colorMap[pairNumber].majorColor,"Black")==0 && strcmp(colorMap[pairNumber].minorColor,"Blue")==0);
    assert(strcmp(getFormattedColorPairString(colorMap[pairNumber]).c_str(),"1 | Black | Blue/0"));
    //test for pairNumber 12
    pairNumber=12;
    assert(strcmp(colorMap[pairNumber].majorColor,"Black")==0 && strcmp(colorMap[pairNumber].minorColor,"Orange")==0);
    assert(strcmp(getFormattedColorPairString(colorMap[pairNumber]).c_str(),"1 | Black | Orange/0"));
    std::cout << "All is well (maybe!)\n";
    return 0;
}