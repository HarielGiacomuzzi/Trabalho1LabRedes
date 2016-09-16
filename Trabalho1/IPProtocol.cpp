#include "IPProtocol.h"
#include <stdio.h>

void IPProtocol::setPackage(unsigned char *pckg){
    this->package = pckg;
}

IPProtocol::IPProtocol(){}

IPProtocol::~IPProtocol(){}

// identifies the type of service and send's back the enum that represent it
int IPProtocol::identifyPackageSize(){
    if(this->identifyProtocol() == IP){
        int pkgSize;
        pkgSize=(package[16]<<8)|(package[17]);
        return pkgSize;
    }
    return 0;
}

// identifies the type of service inside the package
int IPProtocol::identifyTypeOfService(){
    if(this->identifyProtocol() == IP){
        int typeOfService;
        typeOfService=package[23];
        return typeOfService;
    }
    return 0;
}

// identifiesd the type of the protocol and returns it as a Enum.
int IPProtocol::identifyProtocol(){
    int type;
    type=(package[12]<<8)|(package[13]);
    if(type == IP){
        return IP;
    }
    if(type == ARP){
        return ARP;
    }
}


int IPProtocol::getDestinationPort(){
    int port = 0;
    if(this->identifyTypeOfService() == UDP || this->identifyTypeOfService() == TCP){
        port=(package[36]<<8)|(package[37]);
        return port;
    }
    printf("###########################\nNão foi possivel identificar a porta do pacote por não ser um pacote UDP/TCP\n###########################");
    return 0;
}

int IPProtocol::getSourcePort(){
    int port = 0;
    if(this->identifyTypeOfService() == UDP || this->identifyTypeOfService() == TCP){
        port=(package[34]<<8)|(package[35]);
        return port;
    }
    printf("###########################\nNão foi possivel identificar a porta do pacote por não ser um pacote UDP/TCP\n###########################");
    return 0;
}

