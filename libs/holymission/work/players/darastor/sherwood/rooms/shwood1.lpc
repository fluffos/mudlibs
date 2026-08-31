inherit "/room/room";

#include "../light.h" 
#include "../climb.h"
#include "../listen.h"
#include "../cut.h"
#include "../shake.h"
#include "../pass.h"
#include "../dig.h"
#include "../tear.h"

reset(arg){
 set_light(1);
 short_desc=("Dusty road");
 long_desc=("You are walking on the long dusty road. The road continues to the"
             +" west and \n"
          +"to the east. There are high trees and small bushes along the"
       	     +" road.\n"
           +"To the west you see huge dark forest. The forest is "
                 +"named Sherwood.\n");
 smell="You smell dust from the road.";
 dest_dir=({"/players/goldsun/sherwood/room/road", "east",
           "/players/goldsun/sherwood/room/shwood2", "west"});
 items=({"road", "The road is very dusty, but you can see several"
                     +" footprints"
                 +"in the dust",
         "tree", "The tree is high",
         "bush","The bush is small",
	 "animals","There are no animals here",
 	 "grass","It is common grass",
	 "small bush","The bush is small",
	 "small bushes","The bushes are small",
	 "bushes","The bushes are small",
         "high tree", "There are several high trees along the road",
         "forest","A forest to the west",
 	 "dark forest","A forest to the east",
         "high trees", "They are very high",
         "footprints","They are not so old",
         "dusty road","The road is very dusty, but you can see several"
                +" footprints\n"
              +" in the dust",
         "long road","The road is dusty",
         "long dusty road","The road is long and dusty",
         "footprint","The footprint is medium",
         "trees", "The trees along the road are high and old"});

 ::reset(arg);
 }

init(){
 ::init();
 add_action("climb","climb");
 add_action("cut","cut");
 add_action("cut","chop");
 add_action("tear","tear");
 add_action("light","light");
 add_action("pass","pass");
 add_action("shake","shake");
 add_action("dig","dig");
 add_action("listen","listen");
}
