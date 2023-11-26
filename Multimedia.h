#ifndef MULTIMEDIA_H
#define MULTIMEDIA_H

#include <string>
#include <iostream>
#include <memory> // Incluir la cabecera para std::shared_ptr

class Multimedia {
private:
    std::string nameFile; // Nombre del objeto multimedia
    std::string pathName; // Ruta del archivo

protected:
    // Rendre le constructeur protégé pour permettre l'accès à la classe MultimediaManager
    Multimedia();
public:
    // Multimedia();  // Constructor por defecto
    Multimedia(const std::string& name, const std::string& path);  // Constructor con argumentos
    ~Multimedia();  // Destructor

    // Getters
    std::string getNameFile() const;
    std::string getPathName() const;

    // Setters
    void setNameFile(const std::string& name);
    void setPathName(const std::string& path);

    // Visualización
    virtual void Visualization(std::ostream& out) const;

    // Aquí usaremos std::shared_ptr para play()
    virtual void play() const = 0;
};

#endif
