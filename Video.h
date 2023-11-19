#ifndef VIDEO_H
#define VIDEO_H

#include "Multimedia.h"
#include <iostream>
#include <string>

class Video: public Multimedia{
private:
    // We define the atributes
    int duration;
public:
    Video(); //constructor sin parametros
    ~Video(); //destructeur 
    // Video(const int& dur ); // constructor con parametros
    //Constructor con parametros tipo Java
    Video(const std::string& name, const std::string& path, const int  dur);


    //Getter
    int get_duration() const;

    //Setter
    void set_duration(int dur);

    //Visualization
    virtual void Visualization(std::ostream& out) const override;

    //Define the function play()
    virtual void play() const override;

};


#endif