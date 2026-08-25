inherit "std/room";
 
#include "path.h"
 
void setup()
{
  //ef4.c
  set_light(70);
  set_short("Gnarlwood Forest");
  set_long("Gnarlwood Forest\n"
            "You can almost feel the dark magic that surrounds you "
            "in the very air that you are breathing; with each breath, "
            "you feel a change in the very essence of your blood. Bushes "
            "that only retain a pale yellow hue of their once vivid green "
            "spiral upwards, like an eerie version of a child's lollipop, "
            "as the plants circle around themselves as they search for "
            "sunlight and fresh air to revive them.  "
            "You realize with a chill that this forest - the trees, the plants, "
            "the animals - waits for a return to sunshine, not knowing that "
            "the evilness which has grasped them has altered their very structure "
            "forever.\n");
 
             add_item(({"plant","bushes","bush","plants"}),
             "The underbrush continues to grow, unaware of the change in their physical "
             "appearance.  Berry bushes without a shimmer of color or "
             "brightness produce pale fruit that smells foul and rotting.  "
             "This forest feeds now not on sunlight, but on pure evil.\n");
 
             add_item(({"forest"}),
             "The ghastly woods deepens to your south, but you are unable "
             "to hike through the trees and underbrush.  A small trail leads "
             "to your southwest and southeast.\n");
 
  set_zone("e_forest");
   add_property("no_undead",1);
  add_exit("west", HERE+"ef21", "path");
   add_exit("north",HERE+"ef10","path");
  add_exit("southwest", HERE+"ef9", "path");
   add_clone(NPCS+"werewolf",1);
 
}
 
