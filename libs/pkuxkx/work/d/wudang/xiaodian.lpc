// Room: /city/xiaodian.c
// xiao chi dian in wudang
// YZC 1995/12/04 
// arnzh 97/1/24
inherit ROOM;

void create()
{
	set("short", "小吃店");
	set("long", 
"这个小吃店布置简易，简直就是一个四面透风的凉棚嘛，\n"
"也能叫小吃店。顾客多是匆匆的行人，买点包子、鸡腿、米酒\n"
"就赶路去了。\n"
	);

	set("exits", ([
		"east" : __DIR__"yuzhen",
		"northup" : __DIR__"shijie14",
	]));

	set("objects", ([
		__DIR__"npc/xiaoer3" : 1,
                "/clone/npc/camel1": 0,
	]));

	setup();
	replace_program(ROOM);
}

