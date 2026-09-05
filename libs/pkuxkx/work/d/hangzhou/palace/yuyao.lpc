// Room: /hangzhou/nandajie2.c
// hubo 2008/4/19 

// Zine 2013 to 临安
inherit "/d/hangzhou/song_room";
#include <ansi.h>
#include "/d/song/xunshi.h"
void create()
{
	set("short", YEL"御药房"NOR);
	set("long", @LONG
这里是大内的御药房，一个太医正在忙碌着。
LONG
	);
        //set("outdoors", "hangzhou");

	set("exits", ([
		//"east" : __DIR__"walla",
		"southeast" : __DIR__"yudao1",
		//"west" : __DIR__"wall1",
		//"north" : __DIR__"funing",
		//"enter" : __DIR__"kunning2",
	]));
	set("no_die",1);
	set("objects", ([
		//__DIR__"npc/wujiang" : 1,
		"/d/hangzhou/npc/taiyi" : 1,
		"/d/song/npc/yuyao" : 1,
		//"/d/hangzhou/npc/songbing_z" : 2,
        ])); 
	setup();
}

int die_notify(object victim)
{
	 victim->receive_damage("qi", 0, "服用大内剧毒丹丸而");  
}

int valid_leave(object me,string dir)
{
	if (time()-me->query_temp("songtasks/yuyao/try_drug")<12||present("dan wan",me))
	return notify_fail("你正在为御药房试药，不得擅自离开。\n");
	me->remove_listen_to_die(this_object());
	return ::valid_leave(me,dir);
}