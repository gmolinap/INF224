#include "Video.h"

/**
 * @file Video.cpp
 * @brief Implementation file for the Video class.
 */

/**
 * @brief Default constructor for the Video class.
 */
Video::Video() : duration(0) {}

/**
 * @brief Destructor for the Video class.
 */
Video::~Video() {
    // No special actions needed here when using smart pointers.
}

/**
 * @brief Parameterized constructor for the Video class.
 * 
 * @param name The name of the video.
 * @param path The path to the video file.
 * @param dur The duration of the video in seconds.
 */
Video::Video(const std::string& name, const std::string& path, const int dur)
    : Multimedia(name, path), duration(dur) {}

/**
 * @brief Getter for the duration of the video.
 * 
 * @return The duration of the video in seconds.
 */
int Video::get_duration() const {
    return duration;
}

/**
 * @brief Setter for the duration of the video.
 * 
 * @param dur The new duration to set.
 */
void Video::set_duration(int dur) {
    duration = dur;
}

/**
 * @brief Visualization method for the Video class.
 * 
 * @param out The output stream to display the video information.
 */
void Video::Visualization(std::ostream& out) const {
    Multimedia::Visualization(out); // Call the base class function
    out << "Duration: " << duration << " seconds" << std::endl;
}

/**
 * @brief Play method for the Video class.
 * 
 * This method displays a message indicating that the video is being played.
 */
void Video::play() const {
    std::cout << "Playing the video..." << std::endl;
}
