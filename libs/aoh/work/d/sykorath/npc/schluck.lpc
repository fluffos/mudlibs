// the shopkeeper of the pub
// made by magictcs - 18 jun 1997

#include <properties.h>
#include <npc.h>
#include <sykorath.h>

inherit "/std/npc";

//****************************
// special drink properties :)
//****************************
int QueryAlcohol() {
  int alc;
  alc=::QueryAlcohol();
  if (alc<15) {
    tell_room(environment(),
      "Schluck take one of his beers and drinks it very fast.\n"
      "You hear a loud 'Ahhhhh'.\n");
    SetAlcohol(20);
  }
  return alc;
}

create() {
  if (::create()) return;
  SetName("Schluck");
  SetRace("human");
  SetShort("Schluck, the innkeeper");
  SetLong(
    "Schluck is the innkeeper of the city pub. He is working hard.\n"
    "He is a little bit drunken.\n");
  SetGoChance(0);
  SetLevel(13);
  SetAlcohol(20);
  SetGender(GENDER_MALE);
  AddId("innkeeper");

  /* questions */
  AddQuestion(({"menu","drink","drinks"}),
    "Schluck says: Hey are you too stupid? Just 'read' the menu!\n");
  AddQuestion(({"food","foods"}),
    "Schluck says: This is a pub - not a restaurant!\n"
    "  Drink something and you will be happy!\n"
    "  But we don't serve any food here!\n");

}

