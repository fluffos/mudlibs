/*--------------------------------------------------------------------------
 * /sys/regions.h -- Headerfile for region defines
 *
 * Copyright (C) 1997 by One Step Beyond.
 * All Rights Reserved.
 * Permission granted for non-commercial use.
 *--------------------------------------------------------------------------
 * NOTE: the region defines may be combined with binary or, for example
 *       REGION_FOREST|REGION_CAVE, but think about if that makes sense, 
 *       that example does not.
 */

#ifndef _REGIONS_H__
#define _REGIONS_H__

// Climate zones:

#define REGION_ARCTIC         0x00000001
#define REGION_TUNDRA         0x00000002
// no clima-zone means moderate climate like Germany / Nothern-Middle USA
#define REGION_SUBTROPIC      0x00000004
#define REGION_TROPIC         0x00000008
#define REGION_DESERT         0x00000010

// landscapes, can be combined (|) with climates:

#define REGION_CITY           0x00000020  
#define REGION_HARBOUR        0x00000040
#define REGION_COAST          0x00000080
#define REGION_OCEAN          0x00000100
#define REGION_RIVER          0x00000200
#define REGION_LAKE           0x00000400
#define REGION_SWAMP          0x00000800
#define REGION_FOREST         0x00001000
#define REGION_JUNGLE         0x00002000
#define REGION_MEADOW         0x00004000
#define REGION_PLAIN          0x00008000
#define REGION_HILL           0x00010000
#define REGION_MOUNTAIN       0x00020000
#define REGION_CAVE           0x00040000

// special regions:

#define REGION_CLOUD          0x00080000
#define REGION_DREAM          0x00100000

// yet unused values

#define REGION_UNUSED21       0x00200000
#define REGION_UNUSED22       0x00400000
#define REGION_UNUSED23       0x00800000
#define REGION_UNUSED24       0x01000000
#define REGION_UNUSED25       0x02000000
#define REGION_UNUSED26       0x04000000
#define REGION_UNUSED27       0x08000000
#define REGION_UNUSED28       0x10000000

// regions for local use - no fixed except 'this particular area'.

#define REGION_SPECIAL1       0x20000000
#define REGION_SPECIAL2       0x40000000
#define REGION_SPECIAL3       0x80000000

#endif // __REGIONS_H__
