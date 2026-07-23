// zhong.c 移花接木

#include <ansi.h>

inherit F_SSERVER;
int perform(object me, object target)
{
        object obj, victim;
        int damage, lvl, r_lvl, count, form, skill, i;
        string msg;

	if( !target ) target = offensive_target(me);

	if( !target || !target->is_character() || !me->is_fighting(target) )
	return notify_fail("移花接木只能对战斗中的对手使用。\n");

	if( environment(me)->query("no_fight") )
		return notify_fail("这里不准打架。\n");

	if( !target || !target->is_character() )
		return notify_fail("移花接木只能在对手身上使用。\n");

	if( (int)me->query_skill("douzhuan-xingyi",1)<80)
	return notify_fail("你的星移斗转不够娴熟，不会使用「移花接木」。\n");

	if( (int)me->query_skill("yanling-shenfa",1)<80)
	return notify_fail("你的燕灵身法不够敏捷，不能使用「移花接木」。\n");

	if( (int)me->query_skill("shenyuan-gong",1)<100)
	return notify_fail("你的本门内功不够，不能使用「移花接木」。\n");

	msg = HIC "$N把$n全身的劲力,顺着气位打回了$n自身。\n";

	me->start_busy(2);
        skill = (int)me->query_skill("douzhuan-xingyi", 1);
	lvl = skill/20;
	r_lvl = random(lvl);
	if( r_lvl < 1) r_lvl = 1;
	count = me->query_str();
        victim =target;
        if (random((int)me->query("combat_exp")) > (int)target->query("combat_exp")/3 )
        {
                target->start_busy(random(3));
                
                damage = skill/2 + r_lvl*target->query("jiali",1);
                
                target->receive_damage("qi", damage);
                target->receive_wound("qi", damage/2);
                me->add("neili", -damage);
		msg += HIG"将$n的内力全数反击回去！\n" NOR;
                
                if( damage < 20 )
                        msg += HIR"结果$n受到$N的内力反震，闷哼一声。\n"NOR;
        	else if( damage < 40 )
                        msg += HIC"结果$n被$N以内力反震，「嘿」地一声退了两步。\n"NOR;
        	else if( damage < 80 )
                        msg += HIG"结果$n被$N以内力一震，胸口有如受到一记重锤，连退了五六步！\n"NOR;
                else
                        msg += HIY"结果$n被$N的内力一震，眼前一黑，象一捆稻草一样飞出去好几丈远！\n"NOR;
                
        }
        else 
        {
                msg += CYN"可是$n内力深厚，丝毫不为所动。\n"NOR;
		me->add("neili", -100);
        }
        message_vision(msg, me, target);

        if ( (random(me->query("neili",1)) > 2*target->query("neili",1)/3 ) && ( r_lvl > random(5) ) )
        {
                write( CYN"哈哈，成功了！\n"NOR);

		if( target == victim)
		{
		tell_object(target, HIC"你身不由己，自己成名的绝招全部击向自己！\n"NOR);
		message("vision", CYN"\n" + target->name() + "忽然如中魔一般，招招击向自己！\n\n"NOR, environment(me), target);
		for(i = 0; i < r_lvl; i++)
if (!target->query("hunmi"))
{
			COMBAT_D->do_attack(target, victim, target->query_temp("weapon") );
}
else 		message("vision", CYN"\n" + target->name() + "已经快不行了，打不动了！\n\n"NOR, environment(me), target);
		}

		else
		{
		tell_object(target, CYN"你身不由几，向" + victim->name() + "扑去！\n"NOR);
		message("vision", CYN"\n" + target->name() + "忽然向" + victim->name() +"扑去！\n\n"NOR, environment(me), ({target, victim}) );
		tell_object(victim, CYN"\n" + target->name() + "忽然向你扑来！\n\n"NOR);

if (!target->query("hunmi"))
{
		COMBAT_D->do_attack(target, victim, target->query_temp("weapon") );
}
else 		message("vision", CYN"\n" + target->name() + "已经快不行了，打不动了！\n\n"NOR, environment(me), target);
		if( random(me->query("combat_exp")) > (int)victim->query("combat_exp")/2 )		
		{
			if( !victim->is_killing(target) ) victim->fight_ob(target);
		}
		else
		{
		tell_object(victim, HIW"你一定神，原来是" + me->name() + "在捣鬼！\n"NOR);
		tell_object(target, HIW"还好，幸亏" + victim->name() + "经验老到，没有上当。\n"NOR);
		write( HIG "不好，被" + victim->name() + "发觉了！\n"NOR);
		if( !victim->is_killing(me) ) me->kill_ob(victim);
		}

                target->start_busy(random(3));
		me->add("neili", -300);
		}
	}
	else
	{
		write( HIM"可惜没成功。\n"NOR);
		tell_object(target, HIM"你强用心神，终于控制住自己。\n"NOR);
		me->add("neili", -100);
	}

        return 1;
	}
