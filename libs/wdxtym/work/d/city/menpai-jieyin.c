// Room: /city/menpai-jieyin.c
// YZC 1995/12/04 

inherit ROOM;

void create()
{
	set("short", "门派办事处");
	set("long", @LONG
这是装修豪华的门派办事处，负责接引新入门弟子或门派弟子快速往返门派!!!
LONG );
	set("no_fight", 1);     
	set("no_sleep_room", 1);
	set("exits", ([		
		"west" : __DIR__"majiu",
	]));

	set("objects", ([
		__DIR__"npc/jieyin-shi" : 1,
	]));
	setup();
}

