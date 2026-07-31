// Room: /city/beidajie1.c
#include <room.h>
inherit ROOM;
void create()
{

	set("short", "异次元");
	set("long", @LONG
这是异次元，周围有很多时空裂缝，一不小心就会掉下去！
LONG
	);
	set("exits", ([
		//"east"  : "/d/fuben/longzu/longzu",
		"south" : "/d/zhenhun/enter",
		"north"  : "/d/sishenfuben/jinrufuben",
		"west"  : "/d/fuben/qianchipu/qianchipu",
		//"out"  : "/d/gaoli/baodian",
		
	]));

	setup();
}



