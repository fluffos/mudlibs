// Room: /d/yandang/shanxia.c

inherit ROOM;

void create()
{
	set("short", "山路");
	set("long", @LONG
路面开始崎岖不平,抬头看,高大的雁荡诸峰就在头上,好象要倒下
来一般,再过去就要爬山了,看着前面起伏的山峰,你情不自禁的摇了摇
头,问自己,能不能过去呢?
LONG
	);
	set("no_clean_up", 0);
	set("outdoors", "/d/yandang");
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"jiudian",
  "westup" : __DIR__"shanlu",
]));

	setup();
	replace_program(ROOM);
}
