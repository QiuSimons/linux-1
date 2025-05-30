/* SPDX-License-Identifier: GPL-2.0-only */
/*
 * rt722-sdca-sdw.h -- RT722 SDCA ALSA SoC audio driver header
 *
 * Copyright(c) 2023 Realtek Semiconductor Corp.
 */

#ifndef __RT722_SDW_H__
#define __RT722_SDW_H__

#include <linux/regmap.h>
#include <linux/soundwire/sdw_registers.h>

static const struct reg_default rt722_sdca_reg_defaults[] = {
	{ 0x202d, 0x00 },
	{ 0x2f01, 0x00 },
	{ 0x2f02, 0x09 },
	{ 0x2f03, 0x00 },
	{ 0x2f04, 0x00 },
	{ 0x2f05, 0x0b },
	{ 0x2f06, 0x01 },
	{ 0x2f08, 0x00 },
	{ 0x2f09, 0x00 },
	{ 0x2f0a, 0x00 },
	{ 0x2f35, 0x00 },
	{ 0x2f36, 0x00 },
	{ 0x2f50, 0xf0 },
	{ 0x2f58, 0x07 },
	{ 0x2f59, 0x07 },
	{ 0x2f5a, 0x07 },
	{ 0x2f5b, 0x07 },
	{ 0x2f5c, 0x27 },
	{ 0x2f5d, 0x07 },
	{ 0x200003c, 0xc214 },
	{ 0x2000046, 0x8004 },
	{ 0x5810000, 0x702d },
	{ 0x6100000, 0x0201 },
	{ 0x6100006, 0x0005 },
	{ 0x6100010, 0x2630 },
	{ 0x6100011, 0x152f },
	{ 0x6100013, 0x0102 },
	{ 0x6100015, 0x2200 },
	{ 0x6100017, 0x0102 },
	{ 0x6100025, 0x2a29 },
	{ 0x6100026, 0x2a00 },
	{ 0x6100028, 0x2a2a },
	{ 0x6100029, 0x4141 },
	{ 0x6100055, 0x0000 },
	{ SDW_SDCA_CTL(FUNC_NUM_JACK_CODEC, RT722_SDCA_ENT_USER_FU05, RT722_SDCA_CTL_FU_MUTE, CH_L),
		0x01 },
	{ SDW_SDCA_CTL(FUNC_NUM_JACK_CODEC, RT722_SDCA_ENT_USER_FU05, RT722_SDCA_CTL_FU_MUTE, CH_R),
		0x01 },
	{ SDW_SDCA_CTL(FUNC_NUM_JACK_CODEC, RT722_SDCA_ENT_USER_FU05, RT722_SDCA_CTL_FU_VOLUME,
		CH_L), 0x0000 },
	{ SDW_SDCA_CTL(FUNC_NUM_JACK_CODEC, RT722_SDCA_ENT_USER_FU05, RT722_SDCA_CTL_FU_VOLUME,
		CH_R), 0x0000 },
	{ SDW_SDCA_CTL(FUNC_NUM_JACK_CODEC, RT722_SDCA_ENT_USER_FU0F, RT722_SDCA_CTL_FU_MUTE, CH_L),
		0x01 },
	{ SDW_SDCA_CTL(FUNC_NUM_JACK_CODEC, RT722_SDCA_ENT_USER_FU0F, RT722_SDCA_CTL_FU_MUTE, CH_R),
		0x01 },
	{ SDW_SDCA_CTL(FUNC_NUM_JACK_CODEC, RT722_SDCA_ENT_USER_FU0F, RT722_SDCA_CTL_FU_VOLUME,
		CH_L), 0x0000 },
	{ SDW_SDCA_CTL(FUNC_NUM_JACK_CODEC, RT722_SDCA_ENT_USER_FU0F, RT722_SDCA_CTL_FU_VOLUME,
		CH_R), 0x0000 },
	{ SDW_SDCA_CTL(FUNC_NUM_JACK_CODEC, RT722_SDCA_ENT_PDE12, RT722_SDCA_CTL_REQ_POWER_STATE,
		0), 0x03 },
	{ SDW_SDCA_CTL(FUNC_NUM_JACK_CODEC, RT722_SDCA_ENT_CS01, RT722_SDCA_CTL_SAMPLE_FREQ_INDEX,
		0), 0x09 },
	{ SDW_SDCA_CTL(FUNC_NUM_JACK_CODEC, RT722_SDCA_ENT_CS11, RT722_SDCA_CTL_SAMPLE_FREQ_INDEX,
		0), 0x09 },
	{ SDW_SDCA_CTL(FUNC_NUM_JACK_CODEC, RT722_SDCA_ENT_PDE40, RT722_SDCA_CTL_REQ_POWER_STATE,
		0), 0x03 },
	{ SDW_SDCA_CTL(FUNC_NUM_JACK_CODEC, RT722_SDCA_ENT_PLATFORM_FU44, RT722_SDCA_CTL_FU_CH_GAIN,
		CH_L), 0x0000 },
	{ SDW_SDCA_CTL(FUNC_NUM_JACK_CODEC, RT722_SDCA_ENT_PLATFORM_FU44, RT722_SDCA_CTL_FU_CH_GAIN,
		CH_R), 0x0000 },
	{ SDW_SDCA_CTL(FUNC_NUM_MIC_ARRAY, RT722_SDCA_ENT_FU15, RT722_SDCA_CTL_FU_CH_GAIN, CH_01),
		0x0000 },
	{ SDW_SDCA_CTL(FUNC_NUM_MIC_ARRAY, RT722_SDCA_ENT_FU15, RT722_SDCA_CTL_FU_CH_GAIN, CH_02),
		0x0000 },
	{ SDW_SDCA_CTL(FUNC_NUM_MIC_ARRAY, RT722_SDCA_ENT_FU15, RT722_SDCA_CTL_FU_CH_GAIN, CH_03),
		0x0000 },
	{ SDW_SDCA_CTL(FUNC_NUM_MIC_ARRAY, RT722_SDCA_ENT_FU15, RT722_SDCA_CTL_FU_CH_GAIN, CH_04),
		0x0000 },
	{ SDW_SDCA_CTL(FUNC_NUM_MIC_ARRAY, RT722_SDCA_ENT_USER_FU1E, RT722_SDCA_CTL_FU_MUTE, CH_01),
		0x01 },
	{ SDW_SDCA_CTL(FUNC_NUM_MIC_ARRAY, RT722_SDCA_ENT_USER_FU1E, RT722_SDCA_CTL_FU_MUTE, CH_02),
		0x01 },
	{ SDW_SDCA_CTL(FUNC_NUM_MIC_ARRAY, RT722_SDCA_ENT_USER_FU1E, RT722_SDCA_CTL_FU_MUTE, CH_03),
		0x01 },
	{ SDW_SDCA_CTL(FUNC_NUM_MIC_ARRAY, RT722_SDCA_ENT_USER_FU1E, RT722_SDCA_CTL_FU_MUTE, CH_04),
		0x01 },
	{ SDW_SDCA_CTL(FUNC_NUM_MIC_ARRAY, RT722_SDCA_ENT_USER_FU1E, RT722_SDCA_CTL_FU_VOLUME,
		CH_01), 0x0000 },
	{ SDW_SDCA_CTL(FUNC_NUM_MIC_ARRAY, RT722_SDCA_ENT_USER_FU1E, RT722_SDCA_CTL_FU_VOLUME,
		CH_02), 0x0000 },
	{ SDW_SDCA_CTL(FUNC_NUM_MIC_ARRAY, RT722_SDCA_ENT_USER_FU1E, RT722_SDCA_CTL_FU_VOLUME,
		CH_03), 0x0000 },
	{ SDW_SDCA_CTL(FUNC_NUM_MIC_ARRAY, RT722_SDCA_ENT_USER_FU1E, RT722_SDCA_CTL_FU_VOLUME,
		CH_04), 0x0000 },
	{ SDW_SDCA_CTL(FUNC_NUM_MIC_ARRAY, RT722_SDCA_ENT_PDE2A, RT722_SDCA_CTL_REQ_POWER_STATE, 0),
		0x03 },
	{ SDW_SDCA_CTL(FUNC_NUM_MIC_ARRAY, RT722_SDCA_ENT_CS1F, RT722_SDCA_CTL_SAMPLE_FREQ_INDEX,
		0), 0x09 },
	{ SDW_SDCA_CTL(FUNC_NUM_MIC_ARRAY, RT722_SDCA_ENT_IT26, RT722_SDCA_CTL_VENDOR_DEF, 0),
		0x00 },
	{ SDW_SDCA_CTL(FUNC_NUM_AMP, RT722_SDCA_ENT_USER_FU06, RT722_SDCA_CTL_FU_MUTE, CH_L),
		0x01 },
	{ SDW_SDCA_CTL(FUNC_NUM_AMP, RT722_SDCA_ENT_USER_FU06, RT722_SDCA_CTL_FU_MUTE, CH_R),
		0x01 },
	{ SDW_SDCA_CTL(FUNC_NUM_AMP, RT722_SDCA_ENT_USER_FU06, RT722_SDCA_CTL_FU_VOLUME, CH_L),
		0x0000 },
	{ SDW_SDCA_CTL(FUNC_NUM_AMP, RT722_SDCA_ENT_USER_FU06, RT722_SDCA_CTL_FU_VOLUME, CH_R),
		0x0000 },
	{ SDW_SDCA_CTL(FUNC_NUM_AMP, RT722_SDCA_ENT_PDE23, RT722_SDCA_CTL_REQ_POWER_STATE, 0),
		0x03 },
	{ SDW_SDCA_CTL(FUNC_NUM_AMP, RT722_SDCA_ENT_CS31, RT722_SDCA_CTL_SAMPLE_FREQ_INDEX, 0),
		0x09 },
	{ SDW_SDCA_CTL(FUNC_NUM_AMP, RT722_SDCA_ENT_OT23, RT722_SDCA_CTL_VENDOR_DEF, 0), 0x00 },
};

#endif /* __RT722_SDW_H__ */
