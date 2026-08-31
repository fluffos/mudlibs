inherit "/room/room";

#include "/players/mangla/defs.h" 
#include "corridor.h"
object policeman,club;

void reset(int arg) {
   ::reset (arg);
   if (arg) return;
   set_light(1);
   no_castle_flag=1;
   short_desc="A corridor.";
   long_desc=
	"You are in a dimly lit corridor.  This area is free of all clutter "+
	"and reminds you of a hospital in its efficience.  This is the "+
	"hallway running down the middle of the cells which are to the "+
	"north and south of you.\n";

   dest_dir=({
	"/players/bobo/krooms/vill/police_office","east",
	"/players/bobo/krooms/vill/corridor2","west",
   });

   items=({
	"cells","The doors are made of very sturdy steel, there is no chance "+
		"for the prisoners to escape",
	"cell","The doors are made of high-security steel, there is no chance "+
		"for the prisoners to escape",
   });
}

init() {
   ::init();
   add_action("north","north");
   add_action("south","south");
   add_init();
}

north() {
   if("players/bobo/krooms/vill/guardroom"->open())
   TP->MOVEP("north#players/bobo/krooms/vill/cell1n");
   else
   write("The door is closed.\n");
   return 1;
} 

south() {
   if("players/bobo/krooms/vill/guardroom"->open(2))
   TP->MOVEP("north#players/bobo/krooms/vill/cell1s");
   else
   write("The door is closed.\n");
   return 1;
}
