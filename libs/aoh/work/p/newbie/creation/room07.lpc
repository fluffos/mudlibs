
#include <properties.h>
#include <ansi.h>

#define AB(x)   ANSI_BOLD + x + ANSI_NORMAL

inherit "/std/room";

varargs void create()
{
  ::create();
  SetIntShort("room 7");
  SetIntLong(
    "It is important to eat and drink to stay fit and healthy. After a "
    "while, you will become hungry and thirsty. When this happens, you "
    "need to eat and drink. You cannot die from hunger or thirst, but it "
    "can severely affect your ability to heal.\n\n");

  AddExit("north","./room08");
  AddExit("south","./room06");

  SetIndoors(1);

}
