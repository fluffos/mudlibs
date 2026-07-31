// Room: /d/sandboy/zhulin2.c

inherit ROOM;

void create()
{
	set("short", "竹林");
	set("long", @LONG
一片静悄悄的竹林，林子深处传出的鸟鸣在林中久久不绝，竹叶上
的清露在你走过时点点地滴下来，远处露出红墙一角。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"zhulin4",
  "south" : __DIR__"zhulin5",
  "east" : __DIR__"zhulin1",
]));
set("outdoors","/d/jiangnan");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
