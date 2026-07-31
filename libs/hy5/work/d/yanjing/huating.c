// Room: /d/yanjing/huating.c

inherit ROOM;

void create()
{
	set("short", "花厅");
	set("long", @LONG
厅中早就摆上了一桌酒席,只见乌檀木的大圆桌旁候了几个人,正是赵
王请来的武林高手.几盆高大的盆栽沿厅摆放,碧绿的叶片几乎高达花厅的
吊顶.另有几盆花草颜色怪异,看来非中土所有.
LONG
	);
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/lingzhi.c" : 1,
]));
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"huilang2",
]));

	setup();
	replace_program(ROOM);
}
