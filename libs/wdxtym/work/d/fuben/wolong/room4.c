// Room: banfang.c

inherit ROOM;

void create()
{
	set("short", "后院");
	set("long", @LONG
这里是卧龙堡的后院，是堡主周啸天所在的地方。
LONG
	);
	set("exits", ([
		"south" : __DIR__"room3",
	]));
	set("objects", ([
		__DIR__"npc/baozhu" : 1,
		__DIR__"npc/jiaotou": 4,
	]));
	setup();
}
#include "/d/fuben/room_fb.h"
