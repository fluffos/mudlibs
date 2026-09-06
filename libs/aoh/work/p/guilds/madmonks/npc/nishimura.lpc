// the shopkeeper for the madmonks depot
// made by magictcs - 8 may 1997

#include <properties.h>

inherit "/std/npc";

create() {
  ::create();
  SetName("Nishimura");
  SetRace("human");
  SetShort("Nishimura");
  SetLong(
    "An old veteran of the madmonks called Nishimura.\n");
  AddId("veteran","nishimura");
  SetAds(({"old"}));
  SetLevel(40);
  SetGender(GENDER_MALE);

  AddQuestion(({"magictcs","balgarion"}),
    "Nishimura says:\n"
    "  Oh you know him? Magictcs and Balgarion founded this guild.\n");
  AddQuestion(({"depot"}),
    "Nishimura says:\n"
    "  Where do you think we're standing? You can deposit things here.\n"
    "  Try to read the paper.\n");
  AddQuestion(({"madmonks","madmonk"}),
    "Nishimura says:\n"
    "  Oh all these rooms belong to the madmonks guild.\n");
}

