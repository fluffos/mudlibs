// Room: /hangzhou/nandajie2.c
// hubo 2008/4/19 

// Zine 2013 to 临安
inherit "/d/song/song_extra_room";
#include <ansi.h>
void create()
{
	set("short", "库部司衙门");
	set("long", @LONG
这里是库部司的衙门。
LONG
	);
    //set("outdoors", "hangzhou");
	set("yamen","bingbu");
	set("exits", ([
		"northwest" : __DIR__+query("yamen")+"court",
	
	]));
	setup();
}

void init()
{
    add_action("do_qingdian","qingdian");
}

int do_qingdian()
{
    object me=this_player();
    int n=1+random(5);
    if (me->query_temp("songtasks/bingbu/task")!=3)
	return notify_fail("谁让你来库部司的，军粮官没有放行的意思。\n");
	if (me->is_busy() || me->is_fighting())
	return notify_fail("你正忙着哪！\n");
	if (me->query_temp("songtasks/bingbu/liang_degree")>50)
    {
		me->set_temp("songtasks/bingbu/3/finish",1);
		tell_object(me,"军粮清点完毕，你可以回兵部尚书复命了。\n");
		return 1;
    }
    me->add_busy(3);
    message_vision("$N开始核算库中的军粮。\n",me);
    me->set_temp("songtasks/bingbu/liang_degree",(int)me->query_temp("songtasks/bingbu/liang_degree")+n);
    tell_object(me,HIG"军粮被一一造册存放。\n"NOR);
    return 1;
}
