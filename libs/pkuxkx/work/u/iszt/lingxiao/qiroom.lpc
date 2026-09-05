// File		: qiroom.c
// Created By	: iszt@pkuxkx, 2007-02-16

inherit ROOM;

void create()
{
	set("short", "齐自勉居所");
	set("long", @LONG
这是齐自勉的居所。墙上挂着李白的《将进酒》，是齐自勉亲手所书，字迹
豪放奔放，走的是张旭狂草的路子，从这依稀也能看出主人武功的性情。照壁上
一幅《雪月夜行图》，是他当年一夜奔波八百里，灭掉太行三十寨的传奇往事。
桌上燃着一束檀香，散发出恬静的气息。一张焦尾琴摆在桌上，主人常在此自斟
自饮，乐得逍遥。
LONG);

	set("indoors", "凌霄城");
	set("exits", ([
		"south" : __DIR__"stonen2",
	]));

	setup();
	replace_program(ROOM);
}