#include <std.h>
#include <radyne.h>

inherit ROOM;

void create() {
   ::create();
   set_properties( ([
      "outdoors" : 1,  "light" : 2,  "night light" : 1,  "town" : 1,
   ]) );
   set_short("Imperial and Square Street");
   set_long(
      "%^BOLD%^%^BLUE%^Imperial and Square Street%^RESET%^\n"
      ""
   );
   set_night_long(
      "%^BOLD%^%^BLUE%^Imperial and Square Street%^RESET%^\n"
      ""
   );
   set_exits( ([
      "north" : ROOMS "nsquare6",
      "south" : ROOMS "nsquare4",
      "east" : ROOMS "tr01e",
      "west" : ROOMS "tr01w",
   ]) );
}


