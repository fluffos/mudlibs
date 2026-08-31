#include <std.h>
#include <purgatory.h>

inherit ROOM;

void create() {
    ::create();
     add_pre_exit_function("out","go_stairs");
     set_name("castle1");
     set_short("The Purgatory Castle");
     set_long("%^BOLD%^%^CYAN%^The Castle Entrance%^RESET%^\n"
"%^CYAN%^Welcome to Purgatory Castle. Built on an ancient graveyard by "
"%^CYAN%^a foolish ruler long ago, this castle houses spirits as well "
"%^CYAN%^as the living. An elaborate domed ceiling crests this "
"%^CYAN%^entrance. Lit torches and braziers line the hallways to fend "
"%^CYAN%^off the chill that seems to waft through the air. ");
     set_properties(([
        "light"       : 2,
        "night light" : 1,
        "no bump"     : 1,
        "castle"      : 1,
        "no steal"    : 1,
]));
 set_exits( (["east" : ROOMS"castle6", 
              "west" : ROOMS"castle5",
              "north" : ROOMS"castle2",
              "northwest" : ROOMS"castle4",
              "northeast" : ROOMS"castle3",
              "out" : ROOMS"gatehousen"]) );


}
int go_stairs() {
  if(!this_player()->is_player()) return 0;
  return 1; }
