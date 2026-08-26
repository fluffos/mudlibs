// This is an example of how to use the inheritable ship_ob.c
#include <mudlib.h>

inherit SHIP ;

void create() {
  seteuid(getuid()) ;
  ::create();
  set("name", "Pirate Ship") ;
  set("ROOM_LIST", ({ "/d/Ocean/ships/pirates/ship1"
    }) ) ;
  set("arrival_msg", @ENDMSG
A pirate ship slowly sails into view.
ENDMSG
  );
  set("depart_msg", @ENDMSG
The pirate ship slowly sails away.
ENDMSG
  );
  set("get_underway_msg", @ENDMSG
Someone far above on the pirate ship yells out: AVAST!  PREPARE TO GET UNDERWAY!
Several men untie the ship from the pier and haul the lines in.
ENDMSG
 );
  set("get_moored_msg", @ENDMSG
Someone far above on the pirate ship yells out: AVAST!  PREPARE TO MOORE THE SHIP!
Several men scurry out onto the pier and secure the ship the pier.
ENDMSG
  );
  set("underway_msg", @ENDMSG
A loud whistle is heard from somewhere onboard.
Someone shouts: She's underway, ye scurvy dogs!
ENDMSG
  );
  set("moored_msg", @ENDMSG
A loud whistle is heard from somewhere onboard.
Someone shouts: She's moored, ye landlubbers!  
ENDMSG
  );
  set("id", ({ "pirateship", "pirate ship", "ship" }) ) ;
  set("long", @ENDLONG
This large wooden sailing ship looks as though it has been around the world a
hundred times.  The most noticable feature is the Jolly Roger flapping in the
breeze.
This could only be the ship of the Dread Pirate Dan.
ENDLONG
  );
  set("home_port", "/d/Ocean/Ocean/default_pier") ;
  commission_ship() ;
}
