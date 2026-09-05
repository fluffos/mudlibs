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
这里是吏部的一处庭院，整治的春意盎然。
LONG
	);
        set("outdoors", "hangzhou");
	set("yamen","libu");
	set("exits", ([
		"northeast" : __DIR__+query("yamen")+"si1",
		"southeast" : __DIR__+query("yamen")+"si2",
		"east" : __DIR__+query("yamen")+"si3",
		"out" : __DIR__+query("yamen"),//吏部
		"northwest" : __DIR__+query("yamen")+"shu2",
		"west" : __DIR__+query("yamen")+"shu1",
	]));
	
	set("yamen_id","吏部");
	setup();
}