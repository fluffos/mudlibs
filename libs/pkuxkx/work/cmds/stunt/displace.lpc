// displace.c
// zine@pkuxkx 2014/7/11
#include <ansi.h>
#include <skill.h>
#define interval 15
#define vein "足太阴脾经"
#define STUNT "displace"
inherit F_CLEAN_UP;
mapping default_dirs = ([
        "north":        "北",
        "south":        "南",
        "east":         "东",
        "west":         "西",
        "northup":      "北边",
        "southup":      "南边",
        "eastup":       "东边",
        "westup":       "西边",
        "northdown":    "北边",
        "southdown":    "南边",
        "eastdown":     "东边",
        "westdown":     "西边",
        "northeast":    "东北",
        "northwest":    "西北",
        "southeast":    "东南",
        "southwest":    "西南",
        "up":           "上",
        "down":         "下",
		"enter":        "里",
        "out":          "外",
]);

int main(object me, string arg)
{
	int busy=0;
	object env;
	string dir;
	if ((!me->query("StuntList")||!arrayp(me->query("StuntList"))||member_array(STUNT,me->query("StuntList"))==-1)
	&&!me->query("myVeins/"+vein+"/completed"))
	return notify_fail("你还没有掌握"+STUNT+"绝技。\n");
	if (!env=environment(me))
	return notify_fail("都在这里了，还是老老实实待着吧。\n");
	if (!me->is_busy())
	return notify_fail("你要走就走过去好了，还要用什么绝技？\n");
	if (!me->is_fighting())
	return notify_fail("你没在战斗啊，要走就走过去好了，还要用什么绝技？\n");
	if (time()<me->query_temp("stunt/"+STUNT+"/time"))
	return notify_fail("你刚刚使用过"+STUNT+"绝技，等等再用吧。\n");
	dir=keys(env->query("exits"))[random(sizeof(env->query("exits")))];
	message_vision(HIW+"$N"+HIW+"运转内息至"+vein+"，奋起身形冲向"+default_dirs[dir]+"。\n"+NOR,me);
	if (!me->query_temp("stunt/"+STUNT+"/time")&&me->query("myVeins/"+vein+"/completed"))
	{
		me->add_temp("apply/dodge",5);
		write(HIC"你运转内息在"+vein+"之间，提升自己的躲闪效率。\n"NOR);
	}
	if (me->query("myVeins/"+vein+"/completed")==1)
	busy=2;
	if ((me->query("StuntList")&&arrayp(me->query("StuntList"))&&member_array(STUNT,me->query("StuntList"))!=-1)
	||me->query("myVeins/"+vein+"/completed")==2)
	busy=5;
	if (me->query("myVeins/"+vein+"/completed")==3)
	busy=10;
	if (F_VEIN->query(vein+"/fastest/player")==me->query("id"))
	busy=30;
	if (me->query_busy()>busy||!env->valid_leave(me,dir))
	write("很可惜，你没有能成功冲过去。\n");
	else if (!me->move(env->query("exits")[dir]))
	write("很可惜，你没有能成功冲过去。\n");
	me->set_temp("stunt/"+STUNT+"/time",time()+interval);
	return 1;
}

int help(object me)
{
	tell_object(me,@HELP
指令格式 : displace 

拥有绝技displace或足太阴脾经通脉后可使用。
效果：如果自己在busy(时间短)且战斗中可以
逃跑至邻近房间。
足太阴脾经通脉后，可小幅提升自身闪躲。
HELP
        );
	return 1;
}
