// Room: /d/suzhou/xuanmiao.c
// Date: May 31, 98  Java

inherit ROOM;

void create()
{
	set("short", "杂货铺");
	set("long", @LONG
你一走进杂货铺，老板就笑眯眯的跟你打招呼。这里卖一些杂七杂八的东西。
LONG );
	set("outdoors", "suzhou");
	set("no_clean_up", 0);
	set("exits", ([
		"north"  : __DIR__"xidajie2",
	]));
	set("objects",([
		__DIR__"npc/qu" : 1,
		]));
	setup();
	replace_program(ROOM);
}


