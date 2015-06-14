/*
 * Author: Floris Creyf
 * Date: May 2015
 * Tables for Huffman decoding, inverse quantization, the synthetic filter bank, etc.
 */

#ifndef TABLES_H
#define	TABLES_H

struct {
	const unsigned long_32[22] {
		4, 4, 4, 4, 4, 4, 6, 6, 8, 10, 12, 16, 20, 24, 30, 38, 46, 56, 68, 84, 102
	};
	const unsigned short_32[13] {
		4, 4, 4, 4, 6, 8, 12, 16, 20, 26, 34, 42
	};
	const unsigned long_44[22] {
		4, 4, 4, 4, 4, 4, 6, 6, 8, 8, 10, 12, 16, 20, 24, 28, 34, 42, 50, 54, 76
	};
	const unsigned short_44[13] {
		4, 4, 4, 4, 6, 8, 10, 12, 14, 18, 22, 30
	};
	const unsigned long_48[22] {
		4, 4, 4, 4, 4, 4, 6, 6, 6, 8, 10, 12, 16, 18, 22, 28, 34, 40, 46, 54, 54
	};
	const unsigned short_48[22] {
		4, 4, 4, 4, 6, 6, 10, 12, 14, 16, 20, 26
	};
} band_width_table;

struct {
	const unsigned long_32[23] {
		0, 4, 8, 12, 16, 20, 24, 30, 36, 44, 54, 66, 82, 
		102, 126, 156, 194, 240, 296, 364, 448, 550, 576
	};
	const unsigned short_32[14] {
		0, 4, 8, 12, 16, 22, 30, 42, 58, 78, 104, 138, 180, 192
	};
	const unsigned long_44[23] {
		0, 4, 8, 12, 16, 20, 24, 30, 36, 44, 52, 62, 74,
		90, 110, 134, 162, 196, 238, 288, 342, 418, 576
	};
	const unsigned short_44[14] {
		0, 4, 8, 12, 16, 22, 30, 40, 52, 66, 84, 106, 136, 192
	};
	const unsigned long_48[23] {
		0, 4, 8, 12, 16, 20, 24, 30, 36, 42, 50, 60, 72,
		88, 106, 128, 156, 190, 230, 276, 330, 384, 576
	};
	const unsigned short_48[14] {
		0, 4, 8, 12, 16, 22, 28, 38, 50, 64, 80, 100, 126, 192
	};
} band_index_table;

static const char slen[16][2] {
	{0, 0}, {0, 1}, {0, 2}, {0, 3}, {3, 0}, {1, 1}, {1, 2}, {1, 3}, 
	{2, 1}, {2, 2}, {2, 3}, {3, 1}, {3, 2}, {3, 3}, {4, 2}, {4, 3}
};

static const char pretab[21] {
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 2, 2, 3, 3, 3, 2
};

struct {
	const unsigned char value[16][4] {
		{0, 0, 0, 0}, {0, 0, 0, 1}, {0, 0, 1, 0}, {0, 0, 1, 1}, {0, 1, 0, 0}, {0, 1, 0, 1},
		{0, 1, 1, 0}, {0, 1, 1, 1}, {1, 0, 0, 0}, {1, 0, 0, 1}, {1, 0, 1, 0}, {1, 0, 1, 1},
		{1, 1, 0, 0}, {1, 1, 0, 1}, {1, 1, 1, 0}, {1, 1, 1, 1}
	};
	const unsigned char hlen[16] {1, 4, 4, 5, 4, 6, 5, 6, 4, 5, 5, 6, 5, 6, 6, 6};
	const unsigned hcod[16] {
		0x80000000, 0x50000000, 0x40000000, 0x28000000, 0x60000000, 0x14000000, 0x20000000, 0x10000000, 
		0x70000000, 0x18000000, 0x30000000, 0x0, 0x38000000, 0x8000000, 0xc000000, 0x4000000
	};
} quad_table_1;

/* The Huffman values are stored within INT types and are shifted towards the most 
significant bit. */
const unsigned hft_0[1][1][2] {
	{{0x0, 1}}
};
const unsigned hft_1[2][2][2] {
	{{0x80000000, 1}, {0x20000000, 3}}, {{0x40000000, 2}, {0x0, 3}}
};
const unsigned hft_2[3][3][2] {
	{{0x80000000, 1}, {0x40000000, 3}, {0x4000000, 6}}, {{0x60000000, 3}, 
	{0x20000000, 3}, {0x8000000, 5}}, {{0x18000000, 5}, {0x10000000, 5}, 
	{0x0, 6}}
};
const unsigned hft_3[3][3][2] {
	{{0xc0000000, 2}, {0x80000000, 2}, {0x4000000, 6}}, {{0x20000000, 3}, 
	{0x40000000, 2}, {0x8000000, 5}}, {{0x18000000, 5}, {0x10000000, 5}, 
	{0x0, 6}}
};
const unsigned hft_5[4][4][2] {
	{{0x80000000, 1}, {0x40000000, 3}, {0x18000000, 6}, {0xa000000, 7}},
	{{0x60000000, 3}, {0x20000000, 3}, {0x10000000, 6}, {0x8000000, 7}},
	{{0x1c000000, 6}, {0x14000000, 6}, {0xe000000, 7}, {0x1000000, 8}},
	{{0xc000000, 7}, {0x4000000, 6}, {0x2000000, 7}, {0x0, 8}}
}; 
const unsigned hft_6[4][4][2] {
	{{0xe0000000, 3}, {0x60000000, 3}, {0x28000000, 5}, {0x2000000, 7}},
	{{0xc0000000, 3}, {0x80000000, 2}, {0x30000000, 4}, {0x10000000, 5}},
	{{0x50000000, 4}, {0x40000000, 4}, {0x20000000, 5}, {0x4000000, 6}},
	{{0xc000000, 6}, {0x18000000, 5}, {0x8000000, 6}, {0x0, 7}}
};
const unsigned hft_7[6][6][2] {
	{{0x80000000, 1}, {0x40000000, 3}, {0x28000000, 6}, {0x13000000, 8}, 
	{0x10000000, 8}, {0x5000000, 9}}, {{0x60000000, 3}, {0x30000000, 4}, 
	{0x1c000000, 6}, {0x14000000, 7}, {0xa000000, 7}, {0x3000000, 8}},
	{{0x2c000000, 6}, {0x20000000, 5}, {0x1a000000, 7}, {0x11000000, 8}, 
	{0x8000000, 8}, {0x2000000, 9}}, {{0x18000000, 7}, {0x16000000, 7}, 
	{0x12000000, 8}, {0x7800000, 9}, {0x5800000, 9}, {0x1000000, 9}},
	{{0xe000000, 7}, {0xc000000, 7}, {0x9000000, 8}, {0x7000000, 9}, 
	{0x1800000, 9}, {0x400000, 10}}, {{0x6000000, 8}, {0x4000000, 8}, 
	{0x2800000, 9}, {0xc00000, 10}, {0x800000, 10}, {0x0, 10}}
};
const unsigned hft_8[6][6][2] {
	{{0xc0000000, 2}, {0x80000000, 3}, {0x18000000, 6}, {0x12000000, 8}, 
	{0xc000000, 8}, {0x2800000, 9}}, {{0xa0000000, 3}, {0x40000000, 2}, 
	{0x20000000, 4}, {0x10000000, 8}, {0x9000000, 8}, {0x3000000, 8}},
	{{0x1c000000, 6}, {0x30000000, 4}, {0x14000000, 6}, {0xe000000, 8}, 
	{0x7000000, 8}, {0x1800000, 9}}, {{0x13000000, 8}, {0x11000000, 8}, 
	{0xf000000, 8}, {0x6800000, 9}, {0x5000000, 9}, {0x1000000, 10}},
	{{0xd000000, 8}, {0xa000000, 7}, {0x8000000, 8}, {0x5800000, 9}, 
	{0x1400000, 10}, {0x400000, 10}}, {{0x6000000, 9}, {0x4000000, 8}, 
	{0x2000000, 9}, {0x800000, 9}, {0x200000, 11}, {0x0, 11}}
};
const unsigned hft_9[6][6][2] {
	{{0xe0000000, 3}, {0xa0000000, 3}, {0x48000000, 5}, {0x38000000, 6}, 
	{0xf000000, 8}, {0x3800000, 9}}, {{0xc0000000, 3}, {0x80000000, 3}, 
	{0x50000000, 4}, {0x28000000, 5}, {0x18000000, 6}, {0x7000000, 8}},
	{{0x70000000, 4}, {0x60000000, 4}, {0x40000000, 5}, {0x20000000, 6}, 
	{0x10000000, 7}, {0x5000000, 8}}, {{0x3c000000, 6}, {0x30000000, 5}, 
	{0x24000000, 6}, {0x14000000, 7}, {0xa000000, 7}, {0x1000000, 8}},
	{{0x16000000, 7}, {0x1c000000, 6}, {0x12000000, 7}, {0xc000000, 7}, 
	{0x4000000, 8}, {0x800000, 9}}, {{0xe000000, 8}, {0x8000000, 7}, 
	{0x6000000, 8}, {0x2000000, 8}, {0x3000000, 9}, {0x0, 9}}
};
const unsigned hft_10[8][8][2] {
	{{0x80000000, 1}, {0x40000000, 3}, {0x28000000, 6}, {0x17000000, 8}, 
	{0x11800000, 9}, {0xf000000, 9}, {0x6000000, 9}, {0x4400000, 10}},
	{{0x60000000, 3}, {0x30000000, 4}, {0x20000000, 6}, {0x18000000, 7}, 
	{0x12000000, 8}, {0xa800000, 9}, {0xc000000, 8}, {0x7000000, 8}},
	{{0x2c000000, 6}, {0x24000000, 6}, {0x1e000000, 7}, {0x15000000, 8}, 
	{0x10000000, 9}, {0xa000000, 10}, {0x9800000, 9}, {0x3000000, 9}},
	{{0x1c000000, 7}, {0x1a000000, 7}, {0x16000000, 8}, {0x11000000, 9}, 
	{0xb800000, 10}, {0x5c00000, 10}, {0x9000000, 9}, {0x1c00000, 10}},
	{{0x14000000, 8}, {0x13000000, 8}, {0x10800000, 9}, {0xbc00000, 10}, 
	{0x6c00000, 10}, {0x5800000, 10}, {0x2400000, 10}, {0xc00000, 10}},
	{{0xf800000, 9}, {0xb000000, 9}, {0xa400000, 10}, {0x6800000, 10}, 
	{0x2a00000, 11}, {0x2800000, 11}, {0x1400000, 10}, {0x600000, 11}},
	{{0xe000000, 8}, {0xd000000, 8}, {0x5000000, 9}, {0x2c00000, 10}, 
	{0x4000000, 10}, {0x1800000, 10}, {0xa00000, 11}, {0x200000, 11}},
	{{0x4800000, 9}, {0x8000000, 8}, {0x3800000, 9}, {0x2000000, 10}, 
	{0x1000000, 10}, {0x800000, 11}, {0x400000, 11}, {0x0, 11}}
};
const unsigned hft_11[8][8][2] {
	{{0xc0000000, 2}, {0x80000000, 3}, {0x50000000, 5}, {0x30000000, 7}, 
	{0x22000000, 8}, {0x10800000, 9}, {0x15000000, 8}, {0x7800000, 9}},
	{{0xa0000000, 3}, {0x60000000, 3}, {0x40000000, 4}, {0x28000000, 6}, 
	{0x20000000, 8}, {0x11000000, 8}, {0x16000000, 7}, {0xa000000, 8}},
	{{0x58000000, 5}, {0x38000000, 5}, {0x34000000, 6}, {0x24000000, 7}, 
	{0x1e000000, 8}, {0xf800000, 9}, {0x14000000, 8}, {0x5000000, 8}},
	{{0x32000000, 7}, {0x2c000000, 6}, {0x26000000, 7}, {0x1d800000, 9}, 
	{0x1b000000, 8}, {0x4800000, 10}, {0xc000000, 8}, {0x2800000, 9}},
	{{0x23000000, 8}, {0x21000000, 8}, {0x1f000000, 8}, {0x1d000000, 9}, 
	{0xf000000, 9}, {0x4000000, 10}, {0x3800000, 9}, {0x1400000, 10}},
	{{0x1c000000, 8}, {0x1a000000, 8}, {0x10000000, 9}, {0x4c00000, 10}, 
	{0x4400000, 10}, {0x1e00000, 11}, {0x2000000, 10}, {0x1c00000, 11}},
	{{0xe000000, 8}, {0x18000000, 7}, {0x12000000, 7}, {0xd000000, 8}, 
	{0x7000000, 9}, {0x2400000, 10}, {0x1000000, 10}, {0x400000, 10}},
	{{0xb000000, 8}, {0x8000000, 7}, {0x6000000, 8}, {0x3000000, 9}, 
	{0x1800000, 10}, {0xc00000, 10}, {0x800000, 10}, {0x0, 10}}
};
const unsigned hft_12[8][8][2] {
	{{0x90000000, 4}, {0xc0000000, 3}, {0x80000000, 5}, {0x42000000, 7},
	{0x29000000, 8}, {0x13800000, 9}, {0x13000000, 9}, {0xd000000, 9}},
	{{0xe0000000, 3}, {0xa0000000, 3}, {0x60000000, 4}, {0x48000000, 5},
	{0x2e000000, 7}, {0x20000000, 7}, {0x1a000000, 8}, {0xb000000, 8}},
	{{0x88000000, 5}, {0x70000000, 4}, {0x58000000, 5}, {0x38000000, 6},
	{0x2a000000, 7}, {0x1e000000, 8}, {0x14000000, 7}, {0x7000000, 8}},
	{{0x44000000, 6}, {0x50000000, 5}, {0x3c000000, 6}, {0x30000000, 6},
	{0x24000000, 7}, {0x1c000000, 8}, {0xe000000, 8}, {0x5000000, 8}},
	{{0x40000000, 7}, {0x34000000, 6}, {0x2c000000, 7}, {0x26000000, 7},
	{0x12000000, 8}, {0x10000000, 8}, {0x9000000, 8}, {0x2800000, 9}},
	{{0x28000000, 8}, {0x22000000, 7}, {0x1f000000, 8}, {0x1d000000, 8},
	{0x11000000, 8}, {0x6800000, 9}, {0x4000000, 8}, {0x1000000, 9}},
	{{0x1b000000, 8}, {0x18000000, 7}, {0x16000000, 7}, {0xf000000, 8},
	{0xa000000, 8}, {0x3800000, 9}, {0x2000000, 9}, {0x400000, 10}},
	{{0xd800000, 9}, {0xc000000, 8}, {0x8000000, 8}, {0x6000000, 9},
	{0x3000000, 9}, {0x1800000, 9}, {0x800000, 9}, {0x0, 10}}
};
const unsigned hft_13[16][16][2] {
	{{0x80000000, 1}, {0x50000000, 4}, {0x38000000, 6}, {0x2a000000, 7}, 
	{0x22000000, 8}, {0x19800000, 9}, {0x17000000, 9}, {0x11c00000, 10}, 
	{0x15000000, 9}, {0xd000000, 10}, {0x8800000, 11}, {0x6800000, 11}, 
	{0x4300000, 12}, {0x2c00000, 12}, {0x1580000, 13}, {0x980000, 13}},
	{{0x60000000, 3}, {0x40000000, 4}, {0x30000000, 6}, {0x26000000, 7}, 
	{0x1f000000, 8}, {0x1a000000, 8}, {0x16000000, 9}, {0x10800000, 9}, 
	{0xf800000, 9}, {0xc000000, 9}, {0x8000000, 10}, {0x6000000, 10}, 
	{0x3e00000, 11}, {0x2300000, 12}, {0x1600000, 12}, {0xe00000, 12}},
	{{0x3c000000, 6}, {0x34000000, 6}, {0x2e000000, 7}, {0x24000000, 8}, 
	{0x1d800000, 9}, {0x18800000, 9}, {0x13400000, 10}, {0x10400000, 10}, 
	{0xe800000, 9}, {0xa000000, 10}, {0x7800000, 10}, {0x5000000, 11}, 
	{0x3600000, 11}, {0x2100000, 12}, {0x1500000, 13}, {0x800000, 13}},
	{{0x2c000000, 7}, {0x28000000, 7}, {0x25000000, 8}, {0x1e800000, 9}, 
	{0x1c000000, 9}, {0x13c00000, 10}, {0x12400000, 10}, {0x10000000, 10}, 
	{0xac00000, 10}, {0x9800000, 11}, {0x7000000, 11}, {0x4a00000, 11}, 
	{0x3400000, 11}, {0x1f00000, 12}, {0xc80000, 13}, {0x700000, 13}},
	{{0x23000000, 8}, {0x20000000, 7}, {0x1e000000, 9}, {0x1c800000, 9}, 
	{0x18400000, 10}, {0x12c00000, 10}, {0xe400000, 11}, {0xb600000, 11}, 
	{0xd800000, 10}, {0x9200000, 11}, {0x6e00000, 11}, {0x2900000, 12}, 
	{0x3000000, 12}, {0x1a80000, 13}, {0xb80000, 13}, {0x600000, 14}},
	{{0x1d000000, 9}, {0x1b000000, 8}, {0x19000000, 9}, {0x18000000, 10}, 
	{0x13000000, 10}, {0x11800000, 10}, {0xba00000, 11}, {0xa800000, 11}, 
	{0x9a00000, 11}, {0x7400000, 11}, {0x4f00000, 12}, {0x3a00000, 11}, 
	{0x2500000, 13}, {0x1880000, 13}, {0xa40000, 14}, {0x440000, 14}},
	{{0x17800000, 9}, {0x16800000, 9}, {0x13800000, 10}, {0x12800000, 10}, 
	{0xe600000, 11}, {0xbc00000, 11}, {0xb400000, 11}, {0x9e00000, 11}, 
	{0x8a00000, 11}, {0x5300000, 12}, {0x4700000, 12}, {0x3200000, 12}, 
	{0x1d80000, 13}, {0x1300000, 13}, {0x900000, 14}, {0x3c0000, 14}},
	{{0x12000000, 10}, {0x11000000, 9}, {0xe000000, 10}, {0xbe00000, 11}, 
	{0xb800000, 11}, {0xaa00000, 11}, {0x5b00000, 12}, {0x5a00000, 12}, 
	{0x5600000, 12}, {0x4900000, 12}, {0x2680000, 13}, {0x2080000, 13}, 
	{0x1980000, 13}, {0xb00000, 14}, {0x2b0000, 16}, {0x2a0000, 16}},
	{{0x15800000, 9}, {0x14000000, 8}, {0xf000000, 9}, {0xb000000, 10}, 
	{0xdc00000, 10}, {0x9c00000, 11}, {0x9000000, 11}, {0x5700000, 12}, 
	{0x4e00000, 12}, {0x3d00000, 12}, {0x2e00000, 12}, {0x1b00000, 13}, 
	{0x1280000, 13}, {0x780000, 14}, {0x280000, 15}, {0x200000, 15}},
	{{0xd400000, 10}, {0xc800000, 9}, {0xa400000, 10}, {0x9400000, 10}, 
	{0x5800000, 11}, {0x7600000, 11}, {0x6c00000, 11}, {0x2880000, 13}, 
	{0x4200000, 12}, {0x2600000, 13}, {0x1c80000, 13}, {0xd80000, 14}, 
	{0x940000, 14}, {0x480000, 14}, {0x270000, 16}, {0x160000, 15}},
	{{0x8c00000, 10}, {0x8400000, 10}, {0x7c00000, 10}, {0x7200000, 11}, 
	{0x5400000, 11}, {0x5200000, 12}, {0x4800000, 12}, {0x2800000, 13}, 
	{0x2f00000, 12}, {0x1d00000, 13}, {0xdc0000, 14}, {0xa80000, 13}, 
	{0x580000, 14}, {0x340000, 15}, {0x260000, 16}, {0xb0000, 17}},
	{{0x6a00000, 11}, {0x6400000, 10}, {0x5c00000, 10}, {0x4c00000, 11}, 
	{0x4600000, 12}, {0x3c00000, 12}, {0x3300000, 12}, {0x2400000, 12}, 
	{0x1b80000, 13}, {0xd00000, 13}, {0x1100000, 13}, {0x5c0000, 14}, 
	{0x360000, 15}, {0x1c0000, 15}, {0x120000, 15}, {0x70000, 16}},
	{{0x4400000, 11}, {0x4000000, 11}, {0x3800000, 11}, {0x2700000, 12}, 
	{0x3100000, 12}, {0x2580000, 13}, {0x1e00000, 12}, {0x1a00000, 13}, 
	{0xc00000, 14}, {0xa00000, 14}, {0x680000, 15}, {0x380000, 15}, 
	{0x240000, 15}, {0x110000, 16}, {0x90000, 16}, {0x50000, 16}},
	{{0x2d00000, 12}, {0x2a00000, 11}, {0x2200000, 12}, {0x2000000, 13}, 
	{0x1c00000, 13}, {0x1900000, 13}, {0xc40000, 14}, {0xb40000, 14}, 
	{0x7c0000, 14}, {0x4c0000, 14}, {0x300000, 14}, {0x1e0000, 15}, 
	{0xa0000, 16}, {0xe0000, 15}, {0x60000, 16}, {0x30000, 16}},
	{{0x1800000, 13}, {0x1700000, 12}, {0x1400000, 12}, {0x1380000, 13}, 
	{0x1200000, 13}, {0x1180000, 13}, {0x6a0000, 15}, {0x540000, 14}, 
	{0x400000, 14}, {0xb8000, 17}, {0x1a0000, 15}, {0x140000, 15}, 
	{0xc0000, 15}, {0x8000, 17}, {0x40000, 16}, {0x20000, 16}},
	{{0x1000000, 12}, {0xf00000, 12}, {0x880000, 13}, {0x6c0000, 14}, 
	{0x640000, 14}, {0x500000, 14}, {0x3a0000, 15}, {0x2c0000, 14}, 
	{0x220000, 15}, {0x180000, 15}, {0x100000, 16}, {0x80000, 16}, 
	{0x2000, 19}, {0x4000, 18}, {0x0, 19}, {0x10000, 16}}
};
const unsigned hft_15[16][16][2] {
	{{0xe0000000, 3}, {0xc0000000, 4}, {0x90000000, 5}, {0x6a000000, 7}, 
	{0x5e000000, 7}, {0x4c000000, 8}, {0x3e000000, 9}, {0x36000000, 9}, 
	{0x2c800000, 9}, {0x1ec00000, 10}, {0x1b000000, 10}, {0xee00000, 11}, 
	{0xd600000, 11}, {0xa200000, 11}, {0x7a00000, 12}, {0x1f80000, 13}},
	{{0xd0000000, 4}, {0xa0000000, 3}, {0x80000000, 5}, {0x6c000000, 6}, 
	{0x5c000000, 7}, {0x48000000, 7}, {0x3d000000, 8}, {0x33000000, 8}, 
	{0x2a000000, 8}, {0x23000000, 9}, {0x1a000000, 9}, {0x14c00000, 10}, 
	{0x10400000, 10}, {0xa400000, 10}, {0x7600000, 11}, {0x4800000, 11}},
	{{0x98000000, 5}, {0x88000000, 5}, {0x78000000, 5}, {0x60000000, 6}, 
	{0x52000000, 7}, {0x44000000, 7}, {0x3b000000, 8}, {0x30000000, 8}, 
	{0x28000000, 8}, {0x20000000, 9}, {0x19000000, 9}, {0x13800000, 10}, 
	{0xf800000, 10}, {0xa000000, 11}, {0x7000000, 11}, {0x4200000, 11}},
	{{0x74000000, 6}, {0x70000000, 6}, {0x64000000, 6}, {0x56000000, 7}, 
	{0x4e000000, 7}, {0x3f000000, 8}, {0x37000000, 8}, {0x2e800000, 9}, 
	{0x26000000, 9}, {0x1d800000, 9}, {0x17400000, 10}, {0x12000000, 10}, 
	{0xd800000, 10}, {0x9600000, 11}, {0x6400000, 11}, {0x3a00000, 11}},
	{{0x68000000, 7}, {0x58000000, 6}, {0x54000000, 7}, {0x50000000, 7}, 
	{0x43000000, 8}, {0x39000000, 8}, {0x2f800000, 9}, {0x27800000, 9}, 
	{0x24000000, 9}, {0x1c800000, 9}, {0x16400000, 10}, {0x11400000, 10}, 
	{0xc400000, 10}, {0x8400000, 11}, {0x5c00000, 11}, {0x3600000, 11}},
	{{0x4d000000, 8}, {0x4a000000, 7}, {0x46000000, 7}, {0x42000000, 8}, 
	{0x3a000000, 8}, {0x34000000, 8}, {0x2d800000, 9}, {0x25000000, 9}, 
	{0x1f000000, 9}, {0x18000000, 9}, {0x13c00000, 10}, {0xfc00000, 10}, 
	{0xb400000, 11}, {0x7c00000, 11}, {0x5000000, 11}, {0x2600000, 12}},
	{{0x3e800000, 9}, {0x40000000, 7}, {0x3c000000, 8}, {0x38000000, 8}, 
	{0x32000000, 8}, {0x2e000000, 9}, {0x27000000, 9}, {0x20800000, 9}, 
	{0x1b800000, 9}, {0x15c00000, 10}, {0x11c00000, 10}, {0xcc00000, 10}, 
	{0x9200000, 11}, {0x6600000, 11}, {0x4600000, 12}, {0x1e00000, 12}},
	{{0x36800000, 9}, {0x35000000, 8}, {0x31000000, 8}, {0x2f000000, 9}, 
	{0x2c000000, 9}, {0x25800000, 9}, {0x21000000, 9}, {0x1e800000, 10}, 
	{0x16c00000, 10}, {0x12400000, 10}, {0xe000000, 10}, {0xa800000, 10}, 
	{0x8000000, 11}, {0x5800000, 11}, {0x2a00000, 11}, {0x1900000, 12}},
	{{0x2d000000, 9}, {0x2b000000, 8}, {0x29000000, 8}, {0x26800000, 9}, 
	{0x24800000, 9}, {0x1f800000, 9}, {0x1c000000, 9}, {0x17000000, 10}, 
	{0x13400000, 10}, {0x10800000, 10}, {0xbc00000, 10}, {0x8600000, 11}, 
	{0x6000000, 11}, {0x3500000, 12}, {0x2400000, 12}, {0x1400000, 12}},
	{{0x23800000, 9}, {0x22000000, 8}, {0x21800000, 9}, {0x1e000000, 9}, 
	{0x1d000000, 9}, {0x18800000, 9}, {0x16000000, 10}, {0x13000000, 10}, 
	{0x10c00000, 10}, {0xd400000, 11}, {0x8e00000, 11}, {0x6c00000, 11}, 
	{0x4c00000, 11}, {0x2700000, 12}, {0x1700000, 12}, {0xf00000, 12}},
	{{0x1b400000, 10}, {0x1a800000, 9}, {0x19800000, 9}, {0x17800000, 9}, 
	{0x16800000, 10}, {0x14800000, 10}, {0xe800000, 10}, {0xe400000, 10}, 
	{0xc000000, 10}, {0x9000000, 11}, {0x7200000, 11}, {0x5200000, 11}, 
	{0x2e00000, 11}, {0x1b00000, 12}, {0x1f00000, 13}, {0x900000, 12}},
	{{0x15800000, 10}, {0x15000000, 9}, {0x14000000, 9}, {0x12800000, 9}, 
	{0x11800000, 10}, {0x10000000, 10}, {0xd000000, 10}, {0xac00000, 10}, 
	{0x8c00000, 11}, {0x6e00000, 11}, {0x5400000, 11}, {0x3200000, 11}, 
	{0x1d00000, 12}, {0x1200000, 12}, {0xb00000, 12}, {0x580000, 13}},
	{{0xec00000, 11}, {0x11000000, 10}, {0xf000000, 9}, {0xdc00000, 10}, 
	{0xc800000, 10}, {0xb800000, 10}, {0x9400000, 11}, {0x8200000, 11}, 
	{0x6200000, 11}, {0x4e00000, 11}, {0x3000000, 11}, {0x2000000, 11}, 
	{0x1600000, 12}, {0xd00000, 12}, {0x700000, 13}, {0x380000, 13}},
	{{0xb600000, 11}, {0xb000000, 10}, {0x9c00000, 10}, {0x9800000, 10}, 
	{0x8800000, 10}, {0x7e00000, 11}, {0x6800000, 11}, {0x5a00000, 11}, 
	{0x3e00000, 11}, {0x3400000, 12}, {0x1c00000, 12}, {0x1300000, 12}, 
	{0xe00000, 12}, {0x800000, 12}, {0x480000, 13}, {0x180000, 13}},
	{{0x7b00000, 12}, {0x7800000, 11}, {0x7400000, 11}, {0x6a00000, 11}, 
	{0x5e00000, 11}, {0x5600000, 11}, {0x4000000, 11}, {0x2c00000, 11}, 
	{0x2500000, 12}, {0x1800000, 12}, {0x1100000, 12}, {0xc00000, 12}, 
	{0x780000, 13}, {0x500000, 13}, {0x200000, 12}, {0x80000, 13}},
	{{0x4700000, 12}, {0x4a00000, 11}, {0x4400000, 11}, {0x3c00000, 11}, 
	{0x3800000, 11}, {0x2800000, 11}, {0x2200000, 11}, {0x1a00000, 12}, 
	{0x1500000, 12}, {0x1000000, 12}, {0xa00000, 12}, {0x600000, 12}, 
	{0x400000, 13}, {0x300000, 13}, {0x100000, 13}, {0x0, 13}}
};
const unsigned hft_16[16][16][2] {
	{{0x80000000, 1}, {0x50000000, 4}, {0x38000000, 6}, {0x2c000000, 8}, 
	{0x25000000, 9}, {0x1f800000, 9}, {0x1b800000, 10}, {0x17400000, 10}, 
	{0x15800000, 11}, {0x12a00000, 11}, {0x11400000, 11}, {0xf200000, 12}, 
	{0xe100000, 12}, {0xc300000, 12}, {0xbc00000, 13}, {0x8800000, 9}},
	{{0x60000000, 3}, {0x40000000, 4}, {0x30000000, 6}, {0x28000000, 7}, 
	{0x23000000, 8}, {0x1f000000, 9}, {0x1a800000, 9}, {0x17800000, 9}, 
	{0x14c00000, 10}, {0x12c00000, 10}, {0x11000000, 10}, {0xee00000, 11}, 
	{0xc900000, 12}, {0xd600000, 11}, {0xcf00000, 12}, {0x9000000, 8}},
	{{0x3c000000, 6}, {0x34000000, 6}, {0x2e000000, 7}, {0x26000000, 8}, 
	{0x21800000, 9}, {0x1d000000, 9}, {0x19c00000, 10}, {0x16800000, 10}, 
	{0x14200000, 11}, {0x12000000, 10}, {0xfe00000, 11}, {0xea00000, 11}, 
	{0xdc00000, 11}, {0xd100000, 12}, {0xce00000, 12}, {0x8000000, 9}},
	{{0x2d000000, 8}, {0x2a000000, 7}, {0x27000000, 8}, {0x22800000, 9}, 
	{0x20000000, 9}, {0x1c800000, 10}, {0x18c00000, 10}, {0x15c00000, 10}, 
	{0x13c00000, 11}, {0x11800000, 11}, {0xfc00000, 12}, {0xd400000, 12}, 
	{0xc700000, 12}, {0xc180000, 13}, {0xb680000, 13}, {0x6800000, 10}},
	{{0x25800000, 9}, {0x24000000, 8}, {0x22000000, 9}, {0x20800000, 9}, 
	{0x1cc00000, 10}, {0x19400000, 10}, {0x16600000, 11}, {0x14800000, 11}, 
	{0x13600000, 11}, {0x10800000, 12}, {0xf600000, 12}, {0xe200000, 12}, 
	{0xc580000, 13}, {0xbf00000, 13}, {0xb500000, 13}, {0x4800000, 9}},
	{{0x21000000, 9}, {0x1e000000, 8}, {0x1d800000, 9}, {0x1c000000, 9}, 
	{0x19800000, 10}, {0x17200000, 11}, {0x15a00000, 11}, {0x10900000, 12}, 
	{0x11c00000, 11}, {0xfd00000, 12}, {0xe800000, 12}, {0xc800000, 13}, 
	{0xc200000, 13}, {0xbd00000, 13}, {0x6f40000, 14}, {0x4000000, 10}},
	{{0x1bc00000, 10}, {0x1b000000, 9}, {0x1a000000, 9}, {0x19000000, 10}, 
	{0x17000000, 11}, {0x16400000, 11}, {0x14000000, 11}, {0x10a00000, 11}, 
	{0x10100000, 12}, {0xf400000, 12}, {0xe400000, 12}, {0xd900000, 12}, 
	{0xc080000, 13}, {0xb700000, 13}, {0xb2c0000, 14}, {0x2800000, 10}},
	{{0x18800000, 10}, {0x18000000, 9}, {0x16c00000, 10}, {0x16000000, 10}, 
	{0x14a00000, 11}, {0x13a00000, 11}, {0x12800000, 11}, {0x10500000, 12}, 
	{0xf800000, 12}, {0xcb80000, 13}, {0xc680000, 13}, {0xba00000, 13}, 
	{0xbe00000, 13}, {0x6f20000, 15}, {0x6e80000, 15}, {0x2000000, 10}},
	{{0x15400000, 10}, {0x15000000, 10}, {0x14400000, 10}, {0x13e00000, 11}, 
	{0x13800000, 11}, {0x11e00000, 11}, {0x10400000, 12}, {0xf900000, 12}, 
	{0xd580000, 13}, {0xc880000, 13}, {0xc400000, 13}, {0xbf80000, 13}, 
	{0xb5c0000, 14}, {0xb240000, 14}, {0xb100000, 14}, {0x1c00000, 10}},
	{{0x13400000, 11}, {0x13000000, 10}, {0x12400000, 10}, {0x11a00000, 11}, 
	{0x10600000, 11}, {0x10000000, 12}, {0xf500000, 12}, {0xd500000, 13}, 
	{0xcb00000, 13}, {0xc500000, 13}, {0xc000000, 13}, {0xb7c0000, 14}, 
	{0xb380000, 13}, {0xb180000, 14}, {0xb000000, 13}, {0x1600000, 11}},
	{{0x11600000, 11}, {0x10200000, 11}, {0x10c00000, 10}, {0xfa00000, 11}, 
	{0xf700000, 12}, {0xe900000, 12}, {0xe500000, 12}, {0xdb00000, 12}, 
	{0xc480000, 13}, {0xb9c0000, 14}, {0xb840000, 14}, {0xb400000, 14}, 
	{0x6ea0000, 15}, {0x6e40000, 15}, {0x6dc0000, 14}, {0x1000000, 10}},
	{{0xf300000, 12}, {0xf000000, 11}, {0xec00000, 11}, {0xe600000, 11}, 
	{0xe300000, 12}, {0xdf00000, 12}, {0xc600000, 13}, {0xba80000, 14}, 
	{0xb980000, 14}, {0xb800000, 14}, {0xb440000, 14}, {0xb200000, 14}, 
	{0xb080000, 14}, {0x6f80000, 13}, {0x6d00000, 14}, {0xc00000, 11}},
	{{0xca00000, 12}, {0xe000000, 12}, {0xde00000, 12}, {0xda00000, 12}, 
	{0xd800000, 12}, {0xc280000, 13}, {0xc100000, 13}, {0xbe80000, 13}, 
	{0xb600000, 13}, {0x6f00000, 15}, {0x6ec0000, 14}, {0xb0c0000, 14}, 
	{0x6e00000, 14}, {0x6d40000, 14}, {0x6c00000, 16}, {0x800000, 11}},
	{{0xbac0000, 14}, {0xd300000, 12}, {0xd200000, 12}, {0xd000000, 12}, 
	{0xb900000, 13}, {0xbd80000, 13}, {0xb780000, 14}, {0xb4c0000, 14}, 
	{0xb280000, 14}, {0x6c70000, 16}, {0x6e60000, 15}, {0x6da0000, 15}, 
	{0x6d80000, 15}, {0x6c18000, 17}, {0x6c20000, 15}, {0x400000, 11}},
	{{0xbc80000, 13}, {0xb880000, 13}, {0xcc00000, 11}, {0xbb00000, 12}, 
	{0xb580000, 14}, {0xb480000, 14}, {0xb300000, 13}, {0xb1c0000, 14}, 
	{0xb140000, 14}, {0x6c40000, 15}, {0x6c60000, 16}, {0x6ce0000, 15}, 
	{0x6c10000, 17}, {0x6cc0000, 15}, {0x6c80000, 14}, {0x0, 11}},
	{{0x6000000, 9}, {0xa000000, 8}, {0x7000000, 8}, {0x5800000, 9}, 
	{0x5000000, 9}, {0x4400000, 10}, {0x2c00000, 10}, {0x2400000, 10}, 
	{0x1a00000, 11}, {0x1800000, 11}, {0x1400000, 11}, {0xe00000, 11}, 
	{0xa00000, 11}, {0x600000, 11}, {0x200000, 11}, {0x3000000, 8}}
};
const unsigned hft_24[16][16][2] {
	{{0xf0000000, 4}, {0xd0000000, 4}, {0xb8000000, 6}, {0xa0000000, 7}, 
	{0x92000000, 8}, {0x83000000, 9}, {0x7c000000, 9}, {0x6c800000, 10}, 
	{0x6a800000, 10}, {0x53a00000, 11}, {0x51a00000, 11}, {0x51200000, 11}, 
	{0x4da00000, 11}, {0x40a00000, 11}, {0x40800000, 12}, {0x2c000000, 9}},
	{{0xe0000000, 4}, {0xc0000000, 4}, {0xa8000000, 5}, {0x98000000, 6}, 
	{0x8e000000, 7}, {0x82000000, 8}, {0x7a000000, 8}, {0x6c000000, 9}, 
	{0x68800000, 9}, {0x63000000, 9}, {0x51c00000, 10}, {0x56400000, 10}, 
	{0x4fc00000, 10}, {0x4a400000, 10}, {0x45c00000, 10}, {0x2a000000, 8}},
	{{0xbc000000, 6}, {0xb0000000, 5}, {0xa4000000, 6}, {0x94000000, 7}, 
	{0x88000000, 7}, {0x80000000, 8}, {0x78000000, 8}, {0x6e800000, 9}, 
	{0x67800000, 9}, {0x61000000, 9}, {0x5b000000, 9}, {0x55000000, 10}, 
	{0x4ec00000, 10}, {0x49c00000, 10}, {0x43a00000, 11}, {0x24000000, 7}},
	{{0xa2000000, 7}, {0x9c000000, 6}, {0x96000000, 7}, {0x8c000000, 7}, 
	{0x86000000, 8}, {0x7d000000, 8}, {0x74000000, 8}, {0x6e000000, 9}, 
	{0x66000000, 9}, {0x5f000000, 9}, {0x59000000, 9}, {0x51400000, 10}, 
	{0x4dc00000, 10}, {0x49400000, 10}, {0x43c00000, 10}, {0x20000000, 7}},
	{{0x93000000, 8}, {0x90000000, 7}, {0x8a000000, 7}, {0x87000000, 8}, 
	{0x7f000000, 8}, {0x76000000, 8}, {0x70000000, 8}, {0x69000000, 9}, 
	{0x64000000, 9}, {0x5e000000, 9}, {0x58000000, 10}, {0x50c00000, 10}, 
	{0x4c800000, 10}, {0x47400000, 10}, {0x43800000, 11}, {0x1c000000, 7}},
	{{0x83800000, 9}, {0x84000000, 7}, {0x81000000, 8}, {0x7e000000, 8}, 
	{0x77000000, 8}, {0x72000000, 8}, {0x6b000000, 9}, {0x65000000, 9}, 
	{0x60000000, 9}, {0x5a000000, 9}, {0x55400000, 10}, {0x4f400000, 10}, 
	{0x4b400000, 10}, {0x46400000, 10}, {0x41800000, 10}, {0x18000000, 7}},
	{{0x7c800000, 9}, {0x7b000000, 8}, {0x79000000, 8}, {0x75000000, 8}, 
	{0x71000000, 8}, {0x6b800000, 9}, {0x67000000, 9}, {0x61800000, 9}, 
	{0x5c800000, 9}, {0x56c00000, 10}, {0x52800000, 10}, {0x4d000000, 10}, 
	{0x48c00000, 10}, {0x44000000, 10}, {0x41000000, 11}, {0x14000000, 7}},
	{{0x6cc00000, 10}, {0x73000000, 8}, {0x6f000000, 8}, {0x6d000000, 8}, 
	{0x69800000, 9}, {0x65800000, 9}, {0x62000000, 9}, {0x5d800000, 9}, 
	{0x58400000, 10}, {0x53000000, 10}, {0x4e400000, 10}, {0x4a800000, 10}, 
	{0x46c00000, 10}, {0x42600000, 11}, {0x2fa00000, 11}, {0x11000000, 8}},
	{{0x6ac00000, 10}, {0x6a000000, 9}, {0x68000000, 9}, {0x66800000, 9}, 
	{0x64800000, 9}, {0x60800000, 9}, {0x5d000000, 9}, {0x58800000, 9}, 
	{0x54800000, 9}, {0x50000000, 10}, {0x4bc00000, 10}, {0x47800000, 10}, 
	{0x43000000, 10}, {0x40400000, 11}, {0x2f200000, 11}, {0x10000000, 8}},
	{{0x53c00000, 10}, {0x63800000, 9}, {0x62800000, 9}, {0x5f800000, 9}, 
	{0x5e800000, 9}, {0x5a800000, 9}, {0x57000000, 9}, {0x53400000, 10}, 
	{0x50400000, 10}, {0x4c400000, 10}, {0x48400000, 10}, {0x44c00000, 10}, 
	{0x41200000, 11}, {0x2f600000, 11}, {0x2e600000, 11}, {0xb000000, 8}},
	{{0x53800000, 11}, {0x5c000000, 9}, {0x5b800000, 9}, {0x59800000, 9}, 
	{0x57800000, 9}, {0x56000000, 10}, {0x52c00000, 10}, {0x4e800000, 10}, 
	{0x4c000000, 10}, {0x48800000, 10}, {0x45400000, 10}, {0x42400000, 11}, 
	{0x2fe00000, 11}, {0x2ea00000, 11}, {0x2dc00000, 11}, {0xa000000, 8}},
	{{0x51800000, 11}, {0x56800000, 10}, {0x55800000, 9}, {0x54000000, 9}, 
	{0x52000000, 9}, {0x4f800000, 10}, {0x4d400000, 10}, {0x4ac00000, 10}, 
	{0x47c00000, 10}, {0x45000000, 10}, {0x41c00000, 10}, {0x40200000, 11}, 
	{0x2ee00000, 11}, {0x2e000000, 11}, {0x2d400000, 11}, {0x6000000, 8}},
	{{0x51000000, 11}, {0x50800000, 10}, {0x4f000000, 10}, {0x4e000000, 10}, 
	{0x4cc00000, 10}, {0x4b800000, 10}, {0x49000000, 10}, {0x47000000, 10}, 
	{0x43400000, 10}, {0x41400000, 10}, {0x40000000, 11}, {0x2f000000, 11}, 
	{0x2e400000, 11}, {0x2d800000, 11}, {0x2ce00000, 11}, {0x4000000, 8}},
	{{0x4d800000, 11}, {0x4b000000, 10}, {0x4a000000, 10}, {0x49800000, 10}, 
	{0x48000000, 10}, {0x46800000, 10}, {0x44400000, 10}, {0x42800000, 10}, 
	{0x40600000, 11}, {0x2f800000, 11}, {0x2ec00000, 11}, {0x2e200000, 11}, 
	{0x2da00000, 11}, {0x2d200000, 11}, {0x2ca00000, 11}, {0x2000000, 8}},
	{{0x40900000, 12}, {0x46000000, 10}, {0x45800000, 10}, {0x44800000, 10}, 
	{0x42c00000, 10}, {0x42000000, 10}, {0x40c00000, 10}, {0x2fc00000, 11}, 
	{0x2f400000, 11}, {0x2e800000, 11}, {0x2de00000, 11}, {0x2d600000, 11}, 
	{0x2d000000, 11}, {0x2cc00000, 11}, {0x2c800000, 11}, {0x0, 8}},
	{{0x2b000000, 8}, {0x28000000, 7}, {0x26000000, 7}, {0x22000000, 7}, 
	{0x1e000000, 7}, {0x1a000000, 7}, {0x16000000, 7}, {0x12000000, 7}, 
	{0xe000000, 7}, {0xc000000, 7}, {0x8000000, 7}, {0x7000000, 8}, 
	{0x5000000, 8}, {0x3000000, 8}, {0x1000000, 8}, {0x30000000, 4}}
};

static const unsigned *big_value_table[32] {
	&hft_0[0][0][0],  &hft_1[0][0][0],  &hft_2[0][0][0],  &hft_3[0][0][0], 
	&hft_0[0][0][0],  &hft_5[0][0][0],  &hft_6[0][0][0],  &hft_7[0][0][0], 
	&hft_8[0][0][0],  &hft_9[0][0][0],  &hft_10[0][0][0], &hft_11[0][0][0],
	&hft_12[0][0][0], &hft_13[0][0][0], &hft_0[0][0][0],  &hft_15[0][0][0],
	&hft_16[0][0][0], &hft_16[0][0][0], &hft_16[0][0][0], &hft_16[0][0][0],
	&hft_16[0][0][0], &hft_16[0][0][0], &hft_16[0][0][0], &hft_16[0][0][0],
	&hft_24[0][0][0], &hft_24[0][0][0], &hft_24[0][0][0], &hft_24[0][0][0],
	&hft_24[0][0][0], &hft_24[0][0][0], &hft_24[0][0][0], &hft_24[0][0][0]
};

static const unsigned char big_value_linbit[32] {
	0, 0, 0, 0, 0, 0, 0,  0,  0, 0, 0, 0, 0, 0, 0,  0, 
	1, 2, 3, 4, 6, 8, 10, 13, 4, 5, 6, 7, 8, 9, 11, 13
};

static const unsigned big_value_max[32] {
	1,  2,  3,  3,  0,  4,  4,  6,  6,  6,  8,  8,  8,  16, 0,  16,
	16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16
};

static const double synth_window[512] {	
	 0.000000000, -0.000015259, -0.000015259, -0.000015259, -0.000015259, -0.000015259, 
	-0.000015259, -0.000030518, -0.000030518, -0.000030518, -0.000030518, -0.000045776, 
	-0.000045776, -0.000061035, -0.000061035, -0.000076294, -0.000076294, -0.000091553,
	-0.000106812, -0.000106812, -0.000122070, -0.000137329, -0.000152588, -0.000167847, 
	-0.000198364, -0.000213623, -0.000244141, -0.000259399, -0.000289917, -0.000320435, 
	-0.000366211, -0.000396729, -0.000442505, -0.000473022, -0.000534058, -0.000579834, 
	-0.000625610, -0.000686646, -0.000747681, -0.000808716, -0.000885010, -0.000961304,
	-0.001037598, -0.001113892, -0.001205444, -0.001296997, -0.001388550, -0.001480103, 
	-0.001586914, -0.001693726, -0.001785278, -0.001907349, -0.002014160, -0.002120972,
	-0.002243042, -0.002349854, -0.002456665, -0.002578735, -0.002685547, -0.002792358, 
	-0.002899170, -0.002990723, -0.003082275, -0.003173828,  0.003250122,  0.003326416,
	 0.003387451,  0.003433228,  0.003463745,  0.003479004,  0.003479004,  0.003463745, 
	 0.003417969,  0.003372192,  0.003280640,  0.003173828,  0.003051758,  0.002883911, 
	 0.002700806,  0.002487183,  0.002227783,  0.001937866,  0.001617432,  0.001266479, 
	 0.000869751,  0.000442505, -0.000030518, -0.000549316, -0.001098633, -0.001693726, 
	-0.002334595, -0.003005981, -0.003723145, -0.004486084, -0.005294800, -0.006118774, 
	-0.007003784, -0.007919312, -0.008865356, -0.009841919, -0.010848999, -0.011886597, 
	-0.012939453, -0.014022827, -0.015121460, -0.016235352, -0.017349243, -0.018463135, 
	-0.019577026, -0.020690918, -0.021789551, -0.022857666, -0.023910522, -0.024932861,
	-0.025909424, -0.026840210, -0.027725220, -0.028533936, -0.029281616, -0.029937744, 
	-0.030532837, -0.031005859, -0.031387329, -0.031661987, -0.031814575, -0.031845093,
	-0.031738281, -0.031478882,  0.031082153,  0.030517578,  0.029785156,  0.028884888, 
	 0.027801514,  0.026535034,  0.025085449,  0.023422241,  0.021575928,  0.019531250,
	 0.017257690,  0.014801025,  0.012115479,  0.009231567,  0.006134033,  0.002822876, 
	-0.000686646, -0.004394531, -0.008316040, -0.012420654, -0.016708374, -0.021179199, 
	-0.025817871, -0.030609131, -0.035552979, -0.040634155, -0.045837402, -0.051132202, 
	-0.056533813, -0.061996460, -0.067520142, -0.073059082, -0.078628540, -0.084182739,
	-0.089706421, -0.095169067, -0.100540161, -0.105819702, -0.110946655, -0.115921021, 
	-0.120697021, -0.125259399, -0.129562378, -0.133590698, -0.137298584, -0.140670776,
	-0.143676758, -0.146255493, -0.148422241, -0.150115967, -0.151306152, -0.151962280, 
	-0.152069092, -0.151596069, -0.150497437, -0.148773193, -0.146362305, -0.143264771,
	-0.139450073, -0.134887695, -0.129577637, -0.123474121, -0.116577148, -0.108856201, 
	 0.100311279,  0.090927124,  0.080688477,  0.069595337,  0.057617188,  0.044784546,
	 0.031082153,  0.016510010,  0.001068115, -0.015228271, -0.032379150, -0.050354004, 
	-0.069168091, -0.088775635, -0.109161377, -0.130310059, -0.152206421, -0.174789429,
	-0.198059082, -0.221984863, -0.246505737, -0.271591187, -0.297210693, -0.323318481, 
	-0.349868774, -0.376800537, -0.404083252, -0.431655884, -0.459472656, -0.487472534,
	-0.515609741, -0.543823242, -0.572036743, -0.600219727, -0.628295898, -0.656219482, 
	-0.683914185, -0.711318970, -0.738372803, -0.765029907, -0.791213989, -0.816864014,
	-0.841949463, -0.866363525, -0.890090942, -0.913055420, -0.935195923, -0.956481934, 
	-0.976852417, -0.996246338, -1.014617920, -1.031936646, -1.048156738, -1.063217163,
	-1.077117920, -1.089782715, -1.101211548, -1.111373901, -1.120223999, -1.127746582, 
	-1.133926392, -1.138763428, -1.142211914, -1.144287109,  1.144989014,  1.144287109, 
	 1.142211914,  1.138763428,  1.133926392,  1.127746582,  1.120223999,  1.111373901, 
	 1.101211548,  1.089782715,  1.077117920,  1.063217163,  1.048156738,  1.031936646, 
	 1.014617920,  0.996246338,  0.976852417,  0.956481934,  0.935195923,  0.913055420, 
	 0.890090942,  0.866363525,  0.841949463,  0.816864014,  0.791213989,  0.765029907,
	 0.738372803,  0.711318970,  0.683914185,  0.656219482,  0.628295898,  0.600219727, 
	 0.572036743,  0.543823242,  0.515609741,  0.487472534,  0.459472656,  0.431655884, 
	 0.404083252,  0.376800537,  0.349868774,  0.323318481,  0.297210693,  0.271591187, 
	 0.246505737,  0.221984863,  0.198059082,  0.174789429,  0.152206421,  0.130310059, 
	 0.109161377,  0.088775635,  0.069168091,  0.050354004,  0.032379150,  0.015228271, 
	-0.001068115, -0.016510010, -0.031082153, -0.044784546, -0.057617188, -0.069595337,
	-0.080688477, -0.090927124,  0.100311279,  0.108856201,  0.116577148,  0.123474121, 
	 0.129577637,  0.134887695,  0.139450073,  0.143264771,  0.146362305,  0.148773193, 
	 0.150497437,  0.151596069,  0.152069092,  0.151962280,  0.151306152,  0.150115967, 
	 0.148422241,  0.146255493,  0.143676758,  0.140670776,  0.137298584,  0.133590698, 
	 0.129562378,  0.125259399,  0.120697021,  0.115921021,  0.110946655,  0.105819702, 
	 0.100540161,  0.095169067,  0.089706421,  0.084182739,  0.078628540,  0.073059082, 
	 0.067520142,  0.061996460,  0.056533813,  0.051132202,  0.045837402,  0.040634155, 
	 0.035552979,  0.030609131,  0.025817871,  0.021179199,  0.016708374,  0.012420654,
	 0.008316040,  0.004394531,  0.000686646, -0.002822876, -0.006134033, -0.009231567, 
	-0.012115479, -0.014801025, -0.017257690, -0.019531250, -0.021575928, -0.023422241,
	-0.025085449, -0.026535034, -0.027801514, -0.028884888, -0.029785156, -0.030517578, 
	 0.031082153,  0.031478882,  0.031738281,  0.031845093,  0.031814575,  0.031661987, 
	 0.031387329,  0.031005859,  0.030532837,  0.029937744,  0.029281616,  0.028533936, 
	 0.027725220,  0.026840210,  0.025909424,  0.024932861,  0.023910522,  0.022857666, 
	 0.021789551,  0.020690918,  0.019577026,  0.018463135,  0.017349243,  0.016235352, 
	 0.015121460,  0.014022827,  0.012939453,  0.011886597,  0.010848999,  0.009841919,
	 0.008865356,  0.007919312,  0.007003784,  0.006118774,  0.005294800,  0.004486084, 
	 0.003723145,  0.003005981,  0.002334595,  0.001693726,  0.001098633,  0.000549316,
	 0.000030518, -0.000442505, -0.000869751, -0.001266479, -0.001617432, -0.001937866, 
	-0.002227783, -0.002487183, -0.002700806, -0.002883911, -0.003051758, -0.003173828,
	-0.003280640, -0.003372192, -0.003417969, -0.003463745, -0.003479004, -0.003479004, 
	-0.003463745, -0.003433228, -0.003387451, -0.003326416,  0.003250122,  0.003173828,
	 0.003082275,  0.002990723,  0.002899170,  0.002792358,  0.002685547,  0.002578735, 
	 0.002456665,  0.002349854,  0.002243042,  0.002120972,  0.002014160,  0.001907349,
	 0.001785278,  0.001693726,  0.001586914,  0.001480103,  0.001388550,  0.001296997, 
	 0.001205444,  0.001113892,  0.001037598,  0.000961304,  0.000885010,  0.000808716,
	 0.000747681,  0.000686646,  0.000625610,  0.000579834,  0.000534058,  0.000473022, 
	 0.000442505,  0.000396729,  0.000366211,  0.000320435,  0.000289917,  0.000259399,
	 0.000244141,  0.000213623,  0.000198364,  0.000167847,  0.000152588,  0.000137329, 
	 0.000122070,  0.000106812,  0.000106812,  0.000091553,  0.000076294,  0.000076294,
	 0.000061035,  0.000061035,  0.000045776,  0.000045776,  0.000030518,  0.000030518, 
	 0.000030518,  0.000030518,  0.000015259,  0.000015259,  0.000015259,  0.000015259,
	 0.000015259,  0.000015259, 
};

#endif	/* TABLES_H */