// Room: /d/heifeng/shinv.c

inherit ROOM;

void create()
{
	set("short", "使女房");
	set("long", @LONG
这是一间简陋的木板房，是服侍寨主的使女住的房间，墙边
是一张大床，门边放着笤帚、簸箕之类的工具。
LONG
	);

	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"corr07",
]));

	setup();
	replace_program(ROOM);
}
