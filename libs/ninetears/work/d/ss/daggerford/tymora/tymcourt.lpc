inherit "std/room";
#include "path.h"
 

void setup() {

   set_short("Courtyard");

   set_long(

"You are in an open courtyard.  A huge fountain sits in the center of the " +
"courtyard.  The path continues north and south.  A garden lies to the west "+
"and to the east is a gazebo.\n");

   set_light(100);


   add_item("fountain",
   "A statue sits on top of this uniquely carved fountain.  A great plume "+
"of water mushrooms up from behind the statue and lands into the fountain's "+ 
"basin.  A cool breeze touches you with the cool "+
"mist coming from the fountain.\n");

   add_item("statue",
"You see an old, stone, sun bleached statue of a woman with her arms "+
   "outstretched welcoming you to the Temple of Tymora.\n");

   add_item("basin",
"You expected the water in the basin to be shallow, but the water is in "+
"fact dark and there is no bottom in sight.\n");

   add_item("water",
"The water is cool and inviting.\n");

   add_exit("north", ROOM+"tymora", "door");
   add_exit("west", ROOM+"tymgarde", "road");
   add_exit("east", ROOM+"tymgazeb", "door");
   add_exit("south", ROOM+"tymgates", "road");

}

 

 


