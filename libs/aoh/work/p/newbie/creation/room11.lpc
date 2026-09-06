
#include <properties.h>
#include <ansi.h>

#define AB(x)   ANSI_BOLD + x + ANSI_NORMAL

inherit "/std/room";

varargs void create()
{
  ::create();
  SetIntShort("Combat");

  Set(P_INT_LONG,
   "Some people say that a perfect world would be a boring world. Well, "
   "MUD's are no exception. MUD's are generally filled with good people, "
   "evil nasty creatures, and just about everything in between.\n"
   "\n"
   "Most MUD's are very combat oriented. You'll spend a lot of time "
   "running around slaying monsters and solving puzzles. You get "
   "experience points (known as XP) for killing monsters, and quest "
   "points (QP) for solving quests. Of course, there are also other "
   "things to do - explore new territory, meet cool friends, role play, "
   "and even help us expand this world.\n\n");

  AddExit("north","./room12");
  AddExit("south","./room10");

  SetIndoors(1);

}
