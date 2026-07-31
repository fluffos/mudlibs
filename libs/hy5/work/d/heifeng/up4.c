// Room: /d/heifeng/up4.c

inherit __DIR__"up.c";

void create()
{
	set("short", "黑风岭");
	set("long", @LONG
这里是黑风山高耸的山岭顶端的一个小平台，平台周围长着
一些蒿草，不过听说有人在这里采(cai)到过灵芝。南面的草丛里
有一条陡直的小路通向下面。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"up5",
  "south" : __DIR__"ling1",
  "north" : __DIR__"up7",
]));

	set("outdoors","heifeng");

	setup();
}
