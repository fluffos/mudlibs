// Add defines for your custom objects for your mudlib in here.
// See mudlib.h as an example, but add them here to avoid conflicts with mudlib.h

#ifndef __SPACEMUD
#define __SPACEMUD

//Classes
#define SPACE_CLASSES   "/std/classes/space"

//Daemons
#define MISSION_D       "/daemons/mission_d"
#define SPACE_D         "/daemons/space_d"
#define SPACESTATION_D  "/daemons/spacestation_d"
#define SHIP_D          "/daemons/ship_d"
#define GOVERNANCE_D    "/daemons/governance_d"

//Items
#define SPACESHIP       "/std/spaceship"
#define SHIP_PATH(x)	sprintf("/data/ships/%c/%s",x[0],replace_string(base_name()[1..],"/","_"))
#define VDU_MENU        "/obj/mudlib/vdu_menu"
#define DOCKING_MENU    "/obj/mudlib/docking_menu"
#define SHIP_NAV_MENU   "/obj/mudlib/ship_nav_menu"

//Modules

#include "/domains/common/include/common.h"

#endif