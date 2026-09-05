// File		: xiangfangeast.c
// Created By	: iszt@pkuxkx, 2007-01-22

inherit ROOM;

void create()
{
	set("short", "东厢房");
	set("long", @LONG
储藏室
一条平整宽阔的石板路，路边就是积雪，稀稀疏疏的长着几根草茎。东南方
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