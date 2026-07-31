// Room: /d/zuojiacun/lu4.c

inherit ROOM;

void create()
{
	set("short", "土路");
	set("long", @LONG
泥泞的小路上到处是水，你走在路上弄得两脚湿乎乎的。一
些赤脚的村妇不进经过你的身边，却并不在意地上的泥水。路的
北面是一家杂货店。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"lu3",
  "east" : __DIR__"lu5",
  "north" : __DIR__"zahuo",
]));
	set("outdoors", "zuojiacun");
	setup();
	replace_program(ROOM);
}
