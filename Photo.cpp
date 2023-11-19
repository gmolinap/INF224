#include "Photo.h"

//Initializated with an specific value
Photo::Photo(): latitude(0.0), longitude(0.0){};
//Message when object eliminated to check if std::shared_ptr works
Photo::~Photo() {
    std::cout << "Photo destroyed: " << getNameFile() << std::endl;
}


Photo::Photo(const std::string& name, const std::string& path,  double lat,  double lon)
    :Multimedia(name, path), latitude(lat),longitude(lon)  {};

double Photo::get_latitude() const{
    return latitude;
}

double Photo::get_longitude() const{
    return longitude;
}

void Photo::set_latitude(const double& lat){
    latitude = lat;
}

void Photo::set_longitude(const double& lon){
    longitude = lon;
}

//Visualization constant - getters from multimedia, and the local objects from getters.
void Photo::Visualization(std::ostream& out) const {
    out << "Photo name: " << getNameFile() << std::endl;
    out << "Path file: " << getPathName() << std::endl;
    out << "File latitude:" << latitude << std::endl;
    out << "File longitude:" << longitude << std::endl;
    
}

void Photo::play() const{
    std::string pathName = "jpg";
    std::string command= getNameFile() + "." + pathName;
    system(command.c_str());
}
