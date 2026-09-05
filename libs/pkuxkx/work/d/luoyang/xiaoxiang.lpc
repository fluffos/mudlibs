//洛阳，扩展地图
//by kiden
//2006-9-8
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "小巷");
        set("long", @LONG
穿过碎石路，经过几条小街，来到一条窄窄的巷子之中。巷子尽头，
好大一片绿竹丛，迎风摇曳，雅致天然。
LONG
        );

        set("exits", ([
               "southwest" : __DIR__"suishilu1",  
               "north" : __DIR__"xiaoxiangjintou",         
        ]));
        set("objects", ([
//              __DIR__"npc/randomnpc" : 1,
        ]));

        set("outdoors", "luoyang");
        setup();
        replace_program(ROOM);
}

