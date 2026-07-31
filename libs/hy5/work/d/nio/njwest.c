// Room: /u/jpei/thd/njwest.c

inherit ROOM;

void create()
{
	set("short", "村口");
	set("long", @LONG
这是一座小村落的西村口。村子很小，笼罩在一片寂静中。南边隐约可以
看到一条大江。
LONG
	);
	set("no_clean_up", 0);
	set("outdoors","nio");

	set("exits", ([
		"northwest": __DIR__"road2.c",
		"east": __DIR__"njroad1.c",
	]) );

	setup();
	replace_program(ROOM);
}

