#include "Multimedia.h"

/**
 * @brief Default constructor for the Multimedia class.
 * 
 * Initializes the nameFile and pathName to empty strings.
 */
Multimedia::Multimedia() : nameFile(""), pathName("") {}

/**
 * @brief Constructor with arguments for the Multimedia class.
 * 
 * @param name The name of the multimedia object.
 * @param path The path to the multimedia file.
 */
Multimedia::Multimedia(const std::string& name, const std::string& path)
    : nameFile(name), pathName(path) {}

/**
 * @brief Destructor for the Multimedia class.
 * 
 * No special actions are required in this destructor when using smart pointers.
 */
Multimedia::~Multimedia() {
    // No special actions are required here when using smart pointers.
}

/**
 * @brief Get the name of the multimedia object.
 * 
 * @return The name of the multimedia object.
 */
std::string Multimedia::getNameFile() const {
    return nameFile;
}

/**
 * @brief Get the path of the multimedia file.
 * 
 * @return The path of the multimedia file.
 */
std::string Multimedia::getPathName() const {
    return pathName;
}

/**
 * @brief Set the name of the multimedia object.
 * 
 * @param name The name to set.
 */
void Multimedia::setNameFile(const std::string& name) {
    nameFile = name;
}

/**
 * @brief Set the path of the multimedia file.
 * 
 * @param path The path to set.
 */
void Multimedia::setPathName(const std::string& path) {
    pathName = path;
}

/**
 * @brief Display information about the multimedia object.
 * 
 * @param out The output stream to display the information.
 */
void Multimedia::Visualization(std::ostream& out) const {
    out << "Name: " << nameFile << "\nPath: " << pathName << std::endl;
}
