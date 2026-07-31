// Room: banfang.c

inherit ROOM;

void create()
{
	set("short", "天幕");
	set("long", @LONG
禁地迷宫的某一处隐藏着几名守卫者！如没有掌门令牌会遭遇追杀。
LONG
	);
			set("no_fly",1);
	set("exits", ([
		"east" : __DIR__"room10",
	]));
	set("objects", ([
   __DIR__"npc/a1":3,
	]));
	setup();
}
#include "/d/fuben/room_fb.h"