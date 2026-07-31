// Room: /d/huayin/tl1.c

inherit ROOM;

void create()
{
	set("short", "土路");
	set("long", @LONG
这是一条乡间小土路，路上的泥土上压着的车辙，路边没脚
的蒿草随风摆动。东北方向隐约有袅袅的炊烟。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "northeast" : __DIR__"xiaolu1",
  "southwest" : __DIR__"tl2",
]));

	set("outdoors","huayin");
	setup();
	replace_program(ROOM);
}
