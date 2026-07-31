// Room: /d/gaibang/qzandao2.c
// Date: Haa 96/03/22

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "暗道");
	set("long", @LONG
这是丐帮极其秘密的地下通道，乃用丐帮几辈人之心血掘成。
LONG );
	set("exits", ([
		"southeast" : __DIR__"underqz",
		"northwest" : __DIR__"qzandao1",
	]));
	set("objects",([
		"/d/city/obj/jitui" : 3,
		"/d/city/obj/jiudai" : 1,
	]));
//	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

