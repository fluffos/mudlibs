//shuyi_poison.c
#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;

int clear_conditions(object ob);

int update_condition(object me, int dur)
{
	int sklvl = 0;
	if( dur<=1 || me->query("family/family_name")=="火云洞" )
        	return clear_conditions(me);
	if( !me->query_temp("shuyi_posion") )
        {
        	sklvl = me->query_skill("force")/10*3;
        	sklvl = sklvl > 100 ? -100 : -sklvl;
        	me->add_temp("apply/force",sklvl);
        	me->add_temp("apply/dodge",sklvl);
        	me->add_temp("apply/parry",sklvl);
        	me->add_temp("apply/unarmed",sklvl);
        	me->set_temp("shuyi_posion",-sklvl);
        	tell_object(me,HIR"你感觉自己正在渐渐虚弱下去！\n"NOR);
        }
	else    
	{
        	message_vision(HIR"$N"HIR"觉得胸中烦恶，手脚竟似不听使唤了．．．\n"NOR, me);
        	me->start_busy(1+random(2));
        	me->apply_condition("shuyi",dur-1);
        }
	return CND_CONTINUE;
}

int clear_conditions(object ob)
{
	int sklvl = ob->query_temp("shuyi_posion");
	if( !sklvl )
        	return 0;
	ob->delete_temp("shuyi_posion");
	ob->add_temp("apply/force",sklvl);
	ob->add_temp("apply/dodge",sklvl);
	ob->add_temp("apply/parry",sklvl);
	ob->add_temp("apply/unarmed",sklvl);
	message_vision(HIR"$N"HIR"打了个喷嚏，感觉舒服了很多！\n"NOR,ob);
	return 0;
}


