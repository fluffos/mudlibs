// Room: banfang.c

inherit ROOM;

void create()
{
	set("short", "偏房");
	set("long", @LONG
这里是卧龙堡的一处偏房。
LONG
	);
	set("exits", ([
		"east" : __DIR__"room3",
	]));
	set("objects", ([
		__DIR__"npc/jiaotou": 4,
	]));
	setup();
}
#include "/d/fuben/room_fb.h"