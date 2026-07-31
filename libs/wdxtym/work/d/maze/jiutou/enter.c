// Room: /city/beimen.c
#include <room.h>

inherit ROOM;

void create()
{
	set("short", "无尽深渊");
	set("long", @LONG
这是无尽深渊，镇压穷奇妖兽之处。
LONG );
    
	set("exits", ([
		"northeast" : "/d/city/guangchang",
		

	]));

	set("objects", ([
		"/u/dragon" : 2,
	]));
	set("outdoors", "city");
	setup();
}

