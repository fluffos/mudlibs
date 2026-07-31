// Room: /d/zuojiacun/lu14.c

inherit ROOM;

void create()
{
	set("short", "土路");
	set("long", @LONG
这是一条坑坑洼洼小路，你一脚深一脚浅地走在上面，路过
的村民都赤着双脚，看到你走路的样子，嬉笑了起来。再向东不
远就出了村子。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"lu16",
  "west" : __DIR__"midian",
  "east" : __DIR__"lu15",
  "north" : __DIR__"lu13",
]));
	set("outdoors", "zuojiacun");
	setup();
	replace_program(ROOM);
}
