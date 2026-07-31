// Room: /d/heifeng/ling1.c

inherit __DIR__"up.c";

void create()
{
	set("short", "黑风岭");
	set("long", @long
这里是黑风山高耸的山岭顶端的一个小平台，平台周围长着
一些蒿草，不过听说有人在这里采(cai)到过灵芝。南面的草丛里
有一条陡直的小路通向下面。
long
	);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"up2",
  "north" : __DIR__"up4",
]));

	set("outdoors","heifeng");

	setup();
}
