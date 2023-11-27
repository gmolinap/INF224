// protocolCom.h
#ifndef PROTOCOL_COM_H
#define PROTOCOL_COM_H

#include <sstream>
#include <vector>
#include "MultimediaManager.h"

class ProtocolHandler {
public:
    static std::string handleRequest(const std::string& request, MultimediaManager& multimediaManager);
};

#endif // PROTOCOL_COM_H
