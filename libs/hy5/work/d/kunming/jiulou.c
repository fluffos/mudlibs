// Room: /city/zuixianlou.c
// YZC 1995/12/04 

inherit ROOM;

void create()
{
	set("short", "酒楼");
	set("long", @LONG
这是一家极为普通的酒楼，平日里就卖些米酒，包子，大部分
来这里的人都是买点东西就走了，也有些人叫点花生米，切点熟牛
肉来对饮两盅的。
LONG
	);

	set("exits", ([
		"west" : __DIR__"nandajie1",
		
	]));

	set("objects", ([
		__DIR__"npc/xiaoer1" : 1,
	]));

	setup();
	replace_program(ROOM);
}

