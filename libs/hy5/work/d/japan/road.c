// Room: /d/japan/road.c

inherit ROOM;

void create()
{
	set("short", "大道");
	set("long", @LONG
一条宽阔的大道,时不时有骑马的,坐轿的,小贩,行人经过.不过这儿
的人穿的衣服都十分奇特,你以前从没见过.
LONG
	);
	set("no_clean_up", 0);
	set("outdoors", "japan");
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"haigang",
  "northeast" : __DIR__"road2",
]));

	setup();
	replace_program(ROOM);
}
