//  jfhou.c
//  夏口后房
//  created by tset 1/23/98
//  last updated by tset 1/23/98

#include <mudlib.h>

inherit INDOOR_ROOM;

void setup(){
        object door;
        set_area("xiakoujf");
        set_light(20);
        set_brief("后房");
        set_long("
后房有几个丫环正在和夫人小姐作针线活，一见到有人走进来，急
急忙忙地收拾起来，走到一边去了。
\n\n");

  set_exits( ([
        "east" : __DIR__"jiangfu"
                ]) );
                
  set_objects( ([
         __DIR__"obj/jf_door" : ({ "east" }),
                ]) );
                
  set_default_exit( "穿墙而过？还是走正路的好。\n");
  door = present( "door");
  if( !door->query_closed())
  door->do_on_open();
}
