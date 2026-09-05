// File		: chengtouw3.c
// Created By	: iszt@pkuxkx, 2006-08-15

#include <ansi.h>;

inherit ROOM;

void create()
{
	set("short", WHT"城头"NOR);
	set("long", @LONG
这里便是凌霄城的城墙了。几名弟子正来回巡逻，警惕地向外看。顺着他们
的目光，可以看到城外那道护城谷有七八丈阔，不易跃过。此处气候严寒，这谷
极深不说，崖上更泼了水，滑溜溜地结成一片冰壁，不论人兽，都是极难上来。
LONG);
	
	set("outdoors", "凌霄城");
	set("exits", ([
		"east" : __DIR__"chengtouw2",
		"west" : __DIR__"chengtouw4",
	]));
	set("objects", ([
		__DIR__"npc/dizixl" : 1,
	]));

	setup();
	replace_program(ROOM);
}

