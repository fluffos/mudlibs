// Room: /city/zuixianlou2.c
// YZC 1995/12/04 

inherit ROOM;


void create()
{
	set("name", "小酒馆");
	set("short", "小酒馆二楼");
	set("long", @LONG
	这里是雅座，文人学士经常在这里吟诗作画，富商土豪也在这里边吃喝边
作交易。这里也是城里举办喜宴的最佳场所。你站在楼上眺望，只觉得心旷神怡。
北面是嘉峪关，雄姿挺拔。
    墙上挂着价格牌子(paizi)。
LONG
	);

	set("item_desc", ([
		"paizi" : "本店出售烤鸭及上等花雕酒。\n",
	]));


	set("exits", ([
		"down" : __DIR__"jiudian",
	]));

	setup();
	replace_program(ROOM);
}
