// This is an example of how to use the inheritable ship_ob.c
#include <mudlib.h>
//#include "../defs.h"

inherit SHIP ;

void create() {
  seteuid(getuid()) ;
  ::create();
  set("name", "USS Saipan") ;
  set("ROOM_LIST", ({ "/d/Ocean/ships/saipan/ship1",
    }) ) ;
  set("arrival_msg", @ENDMSG
USS Saipan slowly sails into view.
ENDMSG
  );

  set("depart_msg", @ENDMSG
USS Saipan slowly sails away.
ENDMSG
  );
  set("get_underway_msg", @ENDMSG
A loud whistle is heard from atop the Saipan.
USS Saipan is getting underway.
ENDMSG
 );
  set("get_moored_msg", @ENDMSG
A loud whistle is heard from atop the Saipan.
Mooring lines are thrown out, and Saipan is tied to the pier.
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
  set("id", ({ "#SHIP#", "saipan", "uss saipan", "ship" }) ) ;
  set("long", @ENDLONG
This is the mighty warship Saipan, one of the largest ships in the fleet.
ENDLONG
  );
  set("home_port", "/d/Ocean/Ocean/default_pier") ;
  commission_ship() ;
}
