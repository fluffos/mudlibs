// Room: /d/zuojiacun/hu.c

inherit ROOM;

void create()
{
	set("short", "老胡家");
	set("long", @LONG
老胡是个参客，虽然40多岁的人了，但身体仍十分硬朗。他
常年在长白山中采参，据说见过不少珍奇品种。你要是肯出钱，
也许能请他帮你采些上好人参。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"lu10",
]));

	setup();
	replace_program(ROOM);
}
