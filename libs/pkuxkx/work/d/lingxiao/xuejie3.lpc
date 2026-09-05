// File		: xuejie3.c
// Created By	: iszt@pkuxkx, 2006-08-15

#include <ansi.h>;

inherit ROOM;

void create()
{
	set("short", WHT"雪街"NOR);
	set("long", @LONG
也许是因为雪街是凌霄城“城”之所在，雪街上的气氛比之冰街要轻松
很多。几名弟子在来回闲逛，偶尔也相互交手，切磋技艺。巡逻的弟子也少
了些。北边有一家小酒馆，常有同门师兄弟来喝两盅；南边出售山货，进出
的有不少身穿皮衣皮帽的商人。
LONG);
	
	set("outdoors", "凌霄城");
	set("exits", ([
		"west" : __DIR__"xuejie2",
		"east" : __DIR__"bingjie3",
		"north" : __DIR__"xuenorth3",
		"south" : __DIR__"xuesouth3",
	]));
	set("objects", ([
		__DIR__"npc/dizifr" : 2,
	]));

	setup();
	replace_program(ROOM);
}

