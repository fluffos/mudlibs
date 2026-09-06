
#include <properties.h>
#include <ansi.h>
#include <money.h>
#include <rooms.h>

#define AB(x)   ANSI_BOLD + x + ANSI_NORMAL

inherit "/std/room";

varargs void create()
{
  ::create();
  SetIntShort("Money");
  SetIntLong(

   "As you journey about the game, you will sometimes have a need for items "
   "which you don't own, or can't find. Sometimes you will have loot which "
   "you don't need. The answer is to buy the things you need, and sell the "
   "stuff you don't. \n"
   " \n"
   "There are shops scattered about the MUD where you can "
   "buy items, sell items, or both. Some shops are speciality shops, and "
   "only deal in one type of item, like blacksmiths or food shops. Keep "
   "in mind that some items are worthless, and even the most trusting "
   "shopkeeper will refuse to buy them from you.\n"
   "\n"
   "The currency we use is specially minted for us in the capitol. The "
   "basic coin is the copper coin. One silver coin is worth 10 copper "
   "coins, one gold coin is worth 100 copper coins, and one platinum coin "
   "is worth 1000 copper coins.\n\n");

  AddItem(MONEY, REFRESH_REMOVE,
              ([ P_MONEY : ([ "copper" : 15,
                              "gold"   : 2 ]) ]) );


  AddExit("north","./room09");
  AddExit("south","./room07");

  SetIndoors(1);

}
