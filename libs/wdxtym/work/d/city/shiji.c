// Room: /city/zahuopu.c
inherit ROOM;

void create()
{
	set("short", "市集");
	set("long", @LONG
这是一广场大榕树下的市集，大箱小箱堆满了一地，都是一些交易用品。奇怪的幻兽商人洋洋地躺在榕树下，打量着过往行人。据说私底下他也卖一些贵
重宠物。摊上立着一块招牌(zhaopai)。
LONG );
	set("item_desc", ([
		"zhaopai": "只卖有缘人\n",
	]));
	set("no_fight",1);
	set("exits", ([
		"up" :  __DIR__"level_up",
		"down" : __DIR__"guangchang",
		
	]));
	set("objects", ([
		"adm/npc/beastseller": 1,
	]));
	setup();
}

