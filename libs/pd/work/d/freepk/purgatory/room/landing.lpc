#include <std.h>
#include <purgatory.h>
#include <daemons.h>

inherit BEACH;
#include <ocean.h>

void create() {
::create();
set_short("A black sandy beach");
set_day_long("%^BOLD%^%^CYAN%^Waves %^RESET%^crash against the %^BOLD%^%^BLACK%^black%^RESET%^ sandy beach. "
             "A fine mist hangs in the air. Off to the west, a rather large forest "
             "spreads out as far as the eye can see. Small animal tracks lead into the foliage. "
             "A large sign as been stuck into the sand, near where any rafts would land, "
             "<look sign> would be helpful right about now.");
set_night_long("%^BOLD%^%^BLACK%^Darkness%^RESET%^ has decended upon the land. "
"Visibility has dwindeled down to nothing as the %^BOLD%^%^BLACK%^black %^RESET%^sand absorbs "
"all of the stray light. A large sign as been stuck into the sand, near where any rafts would land, "
             "%^BOLD%^%^RED%^<look sign>%^RESET%^ would be helpful right about now.");
set_items(([
"sand" : "%^BOLD%^%^BLACK%^The dark sandy beach runs out of sight to the north and south. Little bits of %^RESET%^white%^BOLD%^%^BLACK%^ shells have been scattered about the footprints.",
"blood" : "Small amounts of sticky %^BOLD%^%^RED%^b%^RESET%^%^RED%^l%^BOLD%^%^RED%^oo%^RESET%^%^RED%^d%^RESET%^ lies in pools near the graveyard.",
"trees" : "Shadows flicker and move about the trees to the northwest. It would be best if you used a large amount of caution while exploring.",
"beach" : "The beach is made out of %^BOLD%^%^BLACK%^ black sand %^RESET%^ and runs to the north and south.",
"footprints" : "Many footprints have been embedded into the soft sands, leaving criss-crossing trails everywhere.",
]));
set_no_clean(1);
set_properties((["light" : 1, 
                 "night light" : 0,
                 "no castle" : 1,
                 "beach" : 1,]));
set_exits(([
"northeast": ROOMS"beach2",
"southwest" : ROOMS"beach3",
]));
set_listen("default","Waves crash against the shore, blowing mist into the air");
set_smell("default","Saltwater and other smells of the sea permeate the air");
set_letter("j");
}
void reset() {
 ::reset();


  if (!present("sign", this_object()))
      new("/wizards/wraith/purgatory/item/beachsign" )->move(this_object());
}
