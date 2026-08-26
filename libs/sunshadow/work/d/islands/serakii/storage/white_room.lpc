// White Tower room

#include <std.h>
#include "../serakii.h"

inherit CVAULT;

void create(){
   ::create();
   set_terrain(CITY);
   set_travel(PAVED_ROAD);
   set_climate("temperate");
   set_property("light", 2);
   set_indoors(1);
   set_name("cramped office");
   set_short("%^C095%^cramped office%^CRST%^");
   set_long("%^C109%^This office in the tower is %^C088%^cramped%^C109%^, and has a completely different feel than the rest of the tower. The %^C255%^stone walls%^C109%^ have been covered in %^C094%^wood paneling%^C109%^ and the %^C111%^rug %^C109%^here is thicker and more comfortable. %^C094%^Crates %^C109%^line the walls and a %^C094%^small desk%^C109%^ is set in the corner. The room is %^C226%^lit %^C109%^with a %^C094%^single torch%^C109%^ hung on one %^C094%^wall%^C109%^.  %^CRST%^\n" );



   set_items(([
      ({"desk","small desk"}) : "%^C094%^This small desk is filled with %^C251%^papers %^C094%^and %^C029%^maps%^C094%^.%^CRST%^",
      ({"walls","wood paneling"}) : "%^C060%^The %^C255%^stone walls%^C060%^ here have been covered in %^C094%^wood paneling%^C060%^, helping with %^C088%^warmth %^C060%^and %^C038%^quiet%^C060%^. %^CRST%^",
      ({"rug","blue rug"}) : "%^C111%^The rug here is %^C021%^deep blue%^C111%^ and has been replaced quite recently. It is soft and warm.%^CRST%^",
      ({"torch","sconce"}) : "%^C059%^The room is %^C226%^lit%^C059%^ with a %^C094%^single torch%^C059%^ in an %^C242%^iron sconce%^C059%^. %^CRST%^",
     
    ]));

set_smell("default","%^C094%^You smell wood polish.%^CRST%^");
set_listen("default","%^C072%^The room is quiet.%^CRST%^");

}

