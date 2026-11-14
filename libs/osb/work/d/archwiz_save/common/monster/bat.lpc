inherit "std/npc";

#include <living.h>

#include <combat.h>
#include "path.h"

create() {
  if (::create()) return 1;
  SetName("bat");
  SetShort("a cave bat");
  SetLong("A black, menace-looking cave bat.\n");
  SetRace("bat");
  SetGender(GENDER_NEUTER);
  SetNoise("You hear the movement of something through the air.\n");
  SetWeight(1000);
  SetIds(({"bat"}));
  SetAds(({"black","menace-looking","a","cave"}));
  SetLevel(5);
  SetAlign(0);
  SetAC(6);
  AddDefence(DT_SLASH,35);
  SetAttribute("MagicDefence",20);
  SetHands(({({"left claw",0,10}),({"right claw",0,10})}));
  InitChats(20,({
	"A bat barely misses your head!\n",
	"A bat dives short before your eyes!\n"
  }));
  InitAChats(10,({
	"A bat dives at your head!\n"
  }));
}
