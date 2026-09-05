// Room: /lingzhou/gongsquare.c
// Java. Sep 21 1998

#include <room.h>

inherit ROOM;
void create()
{
	set("short", "珍宝室");
	set("long", @LONG
这里是西夏国皇宫的珍宝室，里面摆放满了来自各国的珍宝、古玩。
LONG );
	set("exits", ([
		"west":__DIR__"houdian",
	]));
	set("objects",([
		__DIR__"npc/gongweishi":2,
	]));

	setup();
	replace_program(ROOM);
}

