// by jjyy

inherit ROOM;

void create()
{
	set("short", "四圣一街");
	set("long", "这是一条宽阔的青石街道。");
	set("outdoors", "hell");
	set("exits", ([
		"north" : __DIR__"wulinyi6",
		"south" : __DIR__"wulinyi8",
	]));
	//set("price_build", 1000);
	setup();
}
