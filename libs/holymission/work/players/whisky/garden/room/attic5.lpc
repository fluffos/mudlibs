
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
      "You are in the attic of the strange building. "+
      "It's a bit cold and damp here, you can smell "+
      "the odor of rotted wood. There is a little corridor "+
      "to the north and a wooden door to the south. You see "+
      "something on the door and wonder what it is. \n";
    dest_dir = ({ ROOM+"/attic4","north" });

   items = ({"wood","Black stinking wood",
             "door","A big wooden door with an iron wheel",
             "wheel","A big iron wheel, perhaps you could turn it",
             "wall","Dark wet walls",  
             "bottom","A dark wooden bottom"});
}
 
init() {
  ::init();
  add_action("turn","turn");
  add_action("unlock","unlock");
  add_action("open","open");
  add_action("search","search");
  add_action("south","south");
}
south() {
 write("You bang your head against the closed door.\n");
 say(TPN+" bangs "+TPP+" head against the closed door.\n");
 TP->hit_player(1+random(4));
 return 1;
 }
search(str) {
  write("You find nothing special.\n");
 return 1;
}
open(str) {
if (str=="door") {
write("You try to open the door but you fail, it's locked.\n");
say(TPN+ " tries to open the door but fails.\n");
return 1; }
}

unlock(str) {
if (str=="door") {
write("You fail the door has no keyhole.\n");
say(TPN+ " tries to unlock something but fails.\n");
return 1; }
}
turn(str) {
 if (str=="wheel") {
    write("In which direction do you want to turn the wheel.\n");
    return 1;
}
 if (str=="wheel right" || str=="wheel clockwise") {
    write("You turn the wheel right, nothing happens.\n");
    return 1;
   }
 if (str=="wheel left" || str=="wheel anticlockwise") {
   write("Suddenly the door opens and moves you into another room.\n\n");
   write("And with a  >>>>> K L I C K <<<<<  the door closes again.\n");
   say(TPN+" opens the door.\n");
   TP->move_player("trough a wooden door#"+ROOM+"/attic");
   return 1;
  }
}

