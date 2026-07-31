// Room: /d/yandang/luoyan41.c

inherit ROOM;

void create()
{
	set("short", "初级室");
	set("long", @LONG
初级室是庄中弟子初炼武功的地方,此处的陪炼弟子武功是比较低
的,而对于初学者就够了.
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"luoyan40",
]));
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/peilian1.c" : 3,
]));

	setup();
	replace_program(ROOM);
}
