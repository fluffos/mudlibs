// Room: /d/linzhi/lin36.c

inherit ROOM;

void create()
{
	set("short", "高原侧道");
	set("long", @LONG
这里是高原侧道，四下荒无一人。你走在路上，不时地注意
着周围的变化。一阵风吹来，你不禁觉得有些凉。由此再向东去
是一座桥。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"lin35",
  "northwest" : __DIR__"lin37",
  "south" : __DIR__"lin39",
]));
        set("outdoors", "linzhi");
        set("cannot_build_home", 1);
        set("altitude", 3600);
	setup();
	replace_program(ROOM);
}
