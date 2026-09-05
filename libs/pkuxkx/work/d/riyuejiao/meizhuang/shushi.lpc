//shushi.c   书法室
//by bing

#include <room.h>
inherit ROOM;

void create()
{
	set("short","书室");
	set("long",@LONG 这是一间很大的屋子，但你一走进去却觉得很拥挤，因为屋里墙上，
桌子上，地上，到处都是写完或者没写完的字，让人几乎没有落脚的地
方。窗边有张大桌子，旁边立着个人，正在全神贯注地临摹字帖。
LONG
	);

	set("exits", ([
		"west"	: __DIR__"yuanzi",
	]));
	set("objects",([
		__DIR__"npc/tubi":1,
		]));

	setup();

}




