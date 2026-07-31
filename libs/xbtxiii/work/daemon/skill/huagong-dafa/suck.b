//suck.c 只能吸取可以练到的2/3。
#include <ansi.h>
inherit F_SSERVER;
int exert(object me, object target)
{
	int sp, dp,i;
	int my_max, tg_max;
	string msg;
if ( target == me ) target = offensive_target(me);

if( !objectp(target) )
	return notify_fail("你要吸取谁的内力？\n");

        my_max = me->query("max_force");
        tg_max = target->query("max_force");

if ( me->query_temp("sucked") )
	return notify_fail("你刚刚吸取过内力！\n");
if( objectp(me->query_temp("weapon")) )
	return notify_fail("你必须空手才能施用化功大法吸人内力！\n");
if( (int)me->query_skill("huagong-dafa",1) < 20 )
	return notify_fail("你的化功大法功力不够，不能吸取对方的内力！\n");
if( (int)me->query("force") < 20 )
	return notify_fail("你的内力不够，不能使用化功大法。\n");
if( (int)target->query("max_force") <= 250 )
	return notify_fail( target->name() +
		"内力涣散，功力未聚，你无法从他体内吸取任何东西！\n");
//        if( (int)me->query("max_force") >=
//          ((int)me->query_skill("force", 1) + me->query_skill("force")/5) * 7 ) 
//        return notify_fail("你的内功心法已经不能控制你的内力了，再吸下去你会走火入魔的\n");
	msg=HIR "$N全身骨节爆响，双臂暴长数尺，掌缘猛地向$n的天灵拍了下去！\n" NOR,
	message_vision(msg,me,target);
        sp = me->query_skill("force") + me->query_skill("dodge") + me->query_skill("zhaixinggong",1)/2;
        dp = target->query_skill("force") + target->query_skill("dodge");
 //       target->start_busy(6);
if ( living(target) )
{
        if( !target->is_killing(me) ) 
            target->kill_ob(me); 
        }
  	    me->set_temp("sucked", 1);		
//        if (( random(sp) > dp ) || target->query_temp("disable_command") )
// 	    {
	    tell_object(target, HIR "你只觉天顶骨裂，全身功力贯脑而出，如融雪般消失得无影无踪！\n" NOR);
	    tell_object(me, HIG "你觉得" + target->name() + "的内力自手掌源源不绝地流了进来。\n" NOR);
	    i=random(30);
            target->add("max_force",-i);
            me->add("max_force",i);
          if ( target->query("max_force") <1) target->set("max_force",0);
          if( (int)me->query("potential") - (int)me->query("learned_points") < 500 )
  	    me->add("potential",  2);
            me->add("combat_exp", 5);
            me->start_busy(5);
            target->start_busy(random(6));
//            target->start_busy(random(3));
            me->add("force", -10);
            call_out("del_sucked", 10, me);
//	    }
/*
	else
	    {	
	    msg=HIY "可是$p看破了$P的企图，机灵地溜了开去。\n" NOR;
	    message_vision(msg,me,target);
            me->start_busy(6);
            call_out("del_sucked", 15, me);
	    }
*/
	return 1;
}

void del_sucked(object me)
{
	if (me&&me->query_temp("sucked") )
	me->delete_temp("sucked");
}

