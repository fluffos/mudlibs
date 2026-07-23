// luanhuan.c 太极拳「乱环诀」
// xQin 1/99

#include <ansi.h>
inherit F_SSERVER;

int perform(object me, object target)
{
        string *circle, msg;

        if( !target ) target = offensive_target(me);

        if( !target || !target->is_character() || !me->is_fighting(target) )
                return notify_fail("「乱环诀」只能对战斗中的对手使用。\n");

	if( !living(target) )
		return notify_fail("你现在不必使用「乱环诀」。\n");

        if( (int)me->query("jiali") )
                return notify_fail("用意不用力，太极圆转无使断绝。你加了力难以划圈成圆。\n");

	if( me->query("combat_exp") < 500000 )
		return notify_fail("你实战经验不足，不会使用「乱环诀」。\n");

        if( (int)me->query_skill("juehu-shou", 1) < 150 )
                return notify_fail("你的绝户手不够娴熟，使不出「乱环诀」。\n");
                                
        if( (int)me->query_skill("taiji-shengong", 1) < 150 )
                return notify_fail("你的本门内功修为不够，无法运功伤敌。\n");

        if( (int)me->query("max_neili", 1) < 2000 )
                return notify_fail("你的内力修为不够，无法运功伤敌。\n");

        if( (int)me->query("neili", 1) < 200 )
                return notify_fail("你现在的内力太弱，无法运功伤敌。\n");

        if( (int)me->query("jing", 1) < 100 )
                return notify_fail("你现在的精神太差，难以划圆成圈。\n");

        if( me->query_skill_mapped("force") != "taiji-shengong")
                return notify_fail("你所用的内功与「乱环诀」气路相悖！\n");

	circle = ({
		"$N「双风贯耳」，连消带打，双手成圆形击出，随即左圈右圈，一个圆圈跟着一个圆圈，大圈、小圈、平圈、立圈、正圈、斜圈，一个个太极圆圈发出。",
		"$N「云手」使出时连绵不断，有如白云行空，一个圆圈未完，第二个圆圈已生。",
		"$N右肩斜闪，左手凭空划了几个圈子。",
	});

	msg = WHT"\n"+ circle[random(sizeof(circle))] +"\n";
        me->add("jing", -50);
//      me->add("jing", -50);

        if( random(me->query("combat_exp") * me->query_int() / 100) 
		> (int)target->query("combat_exp") * target->query_int() / 200 )
	{
		msg += HIY"结果$N以环形之力，推得$n进了$P的无形圈内。\n"NOR;
		me->start_busy(1);
		call_out("zhen", 1, me, target); 
	}
	else
	{
		msg += CYN"可是$p看破了$P的企图，并没有上当。\n"NOR;
		me->start_busy(1+random(2));
	}

	message_vision(msg, me, target);

	return 1;
}

int zhen(object me, object target)
{
	int damage;
	string *zhen, msg, result, str, type;

//	if (!me->is_fighting(target) || !living(target)) return;

	zhen = ({
		"但见$N双臂一圈一转，使出「六合劲」中的“钻翻”“螺旋”二劲，已将$n圈住。",
		"$N接着使出一招「云手」，左手高，右手低，一个圆圈已将$n套住。",
	});

	if ( random(me->query_skill("juehu-shou", 1)) > 199 )
	{
		type = "瘀伤";
		msg = HIY"\n只见$N左掌阳、右掌阴，目光凝视左手手臂，双掌慢慢合拢，竟是凝重如山，却又轻灵似羽。右捺左收，使得犹如行云流水，潇洒无比！\n"NOR
		"$n只觉上盘各路已全处在$P双掌的笼罩之下，无可闪避，无可抵御！\n";
	}
	else
	{
		type = "内伤";
		msg = "\n"+ zhen[random(sizeof(zhen))] +"随即潜运神功，企图以内力震伤$n！\n";
	}

	if (target->query("neili") <= 0)
	{
		msg += "$p只得强行运劲与$P相抗，不料猛然发觉自己真气已然枯竭耗尽。\n";
		if (type == "内伤")
			msg += RED"结果只听见几声喀喀轻响，$n一声惨叫，像滩软泥般塌了下去！！\n"NOR;
		else 
			msg += RED"结果只听见「砰」地一声巨响，$n像一捆稻草般飞了出去！！\n"NOR;

		target->receive_damage("qi", (int)target->query("qi")+1, me);
	}
	else if (random((me->query_skill("juehu-shou") + me->query_skill("force")) * me->query_int() / 100) >
		(target->query_skill("parry") + target->query_skill("dodge")) * target->query_int() / 200 )
	{
		me->start_busy(1+random(2));
		target->start_busy(2+random(1));
                

		damage = (int)me->query_skill("force") + 
			(int)me->query_skill("claw")/2;                
		damage = damage/2 + random(damage);

		if(type == "瘀伤")
			damage = damage+me->query_skill("juehu-shou")/2;
		if(me->query("neili") > target->query("neili")*2)
			damage = damage+me->query_skill("juehu-shou")/2; 

		target->receive_damage("qi", damage, me);
		target->receive_wound("qi", damage/3, me);
		target->add("neili", -(damage/4));

		me->add("neili", -damage/10);

		result = COMBAT_D->damage_msg(damage, type);
		result = replace_string( result, "$p", target->name() );
		msg += result;

		str = COMBAT_D->status_msg((int)target->query("qi") * 100 /(int)target->query("max_qi"));
		msg += "( $n"+str+" )\n";
	}
	else if (random(me->query_skill("force")) > target->query_skill("force")/2 )
        {
                me->start_busy(1);
                target->start_busy(random(3));
                
                damage = (int)me->query_skill("taiji-shengong", 1);
                damage = damage/2 + random(damage);
                
                target->receive_damage("qi", damage, me);
                target->receive_wound("qi", damage/3, me);
                me->add("neili", -damage/10);

		msg+= HIR"$p只得强行运劲与$N相抗，";
                if( damage < 20 ) 
			msg += "结果受到$P的内力反震，闷哼一声。\n"NOR;
                else if( damage < 40 ) 
			msg += "结果被$P以内力反震，「嘿」地一声退了两步。\n"NOR;
                else if( damage < 80 ) 
			msg += "结果被$P以内力一震，胸口有如受到一记重锤，连退了五六步！\n"NOR;
                else 
			msg += "结果被$P的内力一震，眼前一黑，身子向后飞出丈许！！\n"NOR;
        }
	else if(me->query("neili")*2 < target->query("neili")) 
	{
		me->start_busy(3);
		target->start_busy(1+random(2));
                
		damage = (int)target->query_skill("force")/2;
		damage = damage/2 + random(damage);
                
		me->receive_damage("qi", damage, me);
		me->receive_wound("qi", damage/3, me);
		target->add("neili", -damage/10);
                
                if( damage < 20 ) 
			msg += HIY"不料$P受到$p的内力反震，闷哼一声。\n"NOR;
                else if( damage < 40 ) 
			msg += HIY"不料$P被$p以内力反震，「嘿」地一声退了两步。\n"NOR;
                else if( damage < 80 ) 
			msg += RED"不料$P被$p以内力反震，胸口有如受到一记重锤，连退了五六步！\n"NOR;
                else 
			msg += HIR"不料$P被$p的内力反震，眼前一黑，身子向后飞出丈许！！\n"NOR;
	}
	else
	{
		me->start_busy(3);
		if (!target->is_busy())
		target->start_busy(3); 
		me->add("neili", -300);
		target->add("neili", -300);
		msg += HIY"$p只得强行运劲与$P相抗，两人身子都是一晃，各自退开几步！\n"NOR;
	} 

	message_vision(msg, me, target);
	return 1;
}


//紧跟着$N双臂一合，一招「双耳贯风」，双拳击向$p的左右两耳。这一招绵劲中蓄，其软如绵，其坚胜铁！
