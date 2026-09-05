// File		: chengtoue2.c
// Created By	: iszt@pkuxkx, 2006-08-15

#include <ansi.h>;

inherit ROOM;

void create()
{
	set("short", WHT"城头"NOR);
	set("long", @LONG
这里便是凌霄城的城墙了。几名弟子正来回巡逻，警惕地向外看。顺着他们
的目光，可以看到城外的两条深谷在此交汇，向东北延伸。城墙也随之而行，那
谷仍是陡峭异常，极难上下。
LONG);
	
	set("outdoors", "凌霄城");
	set("no_sleep_room", 1);
	set("exits", ([
		"northeast" : __DIR__"chengtoue3",
		"southwest" : __DIR__"chengtoue1",
	]));
	set("objects", ([
		__DIR__"npc/dizixl" : 1,
	]));

	setup();
	replace_program(ROOM);
}

