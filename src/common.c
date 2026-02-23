
#include "common.h"

const char* artnet_id = "Art-Net";

const uint16_t OpPoll = 0x2000;
const uint16_t OpPollReply = 0x2100;
const uint16_t OpDmx = 0x5000;


/// get the PortAddress assembled
uint16_t port_address_as_number(struct PortAddress address) {
    return (uint16_t)address.net << 8 | (uint16_t)address.subnet << 4 | address.universe;
};

struct PortAddress port_address_from_number(uint16_t number) {
    return (struct PortAddress) {
        .net = (uint8_t)(number >> 8),
        .subnet = (uint8_t)(number >> 4),
        .universe = (uint8_t)number
    };
};