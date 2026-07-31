// Room: /d/fengtian/xiaochi.c

inherit ROOM;

void create()
{
	set("short", "小吃店");
	set("long", @LONG
李林街上的这家小吃店很有名，因为这里的煎饼果子在盛京
您找不出第二份，实在是好吃的不得了，当然这是祖传的手艺。
LONG
	);

	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"ll3",
]));

	setup();
	replace_program(ROOM);
}
