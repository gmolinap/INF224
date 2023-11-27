#include "Group.h"
#include "Multimedia.h" // Add this line to include the Multimedia header

/**
 * @brief Constructor for the Group class.
 * 
 * @param name The name of the group.
 */
Group::Group(const std::string& name) : groupName(name) {}

/**
 * @brief Destructor for the Group class.
 * 
 * Smart pointers will automatically manage the memory of Multimedia objects.
 */
Group::~Group() {
    // Smart pointers will automatically manage the memory of Multimedia objects
}

/**
 * @brief Add a multimedia object to the group.
 * 
 * @param obj A shared pointer to the Multimedia object.
 */
void Group::addObject(MultimediaPtr obj) {
    this->push_back(obj);
}

/**
 * @brief Remove a multimedia object from the group.
 * 
 * @param obj A shared pointer to the Multimedia object.
 */
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

/**
 * @brief Get the name of the group.
 * 
 * @return The name of the group.
 */
const std::string& Group::getGroupName() const {
    return groupName;
}

/**
 * @brief Display information about the group and its multimedia objects.
 */
void Group::displayGroup() const {
    std::cout << "Group Name: " << groupName << std::endl;

    for (const MultimediaPtr& obj : *this) {
        obj->Visualization(std::cout);
        std::cout << "-------------------------" << std::endl;
    }
}
