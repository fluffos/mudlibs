// Room: /city/nandajie2.c
// YZC 1995/12/04 
// CLEANSWORD 1996/2/2

inherit ROOM;

void create()
{
	set("short", "南大街");
	set("long", @LONG
你走在一条繁华的街道上，向南北两头延伸。南边是南城门，北边通往中央
广场，东边是云台街，由于最近扬州商业繁荣，云台街上开了不少新的店铺，成
了扬州城数的着的繁华街道。
LONG);
        set("outdoors", "city");

	set("exits", ([
		"east": __DIR__"ytjie1",
		"south" : __DIR__"nanmen",
		"north" : __DIR__"nandajie2",
		"west": "/d/xinfang/bieshuqu",
	]));

	setup();
}