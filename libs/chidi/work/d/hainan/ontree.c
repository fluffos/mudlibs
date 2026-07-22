// Room: /d/hainan/ontree.c

inherit ROOM;

void create()
{
	set("short", "小树上");
	set("long", @LONG
这棵小树显然不能够完全承担你的重量.它靠着山崖一边的小树根
已经在不断爆裂.泥石簌簌的掉下去,你的面前是一个小山洞.需要人弯
着腰才能进去.
LONG
	);
	set("objects", ([ /* sizeof() == 1 */
  "/d/wudang/npc/monkey.c" : 1,
]));
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "down" : __DIR__"underhill2",
  "enter" : __DIR__"cave",
]));
	set("outdoors", "/d/hainan");
	set("item_desc", ([ /* sizeof() == 1 */
  "小树" : "小树由于承受不了你的体重,快要断了,如果你
不想进去的话,还是赶快爬(climb)下去吧!
",
]));

	setup();
	replace_program(ROOM);
}
