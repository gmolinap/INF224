#include "Multimedia.h"

Multimedia::Multimedia() {}

Multimedia::Multimedia(const std::string& name, const std::string& path)
    : nameFile(name), pathName(path) {}

Multimedia::~Multimedia() {}

std::string Multimedia::getNameFile() const {
    return nameFile;
}

std::string Multimedia::getPathName() const {
    return pathName;
}

void Multimedia::setNameFile(const std::string& name) {
    nameFile = name;
}

void Multimedia::setPathName(const std::string& path) {
    pathName = path;
}

void Multimedia::Visualization(std::ostream& out) const {
    out << "File name: " << nameFile << std::endl;
    out << "File path: " << pathName << std::endl;
}
