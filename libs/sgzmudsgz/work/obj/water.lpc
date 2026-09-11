// Updated by stefan on 10 Jan 1997
/* Do not remove the headers from this file! see /USAGE for more info. */

#include <mudlib.h>
#include <setbit.h>

inherit OBJ;
inherit M_GETTABLE;
inherit M_DRINKABLE;

create() {
  ::create();
  set_proper_name("水");
  set_in_room_desc("这里有一滩水。");
//  set_weight(4);
  set_adj( "一些", "一片", "一滩" );
  set_id( "water", "liquid", "h2o" );
  set_long("这水看起来没什么特别的。\n");
  set_gettable("你试试放点儿什么进去...\n");
  set_droppable("试试把它倒在什么容器里...\n");
}

int move_water(object target) {
    if (present("water", target)) {
        write(target->short()+"里面是满满的水。\n");
        return 0;
    }
    move(target);
    return 1;
}
