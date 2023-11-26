#ifndef GROUP_H
#define GROUP_H

#include <list>
#include <iostream>
#include <memory>  // Add this line
#include "Multimedia.h"  // Add this line

// Forward declaration of Multimedia class
class Multimedia;

// Define smart pointer for the Multimedia class
typedef std::shared_ptr<Multimedia> MultimediaPtr;

class Group : public std::list<MultimediaPtr> {
private:
    std::string groupName;

public:
    Group(const std::string& name);
    ~Group();

    void addObject(MultimediaPtr obj);
    void removeObject(MultimediaPtr obj);
    const std::string& getGroupName() const;
    void displayGroup() const;
};

#endif
