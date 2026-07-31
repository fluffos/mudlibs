// Room: /city/zahuo-neishi.c
inherit ROOM;

void create()
{
	set("short", "杂货铺内室");
	set("long", @LONG
这是杂货铺的内室，大箱小箱堆满了一地，都是一些日常用品。杨
掌柜的伙计热情招呼着过往行人。据说私底下他也卖一些贵
重的东西。
LONG );
	set("exits", ([
		"north" : __DIR__"zahuopu",
	]));
	set("objects", ([
		__DIR__"npc/zhushou": 1,
	]));
	setup();
}

