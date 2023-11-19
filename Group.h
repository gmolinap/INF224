#ifndef GROUP_H
#define GROUP_H

#include <list>
#include <iostream>

// Group class template inheriting from std::list
template <class T>
class Group : public std::list<T*> {
private:
    std::string groupName; // Group name

public:
    // Constructor
    Group(const std::string& name) : groupName(name) {}

    // Accessor for group name
    std::string getGroupName() const {
        return groupName;
    }

    // Display method to show attributes of all objects in the group
    void displayGroup() const {
        std::cout << "Group Name: " << groupName << std::endl;
        for (const auto& objPtr : *this) {
            objPtr->Visualization(std::cout);
            std::cout << "--------------------------" << std::endl;
        }
    }
};

#endif // GROUP_H
