/* Cadra 20-12-94 for the 'free_turanu' quest */
#include "path.h"
#include <rooms.h>
#include <combat.h>

inherit "/obj/spellmonster";

create() {
  if (::create()) return 1;
  SetName("orc captain");
  SetShort("a strong orcish palace guard");
  SetLong(
"You face a strong but friendly looking orc. You never guessed an orc "
"could really look friendly, but this one does. You wonder why someone "
"could trust in such creatures like orcs that much that one makes them "
"one's personal guards.\n");
  SetIds(({"orc","guard","captain"}));
  SetAds(({"orc","palace","a","an","orcish","strong","friendly",
	   "friendly looking"}));
  SetHands(({"huge helbard",0,20}));
  SetRace("orc");
  SetMale();
  SetAlign(1500);
  SetLevel(24);
  AddDefence(DT_COLD,40);
  AddDefence(DT_MAGIC,40);
  AddDefence(DT_BLUDGEON,20);
  SetAC(10);
  AddSpell("kick","are kicked by the guard.","is kicked by the guard.",
  20,20,DT_BLUDGEON);
  SetSpellChance(15);
  AddQuestion(({"lady","his lady","cadra"}),
"The orc says: Oh, you know my Lady?\n");
  AddQuestion("deepthought",
"The orc says: He is often visiting my Lady here.\n");
  AddQuestion(({"herkules","sobak","gandalff","ender","mazoli"}),
"The orc says: He's a son of my Lady.\n");
  AddQuestion(({"palace","alabaster palace","cadra's palace"}),
"The orc says: Cadra built this place by her own magic.\n");
  AddQuestion(({"secrets","secret"}),
"The orc says: "
"There are many secrets in this palace. One is, that there shall be "
"a mirrordragon in the palace, which speaks backwards and only understands "
"things that are spoken backwards.\n");
  AddQuestion(({"dragon","mirror dragon"}),
"The orc says: "
"It is said that he will let you pass if you speak the reverse code to him.\n");
  AddQuestion(({"code","reverse code","music"}),
"The orc says: "
"Some told me they would sometimes hear strange sounds in the kitchen.\n");
  AddQuestion(({"sound","strange sound"}),
"The orc says: It is always heard if anyone plays the piano.\n");
  AddQuestion(({"piano","instrument"}),
"The orc says: It is in the music room.\n");
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
