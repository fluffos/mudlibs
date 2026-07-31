// Room: /d/shaolin/bagua.c
// Date: YZC 96/01/19
// Date: CLEANSWORD 96/05/19

inherit ROOM;

void create()
{
	set("short", "草地");
	set("long", @LONG
这是一片开阔的草地，周围竹林环绕。草地中央有一株奇异的花草，
上面好象结了一颗果实。
LONG
	);

	set("exits", ([
		"out" : __DIR__"xiaodao2",
	]));

	set("objects",([
		"/clone/drug/renshen_guo" : 1,
		]));
        
	

	setup();
	replace_program(ROOM);
}


