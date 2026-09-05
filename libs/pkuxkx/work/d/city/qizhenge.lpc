// Room: /city/zahuopu.c
// YZC 1995/12/04 

inherit ROOM;

void create()
{
	set("short", "奇珍阁");
	set("long", @LONG
这是一家非常小的店铺，里面杂乱的放着许多稀奇古怪的东西。
LONG);

	set("exits", ([
		"north" : __DIR__"xidajie2",
	]));
	set("objects", ([
		__DIR__"npc/jiang": 1,
	]));

	setup();
	replace_program(ROOM);
}