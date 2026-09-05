// Room: /d/baituo/liangong.c 
 
inherit ROOM; 
 
void create() 
{ 
	set("short", "练功场");
	set("long", @LONG
这里是白驼山弟子的练功场。东边是一个练功房。北边是个门廊，
西边连着一条长廊，雕梁画柱，非常气派。南面可见巍巍大厅。
LONG
	);
	set("no_clean_up", 0);
	set("outdoors", "baituo");
//	set("objects", ([ /* sizeof() == 1 */
//  __DIR__"npc/li" : 1,
//]));
	set("exits", ([ 
  "northeast" : __DIR__"chufang",
  "south" : __DIR__"dating",
  "west" : __DIR__"changlang",
  "north" : __DIR__"menlang",
  "east" : __DIR__"fang",
]));

	setup();
	replace_program(ROOM);
}
