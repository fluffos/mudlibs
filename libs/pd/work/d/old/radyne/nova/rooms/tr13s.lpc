#include <std.h>
#include <radyne.h>

inherit ROOM;

void create() {
   ::create();
   set_properties( ([
      "outdoors" : 1,  "light" : 2,  "night light" : 1,  "town" : 1,
   ]) );
   set_short("Radyne Nova - Street");
   set_long(
      "%^BOLD%^%^BLUE%^Radyne Nova: Street%^RESET%^\n"
      ""
   );
   set_night_long(
      "%^BOLD%^%^BLUE%^Radyne Nova: Street%^RESET%^\n"
      ""
   );
   set_exits( ([
      "south" : ROOMS "tr14s",
      "north" : ROOMS "tr12s",
      "east" : ROOMS "m014e",
   ]) );
}


