
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

#include <stdint.h>
#include <stdbool.h>

#include "common.h"


enum ArtPollReplyIndicatorState {
    INDICATOR_UNKNOWN = 0,
    INDICATOR_LOCATING = 1,
    INDICATOR_MUTUED = 2,
    INDICATOR_NORMAL = 3,
};

enum ArtPollReplyProgrammingAuthority {
    PROGRAMMING_UNKNOWN = 0,
    PROGRAMMING_FRONTPANEL = 1,
    PROGRAMMING_NETWORK = 2,
    PROGRAMMING_UNUSED = 3,
};

struct ArtPollReplyStatus1 {
    bool ubea_present;
    bool rdm_capable;
    bool booted_from_rom;
    enum ArtPollReplyIndicatorState indicator_state;
    enum ArtPollReplyProgrammingAuthority programming_authority;
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

struct ArtPollReply {
    uint8_t ip_address[4];
    uint16_t port;
    uint16_t version_info;
    uint16_t oem_code;
    uint8_t ubea_version;
    struct ArtPollReplyStatus1 status1;
    uint16_t esta_manufacturer_code;
    char port_name[17];
    char long_name[63];
    char node_report[64];
    uint16_t num_ports;
    struct ArtPollReplyPortType ports[4];
    struct GoodInput good_input[4];
    struct GoodOutput good_output[4];
    struct PortAddress adresses[4];
    uint8_t acn_priority;
    uint8_t sw_macro;
    uint8_t sw_remote;
};

#endif // ARTNET_C_PACKETS_H