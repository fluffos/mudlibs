// Room: /d/zuojiacun/lu5.c

inherit ROOM;

void create()
{
	set("short", "土路");
	set("long", @LONG
泥泞的小路上到处是水，你走在路上弄得两脚湿乎乎的。一
些赤脚的村妇不进经过你的身边，却并不在意地上的泥水。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"haichan",
  "west" : __DIR__"lu4",
  "east" : __DIR__"lu18",
  "north" : __DIR__"lu6",
]));
	set("outdoors", "zuojiacun");
	setup();
	replace_program(ROOM);
}
