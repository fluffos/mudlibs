#include <ansi.h>
#include "upgrades.h"

/* Settings */
#define SMALL  19
#define MEDIUM 30
#define LARGE  75

/* Inherits */
#define LAND  "/room/housing/land.lpc"
#define HROOM "/room/housing/house_room.lpc"

/* Daemons */
#define LANDD       "/room/housing/land_daemon.lpc"
#define WAXFUNS     "/obj/user/waxfuns.lpc"
#define MISCD       "/room/housing/sort_daemon.lpc"
#define UTILITYD    "/room/housing/sort_daemon.lpc"
#define HOUSED      "/room/housing/house_daemon.lpc"
#define ANSI_PARSER "/obj/user/color_parser.lpc"

/* Objects */
#define HOUSE_OB "/room/housing/house_object.lpc"

/* ID's and Misc */
#define HOUSING_OBJECT_ID "EARWAXIAN_HOUSING_OBJECT_ID_GOES_HERE"

#define BANK     "/room/bank/bank.lpc"
#define HAH      "/room/housing/room_storage_room.lpc"
#define TEMPLATE "/room/housing/room_template.lpc"
#define UPGRADES "/room/housing/upgrades.txt"

/* Paths */
#define DATA        "/room/housing/data/"
#define BIN         "/room/housing/bin/"
#define HELPDIR     "/room/housing/help/"

/* Data Files */
#define LANDDATA    "/room/housing/land_data.o"
#define LANDSAVE    "room/housing/land_data"
#define LANDRESTORE "room/housing/land_data"

/* Logs */
#define BUG           "/room/housing/log/BUG"
#define BUG_CLONE_LOG "/room/housing/log/BUG_CLONE_LOG"
#define REGISTER      "/room/housing/log/REGISTER"
#define HOUSE_CLONE   "/room/housing/log/HOUSE_CLONE"
#define NOREGISTER    "/room/housing/log/NOREGISTER"
#define REGISTERED    "/room/housing/log/REGISTERED"
#define DIRS          "/room/housing/log/DIRS"
#define BOUGHT        "/room/housing/log/BOUGHT"
#define SELL          "/room/housing/log/SELL"

/* Backups */
#define LANDBAK1 "/room/housing/bak/landbak1"
#define LANDBAK2 "/room/housing/bak/landbak2"
#define LANDBAK3 "/room/housing/bak/landbak3"
