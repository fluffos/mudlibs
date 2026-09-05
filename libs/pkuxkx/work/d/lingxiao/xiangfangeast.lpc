// File		: xiangfangeast.c
// Created By	: iszt@pkuxkx, 2007-01-22

inherit ROOM;

void create()
{
	set("short", "东厢房");
	set("long", @LONG
这里是令小城正厅旁的一个厢房，是供给远来的客人所居住的。厢房中央摆着几张大
床，几张桌子。室中光线柔和，使人更增睡意。
LONG);

	set("outdoors", "凌霄城");
	set("exits", ([
		"west" : __DIR__"tingyuan",
	]));
	set("objects", ([
		__DIR__"npc/dizi" : 1,
	]));

	setup();
	replace_program(ROOM);
}
