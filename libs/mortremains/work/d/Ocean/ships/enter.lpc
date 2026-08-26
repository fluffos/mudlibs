// This is an example of how to use the inheritable ship_ob.c
#include <mudlib.h>
#include "../defs.h"

inherit SHIP ;

void create() {
  seteuid(getuid()) ;
  ::create();
  set("name", "USS Enterprise") ;
  set("ROOM_LIST", ({ "/u/c/chronos/area/ships/enter/ship1"
    }) ) ;
  set("arrival_msg", @ENDMSG
The USS Enterprise slowly sails into view.
ENDMSG
  );
  set("depart_msg", @ENDMSG
USS Enterprise slowly sails away.
ENDMSG
  );
  set("get_underway_msg", @ENDMSG
A loud whistle is heard from atop the Enterprise.
USS Enterprise is getting underway.
ENDMSG
 );
  set("get_moored_msg", @ENDMSG
A loud whistle is heard from atop the Enterprise.
Mooring lines are thrown out, and Enterprise is tied to the pier.
ENDMSG
  );
  set("underway_msg", @ENDMSG
A loud whistle is heard from somewhere onboard.
Someone shouts: Underway!
ENDMSG
  );
  set("moored_msg", @ENDMSG
A loud whistle is heard from somewhere onboard.
Someone shouts: Moored!
ENDMSG
  );
  set("id", ({ "#SHIP#", "enterprise", "uss enterprise", "ship" }) ) ;
  set("long", @ENDLONG
This is the mighty warship Enterprise.
ENDLONG
  );
  set("home_port", ROOMS(pier1-2)) ;
  commission_ship() ;
}
