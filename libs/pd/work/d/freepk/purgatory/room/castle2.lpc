#include <std.h>
#include <purgatory.h>

inherit ROOM;

void create() {
    ::create();
     add_pre_exit_function("stairs","go_stairs");
     set_name("castle2");
     set_short("The Purgatory Castle");
     set_long("%^BOLD%^%^CYAN%^Main Hallway\n%^RESET%^"
"%^CYAN%^Adorned with gilded tables, chairs, and other scattered "
"%^CYAN%^artworks, this hallway was built in excess to impress. "
"%^CYAN%^Petitioning peasants scamper around trying to get their "
"%^CYAN%^petitions read. A slight chill passes by every now and then..");
     set_properties(([
        "light"       : 2,
        "night light" : 1,
        "no bump"     : 1,
        "castle"      : 1,
        "no steal"    : 1,
]));
 set_exits( (["north" : ROOMS"castle9", 
              "south" : ROOMS"castle1",
              "northwest" : ROOMS"castle32",
              "northeast" : ROOMS"castle31",
              "stairs" : ROOMS"guest1"]) );

    set_items( ([
        "tables" : "%^BOLD%^%^ORANGE%^G%^BOLD%^%^WHITE%^i%^BOLD%^%^ORANGE%^l%^WHITE%^d%^ORANGE%^e%^WHITE%^d tables line the room",
        "chairs" : "%^BOLD%^%^ORANGE%^G%^BOLD%^%^WHITE%^i%^BOLD%^%^ORANGE%^l%^WHITE%^d%^ORANGE%^e%^WHITE%^d chairs lay scatterd about the room"
      ]) );


}
int go_stairs() {
  if(!this_player()->is_player()) return 0;
  return 1; }
