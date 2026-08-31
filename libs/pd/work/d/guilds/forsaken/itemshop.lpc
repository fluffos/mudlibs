#include <std.h>
#include <guild.h>
inherit ROOM;
void create() {
   ::create();
   set_name("Forsaken selling");
   set_items((["coldfire"   : "%^BLUE%^The fire is magical.%^RESET%^",
               "tools"  : "Tools used in forging items."]));
 set_properties( ([ "no attack"   : 1,
                    "no magic"    : 1,
                    "no bump"     : 1,
                    "light"       : 2,
                    "night light" : 2,
		    "no teleport" : 1,
		    "no scry" : 1,
		    "indoors" : 1,
                    "no steal"    : 1 ]) );

   set_short("Forsaken Shop");
   set_long("This is the shop of the Forsaken.  A large %^BOLD%^%^BLUE%^blue coldfire%^RESET%^ burns " 
            "here where the weapons of the Forsaken are forged.  An anvil and tools sit next to the forge.");
   set_smell("default", "The smell of iron and weapon oil wafts in the air.");
   set_exits(([
       "south" : ROOMS"forsaken/hall",
   ]));
}
void reset() {
   ::reset();
   if(!present("darius"))
   new(ROOMS"forsaken/mob/darius")->move(this_object());
}
