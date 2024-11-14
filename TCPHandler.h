#ifndef RTSP_TCPHANDLER_H
#define RTSP_TCPHANDLER_H

#include "Protos.h"

#include <string>
#include <arpa/inet.h>

class TCPHandler {
public:
    TCPHandler();
    ~TCPHandler();

    static TCPHandler* GetInstance() {
        if (instance == NULL)
            instance = new TCPHandler();
        return instance;
    }

    void CreateTCPSocket();

    int AcceptClientConnection();

    std::string ReceiveRTSPRequest(int clientSocket);

    void SendRTSPResponse(int clientSocket, std::string& response);

    int& GetTCPSocket();

    sockaddr_in& GetTCPAddr();


private:
    static TCPHandler* instance;

    int tcpPort;
    int tcpSocket;

    sockaddr_in tcpAddr;
};

#endif //RTSP_TCPHANDLER_H