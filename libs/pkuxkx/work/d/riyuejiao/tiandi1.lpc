//tiandi1.c	庄稼地
//by bing

#include <room.h>
inherit ROOM;

void create()
{
	set("short","庄稼地");
	set("long",@LONG 
这是山坡上的一块庄稼地，大概是村里人种着自己吃的。
在山上取水不易，种庄稼就更难了。但看这些庄稼长势都很
好，显然种的人照料的很好。
LONG
	);

	set("exits", ([
		"north" : __DIR__"tiandi2",
		"west"	: __DIR__"cunlu1",
	]));
	set("objects",([
		__DIR__"npc/maque" : 4,
			]));

	set("outdoors", "riyuejiao");
	setup();

}

