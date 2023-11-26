#ifndef MULTIMEDIAMANAGER_H
#define MULTIMEDIAMANAGER_H

#include <map>
#include <memory>
#include <string>
#include <iostream>
#include "Multimedia.h"
#include "Group.h"
#include "Film.h"
#include "Photo.h"

// Forward declaration of classes
class MultimediaManager;

// Define smart pointers for the classes
typedef std::shared_ptr<MultimediaManager> ManagerPtr;
typedef std::shared_ptr<Multimedia> MultimediaPtr;
typedef std::shared_ptr<Group> GroupPtr;
typedef std::shared_ptr<Film> FilmPtr;

/**
 * @brief MultimediaManager class, stores Multimedia objects and groups in a map of shared smart pointers
 */
class MultimediaManager {
private:
    std::map<std::string, MultimediaPtr> multimediaTable;
    std::map<std::string, GroupPtr> groupTable;

public:
    // Method to create a Photo and add it to the multimedia table
    MultimediaPtr createPhoto(const std::string& name, const std::string& path, double latitude, double longitude);

    // Method to create a Video and add it to the multimedia table
    MultimediaPtr createVideo(const std::string& name, const std::string& path, int duration);

    // Method to create a Film and add it to the multimedia table
    FilmPtr createFilm(const std::string& name, const std::string& path, int duration, int numChapter, int* chapters);

    // Method to create a Group and add it to the group table
    GroupPtr createGroup(const std::string& name);

    // Method to display multimedia information by name
    void displayMultimedia(const std::string& name);

    // Method to display group information by name
    void displayGroup(const std::string& name);

    // Method to play multimedia by name
    void playMultimedia(const std::string& name);

    // Method to remove multimedia by name
    void removeMultimedia(const std::string& name);

    // Method to remove group by name
    void removeGroup(const std::string& name);
};

#endif // MULTIMEDIAMANAGER_H
