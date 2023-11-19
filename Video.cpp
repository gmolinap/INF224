#include "Video.h"

Video::Video(): duration(0){}

Video::~Video(){}

Video::Video(const std::string& name,const std::string& path, int dur) 
: Multimedia(name, path) , duration(dur) {}

int Video::get_duration() const{
    return duration;
}

void Video::set_duration(int dur){
    duration = dur;
}

void Video::Visualization(std::ostream& out) const{
    out << "Name of Video: " << getNameFile() << "." << std::endl; 
    out << "Path of video: " << getPathName() << "." << std::endl; 
    out << "Video duration: " << duration << " minutes." << std::endl; 
}

void Video::play() const {
    std::string pathName = "mp4";
    std::string command = getNameFile() + "."  + pathName;
    system(command.c_str());
    // Implementa aquí la funcionalidad para reproducir el video
}

