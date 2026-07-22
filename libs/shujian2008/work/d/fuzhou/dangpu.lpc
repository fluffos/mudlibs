// Room: /d/fuzhou/dangpu.c
// Lklv 2001.9.10
inherit ROOM;

void create()
{
	set("short", "当铺");
	set("long", @LONG
这是一家素以买卖公平著称的老字号当铺，一个四尺高的柜台摆在你的面
前，柜台上摆着一个牌子(paizi)， 柜台后坐着当铺的老板，一双鬼溜溜的眼
睛上上下下打量着你。
LONG
	);
	set("no_fight",1);
	set("no_sleep_room",1);

	set("item_desc", ([
		"paizi" : "公平交易，童叟无欺。\n",
	]));
	set("objects", ([
		__DIR__"npc/zhang" : 1,
	]));
	set("exits", ([
		"south" : __DIR__"xijie",
	]));
	setup();
}

