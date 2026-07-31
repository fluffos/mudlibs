// Room: /u/wsl/changan/ca5.c
// This is a room made by wsl.

inherit ROOM;

void create()
{
	set("short", "客房");
	set("long", @LONG
这是一间陈设简陋的客房,四周有几张床，中间摆着一张台，台
上放了一个茶壶和几个杯子。
LONG
);
	set("sleep_room", "1");
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"ca3",
]));
	set("no_magic", "1");

	setup();
	replace_program(ROOM);
}
