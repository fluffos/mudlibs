// Room: /d/jinghai/jhd14.c

inherit ROOM;

void create()
{
	set("short", "兵器房");
	set("long", @LONG
这里是靖海岛的兵器库，靠墙是一排宽大的兵器架，架子上
摆满了各式各样的兵器。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"jhd10",
]));
	set("objects", ([
	__DIR__"obj/changmao"       : 2,
	__DIR__"obj/blade"       : 2,
	__DIR__"obj/sword"       : 2,
]));

	setup();
	replace_program(ROOM);
}
