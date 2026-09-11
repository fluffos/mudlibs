//  xiakous.c
//  夏口城南
//  created by tset 1/23/98
//  last updated by tset 1/23/98

#include <mudlib.h>

inherit OUTDOOR_ROOM;

void setup(){
        set_area("xiakou");
        set_light(20);
        set_brief("城南");
        set_long("
城南一片肃然之气。东边是个铁铺，时而传来「叮当」的敲击声。
西边似乎是一个将府，门口有家丁把守。南方是南城门。
\n\n");

  set_exits( ([
        "north": __DIR__"xiakouc",
        "south": __DIR__"southgate",
        "east" : __DIR__"tiepu",
        "west" : __DIR__"jiangfu",
                ]) );
}
