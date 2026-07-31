// Room: /d/sandboy/zhulin1.c

inherit ROOM;

void create()
{
	set("short", "竹林");
	set("long", @LONG
一片青翠的竹林，淡淡的轻烟的林中氤氲飞散，清婉的鸟鸣在林子深
处响起，浓密的竹叶把人印得满身皆碧。
LONG
	);
	set("no_clean_up", 0);
	set("outdoors", "/d/jiangnan");
	set("exits", ([ /* sizeof() == 3 */
  "east" : __DIR__"zhulin",
  "west" : __DIR__"zhulin2",
  "south" : __DIR__"zhulin3",
]));

	setup();
	replace_program(ROOM);
}
