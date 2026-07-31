// Room: /d/paiyun/lin3.c

inherit ROOM;

void create()
{
	set("short", "树林");
	set("long", @LONG
一片密林，树叶遮住了阳光，阴暗的树林里似乎有一股隐含
的东西，你觉得背上一阵冷风不由的加快了脚步。
LONG
	);

	set("exits", ([ /* sizeof() == 1 */
  "southeast" : __DIR__"lin1",
]));
	set("outdoors", "paiyun");
	setup();
	replace_program(ROOM);
}
