// Room: /d/yandang/luoyan27.c

inherit ROOM;

void create()
{
	set("short", "天一阁");
	set("long", @LONG
天一阁是庄主的独生爱女碧涟的住处,由于她从小体弱多病,而又性
喜清净,所以老庄主特意给她在此建了这栋小楼,庄中弟子无事不准来此,
你现在所处的是客厅,只摆了几张椅子,挂了一幅条幅.
LONG
	);
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/tanger.c" : 1,
]));
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 3 */
  "up" : __DIR__"luoyan28",
  "west" : __DIR__"luoyan29",
  "south" : __DIR__"luoyan26",
]));

	setup();
	replace_program(ROOM);
}
