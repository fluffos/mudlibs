// Room: /d/taiwan/huilang.c

inherit ROOM;

void create()
{
	set("short", "回廊");
	set("long", @LONG
从石拱桥上走过,你来到一条画廊,沿着池塘而建的这条画廊长长地通
向两边,微风拂过廊下的铜铃发出阵阵声响.远处一条野狗叼着什么东西跑
过,你仔细看看,吃了一惊,似乎是人的手臂.
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"chitang",
  "northwest" : __DIR__"dating",
  "northeast" : __DIR__"chufang",
]));
	set("outdoors", "/d/taiwan");

	setup();
	replace_program(ROOM);
}
