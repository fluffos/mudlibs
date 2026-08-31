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
      "west" : ROOMS "esquare7",
      "east" : ROOMS "esquare9",
      "south" : ROOMS "m010e",
      "north" : ROOMS "m009e",
   ]) );
}


