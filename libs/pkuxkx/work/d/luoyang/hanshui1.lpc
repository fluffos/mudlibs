//洛阳，扩展地图
//by kiden
//2006-9-8
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "汉水");
        set("long", @LONG
汉水两岸高山耸立，峡谷中多， 水流很急，水量很大。一条青石大道
沿着河道修建，不时有行人骑马经过。
LONG
        );

        set("exits", ([
                "east" : __DIR__"hanshui",
                "northwest" : __DIR__"danjiangkou",
        ]));
        set("no_task",1);
        set("outdoors", "luoyang");
        setup();
        replace_program(ROOM);
}
