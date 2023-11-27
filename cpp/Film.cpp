#include "Film.h"

/**
 * @brief Constructor for the Film class.
 * 
 * @param name The name of the film.
 * @param path The path of the film.
 * @param dur The duration of the film.
 * @param chapter An array of chapter durations.
 * @param num The number of chapters.
 */
Film::Film(const std::string& name, const std::string& path, int dur, int* chapter, int num)
    : Video(name, path, dur), chapterDuration(nullptr), numChapter(0) {
    setChapter(chapter, num);
}

/**
 * @brief Set the chapters and their durations for the film.
 * 
 * @param chapter An array of chapter durations.
 * @param num The number of chapters.
 */
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

/**
 * @brief Get the shared pointer to the array of chapter durations.
 * 
 * @return A shared pointer to the array of chapter durations.
 */
const std::shared_ptr<int[]>& Film::get_chapterDurations() const {
    return chapterDuration;
}

/**
 * @brief Get the number of chapters in the film.
 * 
 * @return The number of chapters.
 */
int Film::get_numChapter() const {
    return numChapter;
}

/**
 * @brief Destructor for the Film class.
 * 
 * Unique_ptr automatically manages the memory, so no need to delete[].
 */
Film::~Film() {
    // Unique_ptr automatically manages the memory, so no need to delete[]
}

/**
 * @brief Copy constructor for the Film class.
 * 
 * @param other The Film object to copy.
 */
Film::Film(const Film& other) : Video(other), numChapter(other.numChapter) {
    // Use smart pointers to manage dynamic memory
    chapterDuration = std::make_unique<int[]>(numChapter);

    // Loop to copy chapter duration values
    for (int i = 0; i < numChapter; i++) {
        chapterDuration[i] = other.chapterDuration[i];
    }
}

/**
 * @brief Assignment operator for the Film class.
 * 
 * @param other The Film object to assign.
 * @return A reference to the current Film object.
 */
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

/**
 * @brief Visualization function for the Film class.
 * 
 * @param out The output stream to display the information.
 */
void Film::Visualization(std::ostream& out) const {
    out << "Chapter Durations:" << std::endl;
    for (int i = 0; i < numChapter; i++) {
        out << "Chapter " << i + 1 << ": " << chapterDuration[i] << " minutes" << std::endl;
    }
}
