// Room: /d/zuojiacun/zahuo.c

inherit ROOM;

void create()
{
	set("short", "杂货店");
	set("long", @LONG
这是一家小杂货店，由于靠近海边，因此店里除了一般的东
西还卖一些出海用的药什么的。店主人是一个老头，在村里很有
人缘。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"lu4",
]));
  	set("objects",([
	"/d/cloud/npc/seller" : 1,
]));
	setup();
	replace_program(ROOM);
}
