// File		: bingeast5.c
// Created By	: iszt@pkuxkx, 2006-09-04

inherit ROOM;

void create()
{
	set("short", "石板路");
	set("long", @LONG
这里是一片青石铺就的平整的广场，雕饰极尽简单，却整齐有序。再往东北
是一条石板路，通向内城。
LONG);
	
	set("outdoors", "凌霄城");
	set("exits", ([
		"west" : __DIR__"bingjie5",
		"northeast" : __DIR__"stonee1",
	]));
	set("objects", ([
		__DIR__"npc/dizi" : 1,
	]));

	setup();
	replace_program(ROOM);
}