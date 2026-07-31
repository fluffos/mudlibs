#include <wanted.h>
inherit ROOM;

void create()
{
	set("short", "小路");
	set("long", @LONG
这是塘沽边上的一条小路，弯弯曲曲的沿向东方的海滨。路边长着些花草，
几只蝴蝶在花丛中飞来飞去。一阵海风吹来，使你精神更加爽朗。
LONG
	);

	set("exits", ([
		"southwest" : "/d/tanggu/gangkou",
		"northeast" : __DIR__"haitan",
	]));
	set("outdoors", "塘沽");

	setup();
}

int valid_leave(object me, string dir)
{
	if (dir == "northeast" && is_wanted(me))
		return 0;
	return ::valid_leave(me, dir);
}
