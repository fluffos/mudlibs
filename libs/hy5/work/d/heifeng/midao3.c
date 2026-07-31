// Room: /d/heifeng/midao3.c

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
  "south" : __DIR__"midao4",
  "west" : __DIR__"midao2",
]));

	setup();
}
