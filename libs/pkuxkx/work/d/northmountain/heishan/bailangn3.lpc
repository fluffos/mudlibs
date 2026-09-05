inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", "山间小路"+NOR);
	set("long", @LONG
这里是进入白狼山的山间小路，北面通向山海关。
LONG
	);
        set("outdoors", "heishan");

	set("exits", ([
		//"north" : __DIR__"heishane1",
		"southup" : __DIR__"bailangn2",
		"northdown" : "/d/changbai/shguan1",
		//"eastdown" : __DIR__"fengshu",
	]));
	set("objects", ([
		//__DIR__"npc/wujiang" : 1,
		//__DIR__"npc/songbing_y" : 2,
        ]));
	setup();
}
int valid_leave(object me,string dir)
{
	if (!userp(me)&&dir=="northdown") return notify_fail("");
	return ::valid_leave(me,dir);
}