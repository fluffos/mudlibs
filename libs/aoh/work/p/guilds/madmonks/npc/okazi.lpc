// the librarian for the madmonks library
// made by magictcs - 8 may 1997

#include <properties.h>

inherit "/std/npc";

create() {
  ::create();
  SetName("Okazi");
  SetRace("human");
  SetShort("Okazi - the librarian");
  SetLong(
    "Okazi is the librarian of the madmonks. He will watch over the library\n"
    "of the guild.\n");
  SetGender(GENDER_MALE);
  SetLevel(10);
  AddId("libarian");

  AddQuestion(({"scroll of quests"}),
    "Okazi says:\n"
    "  You can take the scroll, but please return it after reading.\n");
  AddQuestion(({"scroll","scrolls"}),
    "Okazi says:\n"
    "  I have many scrolls here. You can take the one you want.\n"
    "  just: 'take scroll of quests'\n"
    "        'take scroll of skills'\n"
    "        'take scroll <number>'\n");
  AddQuestion(({"scroll of skills"}),
    "Okazi says:\n"
    "  Sorry but this scroll isn't available yet.\n");
  AddQuestion(({"shelf","wooden shelf"}),
    "Okazi says:\n"
    "  Well the shelf contains the scrolls.\n");
  AddQuestion(({"magictcs","balgarion"}),
    "Okazi says:\n"
    "  Oh you know him? Well he founded this guild.\n");
  AddQuestion(({"library"}),
    "Okazi says:\n"
    "  Where do you think we're standing?\n");
  AddQuestion(({"madmonks","madmonk"}),
    "Okazi says:\n"
    "  Oh all these rooms belong to the madmonks guild.\n");
}

