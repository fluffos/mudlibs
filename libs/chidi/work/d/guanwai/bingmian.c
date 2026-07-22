// /guanwai/bingmian.c

inherit ROOM;

void create()
{
	set("short", "冰面");
	set("long", @LONG
这里是松花江的江面，现已冻成了几尺厚的坚冰。行人或马匹，车辆均
可横逾江面而绝无危险。冰面上留有厚厚的积雪，与两岸连成一片，只有中
间经常行走之出，露出一条青色的冰路。
LONG );
	set("exits", ([
		"east"  : __DIR__"damenkan",
		"west"  : __DIR__"chuanchang",
	]));
	set("no_clean_up", 0);
	set("outdoors", "guanwai");
	setup();
	replace_program(ROOM);
}
