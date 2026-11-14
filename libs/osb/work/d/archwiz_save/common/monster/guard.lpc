/* Cadra 20-12-94 for the 'free_turanu' quest */
#include "path.h"
#include <rooms.h>
#include <combat.h>

inherit "/std/npc";

create() {
  if (::create()) return 1;
  SetName("orcish guard");
  SetShort("a strong orcish palace guard");
  SetLong(
"You face a strong but friendly looking orc. You never guessed an orc "
"could really look friendly, but this one does. You wonder why someone "
"could trust in such creatures like orcs that much that one makes them "
"one's personal guards.\n");
  SetIds(({"orc","guard"}));
  SetAds(({"orc","palace","a","an","orcish","strong","friendly",
	   "friendly looking"}));
  SetHands(({"strong axe",0,20}));
  SetRace("orc");
  SetMale();
  SetAlign(800);
  SetLevel(24);
  AddDefence(DT_BLUDGEON,30);
  AddDefence(DT_MAGIC,50);
  AddDefence(DT_COLD,30);
  AddDefence(DT_ACID,0);
  SetAC(7);
  AddQuestion(({"lady","his lady","cadra"}),
"The orc says: Oh, you know my Lady?\n");
  AddQuestion("deepthought",
"The orc says: He is often visiting my Lady here.\n");
  AddQuestion(({"herkules","sobak","gandalff","ender","mazoli"}),
"The orc says: He's a son of my Lady.\n");
  AddQuestion(({"palace","alabaster palace","cadra's palace"}),
"The orc says: Cadra built this place by her own magic.\n");
  AddQuestion(({"music room"}),
"The orc says: It is somewhere in the palace.\n");
  AddQuestion(({"shadows","shadow"}),
"The orc says: The old way to their world is closed by strong magic. "
"Elosar could open it, but Cadra hid his wand to prevent that someone "
"could force him to open it though she trust him a lot.\n");
  AddQuestion(({"elosar","elosar dreamweaver","dreamweaver"}),
"The orc says: He is an old elf and mighty conjurer.\n");
  AddQuestion(({"catacomb","catacombs"}),
"The orcs says: The shadows live there.\n");
  AddQuestion(({"orc","orcs"}),
"The orc says: We are the strongest race in the wolrd!!!\n");
}
