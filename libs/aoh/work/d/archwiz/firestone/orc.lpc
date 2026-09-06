#include "path.h"
#include <properties.h>
#include <rooms.h>

inherit "/std/npc";

create() {
  int x;
  if (::create()) return;
  SetName("orc");
  SetShort("large orc");
  SetLong("A nasty looking, strong orc.\n");
  SetRace("orc");
  SetAggressive(1);
  SetLevel(6);
  SetHands( ({ ({"left hand",0,6}),({"right hand",0,6}) }) );
  SetAttribute("MagicDefence",random(20)+5);
  SetAC(1);
  SetGender(1);
  SetAlign(-150);
  InitAChats(10,({"An orc says: Kill him!\n",
  "One orc says: Leave or die!\n","One orc says: Die scum!\n",
  "One orc says: Barbeque time, alright!\n","An orc says: Must be lunch time, the food is here!\n",
  "An orc says: Kill him quickly, don't want to spoil the meat!\n"}));
  x=random(4);
  AddItem(FIRESTONE("weapon"+x),REFRESH_REMOVE,#'wieldme);
}
