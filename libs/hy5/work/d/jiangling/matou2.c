//Edited by fandog, 02/15/2000

#include <ansi.h>
inherit ROOM;

void create()
{

	set("short", "武昌码头");
	set("long", @LONG
武昌也是武汉的一个重镇。渡船在这里停下，走在石板搭砌的江岸，
仍然能感觉到大江的奔流。略带腥味的江边气息随风飘来。南边可见江
中一柱擎天石壁。
LONG );

	set("exits", ([
		"south" : __DIR__"chibi",
		"north" : __DIR__"matou1",
	]));

	set("outdoors", "jiangling");
	set("no_clean_up", 0);
	set("coor/x", -1400);
	set("coor/y", -2200);
	set("coor/z", 0);


	setup();
}