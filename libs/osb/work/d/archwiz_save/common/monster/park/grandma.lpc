#include "path.h"

inherit "/std/npc";

create() {
  if (::create()) return 1;
  SetRace("human");
  SetName("grandma");
  SetShort("Old Grandma");
  SetLong(
"This is the owner of this house: Grandma. "
"She looks really sad. Tears are running down her cheeks. Perhaps you could "
"ask her about her problem?\n");
  SetIds(({"woman","grandma","granny"}));
  SetAds(({"good","old","sad"}));
  SetGender(2);
  SetLevel(4);
  InitChats(5,({
    "Grandma weeps bitterly.\n",
    "Grandma says: If only someone could help me.\n",
    "Grandma says: I know she has been here!\n",
    "Grandma says: Have you seen my sweet little grandchild?\n",
    "Grandma says: She has been the darling of everyone around. Noone could\n"
    "              have hurt her.\n",
    "Grandma looks at you with big tears in her eyes.\n"}));
  AddQuestion(({"problem","sadness","grandchild","little red riding hood",
    "girl","riding hood","hood","red riding hood"}),
"Grandma says: I've just been out, sitting on the small bench at the back of\n"
"  the house.\n"
"Grandma weeps bitterly.\n"
"Grandma says: Every week my little grandchild comes and brings me some food\n"
"  and drink from my daughter. This time something horrible happened.\n"
"Grandma burts into tears.\n");
  AddQuestion(({"horrible thing","story","what happened","something","something horrible","horrible"}),
"Grandma says: While I've been sitting in the sun, the big bad wolf must have\n"
"  been come into my hut. When my grandchild entered it and wanted to greet\n"
"  me, he has eaten her in whole. The only thing I saw has been a big fat\n"
"  wolf running out of my home, burping rudely. Could you bring her back\n"
"  to me? Perhaps the hunter could help you.\n"
"Grandma bursts into tears.\n");
  AddQuestion(({"hunter","friendly hunter"}),
"Grandma says: The son of an old friend of mine...\n"
"Grandma blushes deeply.\n"
"Grandma says: He knows a lot about the animals of the forest. Perhaps he is\n"
"  the only one who knows where the bad wolf can be found. For sure he is\n"
"  the only one who is able to teach you how to free my granddaughter.\n"
"Grandma looks hopefully.\n"
"Grandma says: Perhaps he already knows about all this.. ask him\n"
"  about the story! If not, you'd have to tell it to him.\n"
"Grandma says: He lives somewhere in this park, but noone knows where he\n"
"  hides to view the animals. The only thing I know is, that he uses to hide\n"
"  in the bushes or trees, perhaps you'll find a way to him, when looking\n"
"  around carefully.\n");
  AddQuestion(({"wolf","fat wolf","bad wolf","big wolf","big bad wolf"}),
"Grandma sniffs: The big bad wolf must have been the one whose fault it is\n"
"  that my beloved grandchild vanished.\n");
  AddQuestion("help",
"Grandma says: Oh yes.. would you help me?\n");
  AddQuestion("hut",
"Grandma smiles with tears in her eyes.\n"
"Grandma says: It is my home, I live here for a very long time now,\n"
"  you like it?\n");
}
