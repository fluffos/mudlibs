// restroom of the madmonks guild
// part of the Dojo
// made by MagicTCS 20 may 97
// not used the hotel room - because some problems with the hotelkey card

#include <rooms.h>
#include "/p/guilds/madmonks/madmonks.h"

#define CARD "/p/guilds/madmonks/obj/restroomcard"

inherit BASISROOM;

void create() {
  ::create();
  SetIntShort("The restroom");
  SetIntLong("You are in the comfortable restroom of the MADMONKS' guild.\n"
    "This place is mostly used for restoring your health and for thanking\n"
    "and praying to your god for staying alive.\n"
    "A wonderful silence is around you.\n"
    "The restroom is part of the Madmonks Dojo.\n"
    "All walls are made of paper pavarents. A geisha is sitting in one\n"
    "corner.\n"
    "One wall seems to be different than the other ones.\n");
  AddDetail(({"restroom","comfortable restroom","place","this place"}),
    #'IntLong);
  AddDetail(({"silence","wonderful silence"}),
    "Better listen to it.\n");
  AddDetail(({"wall","walls","all walls","one wall","other walls"}),
    "The wall are made by the hard brown paper often used in japanese\n"
    "houses.\n"
    "There is a small inscription on the wall.\n");
  AddDetail(({"inscription","small inscription","inscription on wall",
    "small inscription on wall","inscription on the wall",
    "small inscription on the wall","inscription of wall",
    "small inscription of wall","inscription of the wall",
    "small inscription of the wall"}),
    "You can read it.\n");
  AddReadMsg(({"inscription","small inscription","inscription on wall",
    "small inscription on wall","inscription on the wall",
    "small inscription on the wall","inscription of wall",
    "small inscription of wall","inscription of the wall",
    "small inscription of the wall"}),
    "You can 'sleep' here. Next time you will wake up here!\n");
  AddDetail(({"paper","brown paper","hard brown paper","hard paper"}),
    "You cannot see through the paper. But you see some shadows on the\n"
    "walls. It looks like that someone is running through the floor.\n");
  AddDetail("geisha",
    "She is wearing a long red kimono. A nice smile surrounds her lips. She\n"
    "looks very beautiful. A really nice girl.\n");
  AddDetail(({"kimono","red kimono","long red kimono","long kimono"}),
    "It is a high expensive kimono. Not all people can buy such a kimono.\n"
    "It is made of pure silk and is batiked by a master of this art.\n");
  SetIntNoise("Silence!\n");
  AddNoise("silence","Did you ever heared silence?\n");
  SetIndoors(1);
  SetBright(100);
  AddExit("east",MONKROOM("statstrain"));
  AddRoomCmd("sleep","do_sleep");
  AddRoomCmd("pray","do_pray");
}

// own sleep function - overload the std-one
// I need an own hotelkey!!!
int do_sleep()
{
  object card;
  write ("You enter the world of dreams ...\n");
  card = clone_object(CARD);
  card->SetNewHome(TP->QueryHome());
  card->move(TP);
  TP->SetHome(object_name(TO));
  TP->cmd_petrify();
  return 1;
}

//*************
// pray command
//*************
int do_pray(string str) {
  if (str) { notify_fail("Use pray without arguments\n"); return 0; }
  write("You pray to your god and thanks to be alive!\n");
  show(NAME+" prays to his god\n");
  return 1;
}

