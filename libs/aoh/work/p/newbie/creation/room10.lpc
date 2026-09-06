
#include <properties.h>
#include <ansi.h>

#define AB(x)   ANSI_BOLD + x + ANSI_NORMAL

inherit "/std/room";

varargs void create()
{
  ::create();
  SetIntShort("Communication");
  Set(P_INT_LONG,
   "Of course, there are more communication possibilities than just the "
   "channels. On your travels you will certainly meet other adventurous "
   "souls such as yourself. When you are standing in the same room, "
   "you can use the command "+AB("say")+" plus whatever you want to say. "
   "Everyone in the room will hear this.\n "
   "\n"
   "Of course, once you make lots of friends, you'll want to tell them all "
   "the neat things you've discovered, but what if they aren't in the same "
   "room? You can then use "+AB("tell <player name> <bla bla bla>")+
   " to tell "
   "someone something, provided they are in the game. No one else will "
   "hear this message except for the person you tell.\n "
   "\n"
   "You can use the "+AB("who")+" command to find out who is in the game at any "
   "time. People with an 'N' next to their name are 'Designated Newbie "
   "Helpers', and will gladly answer your questions. (A "+AB("newbie")+
   " is someone who is new to mudding.)\n"
   "\n"
   "For more information, type 'help communication' at any time.\n");


  AddExit("north","./room11");
  AddExit("south","./room09");

  SetIndoors(1);

}
