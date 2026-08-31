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
      "north" : ROOMS "ssquare4",
      "south" : ROOMS "ssquare6",
      "east" : ROOMS "tr21e",
      "west" : ROOMS "tr21w",
   ]) );
}


