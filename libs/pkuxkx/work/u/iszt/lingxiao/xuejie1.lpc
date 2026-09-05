// File		: xuejie1.c
// Created By	: iszt@pkuxkx, 2006-08-15

#include <ansi.h>;

inherit ROOM;

void create()
{
	set("short", WHT"雪街"NOR);
	set("long", @LONG
也许是因为雪街是凌霄城「城」之所在，雪街上的气氛比之冰街要轻松很多。
几名弟子在来回闲逛，偶尔也相互交手，切磋技艺。巡逻的弟子也少了些。北边
是一家石作坊，供应修修补补的建筑材料；南边是一家柴火店，严寒之中的取暖
几乎全靠这里的木柴。
LONG);

	set("outdoors", "凌霄城");
	set("exits", ([
		"east" : __DIR__"xuejie2",
		"north" : __DIR__"xuenorth1",
		"south" : __DIR__"xuesouth1",
		"northwest" : __DIR__"jiaomenw",
	]));
	set("objects", ([
//		__DIR__"npc/dizifr" : 2,
		__DIR__"npc/dizixl" : 1,
	]));

	setup();
	replace_program(ROOM);
}

