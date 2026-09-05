// File		: xuejie6.c
// Created By	: iszt@pkuxkx, 2006-08-15

#include <ansi.h>;

inherit ROOM;

void create()
{
	set("short", WHT"雪街"NOR);
	set("long", @LONG
也许是因为雪街是凌霄城“城”之所在，雪街上的气氛比之冰街要轻松
很多。几名弟子在来回闲逛，偶尔也相互交手，切磋技艺。巡逻的弟子也少
了些。北边是一家寿板铺，南边是一家卦馆。
LONG);
	
	set("outdoors", "凌霄城");
	set("exits", ([
		"west" : __DIR__"xuejie5",
		"north" : __DIR__"xuenorth6",
		"south" : __DIR__"xuesouth6",
                "northeast" : __DIR__"stonese",
	]));
	set("objects", ([
		__DIR__"npc/dizifr" : 2,
		__DIR__"npc/dizixl" : 1,
	]));

	setup();
	replace_program(ROOM);
}

