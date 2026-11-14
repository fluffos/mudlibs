#ifndef __OVERLAND_H
#define __OVERLAND_H

#include "vt100.h"

#define OV_PATH     "#"
#define OV_WATER    "~"
#define OV_BRIDGE   "="
#define OV_DESERT   "\""
#define OV_FOREST   "f"
#define OV_GRASS    "."
#define OV_MOUNTAIN "B"
#define OV_HILL     "b"
#define OV_CITY     "O"
#define OV_OTHERS   "%"

#define OV_PLY      "X"

#define OV_PATH_COL     VT_BLACK+VT_B_WHITE
#define OV_WATER_COL    VT_WHITE+VT_B_BLUE
#define OV_BRIDGE_COL   VT_BLACK+VT_B_BROWN
#define OV_DESERT_COL   VT_RED+VT_B_BROWN
#define OV_FOREST_COL   VT_YELLOW+VT_B_GREEN
#define OV_GRASS_COL    VT_YELLOW+VT_B_GREEN
#define OV_MOUNTAIN_COL VT_WHITE+VT_B_YELLOW
#define OV_HILL_COL     VT_WHITE+VT_B_YELLOW
#define OV_CITY_COL     VT_CYAN+VT_B_MAGENTA
#define OV_OTHERS_COL   VT_CYAN+VT_B_BLUE

#define OV_PLY_COL      VT_TA_AO+VT_BLACK+VT_B_WHITE

#endif
