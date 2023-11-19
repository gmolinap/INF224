#ifndef MULTIMEDIA_H
#define MULTIMEDIA_H
#pragma once
#include <string>
#include <iostream>

// We will have here all things related to Multimedia
class Multimedia {
private:
    std::string nameFile; //name of multimedia object
    std::string pathName; // name of file path

public:
    Multimedia();  // Default constructor
    Multimedia(const std::string& name, const std::string& path);  // Constructor with arguments
    ~Multimedia();  // Destructor

    // Getters
    std::string getNameFile() const;
    std::string getPathName() const;


    // Setters
    void setNameFile(const std::string& name);
    void setPathName(const std::string& path);

    // Visualization
    virtual void Visualization(std::ostream& out) const;

    //Here we declare the function play(), first in Multimedia as base class and therefore the other classes
    //Bc they will be given a different implementation - Polymorphism

    virtual void play() const = 0;
    //Since there is not form to play all multimedia objects, we can define it as 0
};
#endif