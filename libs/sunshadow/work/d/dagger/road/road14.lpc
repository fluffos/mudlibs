#include <std.h>
#include "/d/dagger/road/short.h"

inherit ROOM;

void create(){
    ::create();
   set_terrain(OLD_MOUNTS);
   set_travel(DIRT_ROAD);
    set_property("light", 2);
    set_short("The Dagger Sea coast road.");
    set_long(
      "%^CYAN%^You are on the Dagger Seacoast road. To the northwest you can see %^RESET%^%^GREEN%^the emerald hills%^RESET%^%^CYAN%^ of the Yniam plains. To the northeast, the walls of a large marble white temple block your view of the %^BOLD%^%^BLUE%^seaport of Torm%^RESET%^%^CYAN%^. To the east are the %^RESET%^%^ORANGE%^golden beaches%^RESET%^%^CYAN%^ of the dagger seacoast and the %^BOLD%^%^BLACK%^high cliffs%^RESET%^%^CYAN%^ that ring them. From here, you can even just make out a few %^BOLD%^%^BLACK%^caves%^RESET%^%^CYAN%^ in the cliffs that line the southern half of the beach. "
    );
    set_smell("default", "You can smell the salts of the sea on the cool breeze.");
    set_listen("default", "The sound of the waves on the cliffs below float up to your ears.");
    set_items( ([
	"beaches" : "Golden sand lines the beaches along the Dagger Sea.",
	"sea" : "The great waves crash against teh cliffs hundreds of feet below.",
	"torm" : "The great seaport of Torm promises rum, fine inns and fresh fish, but it's hard to see here due to the large temple directly ahead.",
	"caves" : "It is hard to make out much more from there. You may find a path past the city of Torm.", 
	"temple" : "A grand temple with marble walls stand upon the cliff. The entrance seems to be a little further north.",
      ]) );
    set_exits( ([
	"northeast" : RPATH "road15",
	"southwest" : RPATH "road13",
      ]) );
}
