
#include <string.h>

#include "art_dmx.h"
#include "../artnet_c_common.h"

// Serializes an ArtDmx packet into a buffer for Artnet
void art_dmx_serialize(struct ArtDmx art_dmx, uint8_t *buffer) {
    memcpy(buffer, &artnet_id, 8);
    pack_u16_le(buffer + 8, OpDmx);
    pack_u16_be(buffer + 10, art_dmx.protocol);
    
    buffer[12] = art_dmx.sequence;
    buffer[13] = art_dmx.physical;

    uint16_t universe_number = port_address_as_number(art_dmx.universe);
    pack_u16_be(buffer + 14, universe_number);

    pack_u16_be(buffer + 16, art_dmx.length);
    memcpy(buffer + 18, art_dmx.data, art_dmx.length);
};

// Parse a ArtDmx packet from a buffer
void art_dmx_parse(struct ArtDmx *art_dmx, uint8_t *buffer) {
    art_dmx->protocol = unpack_u16_be(buffer + 10);

    art_dmx->sequence = buffer[12];
    art_dmx->physical = buffer[13];

    uint16_t universe = unpack_u16_be(buffer + 14);
    art_dmx->universe = port_address_from_number(universe);
    
    art_dmx->length = unpack_u16_be(buffer + 16);
    memcpy(art_dmx->data, buffer + 18, art_dmx->length);
};