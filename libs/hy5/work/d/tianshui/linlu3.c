// Room: /u/xiaozhen/linlu3.c

inherit ROOM;

void create()
{
	set("short", "土坡");
	set("long", @LONG
你正走在一个不小的土坡上，往下看是一片小树林，地下满
是杂沓的脚印和马蹄印。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "southdown" : __DIR__"linlu2",
  "northup" : __DIR__"linlu4",
]));
	set("no_clean_up", 0);
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/tufei" : 2,
]));

	setup();
	replace_program(ROOM);
}
