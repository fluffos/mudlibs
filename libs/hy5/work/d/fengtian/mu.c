// Room: /d/fengtian/mu.c

inherit ROOM;

void create()
{
	set("short", "木器店");
	set("long", @LONG
李林街的木器店是一家新开张的小店，可以做一些简单的木
制家具，还有一些木制的武器。
LONG
	);

	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"ll2",
]));

	setup();
	replace_program(ROOM);
}
