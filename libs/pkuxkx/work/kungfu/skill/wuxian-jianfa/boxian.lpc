//boxian 五弦剑 － 拨弦
#include <ansi.h>

inherit F_SSERVER;

int valid_target_arg(string target)
{
    if (target == "version") return 2;
    return target == "null" || target == "other";
}

int perform(object me, object target)
{
     string msg;
	int damage,count,number,rate,r_fix=0;
	int damage_p;
	object weapon,*enemy;
	int busytime;

        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("「拨弦」只能对战斗中的对手使用。\n");

        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("id") != "gu qin" )
        if (!objectp(weapon = me->query_temp("secondary_weapon"))
        || (string)weapon->query("id") != "gu qin" )
	        return notify_fail("你没拿琴，弹什么？\n");
		if( (int)me->query_skill("riyue-shengong", 1) < 400 )
			return notify_fail("你的日月神功等级不够，无法使用「拨弦」。\n");
		if( (int)me->query_skill("daguangming-xinfa", 1) < 500 )
			return notify_fail("你的大光明心法等级不够，不能使用「拨弦」。\n");
		if (me->query_skill("kuihua-shengong"))
		{
			return notify_fail("死太监使不出来这种雅致的功夫。");
		}

        if( (int)me->query_skill("wuxian-jianfa", 1) < 300 )
                return notify_fail("你的五弦剑法不够娴熟，无法使用「拨弦」。\n");
        if( (int)me->query_skill("music",1) < 500 )
                return notify_fail("你的音律不够娴熟，无法使用「拨弦」。\n");
		
       if((int)me->query("neili") < 250)
              return notify_fail("你的内力不够,无法施展出「拨弦」!\n");
        msg = HIR "突然之间，$N在琴弦上连拨数声，乐音转急，琴音铮铮大响。\n";
		enemy = me->query_enemy();
		count = sizeof(enemy);
		if (count < 1)
		{
			return notify_fail("「拨弦」只能对战斗中的对手使用。\n");
		}
		if (count > 6 )
		{
			count = 6;
		}
		number = (int)(me->query_skill("wuxian-jianfa", 1)/300) + 1;
		//300级涨1个目标，最多6个，1500lv时候可以攻击6个
		if (count > number)
		{
			count = number;
		}
		damage_p = me->query_skill("wuxian-jianfa",1);
		damage_p += me->query_skill("music",1);
		damage_p *=2;
		damage_p +=me->query_skill("riyue-shengong",1)*4/3;
        me->start_busy(1);
		busytime = 0;
		if ( me->query("betrayer") || me->query("chushi/done"))
		{
			r_fix = 1;
		}
		for (number=0; number < count; number++)
		{
	       if((int)me->query("neili") < 250)
              return notify_fail("你的内力不够,无法施展出「拨弦」!\n");
			if (enemy[number] == target)
			{
				rate = 6+r_fix;
			}
			else
			{
				rate = 7+r_fix;
			}
			//命中B-~C-
			if ( F_KUNGFU->hit_rate(me->query("max_neili"), enemy[number]->query("max_neili"), rate, me, enemy[number]) )
			{
                msg += "琴音连响五下，$p不由自主的退了五步。接着又是一声大响，$p脸色雪白，显然是支持不住了。\n" NOR;
				damage = damage_p;
				damage += random(enemy[number]->query("neili")/20+500);
                F_KUNGFU->hit_wound("qi", damage, damage/2, me, enemy[number]);
                me->add("neili", -100-random(damage/10));			
			}
			else
			{
				busytime = random(4);
				msg += "可是$p如同没事人一般，一点反应也没有，丝毫不起感应。\n" NOR;
			}
        message_vision(msg, me, target);
        COMBAT_D->report_status(target);
		}
		if ( busytime > 0 ) me->start_busy(busytime);
	return 1;
}





