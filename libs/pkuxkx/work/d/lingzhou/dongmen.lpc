// Room: /lingzhou/dongmen.c
// Java. Sep 21 1998

#include <room.h>

inherit ROOM;
void create()
{
	set("short", "灵州东门");
	set("long", @LONG
这是东城门，城门正上方刻着几个西夏文字。城墙上贴着几张官府
告示。
LONG );
	set("exits", ([
		"west"      : __DIR__"dongdajie",
		"east" : __DIR__"xiaolu1",
	]));
	set("no_clean_up", 0);
	set("outdoors", "lingzhou");
	setup();
	replace_program(ROOM);
}

