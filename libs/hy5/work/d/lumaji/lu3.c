// Room: /d/lumaji/lu3.c

inherit ROOM;

void create()
{
	set("short", "碎石小径");
	set("long", @LONG
这是一条碎石铺成的小路，石缝中长着一些杂草，时而有人
提着水桶从这里经过，看到你头也不抬就走开了。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"lu4",
  "east" : __DIR__"jing",
  "north" : __DIR__"lu2",
]));
	set("outdoors", "lumaji");
	setup();
	replace_program(ROOM);
}
