inherit "std/pub";
#include "pub.h"
#include "path.h"
mixed top_list, top_deaths;
void add_to_list(object ob);

object karon, garth, wulfgar;

void reset() 
{
  /* if(!karon) 
      {
      karon = clone_object(CHAR+"karon");
      karon->move(this_object());
   }
   if(!garth) 
      {
      garth = (object)HOSPITAL->get_monster("garth");
      garth->move(this_object());
   }
   if(!wulfgar) 
      {
      wulfgar = (object)HOSPITAL->get_monster("wulfgar");
      wulfgar->move(this_object());
   }*/
}

void setup()
{
   add_menu_item("Beer", ALCOHOL, 20, 10, 10, 10,
      "slurp down your beer", "hurls down a pint of beer");
   add_menu_item("Stout", ALCOHOL, 100, 50, 50, 50,
      "drink a meal of thick black beer", "drinks a stout");
   add_menu_item("Malt whisky", ALCOHOL, 200, 100, 100, 100,
      "feel a gentle burning down your throat", "drinks a shot of whisky" );
   add_menu_item("Dwarven spirits", ALCOHOL, 500, 200, 200, 200,
      "start to drink the Dwarven spirits. Suddenly it "+
      "stops in your throat, then gathers speed and shoots into your stomach",
      "starts to drink some spirits, stop confusedly and grins foolishly");
   add_menu_item("Chili nuts", FOOD, 50, 5, 20, 0,
      "eat some very strong chili nuts", "eats some red peanuts");
   add_menu_item("Toast", FOOD, 100, 10, 40, 0,
      "eat a delicious toast", "eats a toast. Mmm it smells good.");
   add_menu_item("Spiced Potatoes", FOOD, 200, 50, 100, 0,
      "eat some tasty spiced potatoes", "eats some spiced potatoes");
   add_menu_alias("beer", "Beer");
   add_menu_alias("house beer", "Beer");
   add_menu_alias("house", "Beer");
   add_menu_alias("stout", "Stout");
   add_menu_alias("black beer", "Stout");
   add_menu_alias("whisky", "Malt whisky");
   add_menu_alias("malt", "Malt whisky");
   add_menu_alias("malt whisky", "Malt whisky");
   add_menu_alias("dwarven", "Dwarven spirits");
   add_menu_alias("dwarven spirits", "Dwarven spirits");
   add_menu_alias("spirits", "Dwarven spirits");
   add_menu_alias("chili", "Chili nuts");
   add_menu_alias("chili nuts", "Chili nuts");
   add_menu_alias("toast", "Toast");
   add_menu_alias("potatoes", "Spiced Potatoes");
   add_menu_alias("spiced potatoes", "Spiced Potatoes");
   
   set_short("Lady Luck Tavern");
   set_long(
   "This noisy tavern is a refurnished warehouse. Owenden Orcslayer runs this "+
   "popular meeting-place and encourages the patronage of soldiers and "+
   "adventurers. The walls are decorated with weapons, armor and trophies that "+
   "patrons have brought back from their adventuring. A large stone column "+
   "set in the middle of the floor. Above the bar is a plaque they've put a menu "+
   "on. The doorways to the south and west lead outside. The bulletin board " +
   "is now located upstairs for the convenience of the players.\n");
   
/*
   add_exit("south", ROOM+"wall1", "door"); 
   add_exit("west", ROOM+"market1", "door"); 
*/
   add_exit("up", ROOM+"board_room", "stairs");
   
   set_light(60);
   set_zone("pub");
   
   add_item(({"column", "stone", "stone column"}),
      "On it are inscribed the unique symbols of patrons who have died "+
      "in a battle or disappeared while adventuring. Any toast given in "+
      "the tavern must include a liberation to: those who have fallen "+
      "before us.\n");
   add_item(({"plaque", "sign"}),
      "It's made of gold or a goldlike material, and is mounted directly "+
      "into the wall. There is a menu on it that you might want to read.\n");
   add_item(({"people", "patrons"}),
      "There are so many of them I didnt mention them in the long "+
      "description.  But ther are here, pushing and shoveing you "+
      "and making lots of noise.\n");
   add_item("bar",
      "The bar is made of wood and has lots of patrons hanging over it, "+
      "trying to get the attention of Owenden, the bar-keeper.\n");
   add_item("weapons",
      "They're all mounted into the walls. Seems impossible to remove them "+
      "There are four longswords, a whip and a double-edged huge battle-axe.\n");
   add_item("armor",
      "The different pieces of armor is mounted securely to the wall. "+
      "You couldn't remove them even if you wanted to. There are 16 "+
      "pieces of armor all-in-all. Most probably every single piece will "+
      "fit on some bodypart on some kind of creature. Not all are easy to "+
      "figure out where might fit however.\n");
   add_item("trophies",
      "Disappointedly the trophies seem to be just junk. Leave it!\n");
   set_co_ord( ({ -3, -4, 0 }) );
}

dest_me()
{
   if (garth)
      garth->dest_me();
   if (karon)
      karon->dest_me();
   if (wulfgar)
      wulfgar->dest_me();
   ::dest_me();
}

