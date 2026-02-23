
#include <stdint.h>
#include <stdbool.h>

#include "art_poll.h"
#include "../common.h"


/// Serializes an ArtPoll packet into a buffer for Artnet
void art_poll_serialize(struct ArtPoll art_poll, uint8_t *buffer) {
    memcpy(buffer, &artnet_id, 8);
    pack_u16_le(buffer + 8, OpPoll);
    pack_u16_be(buffer + 10, art_poll.protocol);
};

/// Parse a ArtPoll packet from a buffer
void art_poll_parse(struct ArtPoll *art_poll, uint8_t *buffer) {

};
