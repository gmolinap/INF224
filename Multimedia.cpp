#include "Multimedia.h"

Multimedia::Multimedia() : nameFile(""), pathName("") {}

Multimedia::Multimedia(const std::string& name, const std::string& path)
    : nameFile(name), pathName(path) {}

Multimedia::~Multimedia() {
    // No es necesario hacer nada especial aquí si usamos punteros inteligentes.
}

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
    out << "Name: " << nameFile << "\nPath: " << pathName << std::endl;
}
