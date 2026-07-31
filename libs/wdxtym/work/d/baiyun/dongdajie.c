// Room: /d/fuzhou/dongdajie.c
// may. 12 1998 Java

inherit ROOM;

void create()
{
	set("short", "东大街");
	set("long", @LONG
你走在东大街上，踩着坚实的青石板地面。东边是东城门。
LONG );
	set("exits", ([
	
		"east"    : __DIR__"dongxiaojie",
		"west"    : __DIR__"weizhongwei",
	]));

	set("objects", ([
		//"/clone/npc/walker" : 1,
	]));

	set("outdoors", "by");
	setup();
}

