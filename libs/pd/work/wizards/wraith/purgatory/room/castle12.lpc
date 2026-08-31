#include <std.h>
#include <purgatory.h>

inherit ROOM;

void create() {
    ::create();
     add_pre_exit_function("stairs","go_stairs");
     set_name("castle12");
     set_short("The Purgatory Castle");
     set_long("%^BOLD%^%^CYAN%^East Corridor\n%^RESET%^"
"%^CYAN%^A large corridor with one side open to look out upon the "
"%^CYAN%^world. High %^BOLD%^%^BLACK%^black oak%^RESET%^%^CYAN%^ columns frame the openings like a porch "
"%^CYAN%^stretching the length of the castle. Lords and Ladies as well "
"%^CYAN%^as a few servants wander around admiring the view. A Large "
"%^CYAN%^set of stairs lead down into the cemetary. ");
     set_properties(([
        "light"       : 2,
        "night light" : 1,
        "no bump"     : 1,
        "castle"      : 1,
        "no steal"    : 1,
]));
     set_listen("default", "Strange moaning and crying can be heard near here.");
 set_exits( (["stairs" : ROOMS"cemetary1", 
              "west" : ROOMS"castle7",
              "northwest" :ROOMS"castle18",
              "northeast" :ROOMS"castle17"]) );

    set_items( ([
        "column" : "%^BOLD%^%^BLACK%^Turned by the hand of a Master Woodcrafter, this column is pure art with a function.",
        "view" : "Gazing out on the town of Purgatory, a sense of well-being falls over you."
      ]) );


}
int go_stairs() {
  if(!this_player()->is_player()) return 0;
  return 1; }
