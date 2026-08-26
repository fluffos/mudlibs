// Hound Tent

#include <std.h>
#include "../serakii.h"

inherit CROOM;

void create(){
   ::create();
   set_terrain(CITY);
   set_travel(PAVED_ROAD);
   set_climate("temperate");
   set_property("light", 2);
   set_indoors(1);
   set_name("black canvas tent");
   set_short("%^C244%^bla%^C058%^c%^C244%^k "+
   "c%^C058%^a%^C244%^nvas "+
   "te%^C058%^n%^C244%^t%^CRST%^");
   set_long("%^C058%^This tent, made from %^C244%^thick black canvas%^C058%^ could be used in any %^C028%^region%^C058%^ and any %^C080%^season%^C058%^ and occupants safe and comfortable. It is tall enough to allow for even a large race to stand. The tent is lit with a single %^C247%^large iron lantern%^C058%^ hung from the top of the tent. The floor has been covered with %^C227%^straw%^C058%^.%^CRST%^\n" );
 
   set_items(([
      ({"floor","straw"}) : "%^C228%^The floor is covered in "+
	  "a layer of straw to keep it dry and clean in the tent.%^CRST%^",
      ({"lantern","iron lantern"}) : "%^C248%^A large lantern "+
	  "hangs from the ceiling and %^C229%^lights %^C248%^the "+
	  "entire tent.%^CRST%^",
    ]));

set_smell("default","%^C058%^You smell %^C246%^"+
"pitch%^C058%^ and %^C227%^straw%^C058%^.%^CRST%^");
set_listen("default","%^C248%^You hear the sound "+
"of the %^C094%^camp %^C248%^outside.%^CRST%^");
  
}

void reset(){
   ::reset();

}
