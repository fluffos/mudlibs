// chuanxin.c 抽髓掌穿心诀
// By Zine Nov 6 2010 //配合10分钟才能要到一次的一种暗器，穿心钉，此pfm本身没有太大威力，配合穿心钉后限制使用pfm。

#include <ansi.h>

inherit F_SSERVER;


int cooldown(object me)
{
    me->delete_temp("chuanxin");
}
int perform(object me, object target)
{
	string msg;

	if( !target ) target = offensive_target(me);

	if( !target || !target->is_character() )
		return notify_fail("穿心诀只能对对手使用。\n");
	if( me->query_temp("chuanxin"))
		return notify_fail("你刚刚使用过穿心诀，消耗甚巨，暂时无法再次使用。\n");

	if( environment(me)->query("no_fight") )
		return notify_fail("这里不能攻击别人! \n");

	if( (int)target->query("combat_exp") < (int)me->query("combat_exp")/4 )
		return notify_fail("穿心诀星宿神技，杀鸡岂用牛刀？\n");

	if( (int)me->query_skill("huagong-dafa", 1) < 100 )
		return notify_fail("你的化功大法不够娴熟，施展不了穿心诀。\n");

	if( (int)me->query_skill("chousui-zhang", 1) < 100 )
		return notify_fail("你的抽髓掌不够娴熟，施展不了穿心诀。\n");

	msg = HIR "只听得$N默念心法，瞬时，$N的掌心变成血红色，一掌拍向$n胸前七处大穴。\n";

	me->start_busy(1);
	if( random( (int)me->query_skill("chousui-zhang",1))
          > random(target->query_skill("dodge") ) ) 
    {
		msg += CYN " 结果$p促不及防，被$P双掌印了个正着！\n" NOR;
            target->receive_damage("qi",random(me->query_skill("chousui-zhang",1)), me);
            target->receive_wound("qi",random(me->query_skill("chousui-zhang",1))+random(me->query_skill("poison",1)), me);
            
		message_combatd(msg, me, target);
		COMBAT_D->report_status(target);

	}
    if (me->query_skill("chousui-zhang",1)>400 && target->query_condition("chuanxin") && random( (int)me->query_skill("chousui-zhang",1))
          > random(target->query_skill("dodge")*2/3))
    {
        target->apply_condition("chuanxin",0);
        target->apply_condition("pfmnotallow",me->query_skill("chousui-zhang",1)/20);
        tell_object(me,HIW"放胆进攻吧，被你的穿心诀打入体内，他已经无法施展特殊攻击。\n"NOR);
        target->set_temp("pfmnotallow",1);
        tell_object(target,HIC"你惊喜地发现体内穿心钉的创伤竟不药而愈了！\n"NOR);
    }
    else {
		msg += "可是$p急提内力奋力一震，将$N的手震了开去。\n" NOR;
		me->start_busy(random(3));
		message_combatd(msg, me, target);
	}
	
}
