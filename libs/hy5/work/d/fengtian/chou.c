// Room: /d/fengtian/chou.c

inherit ROOM;

void create()
{
	set("short", "绸缎庄");
	set("long", @LONG
这间绸缎庄算得上盛京最大的一家了，老板由江南采购一些
好的丝缎，在盛京可以赚不少钱。
LONG
	);

	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"wy4",
]));

	setup();
	replace_program(ROOM);
}
