// Room: /u/wyz/kunlun/klsj.c
// This is a room made by roommaker. write by Fan. :)

inherit ROOM;

void create()
{
	set("short", "昆仑山脚");
	set("long", @LONG
这是一间什麽也没有的空房间。
LONG
);
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"sbxd",
]));
	set("昆仑山脚", "short");

	setup();
	replace_program(ROOM);
}
