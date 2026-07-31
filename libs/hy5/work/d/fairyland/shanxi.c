// Room: /u/qingyun/jyzj/shanxi.c
// Written by qingyun
// Updated by jpei

inherit ROOM;

void create()
{
	set("short", "山溪边");
	set("long", @LONG
这里是一条小溪。昆仑山终年积雪，在烈日照射下，部分冰雪融化成水，
而汇成小溪，溪水向下而流，不知其流向何方。往西而上是一个大丛林。
LONG	);
	set("exits", ([
		"westup" : __DIR__"conglin1",
		"eastup" : __DIR__"hongmeizhuang",
	]));
	set("outdoors", "kunlun");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
