// Room: /u/jpei/thd/road1.c

inherit ROOM;

void create()
{
	set("short", "土路");
	set("long", @LONG
一条郊外的土路，远处似乎有座村落。
LONG
	);
	set("no_clean_up", 0);
	set("outdoors","nio");

	set("exits", ([
		"north": __DIR__"road.c",
		"southeast": __DIR__"road2.c",
	]) );

	setup();
	replace_program(ROOM);
}

