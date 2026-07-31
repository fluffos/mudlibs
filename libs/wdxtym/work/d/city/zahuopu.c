// Room: /city/zahuopu.c

inherit ROOM;

void create()
{
	set("short", "杂货铺");
	set("long", @LONG
这是一家小小的杂货铺，大箱小箱堆满了一地，都是一些日常用品。杨
掌柜懒洋洋地躺在一只躺椅上，招呼着过往行人。据说私底下他也卖一些贵
重的东西。摊上立着一块招牌(zhaopai)。
LONG );

	set("exits", ([
		"north" : __DIR__"dongdajie1",
		"south" : __DIR__"zahuo_neishi",
		"up"    : __DIR__"garments",
		
	]));
	set("objects", ([
		__DIR__"npc/yang": 1,
	]));
	setup();
}

