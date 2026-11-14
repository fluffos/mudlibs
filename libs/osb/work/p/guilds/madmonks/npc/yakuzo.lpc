// the shopkeeper for the madmonks shop
// made by magictcs - 8 may 1997

#include <properties.h>

inherit "/std/npc";

create() {
  ::create();
  SetName("Yakuzo");
  SetRace("human");
  SetShort("Yakuzo");
  SetLong(
    "It's Yakuzo - the shopkeeper of the madmonks dojo shop. He will protect\n"
    "the shop against any robbers from outer space. He is very experienced\n"
    "in this job, because he did it sometimes in the past.\n");
  AddId(({"shopkeeper"}));
  SetLevel(40);
  SetGender(GENDER_MALE);

  AddQuestion(({"magictcs","balgarion"}),
    "Yakuzo says:\n"
    "  Oh you know him? He is one of the founders of this guild.\n");
  AddQuestion(({"shop"}),
    "Yakuzo says:\n"
    "  Where do you think we're standing?\n");
  AddQuestion(({"madmonks","madmonk"}),
    "Yakuzo says:\n"
    "  Oh this room belongs to the madmonks guild too.\n");
  AddQuestion(({"robber","robbers"}),
    "Yakuzo says:\n"
    "  Oh - I killed some of them. They come in and tried to kill me or to\n"
    "  steal some items.\n"
    "Yakuzo laughs: Now they are all dead!\n");
}

