//ROOM: d/suzhou/wroad4.c
// by dwolf
// 97.11.4

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", MAG"西大街"NOR);
	set("long", @LONG
	  你走在西大街上，感到这里的街面要比别处的干净、整洁。不知道是什么
原因。东边远处传来喧闹声。北边是一口水井，可以喝水。西边就到城门了。南边是
有一家杂货铺，可以买一些东东。
LONG
	);
	set("no_sleep_room",0);
	set("outdoors","suzhou"); 
	set("exits", ([
		"west" : __DIR__"wgate",
		"north" : __DIR__"sjin",
		"south" : __DIR__"zhpu",
		"east" : __DIR__"wroad3",
]));
	set("objects", ([
		__DIR__"npc/ren" : 1,
]));
	setup();
}





