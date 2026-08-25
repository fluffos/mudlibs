#ifndef _TERRAIN_H_
#define _TERRAIN_H_

// Terrain temperature defines
#define TERRAIN_MELTING      0x00000003
#define TERRAIN_HOT          0x00000002
#define TERRAIN_WARM         0x00000001
#define TERRAIN_TEMPERATE    0x00000000
#define TERRAIN_COOL         0x00000004
#define TERRAIN_COLD         0x00000005
#define TERRAIN_FREEZING     0x00000006
#define TERRAIN_BITTER_COLD  0x00000007

#define TERRAIN_TEMPERATURES 0x00000007

#define tempGTE(x,y) ((y <= TERRAIN_MELTING && x >= y) || (y > TERRAIN_MELTING && x <= y))
#define tempLTE(x,y) ((y <= TERRAIN_MELTING && x <= y) || (y > TERRAIN_MELTING && x >= y))

// Bit 3 unused.

// Medium defines.
#define TERRAIN_UNDERWATER   0x00000010
#define TERRAIN_INAIR        0x00000020
#define TERRAIN_ONWATER      0x00000040
#define TERRAIN_UNDERGROUND  0x00000080

// What defines.
#define TERRAIN_OUTSIDE      0x00000100

// Origin defines.
#define TERRAIN_NATURAL      0x00000200

// Medium movement defines.
#define TERRAIN_CURRENT      0x00000400

// Area mobility
#define TERRAIN_ONVEHICLE    0x00000800

// Freedom of movement defines.
#define TERRAIN_OPENSPACE    0x00001000

// Terrain size defines.
#define TERRAIN_LARGE        0x00002000

// Terrain has defines.

// Salty water, sulphuric air, etc
#define TERRAIN_IMPURE       0x00004000
#define TERRAIN_WET          0x00008000
#define TERRAIN_ROCK         0x00010000
#define TERRAIN_SAND         0x00020000
#define TERRAIN_SOIL         0x00040000
#define TERRAIN_CLUTTER      0x00080000
#define TERRAIN_TALL_PLANT   0x00100000
#define TERRAIN_SMALL_PLANT  0x00200000
#define TERRAIN_MUD          (TERRAIN_WET | TERRAIN_SOIL)

//Terrain topography defines.
#define TERRAIN_ROUGH        0x00400000
#define TERRAIN_STEEP        0x00800000

// Effects of light.
#define TERRAIN_SHADOWS      0x01000000

// Population defines.
#define TERRAIN_CROWDED      0x02000000

// Domicile defines.
#define TERRAIN_RESIDENCE    0x04000000

// Dead defines.
#define TERRAIN_HASDEAD      0x08000000

#endif

