// Top of White Tower

#include <std.h>
#include "../../serakii.h"

inherit CROOM;

void create(){
   ::create();
   set_terrain(CITY);
   set_travel(PAVED_ROAD);
   set_climate("temperate");
   set_property("light", 2);
   set_indoors(0);
   set_name("top of the tower");
   set_short("%^C252%^top of the tower%^CRST%^");
   set_long("%^C111%^You have reached the top "+
   "of the %^C255%^white tower%^C111%^. From "+
   "here you can see in every direction. To "+
   "the South you can see a %^C094%^small "+
   "inn%^C111%^, and a %^C226%^field %^C111%^"+
   "beyond it. To the east a %^C029%^massive "+
   "forest%^C111%^. To the northeast and "+
   "northwest stand two other towers, "+
   "one %^C001%^Red%^C111%^, and the "+
   "other %^C241%^Black%^C111%^. Directly "+
   "to the north is a %^C060%^ruined "+
   "town%^C111%^, and beyond that a "+
   "%^C252%^shining smaller city%^C111%^ "+
   "on a hill. In the middle of the tower "+
   "roof there is a %^C243%^hole %^C111%^"+
   "for something to be inserted, "+
   "though its not clear what.%^CRST%^\n" );

set_exits(([
"down" : WHITE"27",

]));

   set_items(([
      ({"hole","empty hole"}) : "%^C242%^This hole in the floor is three inches wide, and a foot deep. The stone around the hole is well worn, so something belongs in it, but there is no other indication what.%^CRST%^",
     
    ]));

set_smell("default","%^C111%^You smell %^C250%^fresh %^C111%^air%^CRST%^");
set_listen("default","%^C250%^Its hard to hear anything over the %^C044%^wind%^C250%^!%^CRST%^");

}
