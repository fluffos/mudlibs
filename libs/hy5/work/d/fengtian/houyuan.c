// Room: /d/fengtian/houyuan.c

inherit ROOM;

void create()
{
	set("short", "后院");
	set("long", @LONG
这是一个破落的小院子，地上长满了蒿草，草堆里零星有几
个石桌石椅散落，院墙有些地方也已经坍塌。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"fangjia",
]));

	setup();
	replace_program(ROOM);
}
