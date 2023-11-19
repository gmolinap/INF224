//
// main.cpp
// Created on 21/10/2018
//

#include <iostream>
#include "Multimedia.h"
#include "Photo.h"
#include "Video.h"
#include "Film.h"
#include "Group.h" // Include the Group class template

using namespace std;

int main(int argc, const char* argv[])
{
    // Create some multimedia objects
    Photo* photo1 = new Photo("Neiva centre-ville", "centro-neiva.JPG", 40.7128, -74.0060);
    Video* video1 = new Video("Vacation", "Parque93.JPG", 60);
    Film* film1 = new Film("AUTH", "auth.mp4", 120, new int[3]{30, 40, 50}, 3);

     // Create groups and add objects to them
    Group<Multimedia> multimediaGroup("Multimedia Group");
    multimediaGroup.push_back(photo1);
    multimediaGroup.push_back(video1);
    multimediaGroup.push_back(film1);

    Group<Photo> photoGroup("Photo Group");
    photoGroup.push_back(photo1);
    photoGroup.push_back(photo1);

    Group<Video> videoGroup("Video Group");
    videoGroup.push_back(video1);
    videoGroup.push_back(video1);

    Group<Film> filmGroup("Film Group");
    filmGroup.push_back(film1);
    filmGroup.push_back(film1);

    // Display groups
    multimediaGroup.displayGroup();
    std::cout << "--------------------------" << std::endl;

    photoGroup.displayGroup();
    std::cout << "--------------------------" << std::endl;

    videoGroup.displayGroup();
    std::cout << "--------------------------" << std::endl;

    filmGroup.displayGroup();

    // Clean up memory (assuming no memory ownership transfer to groups)
    delete photo1;
    delete video1;
    delete film1;

    return 0;

};