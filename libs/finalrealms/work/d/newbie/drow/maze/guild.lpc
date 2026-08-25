#include "path.h"
inherit "/std/newbieguild";

int query_underground() { return 1; }

void setup()
  {
  set_short("Realm of the Drow:  Guild Room");
set_light(0);
set_long("\n   Realm of the Drow:  Guild Room.\n\n"
        "     Thick walls made of a thicker, rubbery surface "
             "closets you from the other prisoners of the maze here, "
 "in the one room where you might find rewards.  The Drow's "
             "First Guild has been established by the Matron Mothers to "
      "reward those drow who prove their quickness with sword and "
"their loyalty to Cyrcia through the endowment of gifts of "
             "stamina.  An altar to the great goddess of evil chaos "
             "levitates far above you, for one of your level and naivite should "
             "not even look upon such a holy item.  The requirments and the conditions of "
             "this room, are worded in silver letters on an embroidered "
             "spiderweb that cloaks the right wall.\n\n");
   add_item(({"wall","walls"}),
             "Spongy to the touch, the walls absorb all sound and "
             "yet still do nothing to cushion any blows that knock you against 
them.\n");
   add_item(({"altar", "Cyrcia", "item", "cyrcia", "holy item"}),
             "A voice screams at you, shaking the very center of your skull "
             "for your impropriety!!\n\n"
             "A sudden snake-like hiss is your only warning of the huge "
             "blow that sends you across the floor, far away from the altar.\n");
   add_item(({"requirements, conditions"}),
             "You will find these items discussed in detail in the 
spiderweb.\n");
   add_item(({"embroidery","sign","letters","letter","web","spiderweb"}),
   "\nThe sign reads in drow:\n\n"
        "+------------------------------------------------+\n"
         "|                                                |\n"
           "|               %^BOLD%^ Drow First Guild%^RESET%^                |\n"
            "|                                                |\n"
         "|                                                |\n"
            "| Your success in this guild depends wholy on    |\n"
            "| your own peresevence.  Weakness will not be    |\n"
            "| tolerated, and ability will be noted, but      |\n"
            "| not praised.  If you wish to begin your        |\n"
            "| ascent into drow society, you must advance     |\n"
            "| in this guild until level 5.  The following    |\n"
            "| information will give you the tools needed     |\n"
            "| for success and advancement -- whether you     |\n"
            "| achieve it is up to you.                       |\n"
            "| 'cost' informs you of the XP needed to advance.|\n"
            "| 'advance' advances you to the next level.      |\n"
           "|  'info' provides you with information.         |\n"
          "|                                                |\n"
        "|                                                |\n"
       "+------------------------------------------------+\n"
       "\n");
 
   add_exit("west", MAZE+"maze", "corridor");
   add_exit("southwest", MAZE+"raiserm", "corridor");
}
