// Room: /d/fengtian/lf3.c

inherit ROOM;

void create()
{
	set("short", "空着的房间");
	set("long", @LONG
这是一间什麽也没有的空着的房间。主人好像不想用这个房间。

LONG
	);

	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"lf2",
]));

	setup();
	replace_program(ROOM);
}
