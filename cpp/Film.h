#ifndef FILM_H
#define FILM_H

#include <ostream>
#include <vector>
#include <string>
#include <memory> // Include the header for std::shared_ptr
#include "Video.h"

/**
 * @brief Class representing a Film, derived from the Video class.
 */
class Film : public Video {
private:
    std::shared_ptr<int[]> chapterDuration; /**< Use std::shared_ptr for the matrix of chapter durations. */
    int numChapter; /**< Number of chapters in the film. */

public:
    /**
     * @brief Destructor for the Film class.
     */
    ~Film();

    /**
     * @brief Constructor for the Film class.
     * 
     * @param name The name of the film.
     * @param path The path to the film file.
     * @param dur The duration of the film.
     * @param chapter An array representing the duration of each chapter.
     * @param num The number of chapters in the film.
     */
    Film(const std::string& name, const std::string& path, const int dur, int* chapter, int num);

    // Getters
    /**
     * @brief Get the shared pointer to the array of chapter durations.
     * 
     * @return The shared pointer to the array of chapter durations.
     */
    const std::shared_ptr<int[]>& getChapterDurations() const;

    /**
     * @brief Get the number of chapters in the film.
     * 
     * @return The number of chapters in the film.
     */
    int getNumChapter() const;

    // Setters
    /**
     * @brief Set the chapter durations for the film.
     * 
     * @param chapters An array representing the duration of each chapter.
     * @param num The number of chapters in the film.
     */
    void setChapter(const int* chapters, int num);

    // Visualization
    /**
     * @brief Display information about the film.
     * 
     * @param out The output stream to display the information.
     */
    virtual void Visualization(std::ostream& out) const override;

    // Play function implemented
    /**
     * @brief Play the film.
     */
    virtual void play() const override;
    
    // Copy constructor
    /**
     * @brief Copy constructor for the Film class.
     * 
     * @param other The Film object to copy.
     */
    Film(const Film& other);

    // Assignment operator
    /**
     * @brief Assignment operator for the Film class.
     * 
     * @param other The Film object to assign.
     * @return A reference to the assigned Film object.
     */
    Film& operator=(const Film& other);
};

#endif
