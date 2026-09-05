// File		: datinge.c
// Created By	: iszt@pkuxkx, 2006-08-16

inherit ROOM;

void create()
{
	set("short", "侧廊");
	set("long", @LONG
你走在一条走廊上，走廊两边堆着积雪。西边就是凌霄大殿，东边通着一条
石板路。巡逻的凌霄弟子从你身边经过，向你投来警惕然而友善的微笑。
LONG);
	
	set("outdoors", "凌霄城");
	set("exits", ([
		"west" : __DIR__"dating",
		"east" : __DIR__"stonee1",
	]));
	set("objects", ([
		__DIR__"npc/dizi" : 1,
	]));

	setup();
	replace_program(ROOM);
}