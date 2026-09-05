// File		: xuejie2.c
// Created By	: iszt@pkuxkx, 2006-08-15

#include <ansi.h>;

inherit ROOM;

void create()
{
	set("short", WHT"雪街"NOR);
	set("long", @LONG
也许是因为雪街是凌霄城“城”之所在，雪街上的气氛比之冰街要轻松
很多。几名弟子在来回闲逛，偶尔也相互交手，切磋技艺。巡逻的弟子也少
了些。北边是风流才子徐元文开馆授课的地方，南边则是家书局，卖一些启
蒙书籍。
LONG);
	
	set("outdoors", "凌霄城");
	set("exits", ([
		"west" : __DIR__"xuejie1",
		"east" : __DIR__"xuejie3",
		"north" : __DIR__"xuenorth2",
		"south" : __DIR__"xuesouth2",
	]));
	set("objects", ([
		__DIR__"npc/dizifr" : 2,
		__DIR__"npc/dizixl" : 1,
	]));

	setup();
	replace_program(ROOM);
}

