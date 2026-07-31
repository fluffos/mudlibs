// Room: caidi
// congw 980830 

inherit ROOM;

void create()
{
	set("short", "菜地");
	set("long", @LONG
你看到一片绿油油的菜地，种满了各种各样的菜，空心菜、大头菜、白菜。。。。

LONG
	);

	set("exits", ([
		"east" : __DIR__"whouyuan",
		]));

	setup();
	replace_program(ROOM);
}

