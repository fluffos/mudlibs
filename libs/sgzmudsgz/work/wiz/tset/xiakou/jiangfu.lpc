//  jiangfu.c
//  夏口将府
//  created by tset 1/23/98
//  last updated by tset 1/23/98

#include <mudlib.h>

inherit INDOOR_ROOM;

void setup(){
        object door;
        set_area("xiakoujf");
        set_light(20);
        set_brief("将府");
        set_long("
将府内冷冷清清，四散放了些桌椅。北边好像有人在打算盘，南边
是个大厅，西边的小门正");
set_state_description( "jf_door_off", "关着。\n\n");
set_state_description( "jf_door_on", "开着。\n\n"); 

  set_exits( ([
        "north": __DIR__"jfzhang",
        "south": __DIR__"jfting", 
        "east" : __DIR__"xiakous",
        "west" : __DIR__"jfhou",  
                ]) );
                
  set_objects( ([
         __DIR__"obj/jf_door" : ({ "west" }),
                ]) );
                
  set_default_exit( "穿墙而过？还是走正路的好。\n");
  door = present( "door");
  if( !door->query_closed())
  door->do_on_open();
}
