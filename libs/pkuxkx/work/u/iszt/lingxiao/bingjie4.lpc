// File		: bingjie4.c
// Created By	: iszt@pkuxkx, 2006-08-15

#include <ansi.h>;

inherit ROOM;

void create()
{
	set("short", WHT"冰街"NOR);
	set("long", @LONG
冰街到此就是尽头，向前登上石级，就是雪山一派武学高手聚居的凌霄内城
了。西边是家小吃铺，卖一些精致的小吃，提供外卖。雪山弟子如果错过了饭点，
倒是愿意来解解馋。东边的兵器铺不时有些好兵器出售，也是凌霄城中好武之人
常去的地方。
LONG);

	set("outdoors", "凌霄城");
	set("no_sleep_room", 1);
	set("exits", ([
		"west" : __DIR__"bingwest4",
		"east" : __DIR__"bingeast4",
		"south" : __DIR__"bingjie3",
		"northup" : __DIR__"bingjie5",
	]));
	set("objects", ([
//		__DIR__"npc/dizixl" : 1,
	]));

	setup();
	replace_program(ROOM);
}

