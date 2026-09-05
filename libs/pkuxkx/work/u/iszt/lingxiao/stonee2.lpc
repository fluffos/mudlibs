// File		: stonee2.c
// Created By	: iszt@pkuxkx, 2006-09-04

inherit ROOM;

void create()
{
	set("short", "石板路");
	set("long", @LONG
一条平整宽阔的石板路，路边稀稀疏疏的长着几根草茎。西边通向一个练武
场，有数十名弟子专心致志的练习师授武功。
LONG);

	set("outdoors", "凌霄城");
	set("exits", ([
		"south" : __DIR__"stonee1",
		"north" : __DIR__"stonee3",
		"west" : __DIR__"stones3",
	]));
	set("objects", ([
		__DIR__"npc/dizi" : 1,
	]));

	setup();
	replace_program(ROOM);
}