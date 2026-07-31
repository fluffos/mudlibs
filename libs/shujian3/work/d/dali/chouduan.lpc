// Modify By River 98/12/
inherit ROOM;
#include <ansi.h>
void create()
{
        set("short",HIC"绸缎庄"NOR);
        set("long", @LONG
一进门。老板就热情的迎上来了，这家铺面很大，这儿所卖的绸缎大多都
是从中原购来的，另外也卖一些当地产布匹。
LONG
);
	set("exits", ([
		"east" : __DIR__"xijie3",
	]));

	set("objects", ([
		__DIR__"npc/dasao": 1,
		__DIR__"npc/nvdianzhu": 1,
	]));
	set("incity", 1);
	setup(); 
}

void init()
{
	object me = this_player();
	if(me->query_temp("xuncheng"))
		me->set_temp("dali_xc/chouduan",1);
}
