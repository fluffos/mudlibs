// Room: /u/qingyun/jyzj/conglin1.c
// Written by qingyun
// Updated by jpei

inherit ROOM;

void create()
{
	set("short", "雪山丛林");
	set("long", @LONG
这是一个很大的丛林，树木的枝叶上挂满了冰雪，雪白的一大片，奇美无
比。丛林向山上延伸，直至山顶。在丛林中微露出一条小道，依稀可认，你走
在小道上，雪地中留下一行长长的足印。
LONG	);
	set("exits", ([
		"northup" : __DIR__"conglin2",
		"eastdown" : __DIR__"shanxi",
	]));
	set("outdoors", "kunlun");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
