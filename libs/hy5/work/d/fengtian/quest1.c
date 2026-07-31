// Room: /d/fengtian/quest1.c

inherit ROOM;

void create()
{
	set("short", "后院");
	set("long", @LONG
这是一个破落的小院子，地上长满了蒿草，草堆里零星有几
个石桌石椅散落，西面坍塌的院墙上有一个缺口。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
	"out" : __DIR__"fangjia",
	"west" : __DIR__"quest2",
]));

	setup();
	replace_program(ROOM);
}
