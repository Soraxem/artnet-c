/// @file art_dmx.h
/// @brief Artnet ArtDmx packet definitions and functions

#ifndef ARTNET_C_PACKETS_ART_DMX_H

#define ARTNET_C_PACKETS_ART_DMX_H

#include "../artnet_c_common.h"

ARTNET_C_BEGIN_DECLS

#include <stdint.h>



/// Struct that holds an ArtDmx packet type
struct ArtDmx {
    /// The Artnet protocol revision number
    uint16_t protocol;
    /// Incrementing number for sortiung DMX packets
    uint8_t sequence;
    /// Physical port number of DMX origin
    uint8_t physical;
    /// Address of the ArtDmx packet
    struct PortAddress universe;
    /// Number of DMX data bytes
    uint16_t length;
    /// DMX data as bytes
    uint8_t data[512];
};

/// Serializes an ArtDmx packet into a buffer for Artnet
void art_dmx_serialize(struct ArtDmx art_dmx, uint8_t *buffer);

/// Parse a ArtDmx packet from a buffer, you need to check beforehand what type of packet the buffer containts!
void art_dmx_parse(struct ArtDmx *art_dmx, uint8_t *buffer);

ARTNET_C_END_DECLS

#endif // ARTNET_C_PACKETS_ART_DMX_H