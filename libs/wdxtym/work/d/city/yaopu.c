// Room: /city/yaopu.c
inherit ROOM;

void create()
{
	set("short", "药铺");
	set("long", @LONG
这是一家药铺，一股浓浓的药味让你几欲窒息，那是从药柜上的几百个小
抽屉里散发出来的。神医平一指坐在茶几旁，独自喝着茶，看也不看你一眼。
柜台上贴着一张发黄的广告。
LONG );
	set("item_desc", ([
		"【广告】" : "本店出售以下药品：
金创药：\t十两白银
其他药品内室面议。\n",
	]));
	set("objects", ([
		__DIR__"npc/ping" : 1,
		__DIR__"npc/huoji" : 1,
	]));
	set("no_fight", 1);     
	set("no_sleep_room", 1);
	set("exits", ([
		"south" : __DIR__"dongdajie2",
		"north" : __DIR__"yaopu_neishi",

	]));
	setup();
}
