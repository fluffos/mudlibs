// Room: /lingzhou/gongsquare.c
// Java. Sep 21 1998

#include <room.h>

inherit ROOM;
void create()
{
	set("short", "皇宫后殿");
	set("long", @LONG
这里是西夏皇宫的后殿，西夏国王有时在这里和一些重要的大臣秘谈。
LONG );
	set("exits", ([
		"south"  : __DIR__"zhengdian",
		"north":__DIR__"hougong",
		"east":__DIR__"zhenbao",
		"west":__DIR__"xiuxishi",
	]));
	set("objects", ([
		__DIR__"npc/gongweishi" :2,
	]));
	setup();
	replace_program(ROOM);
}

