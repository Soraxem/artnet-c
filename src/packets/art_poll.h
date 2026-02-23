/// @file art_poll.h
/// @brief Artnet ArtPoll packet definitions and functions

#ifndef ARTNET_C_PACKETS_ART_POLL_H

#define ARTNET_C_PACKETS_ART_POLL_H

#include <stdint.h>
#include <stdbool.h>

#include "../common.h"

/// Flags that define the response behavior to this poll request
struct ArtPollFlags {
    /// Send a poll packet when device settings change
    bool send_on_change;
    /// Send diaganostics packets
    bool send_diagnostics;
    /// Send diagnostics via unicast
    bool unicast_diagnostics;
    /// Disable VLC
    bool vlc_disabled;
    /// Enabled targeted mode
    bool targeted_mode;
};

/// Struct that holds an ArtPoll packet
struct ArtPoll {
    /// Protocol revision number of the packet
    uint16_t protocol;
    /// Flags of the device
    struct ArtPollFlags flags;
    /// Diagnostic priority
    uint8_t diag_priority;
    /// Top PortAddress of polling area
    struct PortAddress top_address;
    /// Bottom PortAddress of polling area
    struct PortAddress bottom_address;
    /// Manufacturer code
    uint16_t esta_manufacturer_code;
    /// Oem code
    uint16_t oem_code;
};

/// Serializes an ArtPoll packet into a buffer for Artnet
void art_poll_serialize(struct ArtPoll art_poll, uint8_t *buffer);

/// Parse a ArtPoll packet from a buffer
void art_poll_parse(struct ArtPoll *art_poll, uint8_t *buffer);

#endif // ARTNET_C_PACKETS_ART_POLL_H