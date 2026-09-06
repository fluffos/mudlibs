#include <combat.h>
#include <rooms.h>
#include <properties.h>

inherit "/std/npc";

varargs void create() {
  (::create());
  SetName("bat");
  SetShort("a evil bat");
  SetRace("bat");
  SetLong("This is a little evil bat, available via OEFC catalog.\n");
  SetIds(({"bat"}));
  SetAds(({"evil"}));
  SetNoGet("You cannot take the bat.\n");
  SetWeight(700);
  SetLevel(1);    // very nice bat
  SetHP(50);      // easy to kill - but never kill it please :)
  SetSize(PSIZE_SMALL);
  SetAlign(-500);
  SetAC(1);
  SetWimpy(5);
  SetHands(({({"left wing",0,5}),({"right wing",0,5}),({"mouth",0,6})}));
  SetShrugMsg("A bat cannot speak to you.\n");
  InitChats(3,({"The bat hangs down under on a small edge.\n",
    "The bat flies some rounds.\n",
    "The bat turns a round and falls down to the earth.\n",
    "The bat sleeps.\n"
    }));
  InitAChats(3,({"You will a little helpless bat?\n",
    "You hear a voice from nowhere. It says - YOU MURDER - killing a nice bat.\n",
    "You are going to kill your own pet!\n"
    }));
  SetLevel(1);
  SetValue(5000);
}

void init() {
  ::init();
//  if (present("bat",this_room())
//    this_object->remove();
//  Corrected by your friendly Lord Suamor :-)
}

