#include <properties.h>
#include <rooms.h>
#include "path.h"

inherit "std/npc";

block_up() {
  if (!this_object()) return 0;
  if (!environment(this_object())) return 0;
  write("The cyclops growls fiercely! You consider your move again.\n");
  tell_room(environment(this_object()),
    "As "+this_player()->QueryName()+" tries to go up, the cyclops\n"+
      "starts to growl fiercely. "+this_player()->QueryName()+" stops "
      +this_player()->QueryPossessive()+" attempt.\n",({this_player()}));
  return 1;
}

create() {
  if (::create()) return 1;
  SetName("cyclops");
  SetShort("A huge cyclop");
  SetLong(
"The cyclop looks very mean. He probably likes to eat luckless adventurers.\n");
  SetRace("cyclop");
  SetGender(GENDER_MALE);
  SetNoise("You hear heavy breathing.\n");
  SetSmell("It smells like rotten flesh.\n");
  SetWeight(250000);
  SetIds(({"cyclop"}));
  SetAds(({"huge","a"}));
  SetLevel(12);
  SetAlign(-300);
  SetAC(8);
  SetSize(PSIZE_LARGE);
  SetAttribute("MagicDefence",35);
  SetHands(({({"left hand",0,14}),({"right hand",0,14})}));
  InitChats(20,({
	"Cyclop says: There is my breakfast!\n",
	"Cyclop says: I'll crush you under my feet!\n",
	"The Cyclop stares at you with his single eye.\n"
  }));
  InitAChats(10,({
	"Cyclop says: 5 minutes to lunch!\n"
  }));
  AddItem(OBJ("protring"),REFRESH_REMOVE,#'wearme);
  AddItem("/obj/key",REFRESH_REMOVE,
    ([P_SHORT:"a bronze key",
      P_LONG:"It is a bronze key. An engraving shows a single eye.\n",
      P_KEYIDS:({"cyclops key"}),
      P_ADS:({"cyclops","a","bronze"}),
      P_IDS:({"key"})]));
}

init() {
  add_action("block_up","up");
}
