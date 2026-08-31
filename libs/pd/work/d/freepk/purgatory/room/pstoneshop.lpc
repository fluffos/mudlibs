#include <std.h>
#include <purgatory.h>

inherit ROOM;

void create() {
    ::create();
     set_name("Dorf's Place");
     set_short("Dorf's Place");
     set_long("%^RESET%^%^ORANGE%^Dorf's Place.%^RESET%^\n"
"%^BOLD%^%^BLACK%^And an odd place this is, everything is about knee height, "
"%^BOLD%^%^BLACK%^including the chairs and tables. An insane cackling can be "
"%^BOLD%^%^BLACK%^heard from the back of the store where it looks like a pygmy "
"%^BOLD%^%^BLACK%^as set up shop. Odd shapes hang from raftors in the back of "
"%^BOLD%^%^BLACK%^the store, and walking closer just makes them drift out of focus.");
     set_properties(([
        "light"       : 2,
"no attack"   : 1,
        "no bump"     : 1,
        "indoors"     : 1,
        "no steal"    : 1,
]));
 set_exits( (["north" : ROOMS"purgatory5", ]) );


    set_items( ([
        ({"chairs", "chair"})  : "Sitting in one of these would either adhere to your rump or break the chair!",
        ({"table", "tables"}) : "These tables look more like large footstools!",
        "raftors" : "Not much can be made out from the raftors, it looks like a magical barrier of sorts...",
        "shapes" : "Small fist sized shapes sway amonst the raftors, toohazy to be made out."
      ]) );

}

void reset() {
 ::reset();
  if (!present("dorf", this_object()))
    new(MOBS"dorf" )->move(this_object());
}
