// Room: /u/jpei/thd/njeast.c

inherit ROOM;

void create()
{
	set("short", "村口");
	set("long", @LONG
这是一座小村落的东村口。村子很小，笼罩在一片寂静中。南边隐约可以
看到一条大江。东北方是条通向海边的小路。
LONG
	);
	set("no_clean_up", 0);
	set("outdoors","nio");

	set("exits", ([
		"west": __DIR__"njroad3.c",
		"northeast": __DIR__"hbroad.c",
	]) );
	set("objects", ([
	"/d/baituo/npc/kid" : 1,
	]) );

	setup();
	replace_program(ROOM);
}

