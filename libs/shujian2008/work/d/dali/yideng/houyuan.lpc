// By River 2002.6.3

inherit ROOM;
#include <ansi.h>

void create()
{
	set("short", "禅院后院");
	set("long", @LONG
这是一个不大的小院，几个小沙弥正忙着打扫地面，后院左边是厨房，右
边是练功房，北面有个拱门，一条青石路曲折的通往前方。
LONG
	);
	set("outdoors", "桃源县");
	set("exits", ([
		"west" : __DIR__"chufang",
		"south" : __DIR__"dadian",
		"east" : __DIR__"liangong",
		"northwest" : __DIR__"xiaojing1",
	]));

	setup();
}
