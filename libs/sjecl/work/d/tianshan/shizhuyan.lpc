// Room: /d/tianshan/shizhuyan.c
// By Linux

inherit ROOM;
#include <wanted.h>

void create()
{
	set("short", "失足岩");
	set("long", @LONG
这里是失足岩，乃天山山路关口，常年风雪连天，地势陡斜，尽是冰天雪
地，踏足滑斜，随时有倾泻之危，常人绝难直进，故取失足之名。
LONG);
	set("exits", ([
                "southdown" :__DIR__"duanhunya",
	        "north" :__DIR__"bzhanjian",   
        ]));    
        set("objects", ([
             //   __DIR__"obj/****" : 1,
        ]));    

	set("outdoors", "天山");
	setup();
}

int valid_leave(object me, string dir)
{
	if (dir == "north" && is_wanted(me))
		return 0;
	return ::valid_leave(me, dir);
}
