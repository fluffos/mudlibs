#include <std.h>
#include <radyne.h>

inherit ROOM;

void create() {
   ::create();
   set_properties( ([
      "outdoors" : 1,  "light" : 2,  "night light" : 1,  "town" : 1,
   ]) );
   set_short("Adian Highway and Comera");
   set_long(
      "%^BOLD%^%^BLUE%^Adian Highway and Comera%^RESET%^\n"
      ""
   );
   set_night_long(
      "%^BOLD%^%^BLUE%^Adian Highway and Comera%^RESET%^\n"
      ""
   );
   set_exits( ([
      "west" : ROOMS "wsquare9",
      "east" : ROOMS "wsquare7",
      "south" : ROOMS "m010w",
      "north" : ROOMS "m009w",
   ]) );
}


