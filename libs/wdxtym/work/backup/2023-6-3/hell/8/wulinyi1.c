// by jjyy

inherit ROOM;

void create()
{
	set("short", "四圣一街");
	set("long", "这是一条宽阔的青石街道。");
	set("outdoors", "hell");
	set("exits", ([
		"west" : __DIR__"beijie3",
		"east" : __DIR__"wulinyi2",
	]));
	//set("price_build", 1000);
	setup();
}
