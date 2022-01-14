#ifndef __GC2235_H__
#define __GC2235_H__

#if defined(CONFIG_CPU_LC1813)
static struct v4l2_isp_parm gc2235_isp_parm = {
	.max_gain = 0x60,
	.min_gain = 0x10,
	.min_exposure = 0x03,
	.default_snapshot_exposure_ratio = 0x00b0,
	.default_preview_exposure_ratio = 0x0173,
	.sensor_vendor = SENSOR_VENDOR_GALAXYCORE,
	.sensor_main_type = GC_2235,
	.down_frm_small_thres = 50,
	.down_frm_large_thres = 25,
	.up_frm_small_thres = 100,
	.up_frm_large_thres = 120,
	.use_dynfrm_algo = 0,
};

static const struct v4l2_isp_regval gc2235_isp_setting[] = {
	{0x60100, 0x01},//Software reset
	{0x6301b, 0xf0},//isp clock enable
	{0x63025, 0x40},//clock divider

	{0x63c0a, 0x01},
	{0x63c0b, 0x53},
	{0x63c0c, 0x02},

	/* L1813 performance setting */
	/* gc2235, 1600*1200 preview */

/* global reg */
	{0x6502b, 0x8a},//turn off bgrh dns, turn on jpeg ycbcr
	{0x65000, 0x2f},
	{0x65001, 0x2f},
	{0x65006, 0x03}, // sensor type

/* blc */
	{0x1c57c, 0x01},
	{0x1c57d, 0x40},
	{0x1c57e, 0x60},
	{0x1c57f, 0xff},//4 in 8bit
	{0x1c580, 0xff},//4 in 8bit

/* aecagc */
	{0x1c174, 0x01},
	{0x1c139, 0x01},
	{0x1c179, 0x00},

	/* dynamic frame rate */
	{0x1c13a, 0x01},// turn on
	{0x1c17b, 0x02},// minimum 10 fps

	/* aecagc sensor address */
	{0x1c528, 0x6c},
	{0x1c529, 0x6c},
	{0x1c52a, 0x09},
	{0x1c52b, 0x09},
	#if 0
	{0x1c52c, 0x35},
	{0x1c52d, 0x00},
	{0x1c52e, 0x35},
	{0x1c52f, 0x01},
	{0x1c530, 0x35},
	{0x1c531, 0x02},
	{0x1c534, 0x38},//vts 1
	{0x1c535, 0x0e},
	{0x1c536, 0x38},//vts 2
	{0x1c537, 0x0f},
	{0x1c538, 0x35},//gain1
	{0x1c539, 0x0a},
	{0x1c53a, 0x35},//gain2
	{0x1c53b, 0x0b},
	#endif
	{0x1c55c, 0xff},
	{0x1c55d, 0xff},
	{0x1c55e, 0xff},
	{0x1c560, 0xff},
	{0x1c561, 0xff},
	{0x1c562, 0xff},
	{0x1c563, 0xff},

	{0x1c146, 0x44},//ori0x30 low AE target
	{0x1c14a, 0x03},
	{0x1c14b, 0x0a},
	{0x1c14c, 0x08},//aec fast step//
	{0x1c14e, 0x04},//slow step
	{0x1c140, 0x01},//banding
	{0x1c13f, 0x02},
	#if 0
	{0x1c180, 0x0f},//60Hz banding step
	{0x1c181, 0x80},
	{0x1c182, 0x12},//50Hz banding step
	{0x1c183, 0x90},
	#endif
	{0x1c176, 0x04},//VTS
	{0x1c177, 0xe2},
	{0x1c150, 0x00},//max gain
	{0x1c151, 0x60},
	{0x1c154, 0x00},//min gain
	{0x1c155, 0x10},
	{0x1c158, 0x00},//max exposure
	{0x1c159, 0x00},
	{0x1c15a, 0x03},
	{0x1c15b, 0xb8},

	{0x1c15c, 0x00},//min expousre
	{0x1c15d, 0x00},
	{0x1c15e, 0x00},
	{0x1c15f, 0x02},
	{0x1c13e, 0x02},//real gain mode

	{0x66401, 0x00},
	{0x66402, 0x30},//StatWin_Left
	{0x66403, 0x00},
	{0x66404, 0x2c},//StatWin_Top
	{0x66405, 0x00},
	{0x66406, 0x30},//StatWin_Right
	{0x66407, 0x00},
	{0x66408, 0x30},//StatWin_Bottom
	{0x66409, 0x00},//definiton ofthe center 3x3 window
	{0x6640a, 0xfa},//nWin_Left = 250
	{0x6640d, 0x00},
	{0x6640e, 0xc8},//nWin_Top = 200
	{0x66411, 0x04},
	{0x66412, 0x4c},//nWin_Width = 1100
	{0x66415, 0x03},
	{0x66416, 0x20},//nWin_Height = 800
	{0x6642e, 0x01},//nWin_Weight_0 weight pass
	{0x6642f, 0x01},//nWin_Weight_1
	{0x66430, 0x01},//nWin_Weight_2
	{0x66431, 0x01},//nWin_Weight_3
	{0x66432, 0x02},//nWin_Weight_4
	{0x66433, 0x02},//nWin_Weight_5
	{0x66434, 0x02},//nWin_Weight_6
	{0x66435, 0x02},//nWin_Weight_7
	{0x66436, 0x03},//nWin_Weight_8
	{0x66437, 0x02},//nWin_Weight_9
	{0x66438, 0x02},//nWin_Weight_10
	{0x66439, 0x02},//nWin_Weight_11
	{0x6643a, 0x02},//nWin_Weight_12
	{0x6644e, 0x01},//nWin_Weight_Shift
	{0x6644f, 0x04},//black level
	{0x66450, 0xf8},//saturate level
	{0x6645b, 0x1a},//black weight1
	{0x6645d, 0x1a},//black weight2
	{0x66460, 0x04},//saturate per1
	{0x66464, 0x0a},//saturate per2
	{0x66467, 0x14},//saturate weight1
	{0x66469, 0x14},//saturate weight2
	//auto AE control

	{0x1c174, 0x00},

/*  auto level */
	{0x66f00, 0x01},
	{0x66f01, 0x00},
	{0x66f02, 0x40},//minlowlevel = 1.5 * blc
	{0x66f03, 0x00},
	{0x66f04, 0x60},//maxlowlevel
	{0x66f05, 0x0f},
	{0x66f06, 0xff},//high level = 255, disable high level

/* auto uv saturation */
	{0x1c4e8, 0x01},//Enable
	{0x1c4e9, 0x40},//0920
	{0x1c4ea, 0x60},//0920
	{0x1c4eb, 0x80},//value for low gain
	{0x1c4ec, 0x78},//value for high gain

/*  dpc  */
	{0x65409, 0x04},
	{0x6540a, 0x02},
	{0x6540b, 0x01},
	{0x6540c, 0x01},
	{0x6540d, 0x04},
	{0x6540e, 0x02},
	{0x6540f, 0x01},
	{0x65410, 0x01},

/* AF */
	{0x1cd0a, 0x00},

	{0x6502a, 0x2a},
	{0x66112, 0xC8},
	{0x66100, 0x04},    //AFHardwareControl
	{0x66104, 0x02},    //nX0
	{0x66105, 0x67},
	{0x66106, 0x01},    //nY0
	{0x66107, 0x92},
	{0x1ccfa, 0x01},    //nW0
	{0x1ccfb, 0xa4},
	{0x1ccfc, 0x01},    //nH0
	{0x1ccfd, 0xa4},

	{0x1c5b0, 0x00},    //nWinMode
	{0x1cca4, 0x00},    //OffsetInit
	{0x1cca5, 0xb4},
	{0x1cca6, 0x01},    //FullRange
	{0x1cca7, 0x5c},
	{0x1cca8, 0x00},    //AFCMinStep
	{0x1cca9, 0x0c},
	{0x1ccaa, 0x00},    //AFCCoarseStep
	{0x1ccab, 0x18},
	{0x1ccac, 0x00},    //AFCStartStep
	{0x1ccad, 0x0c},
	{0x1cd0b, 0x01},    //nAFMode
	{0x1ccae, 0x00},    //nFrameRate
	{0x1ccaf, 0x1e},
	{0x1ccb2, 0x00},    //nMotorResTime
	{0x1ccb3, 0x20},
	{0x1cdc6, 0x09},    //nFocusI2COption
	{0x1cdc7, 0x18},    //nFocusDeviceID
	{0x1cdc8, 0x30},    //pFocusMoveLensAddr_0
	{0x1cdc9, 0xec},
	{0x1cdca, 0x30},    //pFocusMoveLensAddr_1
	{0x1cdcb, 0xed},
	{0x1cddc, 0x01},    //nMotorDriveMode
	{0x1cddd, 0x00},    //bIfMotorCalibrate
	{0x1cd0e, 0x01},    //bIfPreMove
	{0x1cd05, 0x01},
	{0x1cd06, 0x01},


	{0x1cc92, 0x00},    //nT_Compare_1x
	{0x1cc93, 0x08},
	{0x1cc94, 0x00},    //nT_Compare_16x
	{0x1cc95, 0x0a},
	{0x1cc96, 0x00},    //nT_sad_1x
	{0x1cc97, 0x00},
	{0x1cc98, 0x00},    //nT_sad_16x
	{0x1cc99, 0x00},
	{0x1cc9a, 0x00},    //nT_pre_sad_1x
	{0x1cc9b, 0x06},
	{0x1cc9c, 0x00},    //nT_pre_sad_16x
	{0x1cc9d, 0x04},
	{0x1cc9e, 0x00},    //nT_hist_1x
	{0x1cc9f, 0x02},
	{0x1cca0, 0x00},    //nT_hist_16x
	{0x1cca1, 0x02},
	{0x1cca2, 0x00},    //nT_contrast_diff
	{0x1cca3, 0x08},

	{0x1cd08, 0x00},
	{0x1ccef, 0x00},
	{0x1cdde, 0x04},
	{0x1cdcc, 0x0f},
	{0x1cdcd, 0xff},
	{0x1cdd8, 0x20},
	{0x1cdd9, 0x20},
	{0x1cdda, 0x38},
	{0x1ccca, 0x58},
	{0x1ccb1, 0x02},
	{0x1cd05, 0x00},
	{0x1cd0d, 0x36},
	{0x1ccc9, 0x1f},
	{0x1cd0a, 0x01},

/* dns */
	/* raw dns */
	{0x6551a, 0x01},//G
	{0x6551b, 0x02},
	{0x6551c, 0x03},
	{0x6551d, 0x04},
	{0x6551e, 0x05},
	{0x6551f, 0x06},
	{0x65520, 0x07},

	{0x65522, 0x00},//RB
	{0x65523, 0x02},
	{0x65524, 0x00},
	{0x65525, 0x04},
	{0x65526, 0x00},
	{0x65527, 0x06},
	{0x65528, 0x00},
	{0x65529, 0x08},
	{0x6552a, 0x00},
	{0x6552b, 0x0a},
	{0x6552c, 0x00},
	{0x6552d, 0x0c},
	{0x6552e, 0x00},
	{0x6552f, 0x0e},

	///* rgbh dns */
	//{0x66700, 0x01}//y
	//{0x66701, 0x02}
	//{0x66702, 0x03}
	//{0x66703, 0x04}
	//{0x66704, 0x05}
	//{0x66705, 0x06}
	//{0x66706, 0x07}
	//{0x66707, 0x08}
	//{0x66708, 0x02}//uv
	//{0x66709, 0x03}
	//{0x6670a, 0x04}
	//{0x6670b, 0x05}
	//{0x6670c, 0x06}
	//{0x6670d, 0x07}
	//{0x6670e, 0x08}
	//{0x6670f, 0x09}
	//{0x66710, 0x00}//shadow off
	//{0x66722, 0x01}//smooth y enable

	/* uv dns */
	{0x65c00, 0x02},
	{0x65c00, 0x04},
	{0x65c00, 0x08},
	{0x65c00, 0x10},
	{0x65c00, 0x1f},
	{0x65c00, 0x1f},

/* edge sharpen */
	{0x65600, 0x00},
	{0x65601, 0x40},//gain threshold low
	{0x65602, 0x00},
	{0x65603, 0x60},//gain threshold high
	{0x6560c, 0x02},//high gain sharpen strength
	{0x6560d, 0x18},//low gain sharpen strength

/* gamma correction */
	{0x67200, 0x00},
	{0x67201, 0x25},
	{0x67202, 0x00},
	{0x67203, 0x52},
	{0x67204, 0x00},
	{0x67205, 0xa2},
	{0x67206, 0x00},
	{0x67207, 0xf1},
	{0x67208, 0x01},
	{0x67209, 0x46},
	{0x6720a, 0x01},
	{0x6720b, 0x99},
	{0x6720c, 0x01},
	{0x6720d, 0xe0},
	{0x6720e, 0x02},
	{0x6720f, 0x1c},
	{0x67210, 0x02},
	{0x67211, 0x54},
	{0x67212, 0x02},
	{0x67213, 0x82},
	{0x67214, 0x02},
	{0x67215, 0xad},
	{0x67216, 0x02},
	{0x67217, 0xd0},
	{0x67218, 0x02},
	{0x67219, 0xee},
	{0x6721a, 0x03},
	{0x6721b, 0x09},
	{0x6721c, 0x03},
	{0x6721d, 0x23},
	{0x6721e, 0x03},
	{0x6721f, 0x3b},
	{0x67220, 0x03},
	{0x67221, 0x50},
	{0x67222, 0x03},
	{0x67223, 0x62},
	{0x67224, 0x03},
	{0x67225, 0x72},
	{0x67226, 0x03},
	{0x67227, 0x81},
	{0x67228, 0x03},
	{0x67229, 0x8f},
	{0x6722a, 0x03},
	{0x6722b, 0x9c},
	{0x6722c, 0x03},
	{0x6722d, 0xa8},
	{0x6722e, 0x03},
	{0x6722f, 0xb3},
	{0x67230, 0x03},
	{0x67231, 0xbe},
	{0x67232, 0x03},
	{0x67233, 0xc8},
	{0x67234, 0x03},
	{0x67235, 0xd2},
	{0x67236, 0x03},
	{0x67237, 0xdb},
	{0x67238, 0x03},
	{0x67239, 0xe3},
	{0x6723a, 0x03},
	{0x6723b, 0xeb},
	{0x6723c, 0x03},
	{0x6723d, 0xf2},
	{0x6723e, 0x03},
	{0x6723f, 0xf9},
	{0x67240, 0x03},
	{0x67241, 0xff},

/* LENC */
	{0x1c247, 0x02},//3 profile
	{0x1c24c, 0x00},
	{0x1c24d, 0x40},
	{0x1c24e, 0x00},
	{0x1c24f, 0x80},
	{0x1c248, 0x40},
	{0x1c24a, 0x20},
	{0x1c574, 0x00},
	{0x1c575, 0x20},
	{0x1c576, 0x00},
	{0x1c577, 0xf0},
	{0x1c578, 0x40},

	{0x65200, 0x0d},
	{0x65206, 0x3c},
	{0x65207, 0x04},
	{0x65208, 0x3e},
	{0x65209, 0x02},
	{0x6520a, 0x36},
	{0x6520b, 0x0c},
	{0x65214, 0x28},
	{0x65216, 0x20},

    /* OVISP LENC setting for A light Long Exposure (HDR/3D) */
	{0x1c310, 0x2e},
	{0x1c311, 0x19},
	{0x1c312, 0x15},
	{0x1c313, 0x14},
	{0x1c314, 0x1b},
	{0x1c315, 0x34},
	{0x1c316, 0x10},
	{0x1c317, 0x0a},
	{0x1c318, 0x07},
	{0x1c319, 0x07},
	{0x1c31a, 0x0a},
	{0x1c31b, 0x0f},
	{0x1c31c, 0x0b},
	{0x1c31d, 0x04},
	{0x1c31e, 0x00},
	{0x1c31f, 0x00},
	{0x1c320, 0x04},
	{0x1c321, 0x0a},
	{0x1c322, 0x0b},
	{0x1c323, 0x03},
	{0x1c324, 0x00},
	{0x1c325, 0x00},
	{0x1c326, 0x03},
	{0x1c327, 0x0a},
	{0x1c328, 0x0f},
	{0x1c329, 0x09},
	{0x1c32a, 0x06},
	{0x1c32b, 0x06},
	{0x1c32c, 0x09},
	{0x1c32d, 0x0e},
	{0x1c32e, 0x23},
	{0x1c32f, 0x16},
	{0x1c330, 0x13},
	{0x1c331, 0x13},
	{0x1c332, 0x17},
	{0x1c333, 0x28},
	{0x1c334, 0x23},
	{0x1c335, 0x20},
	{0x1c336, 0x1e},
	{0x1c337, 0x1f},
	{0x1c338, 0x26},
	{0x1c339, 0x1d},
	{0x1c33a, 0x1e},
	{0x1c33b, 0x1f},
	{0x1c33c, 0x1e},
	{0x1c33d, 0x1d},
	{0x1c33e, 0x1f},
	{0x1c33f, 0x21},
	{0x1c340, 0x21},
	{0x1c341, 0x20},
	{0x1c342, 0x1e},
	{0x1c343, 0x1c},
	{0x1c344, 0x1f},
	{0x1c345, 0x20},
	{0x1c346, 0x1f},
	{0x1c347, 0x1d},
	{0x1c348, 0x24},
	{0x1c349, 0x1d},
	{0x1c34a, 0x1d},
	{0x1c34b, 0x1f},
	{0x1c34c, 0x1f},
	{0x1c34d, 0x2a},
	{0x1c34e, 0x2c},
	{0x1c34f, 0x2c},
	{0x1c350, 0x2a},
	{0x1c351, 0x28},
	{0x1c352, 0x2a},
	{0x1c353, 0x27},
	{0x1c354, 0x25},
	{0x1c355, 0x27},
	{0x1c356, 0x2b},
	{0x1c357, 0x2a},
	{0x1c358, 0x21},
	{0x1c359, 0x1d},
	{0x1c35a, 0x21},
	{0x1c35b, 0x2a},
	{0x1c35c, 0x2a},
	{0x1c35d, 0x26},
	{0x1c35e, 0x24},
	{0x1c35f, 0x26},
	{0x1c360, 0x2c},
	{0x1c361, 0x2a},
	{0x1c362, 0x2a},
	{0x1c363, 0x2d},
	{0x1c364, 0x2b},
	{0x1c365, 0x27},

	/* OVISP LENC setting for CWF light Long Exposure (HDR/3D) */
	{0x1c2ba, 0x2c},
	{0x1c2bb, 0x17},
	{0x1c2bc, 0x13},
	{0x1c2bd, 0x13},
	{0x1c2be, 0x19},
	{0x1c2bf, 0x30},
	{0x1c2c0, 0x0f},
	{0x1c2c1, 0x09},
	{0x1c2c2, 0x06},
	{0x1c2c3, 0x06},
	{0x1c2c4, 0x09},
	{0x1c2c5, 0x0e},
	{0x1c2c6, 0x0a},
	{0x1c2c7, 0x03},
	{0x1c2c8, 0x00},
	{0x1c2c9, 0x00},
	{0x1c2ca, 0x03},
	{0x1c2cb, 0x09},
	{0x1c2cc, 0x0a},
	{0x1c2cd, 0x03},
	{0x1c2ce, 0x00},
	{0x1c2cf, 0x00},
	{0x1c2d0, 0x03},
	{0x1c2d1, 0x09},
	{0x1c2d2, 0x0e},
	{0x1c2d3, 0x08},
	{0x1c2d4, 0x05},
	{0x1c2d5, 0x05},
	{0x1c2d6, 0x08},
	{0x1c2d7, 0x0d},
	{0x1c2d8, 0x21},
	{0x1c2d9, 0x15},
	{0x1c2da, 0x12},
	{0x1c2db, 0x11},
	{0x1c2dc, 0x15},
	{0x1c2dd, 0x25},
	{0x1c2de, 0x1f},
	{0x1c2df, 0x1f},
	{0x1c2e0, 0x1e},
	{0x1c2e1, 0x1e},
	{0x1c2e2, 0x23},
	{0x1c2e3, 0x1d},
	{0x1c2e4, 0x1d},
	{0x1c2e5, 0x1f},
	{0x1c2e6, 0x1e},
	{0x1c2e7, 0x1d},
	{0x1c2e8, 0x1d},
	{0x1c2e9, 0x20},
	{0x1c2ea, 0x21},
	{0x1c2eb, 0x20},
	{0x1c2ec, 0x1c},
	{0x1c2ed, 0x1d},
	{0x1c2ee, 0x1f},
	{0x1c2ef, 0x20},
	{0x1c2f0, 0x1e},
	{0x1c2f1, 0x1d},
	{0x1c2f2, 0x21},
	{0x1c2f3, 0x1d},
	{0x1c2f4, 0x1d},
	{0x1c2f5, 0x20},
	{0x1c2f6, 0x1d},
	{0x1c2f7, 0x27},
	{0x1c2f8, 0x26},
	{0x1c2f9, 0x24},
	{0x1c2fa, 0x24},
	{0x1c2fb, 0x25},
	{0x1c2fc, 0x23},
	{0x1c2fd, 0x22},
	{0x1c2fe, 0x21},
	{0x1c2ff, 0x22},
	{0x1c300, 0x24},
	{0x1c301, 0x24},
	{0x1c302, 0x20},
	{0x1c303, 0x1f},
	{0x1c304, 0x20},
	{0x1c305, 0x24},
	{0x1c306, 0x23},
	{0x1c307, 0x22},
	{0x1c308, 0x21},
	{0x1c309, 0x22},
	{0x1c30a, 0x25},
	{0x1c30b, 0x27},
	{0x1c30c, 0x23},
	{0x1c30d, 0x24},
	{0x1c30e, 0x24},
	{0x1c30f, 0x24},

	/* OVISP LENC setting for DAY light Long Exposure (HDR/3D) */
	{0x1c264, 0x2d},
	{0x1c265, 0x17},
	{0x1c266, 0x14},
	{0x1c267, 0x13},
	{0x1c268, 0x1a},
	{0x1c269, 0x32},
	{0x1c26a, 0x0f},
	{0x1c26b, 0x09},
	{0x1c26c, 0x06},
	{0x1c26d, 0x06},
	{0x1c26e, 0x09},
	{0x1c26f, 0x0e},
	{0x1c270, 0x0a},
	{0x1c271, 0x04},
	{0x1c272, 0x00},
	{0x1c273, 0x00},
	{0x1c274, 0x04},
	{0x1c275, 0x09},
	{0x1c276, 0x0a},
	{0x1c277, 0x03},
	{0x1c278, 0x00},
	{0x1c279, 0x00},
	{0x1c27a, 0x03},
	{0x1c27b, 0x09},
	{0x1c27c, 0x0e},
	{0x1c27d, 0x09},
	{0x1c27e, 0x05},
	{0x1c27f, 0x05},
	{0x1c280, 0x08},
	{0x1c281, 0x0d},
	{0x1c282, 0x21},
	{0x1c283, 0x15},
	{0x1c284, 0x12},
	{0x1c285, 0x11},
	{0x1c286, 0x15},
	{0x1c287, 0x25},
	{0x1c288, 0x1c},
	{0x1c289, 0x1f},
	{0x1c28a, 0x1d},
	{0x1c28b, 0x1e},
	{0x1c28c, 0x21},
	{0x1c28d, 0x1e},
	{0x1c28e, 0x1e},
	{0x1c28f, 0x1f},
	{0x1c290, 0x1e},
	{0x1c291, 0x1e},
	{0x1c292, 0x1e},
	{0x1c293, 0x20},
	{0x1c294, 0x20},
	{0x1c295, 0x20},
	{0x1c296, 0x1e},
	{0x1c297, 0x1e},
	{0x1c298, 0x1f},
	{0x1c299, 0x20},
	{0x1c29a, 0x1f},
	{0x1c29b, 0x1e},
	{0x1c29c, 0x22},
	{0x1c29d, 0x1e},
	{0x1c29e, 0x1e},
	{0x1c29f, 0x1f},
	{0x1c2a0, 0x1f},
	{0x1c2a1, 0x28},
	{0x1c2a2, 0x29},
	{0x1c2a3, 0x28},
	{0x1c2a4, 0x27},
	{0x1c2a5, 0x27},
	{0x1c2a6, 0x26},
	{0x1c2a7, 0x24},
	{0x1c2a8, 0x23},
	{0x1c2a9, 0x24},
	{0x1c2aa, 0x27},
	{0x1c2ab, 0x26},
	{0x1c2ac, 0x21},
	{0x1c2ad, 0x1e},
	{0x1c2ae, 0x21},
	{0x1c2af, 0x26},
	{0x1c2b0, 0x25},
	{0x1c2b1, 0x24},
	{0x1c2b2, 0x22},
	{0x1c2b3, 0x23},
	{0x1c2b4, 0x27},
	{0x1c2b5, 0x28},
	{0x1c2b6, 0x26},
	{0x1c2b7, 0x28},
	{0x1c2b8, 0x27},
	{0x1c2b9, 0x25},

/* Color matrix calibrated with ovtisp ccm calibration tool final version */
	{0x1C1D8, 0x01},//center matrix,
	{0x1C1D9, 0x7c},
	{0x1C1DA, 0xFF},
	{0x1C1DB, 0x59},
	{0x1C1DC, 0x00},
	{0x1C1DD, 0x2B},
	{0x1C1DE, 0xFF},
	{0x1C1DF, 0x9F},
	{0x1C1E0, 0x01},
	{0x1C1E1, 0x8B},
	{0x1C1E2, 0xFF},
	{0x1C1E3, 0xd6},
	{0x1C1E4, 0xFF},
	{0x1C1E5, 0x78},
	{0x1C1E6, 0xFF},
	{0x1C1E7, 0x5C},
	{0x1C1E8, 0x02},
	{0x1C1E9, 0x2C},

	{0x1C1FC, 0xFF},//cmx left delta
	{0x1C1FD, 0xEC},
	{0x1C1FE, 0x00},
	{0x1C1FF, 0x27},
	{0x1C200, 0xFF},
	{0x1C201, 0xED},
	{0x1C202, 0x00},
	{0x1C203, 0x06},
	{0x1C204, 0xFF},
	{0x1C205, 0xE6},
	{0x1C206, 0x00},
	{0x1C207, 0x14},
	{0x1C208, 0x00},
	{0x1C209, 0x22},
	{0x1C20A, 0xFF},
	{0x1C20B, 0xFB},
	{0x1C20C, 0xFF},
	{0x1C20D, 0xE3},

	{0x1C220, 0x00},//cmx right delta
	{0x1C221, 0x3B},
	{0x1C222, 0x00},
	{0x1C223, 0x00},
	{0x1C224, 0xff},
	{0x1C225, 0xc5},
	{0x1C226, 0xFF},
	{0x1C227, 0xd1},
	{0x1C228, 0x00},
	{0x1C229, 0x30},
	{0x1C22A, 0xff},
	{0x1C22B, 0xff},
	{0x1C22C, 0xFF},
	{0x1C22D, 0xeC},
	{0x1C22E, 0x00},
	{0x1C22F, 0xaE},
	{0x1C230, 0xFF},
	{0x1C231, 0x66},

/* manual awb gain */
	{0x1c4f0, 0x00},//group 3 -- Daylight D50
	{0x1c4f1, 0xac},
	{0x1c4f2, 0x00},
	{0x1c4f3, 0x80},
	{0x1c4f4, 0x00},
	{0x1c4f5, 0xb1},

	{0x1c4f6, 0x00},//group 4 -- Daylight D65
	{0x1c4f7, 0x93},
	{0x1c4f8, 0x00},
	{0x1c4f9, 0x80},
	{0x1c4fa, 0x00},
	{0x1c4fb, 0xca},

	{0x1c4fc, 0x01},//group 5 -- Incandescent A
	{0x1c4fd, 0x20},
	{0x1c4fe, 0x00},
	{0x1c4ff, 0x87},
	{0x1c500, 0x00},
	{0x1c501, 0x80},

	{0x1c502, 0x00},//group 6 -- Fluorescent CWF
	{0x1c503, 0xfa},
	{0x1c504, 0x00},
	{0x1c505, 0x80},
	{0x1c506, 0x00},
	{0x1c507, 0xb6},

	{0x1c508, 0x00},//group 7 -- Fluorescent TL84
	{0x1c509, 0xe2},
	{0x1c50a, 0x00},
	{0x1c50b, 0x80},
	{0x1c50c, 0x00},
	{0x1c50d, 0x9b},

	{0x1c50e, 0x00},//group 8 -- Twilight(little bit warmer than D50)
	{0x1c50f, 0xa8},
	{0x1c510, 0x00},
	{0x1c511, 0x80},
	{0x1c512, 0x00},
	{0x1c513, 0xb5},

	{0x1c514, 0x00},//group 9 -- Shading (D75)
	{0x1c515, 0x86},
	{0x1c516, 0x00},
	{0x1c517, 0x80},
	{0x1c518, 0x00},
	{0x1c519, 0xd1},

/* awb */
	{0x1c1c8, 0x01},
	{0x1c1c9, 0x6a},
	{0x1c1cc, 0x00},
	{0x1c1cd, 0xba},
	{0x1c1d0, 0x02},
	{0x1c1d1, 0x41},
	{0x1c254, 0x00},
	{0x1c255, 0xfc},
	{0x1c256, 0x01},
	{0x1c257, 0x1c},
	{0x1c258, 0x01},
	{0x1c259, 0xbb},
	{0x1c25a, 0x01},
	{0x1c25b, 0xfb},

	{0x1c190, 0x02},//curve awb
	{0x1d8c1, 0x02},//Curve AWB Options: bit0-Cut; bit1-Low light Cut; bit2~4-Extension;
	{0x1d8e8, 0x04},//0x01: Enable AWB Shift, 0x02: Enable Br Shift, 0x04: enable Multiple Map
	{0x1d8e0, 0x04},//min pixels
	{0x1d8e1, 0x00},
	{0x66285, 0x00},//min value
	{0x66286, 0x09},
	{0x66287, 0x03},//max value
	{0x66288, 0xe0},
	{0x1d914, 0x05},//D65 weight inside
	{0x1d915, 0x01},//CWF weight inside
	{0x1d916, 0x01},//a weight inside
	{0x1d917, 0x02},//D65 weight outside
	{0x1d918, 0x02},//CWF weight outside
	{0x1d919, 0x02},//a weight outside
	{0x1dbfc, 0x02},//map value 1
	{0x1dbfd, 0x03},//map value 2
	//cut region
	{0x1d90e, 0xa0},// TOR-Y
	{0x1d90f, 0x80},// TOR-X
	{0x1d910, 0x00},// Lowlight Gain Th
	{0x1d911, 0x60},// Lowlight Gain Th
	{0x1d8d9, 0xa0},// Lowlight-TOR-Y
	{0x1d8da, 0x80},// Lowlight-TOR-X
	{0x1dbf8, 0x20},//x low bound
	{0x1dbf9, 0xb0},//x high bound
	{0x1dbfa, 0x20},//y high bound
	{0x1dbfb, 0xd0},//y high bound
	//dynamic map
	{0x1d8db, 0x20},//nCurveAWBBrRatio
	{0x1d8dc, 0x00},// nCurveAWBBrThres0
	{0x1d8dd, 0x08},
	{0x1d8e6, 0x00},// nCurveAWBBrThres1
	{0x1d8e7, 0x34},

	//X_OFF
	{0x66280, 0xfe},
	{0x66281, 0x17},
	//Y_OFF
	{0x66282, 0xfd},
	{0x66283, 0xf9},
	//KX
	{0x1d8e2, 0x00},
	{0x1d8e3, 0x24},
	//KY
	{0x1d8e4, 0x00},
	{0x1d8e5, 0x14},
	//LowMap
	{0x1d800, 0x00},
	{0x1d801, 0x00},
	{0x1d802, 0x00},
	{0x1d803, 0x00},
	{0x1d804, 0x00},
	{0x1d805, 0x00},
	{0x1d806, 0x00},
	{0x1d807, 0x00},
	{0x1d808, 0x00},
	{0x1d809, 0x00},
	{0x1d80a, 0x11},
	{0x1d80b, 0x11},
	{0x1d80c, 0x11},
	{0x1d80d, 0x01},
	{0x1d80e, 0x00},
	{0x1d80f, 0x00},
	{0x1d810, 0x00},
	{0x1d811, 0x11},
	{0x1d812, 0x21},
	{0x1d813, 0x22},
	{0x1d814, 0x22},
	{0x1d815, 0x01},
	{0x1d816, 0x00},
	{0x1d817, 0x00},
	{0x1d818, 0x00},
	{0x1d819, 0x21},
	{0x1d81a, 0x22},
	{0x1d81b, 0x22},
	{0x1d81c, 0x22},
	{0x1d81d, 0x01},
	{0x1d81e, 0x00},
	{0x1d81f, 0x00},
	{0x1d820, 0x00},
	{0x1d821, 0x21},
	{0x1d822, 0x22},
	{0x1d823, 0x22},
	{0x1d824, 0x22},
	{0x1d825, 0x01},
	{0x1d826, 0x00},
	{0x1d827, 0x00},
	{0x1d828, 0x10},
	{0x1d829, 0x21},
	{0x1d82a, 0x22},
	{0x1d82b, 0x22},
	{0x1d82c, 0x22},
	{0x1d82d, 0x00},
	{0x1d82e, 0x00},
	{0x1d82f, 0x00},
	{0x1d830, 0x20},
	{0x1d831, 0x33},
	{0x1d832, 0x33},
	{0x1d833, 0x33},
	{0x1d834, 0x23},
	{0x1d835, 0x00},
	{0x1d836, 0x00},
	{0x1d837, 0x00},
	{0x1d838, 0x20},
	{0x1d839, 0x33},
	{0x1d83a, 0x33},
	{0x1d83b, 0x33},
	{0x1d83c, 0x23},
	{0x1d83d, 0x00},
	{0x1d83e, 0x00},
	{0x1d83f, 0x00},
	{0x1d840, 0x20},
	{0x1d841, 0x33},
	{0x1d842, 0x33},
	{0x1d843, 0x33},
	{0x1d844, 0x23},
	{0x1d845, 0x00},
	{0x1d846, 0x00},
	{0x1d847, 0x00},
	{0x1d848, 0x20},
	{0x1d849, 0x33},
	{0x1d84a, 0x33},
	{0x1d84b, 0xff},
	{0x1d84c, 0x5f},
	{0x1d84d, 0x55},
	{0x1d84e, 0x05},
	{0x1d84f, 0x00},
	{0x1d850, 0x20},
	{0x1d851, 0x55},
	{0x1d852, 0x55},
	{0x1d853, 0xf5},
	{0x1d854, 0xff},
	{0x1d855, 0xff},
	{0x1d856, 0x05},
	{0x1d857, 0x00},
	{0x1d858, 0x00},
	{0x1d859, 0x00},
	{0x1d85a, 0x00},
	{0x1d85b, 0xf5},
	{0x1d85c, 0xff},
	{0x1d85d, 0xff},
	{0x1d85e, 0x05},
	{0x1d85f, 0x00},
	{0x1d860, 0x00},
	{0x1d861, 0x00},
	{0x1d862, 0x00},
	{0x1d863, 0xf5},
	{0x1d864, 0xff},
	{0x1d865, 0xff},
	{0x1d866, 0x05},
	{0x1d867, 0x00},
	{0x1d868, 0x00},
	{0x1d869, 0x00},
	{0x1d86a, 0x00},
	{0x1d86b, 0x55},
	{0x1d86c, 0xff},
	{0x1d86d, 0xff},
	{0x1d86e, 0x05},
	{0x1d86f, 0x00},
	{0x1d870, 0x00},
	{0x1d871, 0x00},
	{0x1d872, 0x00},
	{0x1d873, 0x50},
	{0x1d874, 0x55},
	{0x1d875, 0x55},
	{0x1d876, 0x05},
	{0x1d877, 0x00},
	{0x1d878, 0x00},
	{0x1d879, 0x00},
	{0x1d87a, 0x00},
	{0x1d87b, 0x00},
	{0x1d87c, 0x00},
	{0x1d87d, 0x00},
	{0x1d87e, 0x00},
	{0x1d87f, 0x00},
	//MiddleMask
	{0x1d880, 0x00},
	{0x1d881, 0x00},
	{0x1d882, 0x00},
	{0x1d883, 0x00},
	{0x1d884, 0x00},
	{0x1d885, 0x00},
	{0x1d886, 0xc0},
	{0x1d887, 0x01},
	{0x1d888, 0xc0},
	{0x1d889, 0x01},
	{0x1d88a, 0xc0},
	{0x1d88b, 0x07},
	{0x1d88c, 0xc0},
	{0x1d88d, 0x07},
	{0x1d88e, 0x80},
	{0x1d88f, 0x07},
	{0x1d890, 0x80},
	{0x1d891, 0x07},
	{0x1d892, 0x80},
	{0x1d893, 0x07},
	{0x1d894, 0x80},
	{0x1d895, 0x0f},
	{0x1d896, 0x80},
	{0x1d897, 0x0f},
	{0x1d898, 0x80},
	{0x1d899, 0x1f},
	{0x1d89a, 0x00},
	{0x1d89b, 0x1f},
	{0x1d89c, 0x00},
	{0x1d89d, 0x0c},
	{0x1d89e, 0x00},
	{0x1d89f, 0x00},
	//HighMask
	{0x1d8a0, 0x00},
	{0x1d8a1, 0x00},
	{0x1d8a2, 0x00},
	{0x1d8a3, 0x00},
	{0x1d8a4, 0x00},
	{0x1d8a5, 0x00},
	{0x1d8a6, 0xc0},
	{0x1d8a7, 0x01},
	{0x1d8a8, 0xc0},
	{0x1d8a9, 0x01},
	{0x1d8aa, 0xc0},
	{0x1d8ab, 0x01},
	{0x1d8ac, 0x80},
	{0x1d8ad, 0x03},
	{0x1d8ae, 0x80},
	{0x1d8af, 0x03},
	{0x1d8b0, 0x80},
	{0x1d8b1, 0x07},
	{0x1d8b2, 0x80},
	{0x1d8b3, 0x07},
	{0x1d8b4, 0x80},
	{0x1d8b5, 0x0f},
	{0x1d8b6, 0x80},
	{0x1d8b7, 0x0f},
	{0x1d8b8, 0x80},
	{0x1d8b9, 0x0f},
	{0x1d8ba, 0x00},
	{0x1d8bb, 0x00},
	{0x1d8bc, 0x00},
	{0x1d8bd, 0x00},
	{0x1d8be, 0x00},
	{0x1d8bf, 0x00},
	//======for AWB shift======
	{0x1d8ed, 0x00},
	{0x1d8ee, 0x00},
	{0x1d8eb, 0x00},
	{0x1d8ec, 0x00},
	{0x1d8e9, 0x00},
	{0x1d8ea, 0x00},
	{0x1d8ef, 0x00},
	{0x1d8f0, 0x00},
	{0x1d8f8, 0x00},
	{0x1d8f9, 0x00},
	{0x1d8fe, 0x00},
	{0x1d8ff, 0x00},
	//====AWB shift End=======
};
#endif

#endif /* __GC2235_H__ */
