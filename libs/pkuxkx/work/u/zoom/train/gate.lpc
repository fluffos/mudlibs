//gate.c
//by zoom
//2004.3.29
 
#include <ansi.h>
 
inherit ROOM;

void create()
{
        set("short", "新手学堂");
        set("long", 
"这是新手学堂的大门，大门的正上方悬挂着一块匾，上面写的是：\n\n"
+HIG"                     新 手 学 堂\n\n"NOR+
"字写的极其俊秀，想来是大家手笔，门口站着几个迎接客人的仆人。\n"
        );

        set("exits", ([
                "north" : __DIR__"yuan1",
//                "south" : "/u/zoom/wizard_room_zoom",
        ]));

        set("objects", ([
//                __DIR__"npc/zhaodai" : 1,
        ]));
 
        set("outdoors", "train");

        setup();
}

