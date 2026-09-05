// Room: /hangzhou/nandajie2.c
// hubo 2008/4/19 

// Zine 2013 to 临安
inherit "/d/hangzhou/song_room";
#include <ansi.h>
#include "/d/song/xunshi.h"
void create()
{
	set("short", HIY"福宁宫"NOR);
	set("long", @LONG
这里是福宁宫，皇帝的寝宫，戒备异常森严。
LONG
	);
        set("outdoors", "hangzhou");

	set("exits", ([
		"east" : __DIR__"shufang",
		"south" : __DIR__"chongzheng",
		"west" : __DIR__"huayuan",
		"north" : __DIR__"yudaoh1",
		"enter" : __DIR__"funing2",
	]));
	set("objects", ([
		//__DIR__"npc/wujiang" : 1,
		"/d/hangzhou/npc/songbing_y" : 2,
		"/d/hangzhou/npc/songbing_y2" : 2,
		"/d/song/npc/dianqian_npc3" : 2,
        ])); 
	setup();
}

int valid_leave(object me,string dir)
{
	if (dir=="enter"&&!me->query_temp("songtasks/see_emperor")&&!me->query_temp("chaoting/see_emperor"))
	return notify_fail("天子寝宫，非召见不得擅入。\n");
	return ::valid_leave(me,dir);
}