inherit "room/room";
#include "/players/tatsuo/def.h"

void reset(int arg){
 
if(!present("farmer")){ MO(CO(HMON+"farmer"),TO); 
                         MO(CO(HMON+"farmer"),TO); 
                         MO(CO(HMON+"farmer"),TO); 
                         MO(CO(HMON+"farmer"),TO); 
                                                   } 
if(arg) return;

  ::reset(arg);
  set_light(1);

  long_desc = "You stand on the west bank of the river.  A stone building lies to the "+
              "north.  Amber fields of wheat stretch out to the horizon
   
            
              ".\n";

  short_desc= "Along the Shayla river";

  dest_dir = ({ HPATH+"bridge","east", HPATH+"p11","north",
                HPATH+"pr1","south" });

  items = ({  "valley","Umm, the valley is to the north",
              "stone structure","go south and see for yourself",
              "structure","It lies to the south",
              "river","Same ole river",
              "land","Yes it is, thank god"
              });

replace_program("room/room");

}
/*filler room to extend mud far to the south*/

