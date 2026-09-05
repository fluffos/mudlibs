//城门
// By Zine 23 Nov 2010

inherit ROOM;
#include <ansi.h>

void create()
{
        set("short", "北城");
        set("long", 
"这里是建康府的北城。北面是神策门，西北是金川门，西南面是几处军营。\n"

        );
        set("exits", ([
                
                
                "northwest" : __DIR__"jinchuan",
                "north" : __DIR__"shence",
                "southwest" : __DIR__"junying1",
                "south" : __DIR__"zhonglou",
                "southeast" : __DIR__"gulou",
                
        ]));
        set("objects", ([
                __DIR__"npc/xianhan" : 1,
        ]));
        set("outdoors", "yingtianfu");
        setup();
   
}

