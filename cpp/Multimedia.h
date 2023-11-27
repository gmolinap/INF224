#ifndef MULTIMEDIA_H
#define MULTIMEDIA_H

#include <string>
#include <iostream>
#include <memory> // Include the header for std::shared_ptr

/**
 * @brief The Multimedia class represents a multimedia object.
 * 
 * This class provides basic functionality for handling multimedia objects,
 * such as storing the name and path of the multimedia file.
 */
class Multimedia {
private:
    std::string nameFile; /**< Name of the multimedia object */
    std::string pathName; /**< Path of the file */

protected:
    /**
     * @brief Protected constructor to allow access to the MultimediaManager class.
     */
    Multimedia();

public:
    /**
     * @brief Constructor with arguments.
     * 
     * @param name The name of the multimedia object.
     * @param path The path to the multimedia file.
     */
    Multimedia(const std::string& name, const std::string& path);

    /**
     * @brief Destructor.
     */
    ~Multimedia();

    /**
     * @brief Get the name of the multimedia object.
     * 
     * @return The name of the multimedia object.
     */
    std::string getNameFile() const;

    /**
     * @brief Get the path of the multimedia file.
     * 
     * @return The path of the multimedia file.
     */
    std::string getPathName() const;

    /**
     * @brief Set the name of the multimedia object.
     * 
     * @param name The name to set.
     */
    void setNameFile(const std::string& name);

    /**
     * @brief Set the path of the multimedia file.
     * 
     * @param path The path to set.
     */
    void setPathName(const std::string& path);

    /**
     * @brief Display information about the multimedia object.
     * 
     * @param out The output stream to display the information.
     */
    virtual void Visualization(std::ostream& out) const;

    /**
     * @brief Virtual function to play the multimedia object.
     * 
     * @note This function is declared as pure virtual and must be implemented
     * in derived classes.
     */
    virtual void play() const = 0;
};

#endif
