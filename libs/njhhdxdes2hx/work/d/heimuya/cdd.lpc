// Room: /d/heimuya/.c
// write by: dfbb@hero 
// date 97/01/25
#include <room.h>
inherit ROOM;

void create()
{
	set("short","成德殿");
	set("long", @LONG
殿顶由四根八丈高的红柱撑著，地板则是由白玉石铺成。
这是一个极大的大厅,阔不过四十来尺,长却有三百来尺
长端彼端高设一座.
LONG
	);

	set("exits", ([
		"south" :__DIR__"dingfeng12",
		"north" :__DIR__"xiaowu",
	]));

	set("objects",([
		 __DIR__"npc/yanglianting" :1,
		 __DIR__"npc/jiao_zhong6" :4,

        ]));
        create_door("north", "铁门", "south", DOOR_CLOSED);
	setup();
}

