#include <std.h>
#include <guild.h>
inherit ROOM;
void create() {
::create();
  set_name("Magic shop");
 set_properties( ([ "no attack"   : 1,
                    "no magic"    : 1,
                    "no bump"     : 1,
                    "light"       : 2,
                    "night light" : 2,
		    "no teleport" : 1,
		    "no scry" : 1,
		    "indoors" : 1,
                    "no steal"    : 1 ]) );

  set_short("Forsaken Magic Shop");
  set_long("This is the Mystic Shop of the Forsaken Guild. The room is lit with dim blue "
           "flames a large counter is in the middle of the room a large pillar of %^BOLD%^%^BLUE%^blue fire%^RESET%^ "
           "stands on the west side of the room. A sign hangs on the wall." );
  set_exits(([
     "up" : ROOMS"forsaken/hall",
  ]));
}
void reset() {
   ::reset();
   if(!present("shengar"))
   new(ROOMS"forsaken/mob/shengar")->move(this_object());
}
