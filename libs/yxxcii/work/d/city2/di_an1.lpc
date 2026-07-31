//Design By Robert 蝴蝶君 email:stcoolman@21cn.com

inherit ROOM;

void create()
{
	set("short", "地安门东大街");
	set("long", @LONG
这是一条东西走向的大道。西边通往地安门。东边通往王府井。南边
就是东厂了，一般人都不敢往那儿去。
LONG
);
	set("outdoors", "city2");

	set("exits", ([
		"east" : __DIR__"wangfu3",
		"west" : __DIR__"di_an2",
		"south" : __DIR__"dongchangdamen",
	]));

	setup();
	replace_program(ROOM);
}


