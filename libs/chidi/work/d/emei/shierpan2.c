// Room: /d/emei/shierpan2.c 峨嵋派 十二盘2

inherit ROOM;

void create()
{
	set("short", "十二盘");
	set("long", @LONG
这里石阶陡折多弯，号称「十二盘」。由此西上可达华严顶，下则到万
年庵。
LONG
	);

	set("exits", ([
                "westdown":  __DIR__"shierpan1",
                "eastup": __DIR__"shierpan3",
	]));

	set("outdoors", "emei");
	setup();
	replace_program(ROOM);
}



