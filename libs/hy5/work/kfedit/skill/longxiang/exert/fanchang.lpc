// fanchang.c
// by secret
// 97-1-16
//

#include <ansi.h>

inherit F_SSERVER;
int exert(object me)
{
	int sp, dp;
object target; 
	if ( target == me )
		target = offensive_target(me);
        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
 return notify_fail(RED"你要对谁使用?\n"NOR);
	if( environment(me)->query("no_fight") )
		return notify_fail("这里不能攻击别人! \n");

	if( !objectp(target) || target->query("id") == "mu ren" )
		return notify_fail("你要攻击谁？\n");

	if( (int)me->query_skill("longxiang",1) < 50 )
		return notify_fail("你的龙象般若功功力不够，不能凝神攻击对方！\n");

	if( (int)me->query("neili",1) < 50 )
		return notify_fail("你的内力不够，不能使用龙象般若功。\n");
//pk
    if(target==me)
        return notify_fail("用 suicide 指令会比较快:P。\n");
if(userp(target) && target->query("combat_exp")/2 > me->query("combat_exp") )
	return notify_fail("你想要杀此人，但他比你强太多，你不敢动手。\n");
    if( userp(target) && me->query_condition("killer"))
        return notify_fail("你已经被通辑了，不要再乱杀玩家了！\n");
    if( userp(target) && target->query("combat_exp") < me->query("combat_exp") && me->query_condition("killer"))
        return notify_fail("你已经被通辑了，不要再乱杀玩家了！\n");
//
	message_combatd(HIW "$N面无表情，歌声如梵唱般贯入$n耳中！\n\n" NOR, me, target );

	if( living(target))
{
			me->kill_ob(target);
                        target->fight_ob(target);
}
	sp = me->query_skill("force") + me->query_skill("mizongxinfa") + me->query_skill("longxiang",1)/2;
	dp = target->query_skill("force");
	
	if (( random(sp) > random(dp) ) || !living(target) )
	{
		tell_object(target, HIW " 你忽然觉得脑中一片空白，不由自主地随歌声舞蹈起来！\n" NOR);
		tell_object(me, HIB "你看到" + target->name() + "随着你的歌声手舞足蹈，十分可笑。\n" NOR);

		target->receive_damage("jing", 10 + random((int)me->query_skill("longxiang", 1)));
				
		if( target->query("combat_exp") >= me->query("combat_exp") )
			if( (int)me->query("potential") - (int)me->query("learned_points") < 100 )
				me->add("potential", 1);

		me->start_busy(2);
		target->start_busy(random(3)+2);
		me->add("neili", -50);

	}
	else
	{	
		message_combatd(HIY "可是$p不为$P歌声所动，定力果然不同凡响！\n" NOR, me, target);
		me->start_busy(4);
	}

	return 1;
}
