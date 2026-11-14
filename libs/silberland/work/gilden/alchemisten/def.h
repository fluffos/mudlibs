#include <defines.h>
#include <moredef.h>

#define NPC     "/gilden/alchemisten/npc/"
#define OBJ     "/gilden/alchemisten/obj/"
#define ARMOUR  "/gilden/alchemisten/obj/"
#define WEAPON  "/gilden/alchemisten/obj/"
#define LOG     "/gilden/alchemisten/log/"
//#define ROOM    "/d/dschungel/feyaria/felseninsel/room/"

#define BMASTER "/gilden/alchemisten/master/alchemistenmaster"
#define MEMBERLIST "/gilden/alchemisten/members/members"

#define BS(x) break_string(x, 78)
#define DB(x) if (find_player("stahldorn")) \
   tell_object(find_player("stahldorn"),("Debug sagt: "+x+"\n"))

#define P_ALCH_ELIXIER "alch_elixier"
#define P_ALCH_QUALITY "alch_quality"
#define MATMASTER "/p/daemon/materialdb.lpc"
#define MATUNIT "/gilden/alchemisten/obj/material.lpc"



