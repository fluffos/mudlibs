/*  Text alterations and additions by Grimbrand 2-3-96                   */

inherit "/std/pub";
#include "path.h"
#include "pub.h"
 
object countertop;
object stove;
object oven;
object *npcs;
int isguarding = 0;
 
void setup() {
   npcs=allocate(1);
   set_short("Realm of the Duergar:  Academy Grubhall");
   add_property("no_undead",1); set_light(55);
   set_long("\n   Realm of the Duergar:  Academy Grubhall.\n\n"
	    "     Entering the grubhall, the smell of food cooking "
	    "and baking is the first thing you notice.  The far "
	    "corner has been adapted into a small kitchen area "
	    "where an old duergar women can be seen prepairing food "
	    "around a stove and oven.  The only other furniture in "
	    "the room is a table and a pair of benches.\n"
	    "\n");

   add_item("table",
	    "   The table is long and made out of stone that "
	    "has obviously been used many times over.  The top surface "
	    "has been worn smooth from the constant use.  It serves as "
	    "testimony to all duergar that have come before you to "
	    "the Academy to begin their journey in life.\n"
	    "\n");

   add_item(({"bench", "benches"}),
	    "   The benches are just as worn as the table.  It is a "
	    "wise duergar that decided upon making the benches out of "
	    "stone.  They must be stone to handle to constant wear and "
	    "tear of countless duergar flowing through the Academy "
	    "Grubhall.\n"
	    "\n");

   add_smell("room",
	     "   It smells like cooking food.\n\n");
   
   add_smell("stew",
	     "   It smells wonderful!  Perhaps you should "
	     "\"ladle\" some for yourself!\n\n");
 
   add_exit("south", NEWBIE+"main02", "door");

   add_menu_item("Apple Cider", ALCOHOL, 30, 15, 15, 15,
                 "carefully sip the cider",
                 "slowly drinks a glass of cider");

   add_menu_item("Biscuits and Gravy", FOOD, 100, 100, 100, 0,
                 "eat a generous portion of biscuits and gravy",
                 "eats a generous portion of biscuits and gravy");

   add_menu_item("Tea", SOFTDRINK, 5, 0, 1, 0,
                 "drink a cup of tea",
                 "drinks a cup of tea");

   add_menu_item("Coffee", SOFTDRINK, 10, 1, 3, 0,
                 "drink a cup of coffee",
                 "drinks a cup of coffee");

   add_menu_alias("apple cider", "Apple Cider");
   add_menu_alias("cider", "Apple Cider");
   add_menu_alias("apple", "Apple Cider");
   add_menu_alias("biscuits and gravy", "Biscuits and Gravy");
   add_menu_alias("Biscuits", "Biscuits and Gravy");
   add_menu_alias("biscuits", "Biscuits and Gravy");
   add_menu_alias("Gravy", "Biscuits and Gravy");
   add_menu_alias("gravy", "Biscuits and Gravy");
   add_menu_alias("tea", "Tea");
   add_menu_alias("coffee", "Coffee");

   set_zone("pub");
   add_clone(ITEMS+"countertop",1);
   add_clone(ITEMS+"oven",1);
   add_clone(ITEMS+"stove",1);
   add_clone(DNPC+"dlady",2);
} /* setup */
 
