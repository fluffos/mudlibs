//  bingying.c
//  夏口兵营
//  created by tset 1/23/98
//  last updated by tset 1/23/98

#include <mudlib.h>

inherit OUTDOOR_ROOM;

void setup(){
        set_area("xiakou");
        set_light(20);
        set_brief("兵营");
        set_long("
兵营里兵丁个个手持刀枪，在校尉的监督下刻苦操练。门口有士兵
守卫，看到你，说到：“闲人免进！”
\n\n");

  set_exits( ([
        "east"  : __DIR__"xiakoudjc",
        "north" : __DIR__"xiakoue",  
                ]) );
                
}
