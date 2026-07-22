// Room: /u/mei/room27.c// This is a room made by roommaker. write by Fan. :)
inherit ROOM;
void create()
{
	set("short", "盆地");
	set("long", @LONG
这地方是个盆地，四周高山拱卫，以致风雨不侵，千百年之物仍能如此完
好，实是罕见罕闻，沿路只见遍地白骨，刀枪剑戟，到处乱丢。城中道路也是
曲折如迷宫，令人眼花缭乱。
LONG
	);
	set("no_new_clean_up", 0);
	set("outdoors", "room27");
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"room26",
  "north" : __DIR__"room29",
]));

	setup();
	replace_program(ROOM);
}
