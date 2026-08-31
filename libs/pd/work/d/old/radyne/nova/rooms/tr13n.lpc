#include <std.h>
#include <radyne.h>

inherit ROOM;

void create() {
   ::create();
   set_properties( ([
      "outdoors" : 1,  "light" : 2,  "night light" : 1,  "town" : 1,
   ]) );
   set_short("Comera and Square Street");
   set_long(
      "%^BOLD%^%^BLUE%^Comera and Square Street%^RESET%^\n"
      ""
   );
   set_night_long(
      "%^BOLD%^%^BLUE%^Comera and Square Street%^RESET%^\n"
      ""
   );
   set_exits( ([
      "north" : ROOMS "tr14n",
      "south" : ROOMS "tr12n",
      "east" : ROOMS "m005e",
      "west" : ROOMS "m004e",
   ]) );
}


