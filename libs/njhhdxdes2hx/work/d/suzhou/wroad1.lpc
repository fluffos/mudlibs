//ROOM: d/suzhou/wroad1.c
// by dwolf
// 97.11.4

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", MAG"西大街"NOR);
	set("long", @LONG
	  这是一条宽阔的青石板街道，向东西两头延伸。东边不时地传来喧闹声,
西边也人声嘈杂。北边是一座豪华的酒楼，半月形的大门上方写着“八仙酒楼”四
个烫金大字，苍劲有力。里面不时地传来酒客们的划拳吆喝声，南边是一家大户。
LONG
	);
	set("no_sleep_room",0);
	set("outdoors","suzhou"); 
	set("exits", ([
		"west" : __DIR__"wroad2",
		"north" : __DIR__"bxlou",
		"south" : __DIR__"zuojia",
		"east" : __DIR__"shizx",
]));
	set("objects", ([
		__DIR__"npc/guo" : 1,
		__DIR__"npc/ren" : 1,
		__DIR__"npc/girl" : 1,
]));
	setup();
}





