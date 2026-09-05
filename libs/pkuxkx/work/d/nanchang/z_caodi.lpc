
// edit: by zine Aug 21 2010


#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "草地");
	set("long", @LONG
这里一片大草地，躺在这里休息一会很是惬意。一对青年男女在远处聊着天。
LONG
	);
	set("exits", ([ 		
        "southeast" : __DIR__"z_guangchang",
        
		
    ]));
	set("no_task",1);
    set("sleep_room", "1");
    set("outdoors", "nanchang");
    set("objects", ([
		__DIR__"npc/zhuang_man": 1,
        __DIR__"npc/zhuang_woman": 1,
        ]));
	setup();
	
}


