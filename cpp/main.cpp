#include "TCPServer.h" 
#include <iostream>
#include "Multimedia.h"
#include "Photo.h"
#include "Video.h"
#include "Film.h"
#include "Group.h"
#include "MultimediaManager.h"
#include "ccsocket.h"
#include "protocolCom.h"
using namespace std;

typedef std::shared_ptr<Film> FilmPtr;
typedef std::shared_ptr<Group> GroupPtr;
typedef std::shared_ptr<Multimedia> MultimediaPtr;

const int PORT = 3331;

/**
 * @brief Main function to demonstrate the MultimediaManager and TCPServer functionality.
 * 
 * @param argc The number of command-line arguments.
 * @param argv An array of command-line arguments.
 * @return 0 on successful execution, 1 on error.
 */
int main(int argc, const char* argv[]) {
    
    // Create an instance of MultimediaManager
    MultimediaManager manager = MultimediaManager();
    
    // Create a Photo and a Video using the manager
    manager.createPhoto("Neiva", "centro-neiva.JPG", 40.7128, -74.0060);
    manager.createVideo("AUTH", "AUTH.mp4", 60);

    // Create the TCPServer
    auto *server = new TCPServer([&](std::string const &request, std::string &response) {
        // The request sent by the client to the server
        std::cout << "request: " << request << std::endl;

        // The response that the server sends back to the client
        response = ProtocolHandler::handleRequest(request, manager);
        std::cout << "response: " << response << std::endl;

        // Returning false would close the connection with the client
        return true;
    });

    // Launch the infinite loop of the server
    std::cout << "Starting Server on port " << PORT << std::endl;

    int status = server->run(PORT);

    // In case of an error
    if (status < 0) {
        std::cerr << "Could not start Server on port " << PORT << std::endl;
        return 1;
    }

    return 0;
}
