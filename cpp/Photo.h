#ifndef PHOTO_H
#define PHOTO_H

#include <iostream>
#include <string>
#include "Multimedia.h"

/**
 * @file Photo.h
 * @brief Header file for the Photo class.
 */

/**
 * @brief Photo class, derived from Multimedia.
 * 
 * Represents a photo with additional location information.
 */
class Photo : public Multimedia {
private:
    //Real - Double
    double latitude; /**< The latitude of the photo location. */
    double longitude; /**< The longitude of the photo location. */

public:
    /**
     * @brief Default constructor for the Photo class.
     */
    Photo();

    /**
     * @brief Destructor for the Photo class.
     */
    ~Photo();

    /**
     * @brief Parameterized constructor for the Photo class.
     * 
     * @param name The name of the photo.
     * @param path The path to the photo file.
     * @param lat The latitude of the photo location.
     * @param lon The longitude of the photo location.
     */
    Photo(const std::string& name, const std::string& path, double lat, const double lon);

    /**
     * @brief Getter for the latitude of the photo.
     * 
     * @return The latitude of the photo.
     */
    double get_latitude() const;

    /**
     * @brief Getter for the longitude of the photo.
     * 
     * @return The longitude of the photo.
     */
    double get_longitude() const;

    /**
     * @brief Setter for the latitude of the photo.
     * 
     * @param lat The new latitude to set.
     */
    void set_latitude(const double& lat);

    /**
     * @brief Setter for the longitude of the photo.
     * 
     * @param lon The new longitude to set.
     */
    void set_longitude(const double& lon);

    /**
     * @brief Visualization method for the Photo class.
     * 
     * @param out The output stream to display the photo information.
     */
    virtual void Visualization(std::ostream& out) const override;

    /**
     * @brief Play method for the Photo class.
     * 
     * This method is specific to the Photo class and can be implemented as needed.
     */
    virtual void play() const override;
};

#endif // PHOTO_H
