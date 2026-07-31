// Room: /d/xueting/sgate.c

inherit ROOM;

void create()
{
	set("short", "草棚");
	set("long", @LONG
这里是雪亭镇南边的唯一入口，往北穿过草棚通往雪亭镇的街
道，出草棚往镇外就是卧龙岗了，那里的强盗很是厉害。但是那里
是通往倚云镇唯一的道路。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "southwest" : "/d/cloud/nroad",
  "north" : __DIR__"sstreet1",
  //"east" : "/d/snow/eroad1",
]));
	set("no_clean_up", 0);
	set("outdoors", "xueting");

	setup();
	replace_program(ROOM);
}
