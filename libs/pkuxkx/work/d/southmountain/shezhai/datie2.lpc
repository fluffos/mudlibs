// 东天目山，一座随机生成的区域。玩家副本 Zine 2014/7/14
inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", HIR+"打铁炉"+NOR);
	set("long", @LONG
这里唯一的一件东西就是打铁炉，地方十分拥挤逼仄。
LONG
	);
        //set("outdoors", "xitianmu");

	set("exits", ([
		//"northwest" : __DIR__"westgc",
		//"east" : __DIR__"xiaolu3",
		"out" : __DIR__"datie",
		//"south" : __DIR__"jiuguan",
	]));

	set("objects", ([
		"obj/smith/tools/furnace" : 1,
		//__DIR__"npc/songbing_y" : 2,
        ]));
	setup();
}
int dest()
{
	if (this_object())
	destruct(this_object());
}
int valid_leave(object me,string dir)
{
	if (dir=="out")
	call_out("dest",1);
	return ::valid_leave(me,dir);
}
