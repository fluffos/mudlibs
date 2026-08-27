#include "path.h"
inherit CITYROOM;

#define NUM 3

setup()
{
   set_light(100);
   set_short("Farmer's Way");
   set_long("You are on Farmer's Way. "+
      "This way continues to the east and west. "+
      "To the north someone has been planting different kinds of plants "+
      "and trees. Some city-animals are playing among the trees. It seems "+
      "almost as if someone is building a Druid Grove or something.\n");
   add_exit("east",ROOM+"farmer4", "road");
   add_exit("west", ROOM+"farmer2", "road");
   add_alias("grove", "druid grove");
   add_item("druid grove",
      "The trees and other plants are growing fast, so it'll soon be finished.\n");
   set_monster(NUM, "city");
   set_zone("city");
}
