// Room: /d/yandang/luoyan43.c

inherit ROOM;

void create()
{
	set("short", "进阶室");
	set("long", @LONG
进阶室是庄中弟子武功有长足进步的地方,如果你在这里还是不涨
经验的话,你可以下山了.
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"luoyan40",
]));
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/peilian3.c" : 3,
]));

	setup();
	replace_program(ROOM);
}
