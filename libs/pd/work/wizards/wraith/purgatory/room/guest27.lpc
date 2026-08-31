#include <std.h>
#include <purgatory.h>

inherit ROOM;

void create() {
    ::create();
     set_name("guest");
     set_short("The Guest Quarters");
     set_long("%^RED%^Bl%^BOLD%^%^RED%^o%^RESET%^%^RED%^od %^RESET%^splatters the doorway and the nearest walls. The room "
"has been halfway torn down by what happened in the east hall. "
"The former occupants of this room were %^BOLD%^%^BLACK%^s%^RESET%^%^RED%^lau%^BOLD%^%^RED%^ght%^RESET%^%^RED%^ere%^BOLD%^%^BLACK%^d%^RESET%^ in the "
"following confusion.");
     set_properties(([
        "light"       : 2,
        "night light" : 1,
        "no bump"     : 1,
        "no steal"    : 1,
]));
 set_exits( (["out" : ROOMS"guest5" ]) );

    set_items( ([
        "blood" : "Splattered across the only remaining walls is the blood of this rooms former occupants.",
        "doorway" : "As you turn around to look at the doorway, you see the human head that has been stuck above it, its face contorted in the rigors of death.",
        "walls" : "Entrails and blood have been smeared all over the remaining walls.",
        "wall" : "A small finger has been jammed into the wall behind you."
      ]) );


}

