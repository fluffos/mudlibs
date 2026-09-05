// Room: /city/dangpu.c
// YZC 1995/12/04 

#include <ansi.h>

inherit F_HOCKSHOP;

void create()
{
	set("short", "当铺");
	set("long",
"这是一家以买卖公平著称的当铺，一个五尺高的柜台挡在你的面前，柜台上
摆着一个牌子"YEL"(paizi)"NOR"，柜台后坐着唐老板，一双精明的眼睛上上下下打量着你。
");
	set("no_beg",1);
	set("no_steal", 1);
	set("no_fight", 1);
	set("item_desc", ([
		"paizi" : "公平交易
	卖东西：sell id(或name) [number]
	买东西：buy id(或name)
	当东西：pawn(dang) id
	赎东西：retrieve(shu) piao
	看可卖物品：list
	估价：value id
",
	]));
	set("objects", ([
		"/d/city/npc/tang" : 1,
	]));
	set("exits", ([
		"west" : __DIR__"nandajie1",
		"south" : __DIR__"rbz",
	]));

	setup();
}