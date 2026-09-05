// File		: xuewu.c
// Created By	: iszt@pkuxkx, 2006-09-05

inherit ROOM;

void create()
{
	set("short", "雪屋");
	set("long", @LONG
雪地中一间屋子，摇摇晃晃，快要被积雪压塌了。看来这里荒废已久，并没
有人居住。
LONG);

	set("indoors", "凌霄城");
	set("exits", ([
		"southwest" : __DIR__"xuedi3",
	]));

	setup();
	replace_program(ROOM);
}