// Room: /d/sandboy/intree.c

inherit ROOM;

void create()
{
	set("short", "大榕树上");
	set("long", @LONG
在繁茂的枝叶中,你能看到远处连绵的稻田,近处的一草一木,头顶传来
雀鸟的鸣叫,在青青枝叶中飘洒下来.
LONG
	);
	set("no_clean_up", 0);
	set("outdoors", "/d/jiangnan");
	set("exits", ([ /* sizeof() == 1 */
  "down" : __DIR__"undertree",
]));

	setup();
	replace_program(ROOM);
}
