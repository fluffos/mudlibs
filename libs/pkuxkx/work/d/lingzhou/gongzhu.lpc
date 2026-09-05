// Room: /lingzhou/gongsquare.c
// Java. Sep 21 1998

#include <room.h>

inherit ROOM;
void create()
{
	set("short", "公主寝宫");
	set("long", @LONG
这里是西夏过公主的寝宫。
LONG );
	set("exits", ([
		"west":__DIR__"zhulin1",
		"east":__DIR__"huayuan",
	]));
	set("objects",([
		__DIR__"npc/gongnu":2,
		"/d/lingjiu/npc/princess":1,
	]));

	setup();
	replace_program(ROOM);
}

