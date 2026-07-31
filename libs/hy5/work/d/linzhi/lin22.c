// Room: /d/linzhi/lin22.c

inherit ROOM;

void create()
{
	set("short", "高原山道滑坡");
	set("long", @LONG
这里是高原山道滑坡，坡面陡峭，你费力地走在上面，不时
地停下来休息休息。前面的路还很长，你有些灰心了，不如现在
就回去吧。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "eastdown" : __DIR__"lin21",
  "northwest" : __DIR__"lin31",
  "south" : __DIR__"lin23",
]));
        set("outdoors", "linzhi");
        set("cannot_build_home", 1);
        set("altitude", 3600);
	setup();
	replace_program(ROOM);
}
