#include <std.h>
#include "../tharis.h"
inherit STORAGE"boroughs";

void create(){
   ::create();
   set_long(::query_long()+" %^RESET%^%^CRST%^%^C244%^Between two of the buildings to the south is a tight alleyway and to the east is a foreboding compound.%^CRST%^\n");
   set_exits(([
      "east" : ROOMS"elf1",
      "west" : ROOMS"east2",
      "south" : ROOMS"thief_tailor",
   ]));
   set_invis_exits(({"south"}));
}

