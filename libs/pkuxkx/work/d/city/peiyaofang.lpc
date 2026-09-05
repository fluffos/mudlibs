// Room: /city/peiyaofang.c   平一指的配药房
// YZC 1995/12/04 

inherit ROOM;

void create()
{
	set("short", "配药房");
	set("long", @LONG
这是平一指大夫的配药房，里边光线非常暗淡，你仔细一看，四周围墙摆满
了一排排的药柜，屋子里散发着浓重的中药气味。
LONG);

	set("exits", ([
		"south" : __DIR__"yaopu",
	]));

	setup();
	replace_program(ROOM);
}