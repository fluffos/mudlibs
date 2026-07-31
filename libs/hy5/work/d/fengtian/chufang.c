// Room: /d/fengtian/chufang.c

inherit ROOM;

void create()
{
	set("short", "厨房");
	set("long", @LONG
厨房好象大家都知道，这个厨房和您见过的厨房区别不大，
不过就是大了点，厨司多那么几个，你看厨司长老刘又在那里发
脾气呢？
LONG
	);

	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"lang1",
]));

	setup();
	replace_program(ROOM);
}
