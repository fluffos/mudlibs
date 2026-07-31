// Room: /d/yandang/luoyan42.c

inherit ROOM;

void create()
{
	set("short", "入门室");
	set("long", @LONG
入门室是庄中弟子武功稍有长进时炼功切措的地方,陪练弟子的等
级也相对高一些.
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"luoyan40",
]));
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/peilian2.c" : 3,
]));

	setup();
	replace_program(ROOM);
}
