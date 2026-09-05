// Room: /hangzhou/nandajie2.c
// hubo 2008/4/19 

// Zine 2013 to 临安
inherit "/d/hangzhou/song_room";
#include <ansi.h>
#include "/d/song/xunshi.h"
void create()
{
	set("short", HIC"坤宁宫"NOR);
	set("long", @LONG
这里是坤宁宫，太后的寝宫。
LONG
	);
        set("outdoors", "hangzhou");

	set("exits", ([
		//"east" : __DIR__"walla",
		"south" : __DIR__"yudaoh1",
		//"west" : __DIR__"wall1",
		"north" : __DIR__"yudaoh2",
		"enter" : __DIR__"kunning2",
	]));
	set("objects", ([
		//__DIR__"npc/wujiang" : 1,
		"/d/hangzhou/npc/songbing_y" : 2,
		//"/d/hangzhou/npc/songbing_y" : 2,
		//"/d/hangzhou/npc/songbing_z" : 2,
        ])); 
	setup();
}

int valid_leave(object me,string dir)
{
	if (dir=="enter")
	return notify_fail("太后的寝宫，也敢乱闯？\n");
	return ::valid_leave(me,dir);
}