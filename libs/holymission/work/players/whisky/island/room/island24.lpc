

#define TP this_player() 

inherit "room/room";
#include "../island.h"

void reset(int arg) 
{
  if (filter_live(this_object()) < 1)
     CM("armonophis");

    if (arg) return;
    set_light(1);
    short_desc = "On an island";
    long_desc = BS(
          "You are standing on a plateau near the top of the mountain. "
        + "You can see bushes to the south. To the north east and west "
        + "you can see the blue sea and the beach of the island. "
        + "The water is so deep and clear, that you get the feeling "
        + "that maybe you can risk to 'jump' down.");
    items = ({
          "bushes","10 feet high bushes",
          "sea","The clear blue sea",
          "beach","A long sandy beach",
          "bottom","A black stony bottom"
            });
     CO("tree2");
}
 init() {
   ::init();
   add_action("jump","jump");
   add_action("jump","down");
   add_action("pass","pass");
  }
 jump(str) {
write("\n\n\n************** y o u  a r e  f a l l i n g ******************\n\n\n"+
       " ************** y o u  a r e  f a l l i n g ******************\n\n\n"+
       " ************** y o u  a r e  f a l l i n g ******************\n\n\n"+
       " ************** y o u  a r e  f a l l i n g ******************\n\n\n"+
       " ************** y o u  a r e  f a l l i n g ******************\n");
   TP->move_player("down#players/whisky/island/room/island26");
  return 1;
  }
  pass(arg) {
   if(arg!="bushes") return;
    if (random(4) > 0) {
     write("You pass the big bushes.\n");
     TP->move_player("over the bushes#players/whisky/island/room/island22");
     return 1;
     }
     write("You try to pass the bushes, but you fall down and land on your ass.\n");
     this_player()->hit_player(random(10));
    return 1;
   }

