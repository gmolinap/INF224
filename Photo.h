#ifndef PHOTO_H
#define PHOTO_H

#include <iostream>
#include <string>
#include "Multimedia.h"

class Photo : public Multimedia {
private:
    //Real - Double
    double latitude;
    double longitude;

public:

    Photo();
    ~Photo();
    //Photo calling the name and path from Multimedia with & and the lat and lon without &
    Photo(const std::string& name, const std::string& path, double lat, const double lon);

    //getters
    double get_latitude() const;
    double get_longitude() const;

    //setters
    void set_latitude(const double& lat);
    void set_longitude(const double& lon);

    //Its override for overwritting the visualization method from Multimedia
    virtual void Visualization(std::ostream& out) const override;

    //We define the play function
    virtual void play() const override;
};
#endif // PHOTO_H
