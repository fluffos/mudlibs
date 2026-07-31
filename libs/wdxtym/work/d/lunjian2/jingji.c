#include <room.h>
inherit ROOM;

void create()
{
	set("short", "竞技场");
	set("long", "这里是华山论剑的比武竞技场。");
	set("exits", ([
		"out" : __DIR__"enter",
	]));
	set("objects",([
	]));
	setup();
}

int valid_leave(object me, string dir)
{
	me->force_me("quit");
	return 0;
}
