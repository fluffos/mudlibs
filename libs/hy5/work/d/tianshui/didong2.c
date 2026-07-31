// Room: /u/xiaozhen/didong2.c

inherit ROOM;

void create()
{
	set("short", "µØ¶´");
	set("long", @LONG
ºÚÆáÆáµÄµØ¶´
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"didong1",
]));
	set("no_clean_up", 0);
	set("objects",([
	__DIR__"npc/youfang_seng" : 1,
]));
	setup();
	replace_program(ROOM);
}
