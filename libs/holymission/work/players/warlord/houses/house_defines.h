
/* house_defines.h      Metaprat       16th April   */

/* various definitions used in the houses */

#define WIZLEVEL     30

/* how much junk goes into /log/LOGFILE */
#define DEBUGLEVEL   1

/* various files used in the houses */
#define HOUSES_DIR   "players/silas/houses/"
#define ROOMS        ("/" + HOUSES_DIR + "house_room")
#define INVITATIONS  ("/" + HOUSES_DIR + "house_invite")
#define MAPS         ("/" + HOUSES_DIR + "house_map")
#define ESTATEAGENT  ("/" + HOUSES_DIR + "estate_agent")
#define HOUSEKEEPER  ("/" + HOUSES_DIR + "house_keeper")
#define HOUSEHELP    ("/" + HOUSES_DIR + "house_help")
#define INVITATIONS  ("/" + HOUSES_DIR + "house_invite")
#define MASTERHOUSE  ("/" + HOUSES_DIR + "master_house")
#define HOUSEKEY     ("/" + HOUSES_DIR + "house_key")
#define HOUSE        ("/" + HOUSES_DIR + "house")

/* 'special' exit destinations */
#define CHURCH       "/room/church"
#define GUILD        "/room/adv_guild"
#define SHOP         "/room/main_shop"

#define LOGFILE      "silas.house"

/* timeout period for maps & invites to turn to dust */
#define TIMEOUT      240

/* the number of rooms. NOTE: house_map RELIES on this being 10 or less. */
#define MAXNUMROOMS  10

/* maximum size of a description. Should be < max str size & max write size */
#define MAXDESCLEN   1200
#define MAXDESCLINES 20

/* charges for various building jobs etc. */
#define HOUSECOST    15000
#define ROOMCOST     5000
#define KEEPERCOST   2000
#define DECORCOST    500
#define DOORCOST     1000
#define INVITECOST   200
#define MAPCOST      100

/* Door types, and state */
#define DOOR_NONE    0
#define DOOR_NORM    1
#define DOOR_L_LOCK  10
#define DOOR_L_UNLK  11
#define DOOR_L_OPEN  12
#define DOOR_O_CLOS  20
#define DOOR_O_OPEN  21
#define DOOR_PORTAL  30

/* Code fragments */
#define GETOWNER     main_hall->query_owner()
#define GETINDEX     main_hall->get_room_index(loc_x, loc_y)
#define GETLONG      main_hall->query_desc(this_room_index)


