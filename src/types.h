
#ifndef ARTNET_C_TYPES_H

#define ARTNET_C_TYPES_H


struct PortAddress {
    uint8_t net;
    uint8_t subnet;
    uint8_t universe;
};

#endif // ARTNET_C_TYPES_H