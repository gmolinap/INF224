#include "Video.h"

Video::Video() : duration(0) {}

Video::~Video() {
    // No es necesario hacer nada especial aquí si usamos punteros inteligentes.
}

Video::Video(const std::string& name, const std::string& path, const int dur)
    : Multimedia(name, path), duration(dur) {}

int Video::get_duration() const {
    return duration;
}

void Video::set_duration(int dur) {
    duration = dur;
}

void Video::Visualization(std::ostream& out) const {
    Multimedia::Visualization(out); // Llamamos a la función de la clase base
    out << "Duration: " << duration << " seconds" << std::endl;
}

void Video::play() const {
    std::cout << "Playing the video..." << std::endl;
}
