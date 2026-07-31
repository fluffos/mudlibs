// Room: yaopu.c
// congw /98/08/29 

inherit ROOM;

void create()
{
	set("short", "药铺");
	set("long", @LONG
这是一家药铺，一股浓浓的药味让你几欲窒息，那是从药柜上的几百个小抽屉里散
发出来的。神医华陀二世坐在茶几旁，独自喝着茶，看也不看你一眼。一名小伙计
站在柜台后招呼着顾客。
LONG
	);
	set("item_desc", ([
		"guanggao" : "本店出售以下药品：
金创药：\t五十两白银
其他神药与老板面议。\n",
	]));

	set("objects", ([
		__DIR__"npc/huatuo" : 1,
		__DIR__"npc/huoji" : 1,
	]));

	set("exits", ([
		"east" : __DIR__"beidajie2",
	]));

	setup();
	replace_program(ROOM);
}

