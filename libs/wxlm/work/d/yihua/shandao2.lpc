// Room: /yihua/shandao1.c
// rtm 2000/03/04 

inherit ROOM;

void create()
{
	set("short", "山道");
	set("long", @LONG
这是一条好似水晶铺成的宽敞大道,每块都是长约八尺，宽约三尺
，甚是整齐，堪称巧夺天工。道旁是郁郁葱葱的玫瑰丛，不时可以看到
一两只野兔蹦蹦跳跳地跃向丛中深处。往北望去，一座巨大的宫殿巍然
耸立。
LONG
	);
        set("outdoors", "city");

	set("exits", ([
		"southdown" : __DIR__"shandao1",
		"northup" : __DIR__"juebi",
	]));

	setup();
	replace_program(ROOM);
}

