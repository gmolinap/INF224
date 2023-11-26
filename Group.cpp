#include "Group.h"
#include "Multimedia.h"  // Add this line to include the Multimedia header

Group::Group(const std::string& name) : groupName(name) {}

Group::~Group() {
    // Smart pointers will automatically manage the memory of Multimedia objects
}

void Group::addObject(MultimediaPtr obj) {
    this->push_back(obj);
}

void Group::removeObject(MultimediaPtr obj) {
    auto it = begin();
    while (it != end()) {
        if (*it == obj) {
            erase(it++);
        } else {
            ++it;
        }
    }
}

const std::string& Group::getGroupName() const {
    return groupName;
}

void Group::displayGroup() const {
    std::cout << "Group Name: " << groupName << std::endl;

    for (const MultimediaPtr& obj : *this) {
        obj->Visualization(std::cout);
        std::cout << "-------------------------" << std::endl;
    }
}
