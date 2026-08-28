/* Orc homeworld - The entrance */

inherit ROOM;
#include "../path.h"

create_room () {
   set_short("In front of cave");
   set_long("You are standing before about 10 feet high and wide, dark hole, leading "
            +"into the depths of the Black Mountain.\n");
   set_light(0);
   set_outdoors(4);
   
   add_sound("A foul odour, carried from the cave, makes your nose stir.");
   
   add_exit("cave", ROOM_PATH+ "passage");
   add_exit("leave", ROOM_PATH+ "/world/hilltop/rooms/room1");

   add_object( MONSTER_PATH + "guard1");
}

