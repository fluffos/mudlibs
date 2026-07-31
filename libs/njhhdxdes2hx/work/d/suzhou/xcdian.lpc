//ROOM: d/suzhou/xcdian.c
// by dwolf
// 97.11.4

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", MAG"小吃店"NOR);
	set("long", @LONG
	  你来到小吃店，小二立即迎了上来。这儿有不少客人再品赏着风味各异的小吃。
LONG
	);
	set("no_sleep_room", 1);
	set("outdoors","suzhou"); 
	set("exits", ([
		"north" : __DIR__"wroad3",
	]));
	set("objects", ([
		__DIR__"npc/xiaoer" : 1,
]));
	setup();
}





