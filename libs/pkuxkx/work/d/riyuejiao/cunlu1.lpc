//cunlu1.c	村中小路
//by bing

#include <room.h>
inherit ROOM;

void create()
{
	set("short","村中小路");
	set("long",@LONG 
这是村子中的小路。路边栽着一些柳树。左边是一个
小院子，看来住着人家，右边是一大块良田，种着庄稼，
远远看去，一片翠绿。
LONG
	);

	set("exits", ([
		"north" : __DIR__"cunlu2",
		"south"	: __DIR__"rukou",
		"west"	: __DIR__"yuanmen",
		"east"	: __DIR__"tiandi1",
	]));
	set("objects",([
		__DIR__"npc/girl" : 2,
		__DIR__"npc/kid"  : 2,
			]));

	set("outdoors", "riyuejiao");
	setup();

}

