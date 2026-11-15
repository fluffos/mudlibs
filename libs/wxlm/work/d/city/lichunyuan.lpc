// Room: /city/lichunyuan.c
// YZC 1995/12/04 

inherit ROOM;

void create()
{
	set("short", "观乐楼");
	set("long", @LONG
你一走进来，一眼就看到大厅的墙上挂着一把琵琶，真是个文雅的听曲之处。
LONG );
	set("objects", ([
		CLASS_D("gaibang") + "/kongkong" : 1,
		__DIR__"npc/wei" : 1,
		__DIR__"npc/mao18" : 1, 
	]));

	set("exits", ([
		"west"  : __DIR__"nandajie2",
		"up"    : __DIR__"lichunyuan2",
	]));

	setup();
}


