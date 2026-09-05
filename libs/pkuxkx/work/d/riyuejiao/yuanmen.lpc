//yuanmen.c	院门口
//by bing

#include <room.h>
inherit ROOM;

void create()
{
	set("short","院门口");
	set("long",@LONG 
这是一所小宅院的院门。门口坐着一条大狗，正吐着
舌头懒懒地晒着太阳。小门上的春联已经残缺不全，认不
出是什么了。
LONG
	);

	set("exits", ([
		"west"	: __DIR__"xiaoyuan",
		"east"	: __DIR__"cunlu1",
	]));
	set("objects",([
		__DIR__"npc/dog" : 1,
			]));
	set("outdoors", "riyuejiao");
	setup();
	create_door("west","小木门","east",DOOR_CLOSED);
	replace_program(ROOM);
}

