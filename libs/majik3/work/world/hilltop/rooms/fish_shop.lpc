/* Fish shop */

inherit ROOM;

#include "../path.h"

create_room ()
{
   set_short("Fish shop");
   set_long ("This is the outdoor shop where fisherman's wife sells the fish his "
             +"husband catches. There's a table full of fish.\n");
   set_light(0);
   set_outdoors(3); 

   add_exit("east"     , ROOM_PATH + "shop_square");
   add_object(MONSTER_PATH + "fisherman_wife");
   
}


