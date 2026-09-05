// File		: stonen3.c
// Created By	: iszt@pkuxkx, 2006-09-05

inherit ROOM;

void create()
{
	set("short", "石板路");
	set("long", @LONG
一条平整宽阔的石板路，路边就是积雪，稀稀疏疏的长着几根草茎。北边是
一个校门，南边通向练武场。
LONG);

	set("outdoors", "凌霄城");
	set("exits", ([
		"east" : __DIR__"stonen4",
		"west" : __DIR__"stonen2",
		"north" : __DIR__"xiaomen",
		"south" : __DIR__"lianwuchang",
	]));
	set("objects", ([
		__DIR__"npc/dizi" : 1,
                __DIR__"npc/huyanwanshan" : 1,
	]));

	setup();
	replace_program(ROOM);
}
