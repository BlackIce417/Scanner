#include <iostream>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <cstring>
#include <unistd.h>
#include <vector>

#define MAX_PORT 65535
#define MIN_PORT 1

std::vector<int> ACTIVATE_PORT;

void start_scanner(char *addr, int port)
{
    int socket_client = 0;
    socket_client = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in addrSrv;
    memset(&addrSrv, 0, sizeof(addrSrv));
    addrSrv.sin_family = AF_INET;
    addrSrv.sin_addr.s_addr = inet_addr(addr);
    addrSrv.sin_port = htons(port);
    if (connect(socket_client, (struct sockaddr *)&addrSrv, sizeof(addrSrv)) == -1)
    {
        
    }
    else
    {
        ACTIVATE_PORT.push_back(port);
    }
    close(socket_client);
}

int main(int argc, char *argv[])
{
    char ip_addr[] = "127.0.0.1";
    std::cout << "-----Start scanning-----" << std::endl;
    for (int port = MIN_PORT; port <= MAX_PORT; port++)
    {
        start_scanner(ip_addr, port);
    }
    for (int i = 0; i < ACTIVATE_PORT.size(); i++)
    {
        std::cout << "Port " << ACTIVATE_PORT[i] << " is open" << std::endl;
    }
    return 0;
}
