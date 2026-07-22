// By River 2002.6.3

inherit ROOM;
#include <ansi.h>

void create()
{
	set("short", "石屋正房");
	set("long", @LONG
室中小几上点着一炉檀香，几旁蒲团上坐一个僧人。只见他身穿粗布僧袍，
两道长长的白眉从眼角垂了下来，面目慈祥，眉间虽隐含愁苦，但一番雍容高
华的神色，却是一望而知。
LONG
	);
	set("exits", ([
		"east" : __DIR__"xiangfang",
		"south" : __DIR__"zhulin",
	]));

	set("objects", ([
		__DIR__"npc/yideng" : 1,
	]));

	setup();
}
