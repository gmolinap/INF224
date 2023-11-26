#ifndef FILM_H
#define FILM_H

#include <ostream>
#include <vector>
#include <string>
#include <memory> // Incluir la cabecera para std::shared_ptr
#include "Video.h"

class Film : public Video {
private:
    std::shared_ptr<int[]> chapterDuration; // Usar std::shared_ptr para la matriz
    int numChapter;

public:
    ~Film();
    Film(const std::string& name, const std::string& path, const int dur, int* chapter, int num);

    // getters
    const std::shared_ptr<int[]>& get_chapterDurations() const;
    int get_numChapter() const;
    // setters
    void setChapter(const int* chapters, int num);

    // Visualization
    virtual void Visualization(std::ostream& out) const override;

    // Play function implemented
    virtual void play() const override {
        std::cout << "Playing the film..." << std::endl;
    }

    // Copy constructor
    Film(const Film& other);
    // Assignment operator
    Film& operator=(const Film& other);
};

#endif
