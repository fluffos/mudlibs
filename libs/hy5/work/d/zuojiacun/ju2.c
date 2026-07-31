// Room: /d/zuojiacun/ju2.c

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
  "west" : __DIR__"lu13",
]));

	setup();
	replace_program(ROOM);
}
