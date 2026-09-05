// File		: stonen2.c
// Created By	: iszt@pkuxkx, 2006-09-05

inherit ROOM;

void create()
{
	set("short", "石板路");
	set("long", @LONG
一条平整宽阔的石板路，路边就是积雪，稀稀疏疏的长着几根草茎。南边是
武器库，北边是齐自勉的居所。
LONG);

	set("outdoors", "凌霄城");
	set("exits", ([
		"west" : __DIR__"stonew4",
		"east" : __DIR__"stonen3",
		"north" : __DIR__"qiroom",
		"south" : __DIR__"weaponroom",
	]));
	set("objects", ([
		__DIR__"npc/dizi" : 1,
	]));

	setup();
	replace_program(ROOM);
}
