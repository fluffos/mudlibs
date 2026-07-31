//ROOM: /d/suzhou/mapeng.c
//by dwolf
//97.11.4
       
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "马棚");
	set("long", "这是供军马休息的地方。里面有许多马匹。\n"); 
	set("objects", ([
		__DIR__"npc/obj/horse" : 4,
]));
	set("exits", ([
		"west" : __DIR__"zhuyin",
]));
	setup();
	replace_program(ROOM);
}
