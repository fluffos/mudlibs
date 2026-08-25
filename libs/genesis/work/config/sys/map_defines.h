/*
 * This file contains information about the size and contents of
 * the map of your world. It is used by:
 *		 /std/map/map.c.
 *		 /std/mapsquare.c
 *		 /std/room.c
 */
#define MAP_DEF

#define MAXY 749          /* Maximum value Y may have */
#define MINY -750         /* Minimum value Y may have */
#define MAXX 500          /* Maximum value X may have */
#define MINX -501         /* Minimum value X may have */
#define UGLY_FIX 2        /* This depends on MAXY and MINY */
#define Y_TOT 1500        /* How many are there between MAXY and MINY, 0 included */
#define MAP_DEPTH 2       /* How many bytes do we have per ML */

#define MAP_SL_MAX 		8            /* 0 - 8 */
#define MAP_WL_MAX 		9999
#define MAP_SL_SIZE             5
#define MAP_SL(x, y) 		((y) * (MAP_SL_MAX + 1) + (x))
#define MAP_X(sl) 		((sl) % (MAP_SL_MAX + 1))
#define MAP_Y(sl) 		((sl) / (MAP_SL_MAX + 1))

/*
 * MAP_SL_DIFFS
 *
 *		      72 73 74 75 76 77 78 79 80
 *		      63 64 65 66 67 68 69 70 71
 *                    54 55 56 57 58 59 60 61 62
 *		      45 46 47 48 49 50 51 52 53
 *		      36 37 38 39 40 41 42 43 44
 *                    27 28 29 30 31 32 33 34 35
 *                    18 19 20 21 22 23 24 25 26 
 *                    09 10 11 12 13 14 15 16 17
 *                    00 01 02 03 04 05 06 07 08
 */
#define MAP_SL_DIFFS		({ (MAP_SL_MAX + 2), (MAP_SL_MAX + 1),    \
				   (MAP_SL_MAX), -1, -(MAP_SL_MAX + 2),   \
				   -(MAP_SL_MAX + 1), -(MAP_SL_MAX), 1 })

#define MAP_SL_DIRS		({ "southwest", "south", 		  \
				   "southheast", "east", "northeast", 	  \
				   "north", "northwest", "west" })

/*
 * Macros to check if a ML should contain road or river information.
 */
#define IS_RIVER(x,y) 		(((x) + (y)) % 2 == 0)
#define IS_ROAD(x,y)		(((x) + (y)) % 2)

/*
 * Each direction needs a bit in the database
 */
#define NORTH 0x2
#define EAST  0x4
#define SOUTH 0x8
#define WEST  0x10
#define ALL_DIRS 0x1E

/*
 * We use bit 1 to decide if the flow direction is going in or out.
 */
#define INVERTED_EXITS 0x1

/*
 * We use bit 6 and 7 to tell wich side has a river entering or exiting
 */
#define OUT_NORTH 0x00
#define OUT_EAST  0x20
#define OUT_SOUTH 0x40
#define OUT_WEST  0x60

/*
 * Some defines for use when parsing the returned value from query_river.
 */
#define RIVER_SOURCE 0x20
#define RIVER_END 0x40
#define RIVER_OUT_NORTH 0x100
#define RIVER_OUT_EAST 0x200
#define RIVER_OUT_SOUTH 0x400
#define RIVER_OUT_WEST 0x800

/*
 * Name of the file holding the map information
 */
#define MAP_FILE "/d/Genesis/a_map"

/*
 * Info on bit patterns in mapfile
 */
#define PLAIN             0x1F
#define RANDOM_ENCOUNTER  0x40
#define DOMAIN_BIT        0x20

/*
 * Path to where all maprooms will be created
 */
#define MAP_PATH "/d/Genesis/map"

/*
 * MAP_CHARS
 *
 * Printable char for each mapsymbol.
 *
 */
#define MAP_DEFAULT_CHAR 	"."
#define MAP_CHARS ({ ".",       /* 0 default */    \
		     ".",  /*  1 wasteland */\
		     ".",  /*  2 arctic sea */\
		     ".",  /*  3 cold_sea */\
		     ".",  /*  4 temperate_sea */\
		     ".",  /*  5 tropical_sea */\
		     ".",  /*  6 lake */\
		     ".",  /*  7 ice_at_sea */\
		     ",",  /*  8 reef */\
		     ".",  /*  9 river */\
		     "~",  /* 10 swamp */\
		     "=",  /* 11 tundra */\
		     "%",  /* 12 jungle */\
		     "%",  /* 13 pine_forest */\
		     "%",  /* 14 forest */\
		     "=",  /* 15 plains */\
		     "'",  /* 16 desert */\
		     "'",  /* 17 hills_desert */\
		     "n",  /* 18 hills_dirt */\
		     "%",  /* 19 hills_forest */\
		     "n",  /* 20 hills_ice */\
		     "%",  /* 21 hills_jungle */\
		     "n",  /* 22 hills_lightveg */\
		     "%",  /* 23 hills_pine_forest */\
		     "n",  /* 24 hills_tundra */\
		     "^",  /* 25 mountain */\
		     "^",  /* 26 mtn_desert */\
		     "^",  /* 27 mtn_ice */\
		     "^",  /* 28 mtn_jungle */\
		     "^",  /* 29 mtn_lightveg */\
		     "^",  /* 30 mtn_pineforest */\
		     "^",  /* 31 volcano */\
		    })



/*
 * MAP_ROOMS
 *
 * Mapsymbols and corresponding filenames of terrain rooms 
 *
 */
#define MAP_DEFAULT_ROOM 	"/d/Genesis/terrain/standard_sea"
#define MAP_ROOMS ({             			        \
		    "/d/Genesis/terrain/standard_sea", 		\
		    "/d/Genesis/terrain/wasteland", 		\
		    "/d/Genesis/terrain/arctic_sea", 		\
		    "/d/Genesis/terrain/cold_sea", 		\
		    "/d/Genesis/terrain/temperate_sea", 	\
		    "/d/Genesis/terrain/tropical_sea", 		\
		    "/d/Genesis/terrain/lake", 			\
		    "/d/Genesis/terrain/ice_at_sea",		\
		     "/d/Genesis/terrain/reef", 		\
		    "/d/Genesis/terrain/river", 		\
		    "/d/Genesis/terrain/swamp", 		\
		     "/d/Genesis/terrain/tundra", 		\
		     "/d/Genesis/terrain/jungle", 		\
		     "/d/Genesis/terrain/pine_forest", 		\
		     "/d/Genesis/terrain/forest", 		\
		     "/d/Genesis/terrain/plains", 		\
		     "/d/Genesis/terrain/desert", 		\
		     "/d/Genesis/terrain/hills_desert",		\
		     "/d/Genesis/terrain/hills_dirt", 		\
		     "/d/Genesis/terrain/hills_forest",		\
		     "/d/Genesis/terrain/hills_ice", 		\
		     "/d/Genesis/terrain/hills_jungle",		\
		     "/d/Genesis/terrain/hills_lightveg", 	\
		     "/d/Genesis/terrain/hills_pine_forest", 	\
		     "/d/Genesis/terrain/hills_tundra",		\
		     "/d/Genesis/terrain/mountain", 		\
		     "/d/Genesis/terrain/mtn_desert", 		\
		     "/d/Genesis/terrain/mtn_ice", 		\
		     "/d/Genesis/terrain/mtn_jungle", 		\
		     "/d/Genesis/terrain/mtn_lightveg",		\
		     "/d/Genesis/terrain/mtn_pineforest", 	\
		     "/d/Genesis/terrain/volcano", 		\
		    })

#define TERRAIN_NAMES ({                        \
		     "standard_sea", 		\
		     "wasteland", 		\
		     "arctic_sea", 		\
		     "cold_sea", 		\
		     "temperate_sea", 	        \
		     "tropical_sea", 		\
		     "lake", 			\
		     "ice_at_sea",		\
		     "reef", 			\
		     "river", 			\
		     "swamp", 		        \
		     "tundra",  		\
		     "jungle", 		        \
		     "pine_forest", 		\
		     "forest", 		        \
		     "plains", 	        	\
		     "desert", 		        \
		     "hills_desert", 		\
		     "hills_dirt", 		\
		     "hills_forest", 		\
		     "hills_ice",               \
		     "hills_jungle", 		\
		     "hills_lightveg",  	\
		     "hills_pine_forest", 	\
		     "hills_tundra", 		\
		     "mountain", 		\
		     "mtn_desert", 		\
		     "mtn_ice", 		\
		     "mtn_jungle", 		\
		     "mtn_lightveg", 		\
		     "mtn_pineforest", 	        \
		     "volcano", 		\
		     })
