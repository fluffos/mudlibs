// Room: /d/emei/basipan1.c 峨嵋派 八十四盘1

inherit ROOM;

void create()
{
	set("short", "八十四盘");
	set("long", @LONG
这里是八十四盘的起点，也是峨嵋山最危险的一段路程，由此攀岩石而
上，后面的人可以看到前面的人的鞋底，前面的人回头则可见到后面的人的
发顶。在这里一般人每走十来步便要稍作休息。
LONG
	);
        set("outdoors", "emei");
	set("exits", ([
                "west": __DIR__"leidongping",
		"westup" : __DIR__"basipan2",
	]));

	setup();
}
