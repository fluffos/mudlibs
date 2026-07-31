//ROOM: d/suzhou/eroad1.c
// by dwolf
// 97.11.4

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", MAG"东大街"NOR);
	set("long", @LONG
	  这是一条宽阔的青石板街道，向东西两头延伸。西边不时地传来喧闹声,
东边挺安静。北边是一家钱庄。南边是一家当铺。街上有一些行人。
LONG
	);
	set("no_sleep_room",0);
	set("outdoors","suzhou"); 
	set("exits", ([
		"west" : __DIR__"shizx",
		"north" : __DIR__"qzhuang",
		"south" : __DIR__"dangpu",
		"east" : __DIR__"eroad2",
]));
	set("objects", ([
		__DIR__"npc/ren" : 2,
		__DIR__"npc/girl" : 1,
]));
	setup();
}





