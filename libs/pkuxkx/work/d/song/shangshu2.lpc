// Room: /hangzhou/nandajie2.c
// hubo 2008/4/19 

// Zine 2013 to 临安
inherit "/d/song/song_extra_room";
#include <ansi.h>
#include "baoxiao.h"
void create()
{
	set("short", "政事堂");
	set("long", @LONG
这里是政事堂，几间值房分别是几位宰执处理公务的处所。
LONG
	);
       // set("outdoors", "hangzhou");

	set("exits", ([
		//"westdown" : __DIR__"taimiao",
		"south" : __DIR__"shangshucourt",
		"north" : __DIR__"shangshu_path1",
		//"west" : __DIR__"streetn3",//吏部
		//"east" : __DIR__"libu2",//礼部
	]));
	set("yamen_id","政事堂");
	"/clone/board/dasong_b"->foo();
	setup();
}