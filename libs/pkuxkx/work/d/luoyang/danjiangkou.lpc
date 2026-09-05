//洛阳，扩展地图
//by kiden
//2006-9-8
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", HIC"丹江口"NOR);
        set("long", @LONG
这里便是丹江口，汉水的上游。沿着汉水走向可以去扬州，西北则去向洛阳。
远远看去，层峦叠嶂，风景如画，你不禁痴了。
LONG
        );

        set("objects", ([
                __DIR__"npc/randomnpc" : random(3),
        ]));
        set("no_task",1);
        set("exits", ([
                "southeast" : __DIR__"hanshui1",
                "northwest" : __DIR__"caodi",
        ]));

        set("outdoors", "luoyang");
        setup();
        replace_program(ROOM);
}
