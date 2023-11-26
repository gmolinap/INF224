#ifndef VIDEO_H
#define VIDEO_H

#include "Multimedia.h"
#include <iostream>
#include <string>
#include <memory> // Incluir la cabecera para std::shared_ptr

class Video: public Multimedia {
private:
    int duration;

public:
    Video(); // Constructor sin parámetros
    ~Video(); // Destructor
    Video(const std::string& name, const std::string& path, const int  dur); // Constructor con parámetros

    // Getter
    int get_duration() const;

    // Setter
    void set_duration(int dur);

    // Visualización
    virtual void Visualization(std::ostream& out) const override;

    // Utilizamos std::shared_ptr para play()
    virtual void play() const override;
};

#endif
