// Room: /city/libailou.c
// congw 980830

inherit ROOM;

void create()
{
        set("short", "饭馆");
	set("long", @LONG
这是一家湘西小饭馆，布置简易，顾客多是匆匆的行人，买点包子、鸡腿、米酒就
赶路去了。
LONG
	);

	set("exits", ([
		"west" : __DIR__"beidajie2",
"up" : __DIR__"libailou2",			
                	]));

	set("objects", ([
		__DIR__"npc/xiaoer2" : 1,
	]));

	setup();
	replace_program(ROOM);
}

