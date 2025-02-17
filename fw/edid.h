#include "config.h"

char edid[129] = {
	0x00, // register number, not part of EDID
	0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, // fixed header (0-7)
	0x6a, 0x12, // manufacturer ID (8-9)
	0x01, 0x00, // product code (10-11)
	0x42, 0x4b, 0x1d, 0x00, // serial number (12-15)
	0x01, // week of manufacture (16)
	0x20, // year of manufacture (17)
	0x01, // EDID version (18)
	0x03, // EDID revision (19)
	0x85, // display parameter (20)
	(SCREEN_SIZE_X / 10), // horizontal screen size in cm (21)
	(SCREEN_SIZE_Y / 10), // vertical screen size in cm (22)
	0x78, // display gamma (23)
	0x06, // supported feature (24)
	0xee, 0x95, 0xa3, 0x54, 0x4c, 0x99, 0x26, 0x0f, 0x50, 0x54, // chromatic (25-34)
	0x00, 0x00, 0x00, // established timing (35-37)
	(SCREEN_HACT / 8 - 31), // X resolution (38)
	SCREEN_ASPECT, // aspect ratio and vertical frequency (39)
	0x01, 0x00, 0x01, 0x00, 0x01, 0x00, 0x01, 0x00, // standard timing
	0x01, 0x00, 0x01, 0x00, 0x01, 0x00, // standard timing continued
	// descriptor 1 (54-71)
	((SCREEN_CLK / 10) & 0xff), ((SCREEN_CLK / 10) >> 8), // pixel clock in 10kHz
	(SCREEN_HACT & 0xff), // HACT LSB
	(SCREEN_HBLK & 0xff), // VBLK LSB
	(((SCREEN_HACT >> 8) << 4) | (SCREEN_HBLK >> 8)), // HACT MSB | HBLK MSB
	(SCREEN_VACT & 0xff), // VACT LSB
	(SCREEN_VBLK & 0xff), // VBLK LSB
	(((SCREEN_VACT >> 8) << 4) | (SCREEN_VBLK >> 8)), // VACT MSB | VBLK MSB
	(SCREEN_HFP & 0xff), // HFP LSB
	(SCREEN_HSYNC & 0xff), // HSYNC LSB
	(((SCREEN_VFP & 0xf) << 4) | (SCREEN_VSYNC & 0xf)), // VFP LSB | VSYNC LSB
	(((SCREEN_HFP >> 8) << 6) | ((SCREEN_HSYNC >> 8) << 4) |
		((SCREEN_VFP >> 4) << 2) | (SCREEN_VSYNC >> 4)), // HFP MSB | HSYNC MSB | VFP MSB | VSYNC MSB
	(SCREEN_SIZE_X & 0xff), // Horizontal size in mm LSB
	(SCREEN_SIZE_Y & 0xff), // Vertical size in mm LSB
	(((SCREEN_SIZE_X >> 8) << 4) | (SCREEN_SIZE_Y >> 8)), // HSIZE MSB | VSIZE LSB
	0x00, // Horizontal border pixels
	0x00, // Vertical border lines 0x1e,
	// descriptor 2 (72-89) display name
	0x00, 0x00, 0x00, 0xfc, 0x00, 0x50, 0x61, 0x70, 0x65, 0x72, 0x20,
	0x4d, 0x6f, 0x6e, 0x69, 0x74, 0x6f, 0x72,
	// descriptor 3 (90-107) display name
	0x00, 0x00, 0x00, 0xfc, 0x00, 0x0a, 0x20, 0x20, 0x20, 0x20, 0x20,
	0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20,
	// descriptor 4 (108-125) dummy
	0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, // number of extensions (126)
	0x00 // checksum (127)
};
