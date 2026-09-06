
#include <properties.h>
#include <ansi.h>

#define AB(x)   ANSI_BOLD + x + ANSI_NORMAL

inherit "/std/room";

varargs void create()
{
  ::create();
  SetIntShort("Stats and Score");

  Set(P_INT_LONG,
   "If you type " + AB("score") + ", you'll see a nice listing of all "
   "your characteristics, stats and points that you've earned.\n"
   "\n"
   "Your stats tell you how something about your character and how "
   "strong you are in certain things. " + AB("Int") + " stands for "
   "intelligence, " + AB("con") + " for constitution, "
   + AB("dex") + " for dexterity, and " + AB("str") + " for strength. "
   " Many things depend upon your stats, for example, how well you "
   "fight or how well you can learn and use magic.\n"
   "\n"
   "Con tells you how long you can survive a battle without dying. "
   "Int gives you a relative index of how well you can learn things "
   "like magic. Str tells you how hard you can hit with a weapon, "
   "or other strength-related tasks. Dex tells you how well you can "
   "avoid getting hit in battle. Of course, there are other things "
   "that depend on stats, but these are the most common.\n"

   "As a new player you start out with lower stats, and as you progress, "
   "you'll be able to raise your stats from time to time.\n");

  AddExit("north","./room13");
  AddExit("south","./room11");

  SetIndoors(1);

}
