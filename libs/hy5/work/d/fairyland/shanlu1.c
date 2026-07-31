// Room: /u/qingyun/jyzj/shanlu1.c
// Written by qingyun
// Updated by jpei

inherit ROOM;

void create()
{
	set("short", "山路");
	set("long", @LONG
这是一条昆仑山上到处可见的山路。只是这里已随处可见梅树，梅花盛开
时到处一片火红，花香飘溢。
LONG	);
	set("exits", ([
		"west" : __DIR__"shanlu2",
		"east" : "/d/kunlun/klshanlu",
		"south" : __DIR__"xuedi1",
	]));
	set("outdoors", "kunlun");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
