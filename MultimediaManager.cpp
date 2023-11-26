#include "MultimediaManager.h"

MultimediaPtr MultimediaManager::createPhoto(const std::string& name, const std::string& path, double latitude, double longitude) {
    MultimediaPtr photo = std::make_shared<Photo>(name, path, latitude, longitude);
    multimediaTable[name] = photo;
    return photo;
}

MultimediaPtr MultimediaManager::createVideo(const std::string& name, const std::string& path, int duration) {
    MultimediaPtr video = std::make_shared<Video>(name, path, duration);
    multimediaTable[name] = video;
    return video;
}

FilmPtr MultimediaManager::createFilm(const std::string& name, const std::string& path, int duration, int numChapter, int* chapters) {
    FilmPtr film = std::make_shared<Film>(name, path, duration, chapters, numChapter);
    multimediaTable[name] = film;
    return film;
}

GroupPtr MultimediaManager::createGroup(const std::string& name) {
    GroupPtr group = std::make_shared<Group>(name);
    groupTable[name] = group;
    return group;
}

void MultimediaManager::displayMultimedia(const std::string& name) {
    auto it = multimediaTable.find(name);
    if (it != multimediaTable.end()) {
        it->second->Visualization(std::cout);
    } else {
        std::cout << "Multimedia not found." << std::endl;
    }
}

void MultimediaManager::displayGroup(const std::string& name) {
    auto it = groupTable.find(name);
    if (it != groupTable.end()) {
        it->second->displayGroup();
    } else {
        std::cout << "Group not found." << std::endl;
    }
}

void MultimediaManager::playMultimedia(const std::string& name) {
    auto it = multimediaTable.find(name);
    if (it != multimediaTable.end()) {
        it->second->play();
    } else {
        std::cout << "Multimedia not found." << std::endl;
    }
}

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

void MultimediaManager::removeGroup(const std::string& name) {
    auto it = groupTable.find(name);
    if (it != groupTable.end()) {
        groupTable.erase(it);
    } else {
        std::cout << "Group not found." << std::endl;
    }
}
