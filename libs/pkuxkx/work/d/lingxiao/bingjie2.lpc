// File		: bingjie2.c
// Created By	: iszt@pkuxkx, 2006-08-15

#include <ansi.h>;

inherit ROOM;

void create()
{
	set("short", WHT"冰街"NOR);
	set("long", @LONG
一条冰街笔直伸向前方。西边是一家小客栈，凌霄城弟子的家眷如果来探亲，
暂时可以住在那里。里边还混迹着一些江湖人物。东边是家钱庄，和中原的钱庄
通存通兑，给城内的其他交易提供了很大方便。
LONG);
	
	set("outdoors", "凌霄城");
	set("exits", ([
		"west" : __DIR__"bingwest2",
		"east" : __DIR__"bingeast2",
		"north" : __DIR__"bingjie3",
		"south" : __DIR__"bingjie1",
	]));
	set("objects", ([
//		__DIR__"npc/dizixl" : 1,
	]));

	setup();
	replace_program(ROOM);
}

