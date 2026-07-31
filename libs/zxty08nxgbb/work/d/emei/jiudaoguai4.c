// Room: /d/emei/jiudaoguai4.c 峨嵋派 九十九道拐4

inherit ROOM;

void create()
{
	set("short", "九十九道拐");
	set("long", @LONG
这里是九十九道拐最末尾一段山道，道路两边生满了各种高大的树木，
郁郁葱葱。在下方不远的地方可以看到有个山洞洞口，向下走去，清凉之
感越来越浓了。
LONG
	);
        set("outdoors", "emei");
	set("exits", ([
                 "northwest" : __DIR__"jiudaoguai3",
                 "enter": __DIR__"jiulaodong",
	]));

	setup();
}
