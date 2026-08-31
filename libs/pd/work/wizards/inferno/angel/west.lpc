#include <std.h>
inherit ROOM;

void create() {
 ::create();
   set_short("%^BOLD%^%^YELLOW%^The West Chamber of Love%^RESET%^");
   set_long("%^BOLD%^%^WHITE%^Near the far western side of the wall, steps descend into a "
"%^BOLD%^%^WHITE%^shallow pool. The waters of the pool are a %^BOLD%^%^YELLOW%^light silvery%^BOLD%^%^WHITE%^ "
"%^BOLD%^%^WHITE%^%^BOLD%^%^YELLOW%^color.%^BOLD%^%^WHITE%^ Looking closely at the pool, a still unmoving silver "
"%^BOLD%^%^WHITE%^surface, one can view their own reflection. This room is %^BOLD%^%^YELLOW%^very%^BOLD%^%^WHITE%^ "
"%^BOLD%^%^WHITE%^%^BOLD%^%^YELLOW%^bright%^BOLD%^%^WHITE%^ and %^BOLD%^%^YELLOW%^always%^BOLD%^%^WHITE%^ filled with %^BOLD%^%^YELLOW%^light%^BOLD%^%^WHITE%^, night or day, though the "
"%^BOLD%^%^WHITE%^source cannot be seen.");
   set_properties(([ "no attack" : 1, "no magic" : 1, "no bump" : 1,
     "no steal" : 1, "no teleport" : 1, "indoors" : 1, "light" : 2 ]));
   set_items(([
     "pool"  :     "The pool is large enough for you to wade in.",
     "water" :     "Silver waters lay in a still pool.",
     "steps" :     "They decend into the silver pool.",
     "closely" :   "You look at yourself in the mirror-like surface of the pool.",
     "reflection": "You look upon a stunningly elegant and magnificent archangel."
   ]));
   set_exits(([ "east" : "/wizards/inferno/angel/main" ]));
}

int wade(string str) {
   write("You slowly lower yourself into the silver waters.");
   this_player()->move_player("/wizards/inferno/angel/pool", "pool");
   return 1;
}

void init() {
 ::init();
   add_action("wade", "wade");
}
