inherit "/room/room";

#include "/players/mangla/defs.h" 
#include "corridor.h"
object policeman,club;

void reset(int arg) {
   ::reset (arg);
   if (arg) return;
   set_light(1);
   short_desc="A corridor.";
   long_desc=
	"You are in a dimly lit corridor.  This area is free from all clutter "+
	"and reminds you of a hospital in its efficiency.  This is the "+
	"hallway running down the middle of the cells which are to the "+
	"north and south of you.\n";
   dest_dir=({
	"/players/bobo/krooms/vill/corridor1","east",
	"/players/bobo/krooms/vill/corridor3","west",
   });
   items=({
	"cells","The doors are made of very sturdy stell, there is no chance "+
		 "for the prisoners to escape",
	"cell","The doors are made of very sturdy seel, leaving no chance to "+
	       "escape",
   });
}

init() {
   ::init();
   add_action("north","north");
   add_action("south","south");
   add_init();
}
north() {
 if("players/bobo/krooms/vill/guardroom"->open(3))
  TP->MOVEP("north#players/bobo/krooms/vill/cell2n");
 else
   write("The door is closed.\n");
 return 1;
} 
south() {
 if("players/bobo/krooms/vill/guardroom"->open(4))
   TP->MOVEP("north#players/bobo/krooms/vill/cell2s");
 else
   write("The door is closed.\n");
 return 1;
}
