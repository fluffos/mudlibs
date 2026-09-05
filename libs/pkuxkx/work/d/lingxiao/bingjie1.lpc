// File		: bingjie1.c
// Created By	: iszt@pkuxkx, 2006-08-15

#include <ansi.h>;

inherit ROOM;

void create()
{
	set("short", WHT"冰街"NOR);
	set("long", @LONG
一条冰街笔直伸向前方。其实一年之中大多数时候并没有冰，而是凌霄城
中对这条街习以为常的称谓叫“冰街”。西边是守城弟子轮值时休息的地方，东
边是凌霄弟子出城进城报到之处。
LONG);
	
	set("outdoors", "凌霄城");
	set("no_sleep_room", 1);
	set("exits", ([
		"west" : __DIR__"bingwest1",
		"east" : __DIR__"bingeast1",
		"south" : __DIR__"chengmen",
		"north" : __DIR__"bingjie2",
	]));
	set("objects", ([
                __DIR__"npc/chuwanchun" : 1,
		__DIR__"npc/dizixl" : 1,
	]));

	setup();
}

int valid_leave(object me, string dir)
{
	if (dir == "south")
		if (me->id("xueshan dizi"))
			return 0;

	return ::valid_leave(me, dir);
}
