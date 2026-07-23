// throw.c 玄天冰蚕掌施毒
// By Yzuo 97.04

#include <ansi.h>

inherit F_SSERVER;
int perform(object me, object target)
{
	object obj,weapon;
	string msg;

	if( !target ) target = offensive_target(me);

	if( environment(me)->query("no_fight") )
		return notify_fail("这里不能攻击别人! \n");

	if( !target || !target->is_character() )
		return notify_fail("施毒只能对对手使用。\n");

	if( (int)me->query_skill("huagong-dafa", 1) < 40 )
		return notify_fail("你的化功大法不够娴熟，不能施毒。\n");

        
	if( (int)me->query_skill("xuantian-strike", 1) < 40 )
		return notify_fail("你的玄天冰蚕掌不够娴熟，不能施毒。\n");

    if( environment(me)->query("no_fight") && userp(target))
        return notify_fail("这里不准战斗。\n");

     if( target->query("env/no_fight") && userp(target) )
        return notify_fail("不能打，打不得啊！\n");
     if( target->query_temp("no_kill") && userp(target) )
        return notify_fail("不能打，打不得啊！\n");
    if( !target->is_character() || target->is_corpse() )
        return notify_fail("看清楚一点，那并不是活物。\n");
    if(target==me)
        return notify_fail("用 suicide 指令会比较快:P。\n");
    if(me->is_busy())
        return notify_fail("你现在正忙，没法杀人。\n");
if( !living(target) && userp(target) && target->query("combat_exp")/2 > me->query("combat_exp") )
	return notify_fail("你想要杀此人，但他比你强太多，你不敢动手。\n");

//pk
    if( userp(target) && me->query_condition("killer"))
        return notify_fail("你已经被通辑了，不要再乱杀玩家了！\n");
    if( userp(target) && target->query("combat_exp") < me->query("combat_exp") && me->query_condition("killer"))
        return notify_fail("你已经被通辑了，不要再乱杀玩家了！\n");


//免战系统
        if (userp(me) && userp(target)
         && target->query_temp("nokill") )
        return notify_fail("那人启用了免战牌！\n");

        if (userp(me) && userp(target)
         && me->query_temp("nokill") )
        return notify_fail("你启用了免战牌！\n");

    if( userp(me) && userp(target) && target->query_condition("nokill")
    && !target->query_condition("killer"))
        return notify_fail("那个人刚被杀过，放过他吧！\n");
if( !living(target) && userp(target) && target->query("combat_exp")/2 > me->query("combat_exp") )
	return notify_fail("你想要杀此人，但他比你强太多，你不敢动手。\n");      
	
	if ( !(objectp(obj=present("corpse", environment(me))) 
        || objectp(obj=present("corpse", me))
        || objectp(obj=present("Skeleton", environment(me)))
        || objectp(obj=present("Skeleton", me)) ) )
		return notify_fail("你周围没有尸体。\n");

	msg = CYN "$N顺手抓起尸体，将毒质运于其上，掷向$n。\n";

	me->start_busy(1);
	if( random( (int)me->query_skill("xuantian-strike",1))
          > random(target->query_skill("dodge") ) ) {
		msg += CYN " 结果$p被$P攻了个正着！\n" NOR;
            target->receive_damage("qi",(int)me->query_skill("xuantian-strike",1)*2);
            target->receive_wound("qi",55 + random(10));
            target->receive_wound("jing", 50);
	 target->apply_condition("x2_sandu",20);
	 target->apply_condition("sanpoison",20);
target->apply_condition("corpse_poison",60);
target->apply_condition("fire_poison",60);
            target->apply_condition("xx_poison", random(me->query_skill("xuantian-strike",1)/10) + 10 +
			target->query_condition("xx_poison"));
			target->start_busy(1 + random(2));
	message_combatd(msg, me, target);
	COMBAT_D->report_status(target);

	} else {
		msg += "可是$p急忙闪在一旁，躲了开去。\n" NOR;
		me->start_busy(4);
		message_combatd(msg, me, target);
	}
me->kill_ob(target);
//	if( !target->is_killing(me) ) target->kill_ob(me);
		destruct(obj);
	return 1;
}
