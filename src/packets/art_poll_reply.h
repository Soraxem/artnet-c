/// @file art_poll_reply.h
/// @brief Artnet ArtPollReply packet definitions and functions

#ifndef ARTNET_C_PACKETS_ART_POLL_REPLY_H

#define ARTNET_C_PACKETS_ART_POLL_REPLY_H

#include "../artnet_c_common.h"

ARTNET_C_BEGIN_DECLS

#include <stdint.h>
#include <stdbool.h>



/// Describes the state of the indicator light on the node
enum ArtPollReplyIndicatorState {
    /// No Known State
    INDICATOR_UNKNOWN = 0,
    /// Indicator light is in Locating mode
    INDICATOR_LOCATING = 1,
    /// Indicator light is turned off
    INDICATOR_MUTUED = 2,
    /// Indicator light acs normal
    INDICATOR_NORMAL = 3,
};

/// Describes how the node address can be programmed
enum ArtPollReplyProgrammingAuthority {
    /// No Known State
    PROGRAMMING_UNKNOWN = 0,
    /// Address can only be programmed at the node itself
    PROGRAMMING_FRONTPANEL = 1,
    /// Address can be programmed over the network
    PROGRAMMING_NETWORK = 2,
    /// Address cannot be programmed
    PROGRAMMING_UNUSED = 3,
};

/// Descripes the state of the status1 flags
struct ArtPollReplyStatus1 {
    bool ubea_present;
    bool rdm_capable;
    bool booted_from_rom;
    enum ArtPollReplyIndicatorState indicator_state;
    enum ArtPollReplyProgrammingAuthority programming_authority;
};

/// Describes the type of a port
enum ArtPollReplyPortTypes {
    DMX512 = 0,
    MIDI = 1,
    AVAB = 2,
    COLORTRAN = 3,
    ADB = 4,
    ARTNET = 5,
    DALI = 6,
};

struct ArtPollReplyPortType {
    bool is_input;
    bool is_output;
    enum ArtPollReplyPortTypes type;
};

struct GoodInput {
    bool convert_to_sacn;
    bool recieve_errors_detected;
    bool input_disabled;
    bool includes_dmx_text;
    bool includes_dmx_sip;
    bool includes_dmx_test;
    bool recieved_data;
};

struct GoodOutput {
    bool convert_from_sacn;
    bool merge_mode_ltp;
    bool dmx_short_detected;
    bool merging_artnet_data;
    bool includes_dmx_text;
    bool includes_dmx_sip;
    bool includes_dmx_test;
    bool outputting_data;
};

/// Struct that holds an ArtPollReply packet
struct ArtPollReply {
    /// IPv4 Address of the replying node
    uint8_t ip_address[4];
    /// UDP port of the replying node
    uint16_t port;
    /// The Artnet protocol revision number
    uint16_t version_info;
    uint16_t oem_code;
    /// Version of the UBEA
    uint8_t ubea_version;
    /// status1 flags
    struct ArtPollReplyStatus1 status1;
    uint16_t esta_manufacturer_code;
    /// Name of the node
    char port_name[17];
    /// Detailed name of the node
    char long_name[63];
    /// Short description of the node
    char node_report[64];
    /// How many ports are on the node, max 4
    uint16_t num_ports;
    
    struct ArtPollReplyPortType ports[4];
    struct GoodInput good_input[4];
    struct GoodOutput good_output[4];
    struct PortAddress adresses[4];
    uint8_t acn_priority;
    uint8_t sw_macro;
    uint8_t sw_remote;
};

ARTNET_C_END_DECLS

#endif // ARTNET_C_PACKETS_ART_POLL_REPLY_H