// Room: /d/lumaji/nongju.c

inherit ROOM;

void create()
{
	set("short", "农居");
	set("long", @LONG
这是一间用砖彻成的民房，屋里除了一个土坑和一些农具什
么也没有。白天农户都在田里干活，因此没有人在家。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"lu5",
]));

	setup();
	replace_program(ROOM);
}
