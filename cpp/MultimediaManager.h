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
    std::map<std::string, MultimediaPtr> multimediaTable; ///< Map to store multimedia objects
    std::map<std::string, GroupPtr> groupTable; ///< Map to store groups

public:
    /**
     * @brief Create a Photo and add it to the multimedia table.
     * 
     * @param name The name of the photo.
     * @param path The path to the photo file.
     * @param latitude The latitude information for the photo.
     * @param longitude The longitude information for the photo.
     * @return A shared pointer to the created Photo object.
     */
    MultimediaPtr createPhoto(const std::string& name, const std::string& path, double latitude, double longitude);

    /**
     * @brief Create a Video and add it to the multimedia table.
     * 
     * @param name The name of the video.
     * @param path The path to the video file.
     * @param duration The duration of the video.
     * @return A shared pointer to the created Video object.
     */
    MultimediaPtr createVideo(const std::string& name, const std::string& path, int duration);

    /**
     * @brief Create a Film and add it to the multimedia table.
     * 
     * @param name The name of the film.
     * @param path The path to the film file.
     * @param duration The duration of the film.
     * @param numChapter The number of chapters in the film.
     * @param chapters An array representing the duration of each chapter.
     * @return A shared pointer to the created Film object.
     */
    FilmPtr createFilm(const std::string& name, const std::string& path, int duration, int numChapter, int* chapters);

    /**
     * @brief Create a Group and add it to the group table.
     * 
     * @param name The name of the group.
     * @return A shared pointer to the created Group object.
     */
    GroupPtr createGroup(const std::string& name);

    /**
     * @brief Display information about a multimedia object.
     * 
     * @param name The name of the multimedia object to display.
     */
    void displayMultimedia(const std::string& name);

    /**
     * @brief Display information about a group.
     * 
     * @param name The name of the group to display.
     */
    void displayGroup(const std::string& name);

    /**
     * @brief Play a multimedia object.
     * 
     * @param name The name of the multimedia object to play.
     */
    void playMultimedia(const std::string& name);

    /**
     * @brief Remove a multimedia object from the multimedia table and associated groups.
     * 
     * @param name The name of the multimedia object to remove.
     */
    void removeMultimedia(const std::string& name);

    /**
     * @brief Remove a group from the group table.
     * 
     * @param name The name of the group to remove.
     */
    void removeGroup(const std::string& name);
};

#endif // MULTIMEDIAMANAGER_H
