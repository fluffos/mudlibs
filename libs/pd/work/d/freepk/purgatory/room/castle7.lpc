
#include <std.h>
#include <purgatory.h>

inherit ROOM;

void create() {
    ::create();
     set_name("castle7");
     set_short("The Purgatory Castle");
     set_long("%^BOLD%^%^CYAN%^East Corridor\n%^RESET%^"
"%^CYAN%^A large corridor with one side open to look out upon the "
"%^CYAN%^world. High %^BOLD%^%^BLACK%^black oak%^RESET%^%^CYAN%^ columns frame the openings like a porch "
"%^CYAN%^stretching the length of the castle. Lords and Ladies as well "
"%^CYAN%^as a few servants wander around admiring the view. ");
     set_properties(([
        "light"       : 2,
        "night light" : 1,
        "no bump"     : 1,
        "castle"       : 1,
        "no steal"    : 1,
]));
 set_exits( (["east" : ROOMS"castle12", 
              "west" : ROOMS"castle6",
              "northeast" :ROOMS"castle18"]) );

    set_items( ([
        "column" : "%^BOLD%^%^BLACK%^Turned by the hand of a Master Woodcrafter, this column is pure art with a function.",
        "view" : "Gazing out on the town of Purgatory, a sense of well-being falls over you."
      ]) );


}
