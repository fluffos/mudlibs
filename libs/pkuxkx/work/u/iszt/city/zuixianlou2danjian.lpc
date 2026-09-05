// Room: /city/zuixianlou2.c
// YZC 1995/12/04 

inherit ROOM;

void create()
{
	set("name", "醉仙楼");
	set("short", "醉仙楼雅座单间");
	set("long", @LONG
这里是雅座的一个单间。一个醉汉在这里醉得糊里糊涂的，还经常说梦话。
LONG);
	set("objects", ([
		__DIR__"npc/zuihan" : 1,
	]));

	set("exits", ([
		"west" : __DIR__"zuixianlou2",
	]));

	setup();
	replace_program(ROOM);
}