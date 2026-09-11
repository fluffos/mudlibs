//  xiakoue.c
//  夏口城东
//  created by tset 1/20/98
//  last updated by tset 1/20/98

#include <mudlib.h>

inherit OUTDOOR_ROOM;

void setup(){
        set_area("xiakou");
        set_light(20);
        set_brief("城东");
        set_long("
这是一条颇为热闹的大街，好些小店都在这儿。北边有个仓库，门   
外有卫兵看守，看来是个要紧的地方。南边时时传来些呼喝声。 
\n\n");

  set_exits( ([
        "north" : __DIR__"liangcang",
        "south" : __DIR__"bingying",
        "east"  : __DIR__"eastgate",
        "west"  : __DIR__"xiakouc",
                ]) );
 
}
