#ifndef IPPROTOCOL_H
#define IPPROTOCOL_H

enum Protocol{
    ARP = 0x0806,
    IP = 0x0800
};

enum TypeOfService{
    ICMP = 0x01,
    UDP = 0x11,
    TCP = 0x06,
};

enum UDPService{
    DNS = 0x0035
};

enum TCPService{
    HTTP = 0x0050
};

class IPProtocol
{
    public:
        IPProtocol(void *package);
        ~IPProtocol();
        // sendś back the tipe of the protocol inside
        int identifyProtocol();
        //sends back the size of the package in bytes
        int identifyPackageSize();
    protected:
    private:
        void *package;
};

#endif // IPPROTOCOL_H
