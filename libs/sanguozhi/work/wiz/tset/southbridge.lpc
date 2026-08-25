// southbridge.c "山口"
#include <mudlib.h>
#include <ansi.h>
inherit OUTDOOR_ROOM;

void setup(){
    set_area("southbridge");
    set_light(0);
    set_brief(YEL+"山口"+NOR);
    set_long("
你从桥上走到这边。呀，原来这里有个小山呢！你不觉好奇心顿起。
北边有一条小河，可以从桥上(bridge)走过去。
\n\n");
    set_objects( ([
        __DIR__"bridge" : 1,
                    ]) );

    set_default_exit("好象走不通耶？\n");

    set_exits( ([
        "south" : __DIR__ "cave",
    ]) );
}

