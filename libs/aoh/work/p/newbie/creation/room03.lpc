
#include <properties.h>
#include <ansi.h>
#include <nightday.h>

#define AB(x)   ANSI_BOLD + x + ANSI_NORMAL


inherit "/std/room";

string look_down()
{
  if(({int})NIGHTDAY->IsDay())
    return "A vast expanse of sparkling, blue sea lies far beneath "
           "this bank of clouds.\n";
  else
    return "The lights of a city are faintly visible far beneath the "
           "bank of clouds, and the moon shining on a vast expanse of "
           "water.\n";
}


varargs void create()
{
  ::create();
  SetIntShort("Looking");
  SetIntLong(
   "The fog still billows around your face in long wispy strands, but "
   "it is noticably thinner than to the south.\n"
   "\n"
   "Every room in the MUD has a description. It is wise to look carefully "
   "at your surroundings, as they contain clues and hints to assist you "
   "in your adventuring. Often you can find a wide range of possibilities "
   "just by carefully examining your environment.\n "
   " \n"
   "There are two commands you can use to look at things: " +
    AB("look") + " (or look at) and " + AB("examine") +
   " (shortcuts: l and exa). Examine will sometimes show you more than "
   "a simple look. Try looking at the fog, then examining it.\n\n");

  AddDetail("fog",
    ({ "An indistinct grey gauze of moisture.\n",
	 "The fog seems thinner beneath you, try looking down.\n" }));
  AddDetail( ({ "down", "d" }),
    #'look_down /*'*/);

  AddExit("north","./room04");
  AddExit("south","./room02");

  SetIndoors(1);

}
