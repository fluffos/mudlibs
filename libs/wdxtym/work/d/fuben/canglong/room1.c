// Room: banfang.c

inherit ROOM;

void create()
{
	set("short", "院中");
	set("long", @LONG
这里是堡内大院子，场中充满萧杀之气。
LONG
	);
	set("exits", ([
		"south" : __DIR__"enter",
		"north" : __DIR__"room2",
		"east" : __DIR__"room11",
		"west" : __DIR__"room14",
	]));
	set("objects", ([
		"/d/fuben/npc/hanfei": 2,
	]));
	setup();
}
#include "/d/fuben/room_fb.h"