// Room: /u/cuer/emei/xiaoxi2.c

inherit ROOM;

void create()
{
	set("short", "小溪");
set("outdoors","emei");
	set("long", @LONG
这是一条不起眼的山间小溪，夹在两座高山之间，小
溪上冒着热气，看来还是一个温泉，两边的植物也由于它
的原因而分外茂盛，空气中还夹杂着颇为刺鼻的硫磺的味
道，向着小溪的上游去，硫磺的味道越来越浓。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "southeast" : __DIR__"pubu",
  "north" : __DIR__"xiaoxi1",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
