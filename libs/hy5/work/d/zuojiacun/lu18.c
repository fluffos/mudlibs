// Room: /d/zuojiacun/lu18.c

inherit ROOM;

void create()
{
	set("short", "土路");
	set("long", @LONG
这是一条坑坑洼洼小路，你一脚深一脚浅地走在上面，路过
的村民都赤着双脚，看到你走路的样子，嬉笑地对你指指点点，
你不觉感到脸上一阵发热。路北不时传来叮叮当当的声响。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"lu19",
  "west" : __DIR__"lu5",
  "east" : __DIR__"lu17",
  "north" : __DIR__"tie",
]));
	set("outdoors", "zuojiacun");

	set("objects",([
	__DIR__"npc/yu_fanzi" : 1,
	__DIR__"npc/yuwen" : 3,	
]));

	setup();
	replace_program(ROOM);
}
