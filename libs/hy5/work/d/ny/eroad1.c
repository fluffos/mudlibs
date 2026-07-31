
// Room: /d/snow/eroad1.c


inherit ROOM;

void create()
{
	set("coor",({1100,4600,10}));
	set("short", "黄土小径");
	set("long",
"这是一条普通的黄土小径，弯弯曲曲往东北一路盘旋上山，不远处有一间城隍庙，西北方向\n"
"不远则是宁远城的街道。\n"
);
	set("exits", ([ /* sizeof() == 3 */
  "northeast" : __DIR__"eroad2",
//  "north" : "/d/snow/temple",
  "northwest" : __DIR__"road12",
]));
	set("outdoors", "ny");

	setup();
//        replace_program(ROOM);
}
