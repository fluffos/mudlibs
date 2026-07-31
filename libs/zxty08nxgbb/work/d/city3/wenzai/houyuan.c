// Room: /d/city3/wenzai/houyuan.c
// This is a room made by roommaker. write by zhm/silversand.

inherit ROOM;

void create()
{
	set("short", "后院");
	set("long", @LONG
这里是个大大的后院，古树参天，知了在树上不停地叫着，有个
仆人在那里清扫着地面。
LONG
);
	set("outdoors", "city3");
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/atu" : 1,
]));
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"wuchang",
  "north" : __DIR__"zoulang4",
]));

	setup();
	replace_program(ROOM);
}
