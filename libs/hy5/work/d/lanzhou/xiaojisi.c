// Room: /wizhome/lanzhou/xiaojisi.c
// Data: xws 98/10/14

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "小集市");
        set("long", @LONG
这里是兰州城的一个小集市。南边有一座老酒店，不时传来一阵阵酒香。由
于兰州是西北地区的交通要道，不论到西域还是中原都要经过这里，所以各地的
行人来来往往，你不时可以看见一些人带着满身酒气从身边经过。

LONG
        );
        set("no_sleep_room",1);
        set("outdoors", "lanzhou");


        set("exits", ([
                "south"  : __DIR__"jioudian",
                "north"  : __DIR__"xidajie1",
        ]));

        set("objects", ([
        __DIR__"npc/liumang" : 2,
        __DIR__"npc/liumangtou" : 1,    
       	]));

        setup();
}
