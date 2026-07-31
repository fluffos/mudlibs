// Room: /jingzhou/liangcang.c
// congw 980830 

inherit ROOM;

void create()
{
	set("short", "粮仓");
	set("long", @LONG
这里就是荆州粮仓了，地上堆着许多麻袋（dai)，大概装的是包谷大米之类的粮
食。
LONG
	);

	set("exits", ([
		"west" : __DIR__"lcmen",
	]));

	setup();
	replace_program(ROOM);
}

