// Room: /d/paiyun/lin1.c

inherit ROOM;

void create()
{
	set("short", "树林");
	set("long", @LONG
一片密林，树叶遮住了阳光，阴暗的树林里似乎有一股隐含
的东西，你觉得背上一阵冷风不由的加快了脚步。
LONG
	);

	set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"kongdi",
  "east" : __DIR__"lu3",
  "northwest" : __DIR__"lin3",
  "southeast" : __DIR__"dayuan",
]));
	set("outdoors", "paiyun");
	setup();
	replace_program(ROOM);
}
