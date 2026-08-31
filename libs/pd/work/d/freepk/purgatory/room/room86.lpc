#include <std.h>
#include <purgatory.h>

inherit ROOM;

void create() {
    ::create();
     set_name("The Mortuary");
     set_short("The Mortuary");
     set_long("The entrance to the mortuary looks to be very elegant. "
"The walls and floor have been made of %^BOLD%^%^BLACK%^black %^BOLD%^%^WHITE%^ma%^BOLD%^%^BLACK%^rb%^BOLD%^%^WHITE%^le%^RESET%^ "
"so highly posished that there are reflections of the other items in the room. "
"A strange sense of being watched feels like it has been embedded into the walls. "
"A deathly silence mutes out all the ghastly sounds from outside. "
"Ornate chairs and tables rest against the walls "
"for the many mourners that pass through here.");
     set_properties(([
        "light"       : 2,
        "night light" : 1,
        "no bump"     : 1,
        "castle"      : 1,
        "no steal"    : 1,
]));
 set_exits( (["northeast" : ROOMS"room33",
              "southeast" : ROOMS"room32", 
              "west" : ROOMS"room5",
              "east" : ROOMS"room34"]) );
 set_listen("default", "The clicking of a clock can be heard in the distance.");
 set_smell("default", "A light scent of beeswax floats off the wookwork of the furniture.");
    set_items( ([
        "walls" : "These walls have been made from a rare black marble.",
        "floor" : "The floor has been polished to a high sheen.",
        "chair" : "Turned black oak legs hold up a silky cushion on a finely guilded and carved chair.",
        "table" : "A heavy solid slab of stained oak rests on legs that look to be foritified wood.",

      ]) );


}
