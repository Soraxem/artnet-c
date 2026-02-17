
/** 
 * @mainpage Artnet C Library Documentation
 * 
 * @author Samuel Hafen
 */

/** 
 * @file packets.h
 * @brief In this file all Artnet packets are defined
 * @author Samuel Hafen
 */

#ifndef ARTNET_C_PACKETS_H

#define ARTNET_C_PACKETS_H

#include <types.h>


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

struct ArtPoll {
    /// Protocol revision number of the packet
    uint16_t protocol;
    /// Flags of the device
    ArtPollFlags flags;
    /// Diagnostic priority
    uint8_t diag_priority;
    /// Top PortAddress of polling area
    PortAddress top_address;
    /// Bottom PortAddress of polling area
    PortAddress bottom_address;
    /// Manufacturer code
    uint16_t esta_manufacturer_code;
    /// Oem code
    uint16_t oem_code;
};

enum ArtPollReplyIndicatorState {
    UNKNOWN = 0,
    LOCATING = 1,
    MUTUED = 2,
    NORMAL = 3,
};

enum ArtPollReplyProgrammingAuthority {
    UNKNOWN = 0,
    FRONTPANEL = 1,
    NETWORK = 2,
    UNUSED = 3,
};

struct ArtPollReplyStatus1 {
    bool ubea_present;
    bool rdm_capable;
    bool booted_from_rom;
    ArtPollReplyIndicatorState indicator_state;
    ArtPollReplyProgrammingAuthority programming_authority;
};


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
    ArtPollReplyPortTypes type;
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

struct ArtPollReply {
    uint8_t ip_address[4];
    uint16_t port;
    uint16_t version_info;
    uint16_t oem_code;
    uint8_t ubea_version;
    ArtPollReplyStatus1 status1;
    uint16_t esta_manufacturer_code;
    char port_name[17];
    char long_name[63];
    char node_report[64];
    uint16_t num_ports;
    ArtPollReplyPortType ports[4];
    GoodInput good_input[4];
    GoodOutput good_output[4];
    PortAddress adresses[4];
    uint8_t acn_priority;
    uint8_t sw_macro;
    uint8_t sw_remote;
};




struct ArtDmx {
    /// The Artnet protocol revision number
    uint16_t protocol;
    /// Incrementing number for sortiung DMX packets
    uint8_t sequence;
    /// Physical port number of DMX origin
    uint8_t physical;
    /// Address of the ArtDmx packet
    PortAddress universe;
    /// Number of DMX data bytes
    uint16_t length;
    /// DMX data as bytes
    uint8_t data[512];
};

#endif // ARTNET_C_PACKETS_H