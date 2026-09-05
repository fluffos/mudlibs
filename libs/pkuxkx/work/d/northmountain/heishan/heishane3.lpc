inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", "入山道"+NOR);
	set("long", @LONG
这里是进入黑山的山间路。
LONG
	);
        set("outdoors", "heishan");

	set("exits", ([
		"northwest" : __DIR__"heishane2",
		"southeast" : "/d/changbai/guandao9",
		//"northeast" : __DIR__"wall1",
		//"eastdown" : __DIR__"fengshu",
	]));
	set("objects", ([
		__DIR__"npc/laoliehu2" : 1,
		//__DIR__"npc/songbing_y" : 2,
        ]));
	setup();
}
int valid_leave(object me,string dir)
{
	if (!userp(me)&&dir=="southeast") return notify_fail("");
	return ::valid_leave(me,dir);
}