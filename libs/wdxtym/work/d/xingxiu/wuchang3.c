// Room: /d/xingxiu/wuchang3.c

inherit ROOM;

void create()
{
	set("short", "山间平地");
	set("long", @LONG
这里有点荒凉，小草也长得无精打采的，看来是星宿的底子毒
练多了，毒素都聚集在这里，连草木也遭了殃。地上零零散散的摆
了几个木人，有些破旧。
LONG );

	set("objects", ([
		"/clone/npc/mu-ren" : 3
	]));
	set("exits", ([
		"east" : __DIR__"wuchang2",
	]));
	set("outdoors", "xingxiu");
	set("for_family", "星宿派");
	setup();
}
