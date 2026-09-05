//cunlu2.c	村中小路
//by bing

#include <room.h>
inherit ROOM;

void create()
{
	set("short","村中小路");
	set("long",@LONG 
这是村子中的小路。路边栽着一些柳树。左边是一个
铁匠铺，由于这是日月神教的地盘，习武之人很多，所以
铁匠铺生意很好。右边是一大块良田，种着庄稼，远远看
去，一片翠绿。
LONG
	);

	set("exits", ([
		"north" : __DIR__"cunlu3",
		"south"	: __DIR__"cunlu1",
		"west"	: __DIR__"datiepu",
		"east"	: __DIR__"tiandi2",
	]));
	set("objects",([
		__DIR__"npc/boy" : 2,
		__DIR__"npc/girl": 1,
			]));

	set("outdoors", "riyuejiao");
	setup();

}

