// Room: /d/hainan/underhill.c

inherit ROOM;

void create()
{
	set("short", "琼崖下");
	set("long", @LONG
海鸟声声,从你的头顶掠过.一座悬崖绝壁横亘在面前.广秃的山壁寸
草不生.即使猿猴也无法攀登.山壁到了下面向内微凹,形成一个终年不见
阳光的背阴地带.
LONG
	);
	set("no_clean_up", 0);
	set("outdoors", "/d/hainan");
	set("item_desc", ([ /* sizeof() == 1 */
  "山壁" : "别看了,这种地方是不可能爬上去的.
",
]));
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"shatan",
  "south" : __DIR__"underhill2",
]));

	setup();
	replace_program(ROOM);
}
