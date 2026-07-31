// Room: /u/jpei/thd/kezhan3.c

inherit ROOM;

void create()
{
	set("short", "东厢房");
	set("long", @LONG
一间普通的客房，只有一张床和一张残破的桌子。
LONG
	);
	set("sleep_room", 1);
	set("hotel", 1);
	set("no_clean_up", 0);
	set("no_fight", 1);

	set("exits", ([
		"west": __DIR__"kezhan2.c",
	]) );

	setup();
	replace_program(ROOM);
}
