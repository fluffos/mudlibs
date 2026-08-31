#include <std.h>
#include <purgatory.h>

inherit ROOM;

void create() {
    ::create();
     add_pre_exit_function("stairs","go_stairs");
     set_name("castle9");
     set_short("The Purgatory Castle");
     set_long("%^BOLD%^%^CYAN%^Main Hallway\n%^RESET%^"
"%^CYAN%^Lining the walls of this hallway are the tapestries of the "
"%^CYAN%^Royal Court. A small fountain produces a cascading waterfall "
"%^CYAN%^in the center of the room. Petitioning peasants scamper "
"%^CYAN%^around trying to get their petitions read. A slight chill "
"%^CYAN%^passes by every now and then..");
     set_properties(([
        "light"       : 2,
        "night light" : 1,
        "no bump"     : 1,
        "castle"      : 1,
        "no steal"    : 1,
]));
     set_listen("default", "Joyous laughter echoes around the hallways.");
 set_exits( (["east" : ROOMS"castle22", 
              "west" : ROOMS"castle21",
              "north" : ROOMS"castle14",
              "south" : ROOMS"castle2",
              "northeast" : ROOMS"castle33",
              "northwest" : ROOMS"castle34",
              "stairs" : ROOMS"guest2"]) );

    set_items( ([
        "tapestry" : "%^BOLD%^%^CYAN%^Many tapestries line this room, most of the depicting major battles won over the centuries by the rules of Purgatory"
      ]) );


}

void reset() {
 ::reset();
  if (!present("fountain", this_object()))
    new(ITEMS"fountain" )->move(this_object());
}
int go_stairs() {
  if(!this_player()->is_player()) return 0;
  return 1; }
