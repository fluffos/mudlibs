// Room: /d/zuojiacun/lu10.c

inherit ROOM;

void create()
{
	set("short", "土路");
	set("long", @LONG
这是一条坑坑洼洼小路，你一脚深一脚浅地走在上面，路过
的村民都赤着双脚，看到你走路的样子，嬉笑地对你指指点点，
你视如不见加快了脚步。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"lu8",
  "east" : __DIR__"lu11",
  "south" : __DIR__"hu",
]));
	set("outdoors", "zuojiacun");
	setup();
	replace_program(ROOM);
}
