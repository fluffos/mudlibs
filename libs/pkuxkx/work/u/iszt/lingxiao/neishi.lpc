// File		: neishi.c
// Created By	: iszt@pkuxkx, 2007-01-22

inherit ROOM;

void create()
{
	set("short", "内室");
	set("long", @LONG
这里是白自在居住的内室。
LONG);

	set("indoors", "凌霄城");
	set("exits", ([
		"east" : __DIR__"huating",
	]));

	setup();
	replace_program(ROOM);
}