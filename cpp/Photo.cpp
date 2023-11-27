#include "Photo.h"

/**
 * @file Photo.cpp
 * @brief Implementation of the Photo class.
 */

/**
 * @brief Default constructor for the Photo class.
 */
Photo::Photo() : latitude(0.0), longitude(0.0) {}

/**
 * @brief Destructor for the Photo class.
 */
Photo::~Photo() {}

/**
 * @brief Parameterized constructor for the Photo class.
 * 
 * @param name The name of the photo.
 * @param path The path to the photo file.
 * @param lat The latitude of the photo location.
 * @param lon The longitude of the photo location.
 */
Photo::Photo(const std::string& name, const std::string& path, double lat, const double lon)
    : Multimedia(name, path), latitude(lat), longitude(lon) {}

/**
 * @brief Getter for the latitude of the photo.
 * 
 * @return The latitude of the photo.
 */
double Photo::get_latitude() const {
    return latitude;
}

/**
 * @brief Getter for the longitude of the photo.
 * 
 * @return The longitude of the photo.
 */
double Photo::get_longitude() const {
    return longitude;
}

/**
 * @brief Setter for the latitude of the photo.
 * 
 * @param lat The new latitude to set.
 */
void Photo::set_latitude(const double& lat) {
    latitude = lat;
}

/**
 * @brief Setter for the longitude of the photo.
 * 
 * @param lon The new longitude to set.
 */
void Photo::set_longitude(const double& lon) {
    longitude = lon;
}

/**
 * @brief Visualization method for the Photo class.
 * 
 * @param out The output stream to display the photo information.
 */
void Photo::Visualization(std::ostream& out) const {
    out << "Photo Information:\n";
    Multimedia::Visualization(out);
    out << "Location: Latitude " << latitude << ", Longitude " << longitude << "\n";
}

/**
 * @brief Play method for the Photo class.
 * 
 * This method is specific to the Photo class and can be implemented as needed.
 */
void Photo::play() const {
    // Implementation of play() for Photo (if applicable)
    // For example, displaying the photo on a screen.
    std::cout << "Displaying the photo..." << std::endl;
}
