// protocolCom.cpp

#include "protocolCom.h"

std::string ProtocolHandler::handleRequest(const std::string& request, MultimediaManager& manager) {
    const std::string endLine = "\n";
    std::stringstream iss(request);
    std::string command;
    std::vector<std::string> args;

    iss >> command;
    std::string arg;
    while (iss >> arg) {
        if (arg == endLine) {
            break;
        }
        args.push_back(arg);
    }

    if (args.empty())
        return "Please enter the name of the file/group" + endLine;

    std::string result;  // Variable para almacenar el resultado de las operaciones

    if (command == "find") {
        manager.playMultimedia(args[0]);
    }else if(command == "displayGroup"){
        manager.displayGroup(args[0]);
    }
    else {
        return "Check the command line" + endLine;
    }

    return result;  // Devolver el resultado de las operaciones
}
