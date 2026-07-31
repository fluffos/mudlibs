//Design By Robert 蝴蝶君 email:stcoolman@21cn.com

#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", "庄府大厅");
	set("long", @LONG
这是一间大厅，大厅上收拾得十分干净，也显得十分冷清。大厅四面
各有扇门，通往各个房间。东边的屋里有女子啼哭之声隐隐传来......
LONG );
	set("exits", ([
		"east" : "/d/city2/zhuang6",
		"west" : "/d/city2/zhuang7",
		"north" : "/d/city2/zhuang8",
		"south" : "/d/city2/zhuang4",
	]));
	set("objects", ([
		"/d/city2/npc/dizi": 2,
	]));
	set("outdoors", "city2");

	setup();
	replace_program(ROOM); 
}


