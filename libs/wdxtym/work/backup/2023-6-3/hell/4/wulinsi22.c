
inherit ROOM;

void create()
{
	set("short", "东阳四街");
	set("long", "这是一条宽阔的青石街道。");
	set("outdoors", "hell");
	set("exits", ([
		"south" : "/data/home/q/q3043765268_1/hell/wanxia",
		"east" : __DIR__"wulinsi21",
		"west" : __DIR__"nanjie6",
	]));
	set("price_build", 1000);
	setup();
}
