
#define	TP	this_player()
#define TPP     TP->query_possessive()
#define TPN	TP->query_name()
 
inherit "room/room";
#include "../garden.h" 
 object bed;


int counter;
 
reset(arg) {

counter=0;
    if (arg) return;
    set_light(0);
    property = "no_teleport";
    short_desc = "In a hot bedroom";
    no_castle_flag = 0;
    long_desc = 
        "You have entered a very warm, comfortable room. There is a "+
        "window to the west and a bed is standing invitingly in the "+
          "center of the room. It would appear that the witch "+
          "seduces lost adventurers here. Perhaps you are next.\n";
    dest_dir = ({ ROOM+"/kitchen","south",
  /*
     ROOM+"/bedroom2","bed" });
   */
    });

   items = ({
             "window","A big open window",
             "pillow","A little red pillow",
             "out of the window","You see the bright moon shining in your face",
             "wall","Dark walls",
             "bottom","A wet black wooden bottom"});
}
 
init() {
  ::init();
  add_action("close","close");
   add_action("search","search");
  add_action("open","open");
}
 open(str) {
  if(str=="window" || str=="the window") {
  write("But why ?? , its already open.\n");
  return 1;
 }
}
close(str) {
  if (str!="window") return;
  write("You try to close the window, but as hard as you try you fail.\n");
  say(TPN+" tries to close the window but fails.\n");
  return 1;
 }

  search(str) {
   if (str=="pocket") return;
   write("You search and search and find nothing.\n");
   say(TPN+" searches around.\n");
   return 1;
   }
