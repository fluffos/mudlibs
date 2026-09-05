// Zine Nov 26 2010
inherit ROOM;
#include <ansi.h>

void create()
{
        set("short", "义兴县城");
        set("long", @LONG
这里是义兴县城的广场，几个军士正在巡逻。
LONG);
        set("outdoors", "zhenjiang");
        set("exits", ([     
                "south" : __DIR__"yx-nanmen",
                "north" : __DIR__"yx-beimen",
                "enter" : __DIR__"xianfu",
                "east" : __DIR__"zhoujia",
                "west" : __DIR__"yx-ximen",
]));
     
    set("objects", ([
        "/d/city/npc/bing" : random(3),
        ]));    
   setup();
}

