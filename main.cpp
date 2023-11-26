#include "TCPServer.h" // Replace with the actual header file name if different
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
int main(int argc, const char* argv[])
{
    
    MultimediaManager manager = MultimediaManager();
    manager.createPhoto("Neiva", "centro-neiva.JPG", 40.7128, -74.0060);
    manager.createVideo("AUTH", "AUTH.mp4", 60);

    // create the TCPServer
    auto *server =
        new TCPServer([&](std::string const &request, std::string &response)
                      {
                          // the request sent by the client to the server
                          std::cout << "request: " << request << std::endl;

                          // the response that the server sends back to the client
                          response = ProtocolHandler::handleRequest(request, manager);
                          std::cout << "response: " << response << std::endl;

                          // return false would close the connection with the client
                          return true;
                      });

    // launch the infinite loop of the server
    std::cout << "Starting Server on port " << PORT << std::endl;

    int status = server->run(PORT);

    // in case of an error
    if (status < 0)
    {
        std::cerr << "Could not start Server on port " << PORT << std::endl;
        return 1;
    }

    return 0;
}
