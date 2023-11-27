#include "MultimediaManager.h"

/**
 * @brief Create a Photo and add it to the multimedia table.
 * 
 * @param name The name of the photo.
 * @param path The path to the photo file.
 * @param latitude The latitude information for the photo.
 * @param longitude The longitude information for the photo.
 * @return A shared pointer to the created Photo object.
 */
MultimediaPtr MultimediaManager::createPhoto(const std::string& name, const std::string& path, double latitude, double longitude) {
    MultimediaPtr photo = std::make_shared<Photo>(name, path, latitude, longitude);
    multimediaTable[name] = photo;
    return photo;
}

/**
 * @brief Create a Video and add it to the multimedia table.
 * 
 * @param name The name of the video.
 * @param path The path to the video file.
 * @param duration The duration of the video.
 * @return A shared pointer to the created Video object.
 */
MultimediaPtr MultimediaManager::createVideo(const std::string& name, const std::string& path, int duration) {
    MultimediaPtr video = std::make_shared<Video>(name, path, duration);
    multimediaTable[name] = video;
    return video;
}

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
FilmPtr MultimediaManager::createFilm(const std::string& name, const std::string& path, int duration, int numChapter, int* chapters) {
    FilmPtr film = std::make_shared<Film>(name, path, duration, chapters, numChapter);
    multimediaTable[name] = film;
    return film;
}

/**
 * @brief Create a Group and add it to the group table.
 * 
 * @param name The name of the group.
 * @return A shared pointer to the created Group object.
 */
GroupPtr MultimediaManager::createGroup(const std::string& name) {
    GroupPtr group = std::make_shared<Group>(name);
    groupTable[name] = group;
    return group;
}

/**
 * @brief Display information about a multimedia object.
 * 
 * @param name The name of the multimedia object to display.
 */
void MultimediaManager::displayMultimedia(const std::string& name) {
    auto it = multimediaTable.find(name);
    if (it != multimediaTable.end()) {
        it->second->Visualization(std::cout);
    } else {
        std::cout << "Multimedia not found." << std::endl;
    }
}

/**
 * @brief Display information about a group.
 * 
 * @param name The name of the group to display.
 */
void MultimediaManager::displayGroup(const std::string& name) {
    auto it = groupTable.find(name);
    if (it != groupTable.end()) {
        it->second->displayGroup();
    } else {
        std::cout << "Group not found." << std::endl;
    }
}

/**
 * @brief Play a multimedia object.
 * 
 * @param name The name of the multimedia object to play.
 */
void MultimediaManager::playMultimedia(const std::string& name) {
    auto it = multimediaTable.find(name);
    if (it != multimediaTable.end()) {
        it->second->play();
    } else {
        std::cout << "Multimedia not found." << std::endl;
    }
}

/**
 * @brief Remove a multimedia object from the multimedia table and associated groups.
 * 
 * @param name The name of the multimedia object to remove.
 */
void MultimediaManager::removeMultimedia(const std::string& name) {
    auto it = multimediaTable.find(name);
    if (it != multimediaTable.end()) {
        // Remove multimedia from groups
        for (auto& group : groupTable) {
            group.second->removeObject(it->second);
        }
        multimediaTable.erase(it);
    } else {
        std::cout << "Multimedia not found." << std::endl;
    }
}

/**
 * @brief Remove a group from the group table.
 * 
 * @param name The name of the group to remove.
 */
void MultimediaManager::removeGroup(const std::string& name) {
    auto it = groupTable.find(name);
    if (it != groupTable.end()) {
        groupTable.erase(it);
    } else {
        std::cout << "Group not found." << std::endl;
    }
}
