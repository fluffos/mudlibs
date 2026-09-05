// Room: /lingzhou/gongsquare.c
// Java. Sep 21 1998

#include <room.h>

inherit ROOM;
void create()
{
	set("short", "皇宫正殿");
	set("long", @LONG
这里是西夏皇宫的正殿，西夏国王日常就在这里接见群臣，批阅奏折，处理军国大事。
LONG );
	set("exits", ([
		"south"  : __DIR__"gongsquare",
		"north":__DIR__"houdian",
		"east":__DIR__"piandian1",
		"west":__DIR__"piandian2",
	]));
	set("objects", ([
		__DIR__"npc/taijian" :2,
		__DIR__"npc/gongweishi":4
	]));
	setup();
	replace_program(ROOM);
}

