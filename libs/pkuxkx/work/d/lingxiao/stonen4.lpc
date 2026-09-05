// File		: stonen3.c
// Created By	: iszt@pkuxkx, 2006-09-05

inherit ROOM;

void create()
{
	set("short", "石板路");
	set("long", @LONG
一条平整宽阔的石板路，路边就是积雪，稀稀疏疏的长着几根草茎。南边是
防具库，北边是成自学的居所。
LONG);

	set("outdoors", "凌霄城");
	set("exits", ([
		"west" : __DIR__"stonen3",
		"east" : __DIR__"stonee4",
		"north" : __DIR__"chengroom",
		"south" : __DIR__"armorroom",
	]));
	set("objects", ([
		__DIR__"npc/dizi" : 1,
	]));

	setup();
	replace_program(ROOM);
}
