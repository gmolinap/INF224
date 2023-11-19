#ifndef FILM_H
#define FILM_H

#include <ostream>
#include <vector>
#include <string>
#include "Video.h"


class Film : public Video{
private:
//here we use a nullpointr, it's not going to point to any direction of memory
    int* chapterDuration{};
    int numChapter; 
public:
    ~Film();
    Film(const std::string& name, const std::string& path, const int dur, int* chapter, int num);

    // getters
    const int* get_chapterDurations() const;
    int get_numChapter() const;
    // setters 
    void setChapter(const int* chapters, int num);

    //Visualization 
    //Remember that every method that inheretes from the superclass needs to be with virtual
    virtual void Visualization(std::ostream& out) const;

    // Play function implemented
    virtual void play() const override {
        // Play function 
        std::cout << "Playing the film..." << std::endl;
    }

    //7e étape. Destruction et copie des objets
    // we must create the Film copy structure
    Film (const Film& other);
    // and the operator affectation
    Film& operator=(const Film& other);


};

#endif