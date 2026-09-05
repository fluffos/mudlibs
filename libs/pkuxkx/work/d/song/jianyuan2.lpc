// Room: /hangzhou/nandajie2.c
// hubo 2008/4/19 

// Zine 2013 to 临安
inherit "/d/song/song_extra_room";
#include <ansi.h>
void create()
{
	set("short", "谏院大厅");
	set("long", @LONG
这里是谏院衙门的官厅。
LONG
	);
        set("outdoors", "hangzhou");

	set("exits", ([
		//"westdown" : __DIR__"taimiao",
		"west" : __DIR__"jianyuanb",
		//"south" : __DIR__"heningxi",
		"east" : __DIR__"jianyuana",//吏部
		"out" : __DIR__"jianyuan",//礼部
	]));

	setup();
	"/clone/board/dasong_jianyuan_b"->foo();
}