#include <rooms.h>
#include <properties.h>
#include <ansi.h>

#define AB(x)   ANSI_BOLD + x + ANSI_NORMAL

inherit "/std/room";

varargs void create()
{
  ::create();
  SetIntShort("room 6");
  SetIntLong(
   "Throughout the game you will find items which you can carry away with "
   "you. You can "+AB("take")+ " or "+AB("get")
   + " an object to pick it up, and " +AB("drop") + " an item to put "
   "it on the ground, or "+AB("put")+" an item to place it in a "
   "specific place. Some items, though, are either too heavy to take, or "
   "simply cannot be taken no matter how strong you are.\n"
   "\n"
   "To see what you are carrying, type "+AB("inventory")+" (or i).\n"
   "\n"
   "There is no absolute limit to how many items you may carry, "
   "but there is a limit to how much weight you can carry. Every item in "
   "the game has a weight. As your strength increases, the weight you can "
   "carry will also increase. Remember that carrying a heavy load limits "
   "both your ability to heal and your ability to fight well.\n"
   " \n"
   "Take the bread and water with you. (Try 'take all')\n\n");

  AddItem("/p/newbie/obj/water", REFRESH_ALWAYS);
  AddItem("/p/newbie/obj/roll", REFRESH_ALWAYS);

  AddExit("north","./room07");
  AddExit("south","./room05");

  SetIndoors(1);

}
