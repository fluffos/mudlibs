// Room: /city/zuixianlou.c
// YZC 1995/12/04 

inherit ROOM;

void create()
{
        set("short", "迎仙酒楼");
	set("long", @LONG
方圆数百里内提起迎仙酒可以说是无人不知，无人不晓。人
们对迎仙酒楼的郎酒赞不绝口。楼下布置简易，顾客多是匆匆的
行人，买点包子、鸡腿、米酒就赶路去了。楼上是雅座。
LONG
	);

	set("exits", ([
                "north" : __DIR__"xijie2",
                "up" : __DIR__"cdjiulou2",
	]));

	set("objects", ([
		__DIR__"npc/xiaoer2" : 1,
	]));

	setup();
	replace_program(ROOM);
}

