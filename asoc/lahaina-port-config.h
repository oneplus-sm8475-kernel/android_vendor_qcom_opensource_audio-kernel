/* SPDX-License-Identifier: GPL-2.0-only */
/*
 * Copyright (c) 2018-2020, The Linux Foundation. All rights reserved.
 */

#ifndef _LAHAINA_PORT_CONFIG
#define _LAHAINA_PORT_CONFIG

#include <soc/swr-common.h>

#define WSA_MSTR_PORT_MASK 0xFF
/*
 * Add port configuration in the format
 *{ si, off1, off2, hstart, hstop, wd_len, bp_mode, bgp_ctrl, lane_ctrl, dir,
 *  stream_type}
 */

static struct port_params wsa_frame_params_default[SWR_MSTR_PORT_LEN] = {
	{7,  1,  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00},
	{31, 2,  0,    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00},
	{63, 12, 31,   0xFF, 0xFF, 0xFF,  0x1, 0xFF, 0xFF, 0x00, 0x00},
	{7,  6,  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00},
	{31, 18, 0,    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00},
	{63, 13, 31,   0xFF, 0xFF, 0xFF,  0x1, 0xFF, 0xFF, 0x00, 0x00},
	{15, 7,  0,    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00},
	{15, 10, 0,    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00},
};

static struct port_params rx_frame_params_dsd[SWR_MSTR_PORT_LEN] = {
	{3,  0,  0,  0xFF, 0xFF, 1,    0xFF, 0xFF, 1, 0x00, 0x00},
	{31, 0,  0,  3,    6,    7,    0,    0xFF, 0, 0x00, 0x00},
	{31, 11, 11, 0xFF, 0xFF, 4,    1,    0xFF, 0, 0x00, 0x00},
	{7,  9,  0,  0xFF, 0xFF, 0xFF, 0xFF, 1,    0, 0x00, 0x00},
	{3,  1,  0,  0xFF, 0xFF, 0xFF, 0xFF, 3,    0, 0x00, 0x00},
};

/* Headset + PCM Haptics */
static struct port_params rx_frame_params_default[SWR_MSTR_PORT_LEN] = {
	{3,  0,  0,  0xFF, 0xFF, 1,    0xFF, 0xFF, 1, 0x00, 0x00}, /* HPH/EAR */
	{31, 0,  0,  3,    6,    7,    0,    0xFF, 0, 0x00, 0x00}, /* HPH_CLH */
	{31, 11, 11, 0xFF, 0xFF, 4,    1,    0xFF, 0, 0x00, 0x00}, /* HPH_CMP */
	{7,  1,  0,  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0, 0x00, 0x00}, /* LO/AUX */
	{0,  0,  0,  0xFF, 0xFF, 0xFF, 0xFF, 0,    0, 0x00, 0x00}, /* DSD */
	{0x18F, 0, 0, 0x8, 0x8, 0x0F,  0x00, 0,    0, 0x00, 0x01}, /* PCM_OUT */
};

/* TX UC1: TX1: 1ch, TX2: 2chs, TX3: 1ch(MBHC) */
static struct port_params tx_frame_params_default[SWR_MSTR_PORT_LEN] = {
	{7,  1,  0,  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0, 0x00, 0x00}, /* TX1 */
	{3,  0,  0,  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 1, 0x00, 0x00}, /* TX2 */
	{7,  5,  0,  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0, 0x00, 0x00}, /* TX3 */
};

/* TX UC1: TX1: 1ch, TX2: 2chs, TX3: 1ch(MBHC) */
static struct port_params tx_frame_params_shima[SWR_MSTR_PORT_LEN] = {
	{3,  1,  0,  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0, 0x00, 0x00}, /* TX1 */
	{3,  0,  0,  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 1, 0x00, 0x00}, /* TX2 */
	{7,  2,  0,  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0, 0x00, 0x00}, /* TX3 */
};

/* 4.8 MHz clock */
static struct port_params tx_frame_params_4p8MHz[SWR_MSTR_PORT_LEN] = {
	{7,  1,  0,  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0, 0x00, 0x00}, /* TX1 */
	{3,  0,  0,  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 1, 0x00, 0x00}, /* TX2 */
	{3,  2,  0,  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0, 0x00, 0x00}, /* TX3 */
};

/* 0.6 MHz clock */
static struct port_params tx_frame_params_0p6MHz[SWR_MSTR_PORT_LEN] = {
	{1,  1,  0,  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0, 0x00, 0x00}, /* TX1 */
	{1,  1,  0,  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0, 0x00, 0x00}, /* TX2 */
	{1,  1,  0,  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0, 0x00, 0x00}, /* TX3 */
};
static struct swr_mstr_port_map sm_port_map[] = {
	{TX_MACRO, SWR_UC0, tx_frame_params_default},
	{TX_MACRO, SWR_UC1, tx_frame_params_4p8MHz},
	{TX_MACRO, SWR_UC2, tx_frame_params_0p6MHz},
	{RX_MACRO, SWR_UC0, rx_frame_params_default},
	{RX_MACRO, SWR_UC1, rx_frame_params_dsd},
	{WSA_MACRO, SWR_UC0, wsa_frame_params_default},
};

static struct swr_mstr_port_map sm_port_map_shima[] = {
	{TX_MACRO, SWR_UC0, tx_frame_params_shima},
	{RX_MACRO, SWR_UC0, rx_frame_params_default},
	{RX_MACRO, SWR_UC1, rx_frame_params_dsd},
	{WSA_MACRO, SWR_UC0, wsa_frame_params_default},
};

#endif /* _LAHAINA_PORT_CONFIG */
