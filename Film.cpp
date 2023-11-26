#include "Film.h"

Film::Film(const std::string& name, const std::string& path, int dur, int* chapter, int num)
    : Video(name, path, dur), chapterDuration(nullptr), numChapter(0) {
    setChapter(chapter, num);
}

void Film::setChapter(const int* chapter, int num) {
    // Use smart pointers to manage dynamic memory
    chapterDuration = std::make_unique<int[]>(num);

    // Loop to copy chapter duration values
    for (int i = 0; i < num; i++) {
        chapterDuration[i] = chapter[i];
    }

    // Assigning chapter number
    numChapter = num;
}

const std::shared_ptr<int[]>& Film::get_chapterDurations() const {
    return chapterDuration;
}


int Film::get_numChapter() const {
    return numChapter;
}

Film::~Film() {
    // Unique_ptr automatically manages the memory, so no need to delete[]
}

// Copy constructor
Film::Film(const Film& other) : Video(other), numChapter(other.numChapter) {
    // Use smart pointers to manage dynamic memory
    chapterDuration = std::make_unique<int[]>(numChapter);

    // Loop to copy chapter duration values
    for (int i = 0; i < numChapter; i++) {
        chapterDuration[i] = other.chapterDuration[i];
    }
}

// Assignment operator
Film& Film::operator=(const Film& other) {
    if (this != &other) {
        // Smart pointers manage memory, so no need to delete[]
        numChapter = other.numChapter;
        chapterDuration = std::make_unique<int[]>(numChapter);

        // Loop to copy chapter duration values
        for (int i = 0; i < numChapter; i++) {
            chapterDuration[i] = other.chapterDuration[i];
        }
    }
    return *this;
}

void Film::Visualization(std::ostream& out) const {
    out << "Chapter Durations:" << std::endl;
    for (int i = 0; i < numChapter; i++) {
        out << "Chapter " << i + 1 << ": " << chapterDuration[i] << " minutes" << std::endl;
    }
}
