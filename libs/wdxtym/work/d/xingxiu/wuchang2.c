// Room: /d/xingxiu/wuchang2.c

inherit ROOM;

void create()
{
	set("short", "山间平地");
	set("long", @LONG
山间平地，地上是嫩绿的小草，周围布了几棵桦树，山边有一
眼清泉。草地上树着几个星宿老怪当年从少林寺偷来的木人，用来
供星宿弟子练功所用。东西边紧邻着另一个练功场。
LONG );

	set("resource/water", 1);
	set("objects", ([
		__DIR__"obj/yangrou.c" : 3,
		"/clone/npc/mu-ren" : 4
	]));
	set("exits", ([
		"east" : __DIR__"xxroad6",
		"west" : __DIR__"wuchang3",
	]));
	set("outdoors", "xingxiu");
	set("for_family", "星宿派");
	setup();
}
