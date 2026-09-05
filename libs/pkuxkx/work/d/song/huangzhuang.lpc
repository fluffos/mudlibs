// Room: /hangzhou/nandajie2.c
// hubo 2008/4/19 

// Zine 2013 to 临安
inherit "/d/song/song_extra_room";
#include <ansi.h>
void create()
{
	set("short", "军屯");
	set("long", @LONG
这里是临安府治下的一处军屯，你可以来指挥屯田(tun)。
LONG
	);
        set("outdoors", "hangzhou");

	set("exits", ([
		//"westdown" : __DIR__"taimiao",
		"west" : "/d/hangzhou/nanmen",
		
	]));
	
	set("at_hangzhou",1);
	setup();
}

void init()
{
    add_action("do_tun","tun");
}

int do_tun()
{
    object me=this_player();
	string *desc=({"抢种作物","挑水施肥","清除虫害","收割庄稼"});
	if (me->query_temp("songtasks/gongbu/task")!=1)
	return notify_fail("这里可是皇庄，闲杂人等切勿接近。\n");
	if (me->is_busy())
	return notify_fail("你正忙着呢。\n");

    message_vision("$N指挥起大量民伕在田间"+desc[random(sizeof(desc))]+"。\n",me);
    me->add_temp("songtasks/gongbu/tuntian",1+random(5));
    me->add_busy(2);
	if (me->query_temp("songtasks/gongbu/tuntian")>30)
	{
		me->set_temp("songtasks/gongbu/1/finish",1);
		me->delete_temp("songtasks/gongbu/tuntian");
		tell_object(me,"屯田的任务顺利完成了，你可以回去复命了。\n");
	}
    return 1;
}

int valid_leave(object me,string dir)
{
	if (me->query_temp("songtasks/gongbu/task")==1)
	{
		me->delete_temp("songtasks/gongbu/task");
	}
	return ::valid_leave(me,dir);
}