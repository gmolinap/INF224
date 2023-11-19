#include "Film.h"




Film::Film(const std::string& name, const std::string& path, int dur, int* chapter, int num)
    : Video(name, path, dur), chapterDuration(nullptr), numChapter(0) {
    setChapter(chapter, num);
}

void Film::setChapter(const int* chapter, int num){
    //empty the memory if necessary
    delete[] chapterDuration;

    //allocate in memory
    chapterDuration = new int[num];

    //loop in chapter duration and adding to array 
    for (int i=0; i < num; i++){
        chapterDuration[i] = chapter[i];
    }

    //assigning chapter number

    numChapter = num;
}

const int* Film::get_chapterDurations() const{
    return chapterDuration;
}

int Film::get_numChapter() const{
    return numChapter;
}

Film::~Film(){
    delete[] chapterDuration;
}

//Copy constructor

Film::Film(const Film& other) : Video(other), numChapter(other.numChapter){
    chapterDuration = new int[numChapter];
    for (int i = 0; i < numChapter; i++) {
        chapterDuration[i] = other.chapterDuration[i];
    }
}

// Sobrecarga del operador de asignación
Film& Film::operator=(const Film& other) {
    if (this != &other) { // protección contra auto-asignación
        delete[] chapterDuration; // libera la memoria actual

        numChapter = other.numChapter;
        chapterDuration = new int[numChapter];
        for (int i = 0; i < numChapter; i++) {
            chapterDuration[i] = other.chapterDuration[i];
        }
    }
    return *this;
}




void Film::Visualization(std::ostream& out) const{
        out << "Chapter Durations:" << std::endl;
        for (int i = 0; i < numChapter; i++) {
            out << "Chapter " << i + 1 << ": " << chapterDuration[i] << " minutes" << std::endl;
        }
}

