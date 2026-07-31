// Room: /d/fengtian/midian.c

inherit ROOM;

void create()
{
	set("short", "米店");
	set("long", @LONG
这里是一家米店，门口挂着牌子上面写着：童叟无欺，米店
的老板是个老实人，逢年过节的经常给穷人布施一些食物。
LONG
	);

	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"kd2",
]));

	setup();
	replace_program(ROOM);
}
