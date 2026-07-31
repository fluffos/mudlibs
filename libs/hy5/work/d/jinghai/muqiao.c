// Room: /d/jinghai/muqiao.c

inherit ROOM;

void create()
{
	set("short", "小木桥上");
	set("long", @LONG
这是小木桥上。

LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "southwest" : __DIR__"xiaoxi",
  "northeast" : __DIR__"lukou",
]));
        set("outdoors","jinghai");

	setup();
	replace_program(ROOM);
}
