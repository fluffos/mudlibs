// Room: /u/wsl/changan/ca4.c
// This is a room made by wsl.

inherit ROOM;

void create()
{
	set("short", "客房");
	set("long", @LONG
这里住着一个书生，因赶考多年未能高中，一直住在这，准备下
下次再进京科考。
LONG
);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"ca3",
]));

	setup();
	replace_program(ROOM);
}
