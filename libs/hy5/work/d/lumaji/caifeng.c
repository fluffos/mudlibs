// Room: /d/lumaji/caifeng.c

inherit ROOM;

void create()
{
	set("short", "裁缝铺");
	set("long", @LONG
这是村里的裁缝铺，由于村里的妇女很穷，一般的缝缝补补
也都自已做了，所以这里生意不算太好。只有过年过节的，才有
人来找李裁缝做身新衣服。不过村里人都公认李裁缝的手艺是不
错的。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"lu14",
]));

	set("objects",([
	__DIR__"npc/caifeng_boss" : 1,
]));

	setup();
	replace_program(ROOM);
}
