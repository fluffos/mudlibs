// Room: /u/jpei/thd/road2.c

inherit ROOM;

void create()
{
	set("short", "土路");
	set("long", @LONG
一条郊外的土路，东南方有着一座小小的村落。
LONG
	);
	set("no_clean_up", 0);
	set("outdoors","nio");

	set("exits", ([
		"northwest": __DIR__"road1.c",
		"southeast": __DIR__"njwest.c",
	]) );

	setup();
	replace_program(ROOM);
}

