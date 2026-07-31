// /u/dubei/miaojiang

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "前厅");
        set("long", @LONG
这里是五毒教的前厅，四周全是苗疆风格的房屋。一名教众正在这里巡视
着，你抬眼望去，发现四周的屋顶上竟有许多毒蛇。
LONG
        );

        set("exits", ([
                "south" : __DIR__"wddamen",
                "east" : __DIR__"bingqif",
                "west" : __DIR__"chufang",
                "north" : __DIR__"myt",                
        ]));
      
        set("objects",([
                __DIR__"npc/jiaozhong" : 1,
        ]));

	setup();
}

#include "mjpoison.h"
