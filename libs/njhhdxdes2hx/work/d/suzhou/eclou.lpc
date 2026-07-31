//ROOM: d/suzhou/eclou.c
// by dwolf
// 97.11.4

#include <ansi.h>
inherit ROOM;   

string look_hill();

void create()
{
	set("short", MAG"东城楼"NOR);
	set("long", @LONG
	  这是苏州东门城楼，从这儿可以看见(look)远处的山峰(hill)。许多游
人喜欢到这儿眺望。
LONG
	);
	set("no_sleep_room",0);
	set("outdoors","suzhou"); 
	set("exits", ([
		"down" : __DIR__"egate",
	]));
	set("objects", ([
		__DIR__"npc/ren" : 1,
]));                              
	set("item_desc", ([
		"hill" : (: look_hill :),
]));
	setup();
}           

string look_hill()
{
	return YEL"远处山峰高耸入云，飘渺莫测。\n"NOR;
}





