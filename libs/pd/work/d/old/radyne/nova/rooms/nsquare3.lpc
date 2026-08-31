#include <std.h>
#include <radyne.h>

inherit ROOM;

void create() {
   ::create();
   set_properties( ([
      "outdoors" : 1,  "light" : 2,  "night light" : 1,  "town" : 1,
   ]) );
   set_short("Comera and Imperial Street");
   set_long(
      "%^BOLD%^%^BLUE%^Comera and Imperial Street%^RESET%^\n"
      ""
   );
   set_night_long(
      "%^BOLD%^%^BLUE%^Comera and Imperial Street%^RESET%^\n"
      ""
   );
   set_exits( ([
      "north" : ROOMS "nsquare4",
      "south" : ROOMS "nsquare2",
      "east" : ROOMS "m001e",
      "west" : ROOMS "m001w",
   ]) );
}


