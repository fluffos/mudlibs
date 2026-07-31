// literate.c

inherit ROOM;

void create()
{
	set("short", "图书馆");
	set("long", @LONG
这是一间极为隐蔽的图书收藏室。
LONG );
	set("exits", ([
		"south" : __DIR__"lichunyuan",
	]));
	setup();
}

