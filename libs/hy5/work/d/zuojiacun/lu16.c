// Room: /d/zuojiacun/lu16.c

inherit ROOM;

void create()
{
	set("short", "土路");
	set("long", @LONG
这是一条坑坑洼洼小路，你一脚深一脚浅地走在上面，路过
的村民都赤着双脚，看到你走路的样子，嬉笑地对你指指点点。
路的东面是本村的木匠店。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"lu17",
  "east" : __DIR__"mujiang",
  "north" : __DIR__"lu14",
]));
	set("outdoors", "zuojiacun");
	setup();
	replace_program(ROOM);
}
