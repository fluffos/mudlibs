// Room: /huanghe/tiandi2.c
// Java. Sep 21 1998

#include <room.h>

inherit ROOM;
void create()
{
	set("short", "田地");
	set("long", @LONG
这里林木渐渐稀疏，不远处有一些村庄，炊烟袅袅升起。村庄周围
是一块块的田地，田里有一些正在耕作的农人。
LONG );
	set("exits", ([
		"southwest" : __DIR__"shulin5",
		"east"      : __DIR__"tiandi1",
	]));
	set("objects", ([
		"/d/wudang/npc/cow" : 1,
	]));
//	set("no_clean_up", 0);
	set("outdoors", "huanghe");
	setup();
	replace_program(ROOM);
}

