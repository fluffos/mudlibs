// healer npc for the healer shop

#include <properties.h>

inherit "/std/npc";

void create()
{
  ::create();
  
  SetShort("the healer");
  SetName("Brianna");
  
  SetLong("A gentle-looking woman with wise eyes.\n");
  
  AddId("healer");
  
  Set(P_GENDER, GENDER_FEMALE);
  Set(P_RACE, "human");
  Set(P_ALIGN, 1000);
  Set(P_LEVEL, 19);
  
  AddQuestion("poltice",
   "A poltice is a mixture of dried herbs soaked in hot water to make a "
   "paste, then applied to your skin in a bandage covering of linen.\n");
   
  AddQuestion("liniment",
   "A liniment is a mixture of herbs and oil, vinegar or alchohol. It is "
   "applied directly to the skin.\n");
   
  AddQuestion("compress",
   "A compress is made by soaking dried herbs in hot water, and applying "
   "the liquid to the skin on a bandage.\n");
}
  
