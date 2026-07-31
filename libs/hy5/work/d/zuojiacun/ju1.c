// Room: /d/zuojiacun/ju1.c

inherit ROOM;

void create()
{
	set("short", "民居");
	set("long", @LONG
这是一间普普通通的住宅，没有太多的陈设。屋的左边是一
个大灶，灶里的火还在烧着，旁边坚着一堆干柴。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"lu2",
]));
	set("objects",([
	"/clone/npc/man" : 2,
]));


	setup();
	replace_program(ROOM);
}
