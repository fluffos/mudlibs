// Room: grass.c 草原
// created by Zine 30 Aug 2010
#include <ansi.h>
inherit ROOM;
#include "/d/menggu/entry_migong.h"
#include "/d/menggu/check_point.h"
string *souths=({__DIR__"d_menggubao1",__DIR__"d_menggubao6",});
void create()
{
	set("short", YEL+"废弃草场"+NOR);
	set("long", @LONG
这里是一座废弃的草场，牧民们被都南迁了。
LONG
	);

	set("exits", ([
		"south" : souths[random(sizeof(souths))],
		"north" : __DIR__"random_caoyuan2_s",
	]));
    set("entry_direction","north");
    set("migong","/d/menggu/caoyuan2");
    set("migong_posi","south");
    set("look_refuse_msg","中央大草原上刮起了大风，你什么都看不清了。\n");
    set("enter_refuse_msg","中央大草原上刮起了大风，这会儿进去太危险了。\n");
    set("objects", ([
        	__DIR__"npc/leader" : 1,
	    ]));
    set("outdoors", "menggu_m");
	setup();
}

void init()
{
    object me=this_player(),ob=this_object();
    if (me->query_temp("shediaoquest/jdfm/gogogo"))
    {
		check_point(me,ob);
		if (present("shifu zhang",this_object()))
		{
			tell_object(me,"这个十夫长守在这里呢，如果能想办法套出口令就好了。\n");
		}
	}
}