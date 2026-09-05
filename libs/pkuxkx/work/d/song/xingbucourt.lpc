// Room: /hangzhou/nandajie2.c
// hubo 2008/4/19 

// Zine 2013 to 临安
inherit "/d/song/song_extra_room";
#include <ansi.h>
#include "baoxiao.h"
void create()
{
	set("short", HIG+"庭院"+NOR);
	set("long", @LONG
这里是刑部的一处庭院，整治的春意盎然。
LONG
	);
        set("outdoors", "hangzhou");
	set("yamen","xingbu");
	set("exits", ([
		"northeast" : __DIR__+query("yamen")+"si1",
		"east" : __DIR__+query("yamen")+"si2",
		"southeast" : __DIR__+query("yamen")+"si3",
		"out" : __DIR__+query("yamen"),//吏部
		"southwest" : __DIR__+query("yamen")+"shu2",
		"west" : __DIR__+query("yamen")+"shu1",
		"north":__DIR__+"xing_ku",
	]));
	
	set("yamen_id","刑部");
	setup();
}