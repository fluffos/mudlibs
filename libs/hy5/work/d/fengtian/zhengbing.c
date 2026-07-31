// Room: /d/fengtian/zhengbing.c

inherit ROOM;

void create()
{
	set("short", "征兵处");
	set("long", @LONG
由于盛京是朝廷的门户，所以朝廷在这里设了征兵处，而且
盛京的百姓也很尚武，所以这里征兵也不是很难，你如果在这里
报名，您就是军队的一员了！
LONG
	);

	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"wy1",
]));

	setup();
	replace_program(ROOM);
}
