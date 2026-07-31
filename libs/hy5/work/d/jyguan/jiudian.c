// Room: /jyguan/jiudian.c
// YZC 1995/12/04 , 1998/10/08 Shark Edit

inherit ROOM;

void create()
{
	set("short", "小酒馆");
	set("long", @LONG
	方圆数百里内这家酒馆很是出名，是戍边将士、过往客商寻乐解闷的场
所。楼下布置简易，顾客多是匆匆的行人，买点包子、鸡腿、米酒就赶路去了。
楼上是雅座。
LONG
	);

	set("exits", ([
		"west" : __DIR__"townroad",
		"up" : __DIR__"zuixianlou2",
	]));

	set("objects", ([
		__DIR__"npc/xiaoer2" : 1,
	]));

	setup();
	replace_program(ROOM);
}

