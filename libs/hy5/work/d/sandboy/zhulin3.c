// Room: /d/sandboy/zhulin3.c

inherit ROOM;

void create()
{
	set("short", "竹林");
	set("long", @LONG
一片洋溢着清新的竹林，脚步踩在落叶上发出沙沙的声音，是有一两声
鸟鸣从林中回响出来，空气清新无比。
LONG
	);
	set("no_clean_up", 0);
	set("outdoors", "/d/jiangnan");
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"zhulin1",
  "west" : __DIR__"zhulin5",
]));

	setup();
	replace_program(ROOM);
}
