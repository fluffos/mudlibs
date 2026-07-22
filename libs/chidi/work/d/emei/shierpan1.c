// Room: /d/emei/shierpan1.c 峨嵋派 十二盘1


inherit ROOM;




void create()
{
	set("short", "十二盘");
	set("long", @LONG
这里石阶陡折多弯，号称「十二盘」。由此西上可达华严顶，东至万年庵，
下则到白龙洞。
LONG
	);

	set("exits", ([
                "west" : __DIR__"wannianan",
                "eastup": __DIR__"shierpan2",
                "northdown":  __DIR__"bailongdong",
	]));

	set("outdoors", "emei");
	setup();
}



