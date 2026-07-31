// Room: /d/lumaji/zahuo.c

inherit ROOM;

void create()
{
	set("short", "杂货店");
	set("long", @LONG
这是一家普普通通的小杂货店，除了一些日常用品什么也没
有。店主人徐三娘是村里出了名的好人，谁家有事她都会帮上一
把。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 3 */
  "east" : __DIR__"lu4",
]));

	set("objects",([
		__DIR__"npc/sanniang" : 1,
]));

	setup();
	replace_program(ROOM);
}