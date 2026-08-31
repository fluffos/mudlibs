
#define	TP	this_player()
#define TPP     TP->query_possessive()
#define TPN	TP->query_name()
 
inherit "room/room";
#include "../garden.h" 

 
reset(arg) {

    if (arg) return;
    set_light(0);
    property = "no_teleport";
    short_desc = "On an attic";
    no_castle_flag = 0;
    long_desc = 
       "You have entered the attic of the strange building. "+
     "It is cold and damp here, you can smell the odor of "+
     "rotted wood. A little corridor leads to the north, and "+
     "a dark hole leads down to an even darker place.\n";
    dest_dir = ({ ROOM+"/attic3","north" });

   items = ({"wood","Dark bad smelling wood",
             "fireladder","An iron fireladder",
             "bottom","A wooden bad smelling bottom",
             "wall","A dark wet wall"});
}
 
init() {
  ::init();
  add_action("down","down");
  add_action("down","jump");
  add_action("search","search");
}
down() {
 write("You jump back into the black hole.\n");
 say(TPN+" jumps down into the black hole.\n");
 TP->move_player("into a black hole#"+ROOM+"/cell");
 write("\n\nA u t c h   you hurt yourself badly.\n");
 TP->hit_player(1+random(4));
 return 1;
 }
search(str) {
  write("You find nothing special.\n");
 return 1;
}

