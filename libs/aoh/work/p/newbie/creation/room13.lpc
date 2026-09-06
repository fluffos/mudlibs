
#include <properties.h>
#include <ansi.h>

#define AB(x)   ANSI_BOLD + x + ANSI_NORMAL

inherit "/std/room";

varargs void create()
{
  ::create();
  SetIntShort("HP and SP");
  Set(P_INT_LONG,
   "If you look at score again, you'll see two values:"
   + AB("HP") + " and " + AB("SP") + ".\n"
   "\n"
   "HP stands for 'hit points'. Every player has a certain number of "
   "HP. Whenever you are in a fight or get hurt somehow, you'll lose a "
   "number of these HP. It is important to keep a good eye on your HP, "
   "because when they reach 0 you're dead! Now don't panic, you won't "
   "lose your character if you die.\n"
   "\n"
   "Being dead is a small inconvenience, and you'll have to find a holy "
   "place such as a temple and pray to become alive again. You also lose "
   "some XP when you die (hey, nothing in life is free...) and you can't "
   "carry much. But there are a few advantages which you'll just have to "
   "find for yourself.\n"
   "\n"
   "SP stands for 'spell points', and as you might imagine, these are "
   "only important when you're using magic. You won't die if your SP hit "
   "0, but you won't be able to use magic until they increase. Both HP "
   "and SP will regenerate naturally over time.\n");


  AddExit("north","./last");
  AddExit("south","./room12");

  SetIndoors(1);

}
