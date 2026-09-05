//road3.c	土路
//by bing

#include <room.h>
inherit ROOM;

void create()
{
	set("short","土路");
	set("long",@LONG 
地势渐渐上倾，土路也慢慢变窄，两旁稀稀落落有几个行人
慢慢走着。道路两边已是高耸的山崖。这里官府不愿管，所以不
太安全。一般人到这儿都带着武器防身。
LONG
	);

	set("exits", ([
		"northup" : __DIR__"shanlu",
		"southwest"	: __DIR__"road2",
	]));
	set("outdoors", "riyuejiao");
	setup();

}

