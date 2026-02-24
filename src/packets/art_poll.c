
#include <stdint.h>
#include <stdbool.h>
#include <string.h>

#include "art_poll.h"
#include "../common.h"


/// Serializes an ArtPoll packet into a buffer for Artnet
void art_poll_serialize(struct ArtPoll art_poll, uint8_t *buffer) {
    memcpy(buffer, &artnet_id, 8);
    pack_u16_le(buffer + 8, OpPoll);
    pack_u16_be(buffer + 10, art_poll.protocol);

    uint8_t flags = art_poll.flags.send_on_change ? 0x02 : 0x00;
    flags |= art_poll.flags.send_diagnostics ? 0x04 : 0x00;
    flags |= art_poll.flags.unicast_diagnostics ? 0x08 : 0x00;
    flags |= art_poll.flags.vlc_disabled ? 0x10 : 0x00;
    flags |= art_poll.flags.targeted_mode ? 0x20 : 0x00;
    buffer[12] = flags;

    buffer[13] = art_poll.diag_priority;

    uint16_t top_address = port_address_as_number(art_poll.top_address);
    pack_u16_be(buffer + 14, top_address);
    uint16_t bottom_address = port_address_as_number(art_poll.bottom_address);
    pack_u16_be(buffer + 16, bottom_address);

    pack_u16_be(buffer + 18, art_poll.esta_manufacturer_code);
    pack_u16_be(buffer + 20, art_poll.oem_code);
};

/// Parse a ArtPoll packet from a buffer
void art_poll_parse(struct ArtPoll *art_poll, uint8_t *buffer) {
    art_poll->protocol = unpack_u16_be(buffer + 10);

    art_poll->flags.send_on_change = (buffer[12] & 0x02) == 0x02;
    art_poll->flags.send_diagnostics = (buffer[12] & 0x04) == 0x04;
    art_poll->flags.unicast_diagnostics = (buffer[12] & 0x08) == 0x08;
    art_poll->flags.vlc_disabled = (buffer[12] & 0x10) == 0x10;
    art_poll->flags.targeted_mode = (buffer[12] & 0x20) == 0x20;

    art_poll->diag_priority = buffer[13];

    uint16_t top_address = unpack_u16_be(buffer + 14);
    art_poll->top_address = port_address_from_number(top_address);

    uint16_t bottom_address = unpack_u16_be(buffer + 16);
    art_poll->bottom_address = port_address_from_number(bottom_address);

    art_poll->esta_manufacturer_code = unpack_u16_be(buffer + 18);
    art_poll->oem_code = unpack_u16_be(buffer + 20);
};
