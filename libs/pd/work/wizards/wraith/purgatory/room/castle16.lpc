#include <std.h>
#include <purgatory.h>

inherit ROOM;

void create() {
    ::create();
     add_pre_exit_function("stairs","go_stairs");
     set_name("castle16");
     set_short("The Purgatory Castle");
     set_long("%^BOLD%^%^CYAN%^West Corridor\n%^RESET%^"
"%^CYAN%^A large corridor with one side open to look out upon the "
"%^CYAN%^world. High %^BOLD%^%^BLACK%^black oak%^RESET%^%^CYAN%^ columns frame the openings like a porch "
"%^CYAN%^stretching the length of the castle. Lords and Ladies as well "
"%^CYAN%^as a few servants wander around admiring the view. Stairs "
"%^CYAN%^climb down slightly at the end of the corridor. ");
     set_properties(([
        "light"       : 2,
        "night light" : 1,
        "no bump"     : 1,
        "castle"      : 1,
        "no steal"    : 1,
]));
     set_listen("default", "Church-bells can be heard to the west.");
 set_exits( (["east" : ROOMS"castle11", 
              "stairs" : ROOMS"church1",
              "northwest" : ROOMS"castle20",
              "northeast" : ROOMS"castle19"]) );

    set_items( ([
        "column" : "%^BOLD%^%^BLACK%^Turned by the hand of a Master Woodcrafter, this column is pure art with a function.",
        "view" : "Gazing out on the town of Purgatory, a sense of well-being falls over you."
      ]) );


}
int go_stairs() {
  if(!this_player()->is_player()) return 0;
  return 1; }
