// Room: /d/heifeng/midao4.c

inherit ROOM;

void create()
{
	set("short", "密道");
	set("long", @LONG
这里是一处密道，地上干干净净，可见经常有人过往，密道
边上的石壁挂着水珠。
LONG
	);

	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"mishi2",
  "north" : __DIR__"midao3",
]));

	setup();
}
