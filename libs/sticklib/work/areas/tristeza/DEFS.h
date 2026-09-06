#ifndef _TRISTEZA_DEFS_H
#define _TRISTEZA_DEFS_H

/* The main configuration file that links rooms and areas to/from
 * Main Town. Note the #ifdef - mess; depending on whether certain
 * areas are included in StickLib or not, certain definitions are
 * added...
 */

#ifndef _AREAS_H
#include <areas.h>
#endif

#ifndef _DAEMONS_H
#include <daemons.h>
#endif

#ifndef _GENERIC_ROOMS_H
#include <generic_rooms.h>
#endif

// Dimensions of Tristeza:

#define	SMALLEST_X	0
#define	SMALLEST_Y	0
#define	LARGEST_X	14
#define	LARGEST_Y	14

#include <city_name.h>

// Some directories to be used:

#define CITY_PATH       "/areas/tristeza/"
#define	CITY_DIR	"/areas/tristeza/virtual/"
#define	NPC_DIR		"/areas/tristeza/npc/"
#define	OBJ_DIR		"/areas/tristeza/obj/"

// Clonable base rooms & inheritables:

#define	TRISTEZA_ROOM_C	"/areas/tristeza/virtual/tristeza_room"
#define	TOWER_LOOK_C	"/areas/tristeza/tower_look"
#define	NAMEGEN_C	NAMING_D
#define	CITYGUARD_C	"/areas/tristeza/npc/guard"
#define	CITYMONSTER_C	"/areas/tristeza/npc/citymonster"
#define	CITY_DAEMON	"/areas/tristeza/city_daemon"

// Filenames for special rooms:

/* Not defined here: */

#define WEAPON_SHOP	"/areas/tristeza/shops/weaponer"
#define ARMOUR_SHOP	"/areas/tristeza/shops/armourer"
#define GENERAL_SHOP	"/areas/tristeza/shops/shop"
#define FLOWER_SHOP	"/areas/tristeza/shops/flshop"
#define MAGIC_SHOP	"/areas/tristeza/shops/magic_shop"
#define ROYAL_TAILOR	"/areas/tristeza/shops/royal_tailor"
#define SIMOS_CLOTHROOM "/areas/tristeza/shops/cloth_shop"
#define	JEWELLERY	AREA_TRISTEZA "wedding/jewelry_shop"
#define SMOKE_SHOP	"/areas/tristeza/shops/sshop"
#define TRAV_SHOP       "/areas/tristeza/shops/trav_shop"

#define TRAV_SHOP_DOOR  "/areas/tristeza/shops/trav_shop_door"

#define ADV_GUILD	GENERIC_ROOM_ADV_GUILD
#define RACE_GUILD	"/areas/tristeza/rooms/race_guild"
#define BVL_LOBBY	"/areas/tristeza/bvl/lobby"
#define	FINNISH_CLUB	"/areas/tristeza/finnclub/foyer"

#define PUB		"/areas/tristeza/shops/pub2"
#define LORD_PUB	"/areas/tristeza/shops/lords_pub"
#define BAKERY		"/areas/tristeza/shops/bakery"

#define	TOWN_HALL	AREA_TRISTEZA "town_hall/hall"
#define	COURT_HOUSE	"/areas/tristeza/virtual/lobby"
#define	GUARD_HQ	"/areas/tristeza/virtual/guard_front"
//#define DONT_COME_INN   "/u/macleod/inn/lobby"

#define	HEALER		"/room/healer"
//#define	HAPPY_INN	"/u/stalker/inn/lobby"

#define JOES		AREA_TRISTEZA "rooms/joes"

#define	AMOS_BUILDING	AREA_ZOO "city/lobby"
#define	AMOS2		AREA_ZOO "city/apartment2"
#define	AMOS3		AREA_ZOO "city/apartment3"

#define	SWEDISH_CLUB	AREA_TRISTEZA "virtual/house12_9"
#define EAST_PATH	AREA_EAST "east/east_mist"
#define SOUTH_PATH	AREA_HIGHWAYS "south_path/south_mist"
#define WEST_PATH	AREA_WEST "forest/west_mist"

#ifdef AREA_SEWERS
#define	SEWERS1	"/areas/sewers/lvl1/wide1"
#define SEWERS2       "/areas/sewers/lvl1/wide8"
#define	SEWERS3	"/areas/sewers/lvl1/narrow4"
#endif

#define	PLAYER_HOMES1	"/areas/player_homes/home60"
#define	PLAYER_HOMES2	"/areas/player_homes/home40"
#define	NORTHERN_HIGHWAY AREA_HIGHWAYS "north/a_1"
#define WELL		"/areas/tristeza/rooms/well"
#define	GALLOWS		"/areas/tristeza/virtual/S7_7"

#define CASINO		AREA_TRISTEZA "casino/rooms/entrance"
#define	MAP_FILE	"/doc/maps/city_small_map"

#define	BOCCOB_CATHEDRAL_ENTRANCE	"/guilds/priests/rooms/entrance"

#endif
