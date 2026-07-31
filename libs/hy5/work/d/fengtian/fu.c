// Room: /d/fengtian/fu.c

inherit ROOM;

void create()
{
	set("short", "富宅");
	set("long", @LONG
这是一位富豪的宅院，祥马街上住着不少这样的富豪，不过
这些人也就是有一些身家在祥马街上置个宅院，都并非富可敌国
的巨富。
LONG
	);

	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"xm3",
]));

	setup();
	replace_program(ROOM);
}
