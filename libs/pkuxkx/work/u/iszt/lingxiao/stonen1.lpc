// File		: stonen1.c
// Created By	: iszt@pkuxkx, 2006-09-05

inherit ROOM;

void create()
{
	set("short", "石板路");
	set("long", @LONG
一条平整宽阔的石板路，路边就是积雪，稀稀疏疏的长着几根草茎。东南方
LONG);

	set("outdoors", "凌霄城");
	set("exits", ([
		"east" : __DIR__"stonew4",
		"north" : __DIR__"xiuxishi",
		"south" : __DIR__"maofang",
	]));
	set("objects", ([
		__DIR__"npc/dizi_free" : 1,
	]));

	setup();
	replace_program(ROOM);
}