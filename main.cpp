//
// main.cpp
// Created on 21/10/2018
// 

#include <iostream>
#include "Multimedia.h"
#include "Photo.h"
#include "Video.h"
#include "Film.h"
#include "Group.h" 
#include "MultimediaManager.h"  // Include the header file that declares MultimediaPtr, GroupPtr, PhotoPtr, VideoPtr, FilmPtr

using namespace std;
typedef std::shared_ptr<Film> FilmPtr;
typedef std::shared_ptr<Group> GroupPtr;
typedef std::shared_ptr<Multimedia> MultimediaPtr;

int main(int argc, const char* argv[])
{
    // // Create some multimedia objects
    // Photo* photo1 = new Photo("Neiva centre-ville", "centro-neiva.JPG", 40.7128, -74.0060);
    // Video* video1 = new Video("Vacation", "Parque93.JPG", 60);
    // Film* film1 = new Film("AUTH", "auth.mp4", 120, new int[3]{30, 40, 50}, 3);




    // Group<Photo> photoGroup("Photo Group");
    // photoGroup.push_back(photo1);
    // photoGroup.push_back(photo1);

    // Group<Video> videoGroup("Video Group");
    // videoGroup.push_back(video1);
    // videoGroup.push_back(video1);

    // Group<Film> filmGroup("Film Group");
    // filmGroup.push_back(film1);
    // filmGroup.push_back(film1);

    // // Display groups
    // multimediaGroup.displayGroup();
    // std::cout << "--------------------------" << std::endl;

    // photoGroup.displayGroup();
    // std::cout << "--------------------------" << std::endl;

    // videoGroup.displayGroup();
    // std::cout << "--------------------------" << std::endl;

    // filmGroup.displayGroup();

    // // Clean up memory (assuming no memory ownership transfer to groups)
    // delete photo1;
    // delete video1;
    // delete film1;

    // PUNTO6
    // Group group("VacationGroup");

    // Photo* photo1 = new Photo("Beach", "beach.jpg", 0.0, 0.0);
    // Photo* photo2 = new Photo("Mountains", "mountains.jpg", 0.0, 0.0);

    // group.push_back(photo1);
    // group.push_back(photo2);

    // group.displayGroup();

    // // Recuerda liberar la memoria para evitar fugas de memoria
    // for (Multimedia* obj : group) {
    //     delete obj;
    // }

 

    // // Create some films
    // int chapters1[] = {10, 15, 20};
    // int numChapters1 = sizeof(chapters1) / sizeof(chapters1[0]);
    // FilmPtr film1 = std::make_shared<Film>("Film1", "mp4", 120, chapters1, numChapters1);

    // int chapters2[] = {8, 12, 18};
    // int numChapters2 = sizeof(chapters2) / sizeof(chapters2[0]);
    // FilmPtr film2 = std::make_shared<Film>("Film2", "avi", 90, chapters2, numChapters2);

    // // Create a group
    // GroupPtr group = std::make_shared<Group>("MyGroup");

    // // Add films to the group
    // group->addObject(film1);
    // group->addObject(film2);

    // // Display group information
    // group->displayGroup();


//Punto 11

    // Crear un objeto MultimediaManager
    MultimediaManager manager;

    // Crear algunos objetos multimedia y grupos
    auto photo1 = manager.createPhoto("Photo1", "/path/to/photo1.jpg", 37.7749, -122.4194);
    auto video1 = manager.createVideo("Video1", "/path/to/video1.mp4", 120);
    auto movie1 = manager.createFilm("Movie1", "/path/to/movie1.mp4", 180, 3, new int[]{30, 60, 90});
    
    auto group1 = manager.createGroup("Group1");
    auto group2 = manager.createGroup("Group2");

    // Agregar objetos multimedia a grupos
    group1->addObject(photo1);
    group1->addObject(video1);
    group2->addObject(movie1);

    // Mostrar información sobre un objeto multimedia y un grupo
    manager.displayMultimedia("Photo1");
    manager.displayGroup("Group1");

    // Reproducir un objeto multimedia
    manager.playMultimedia("Video1");

    // Eliminar un objeto multimedia y un grupo
    manager.removeMultimedia("Photo1");
    manager.removeGroup("Group1");

    return 0;

    return 0;
};