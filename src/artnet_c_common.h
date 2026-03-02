
#ifndef ARTNET_C_COMMON_H

#define ARTNET_C_COMMON_H

#ifdef __cplusplus
  #define ARTNET_C_BEGIN_DECLS extern "C" {
  #define ARTNET_C_END_DECLS   }
#else
  #define ARTNET_C_BEGIN_DECLS
  #define ARTNET_C_END_DECLS
#endif

ARTNET_C_BEGIN_DECLS


#include <stdint.h>

extern const char artnet_id[8];

extern const uint16_t OpPoll;
extern const uint16_t OpPollReply;
extern const uint16_t OpDmx;

/// This is an Artnet PortAddress
struct PortAddress {
    uint8_t net;
    uint8_t subnet;
    uint8_t universe;
};

uint16_t port_address_as_number(struct PortAddress address);

struct PortAddress port_address_from_number(uint16_t number);

// Implementing little endian and big endian packing for platform compatibility

static inline void pack_u16_le(uint8_t *buffer, uint16_t value) {
    buffer[0] = value & 0xFF;
    buffer[1] = (value >> 8) & 0xFF;
};

static inline uint16_t unpack_u16_le(uint8_t *buffer) {
    return (buffer[0] | (buffer[1] << 8));
};

static inline void pack_u16_be(uint8_t *buffer, uint16_t value) {
    buffer[0] = (value >> 8) & 0xFF;
    buffer[1] = value & 0xFF;
};

static inline uint16_t unpack_u16_be(uint8_t *buffer) {
    return (buffer[0] << 8 | buffer[1]);
};

ARTNET_C_END_DECLS

#endif // ARTNET_C_COMMON_H