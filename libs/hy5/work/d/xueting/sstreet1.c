// Room: /d/xueting/sstreet1.c

inherit ROOM;

void create()
{
	set("short", "雪亭街道");
	set("long", @LONG
这里是雪亭镇南边连接镇外的街道，西边有一间货栈，东边则
是一家杂货铺，街道往北通往广场南边，往南穿过一个草棚出镇外。
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
//  "west"  : __DIR__"store",
  "north" : __DIR__"guangchang_s",
  "south" : __DIR__"sgate",
  "east"  : __DIR__"temple",
]));
	set("no_clean_up", 0);
	set("outdoors", "xueting");

	setup();
	replace_program(ROOM);
}
