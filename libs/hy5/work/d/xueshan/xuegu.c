// Room: xuegu.c

inherit ROOM;

void create()
{
	set("short", "雪谷");
	set("long", @LONG
这里是群山环绕中的一个山谷，人迹罕至。仰面向上看，四面山峰高耸入云，
覆盖着冰雪。周围茫茫雪原，甚至连野兽的足迹都看不到。
LONG
	);
	set("exits", ([
		"eastdown" : __DIR__"shanjiao",
	]));

	setup();

	replace_program(ROOM);
}
