#ifndef __SEA_H
#define __SEA_H

#include "vt100.h"

#define OV_PATH     ":"
#define OV_WATER    " "
#define OV_BRIDGE   "="
#define OV_DESERT   "\""
#define OV_FOREST   "f"
#define OV_GRASS    "."
#define OV_MOUNTAIN "^"
#define OV_HILL     "o"
#define OV_CITY     "O"
#define OV_OTHERS   "%"
#define OV_REEF     "'"

#define OV_PLY      "X"

#define OV_PATH_COL     VT_TA_AO+VT_RED+VT_TA_B+VT_B_WHITE
#define OV_WATER_COL    VT_TA_AO+VT_BLACK+VT_B_BLUE
#define OV_BRIDGE_COL   VT_TA_AO+VT_BLACK+VT_TA_B+VT_B_BROWN
#define OV_DESERT_COL   VT_TA_AO+VT_RED+VT_B_BROWN
#define OV_FOREST_COL   VT_TA_AO+VT_BLUE+VT_B_GREEN
#define OV_GRASS_COL    VT_TA_AO+VT_WHITE+VT_B_GREEN
#define OV_MOUNTAIN_COL VT_TA_AO+VT_BLACK+VT_TA_B+VT_B_RED
#define OV_HILL_COL     VT_TA_AO+VT_MAGENTA+VT_B_YELLOW
#define OV_CITY_COL     VT_TA_AO+VT_CYAN+VT_TA_B+VT_B_MAGENTA
#define OV_OTHERS_COL   VT_TA_AO+VT_CYAN+VT_B_BLUE
#define OV_REEF_COL	VT_TA_AO+VT_BLACK+VT_B_BLUE

#define OV_PLY_COL      VT_TA_AO+VT_BLACK+VT_B_WHITE

#define OV_MSTR "/d/wasser/creative/oversea/seamaster"
#define OV_MAP "/d/wasser/creative/oversea/map"
#define OV_ROOM "/d/wasser/creative/oversea/sea"

#define WTH_CHG_RND 40
#define WTH_CHG_OFF 35
#define RAD_RND 9
#define RAD_OFF 3
#define DIFF_RND 8
#define DIFF_OFF -4

#endif

