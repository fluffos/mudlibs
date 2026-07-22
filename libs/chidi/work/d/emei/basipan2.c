// Room: /d/emei/basipan2.c 峨嵋派 八十四盘2

inherit ROOM;

void create()
{
	set("short", "八十四盘");
	set("long", @LONG
这里是八十四盘的中间，从窄窄的山梁上垂下了数根粗长的麻绳做成了
一个扶手，人只能紧贴岩石，蹒跚而上。
LONG
	);
        set("outdoors", "emei");
	set("exits", ([
		"eastdown" : __DIR__"basipan1",
                "southup":__DIR__"basipan3",
	]));

	setup();
}
