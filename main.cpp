//
// main.cpp
// Created on 21/10/2018
//

#include <iostream>
#include "Multimedia.h"
#include "Photo.h"
#include "Video.h"
#include "Film.h"
using namespace std;

int main(int argc, const char* argv[])
{
    Photo p1("centro-neiva", "JPG", 1000.7, 1201.3);
    Photo p2("Parque93", "JPG", 1002.7, 1201.3);
    Video v1("AUTH", "mp4", 1000);

    Multimedia* m[3] = {&p1, &p2, &v1};
    
    for (int i = 0; i < 3; i++) {
        m[i]->Visualization(std::cout);
        m[i]->play();
    }
    return 0;

};