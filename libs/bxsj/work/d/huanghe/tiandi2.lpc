// by XiaoYao

#include <room.h>

inherit ROOM;
void create()
{
	set("short", "田地");
	set("long", @LONG
这里林木渐渐稀疏，不远处有一些村庄，炊烟袅袅升起。村庄周围是一块
块的田地，田里有一些正在耕作的农人。
LONG );
	set("exits", ([
		"southwest" : "/d/group/entry/hhshulin5",
		"east"      : __DIR__"tiandi1",
	]));
	set("objects", ([
		__DIR__"npc/cow" : 1,
	]));
	set("outdoors", "黄河");
	setup();
}
