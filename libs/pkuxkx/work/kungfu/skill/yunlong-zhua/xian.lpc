// 凝血神抓 云龙三现

#include <ansi.h>
#include <combat.h>
#define Menpai "天地会"
inherit F_SSERVER;

int perform(object me, object target)
{
        int dur, times, damage, force;
        string msg;
		int hit_rate, i, count;
		object tar, *enemy;

        if(!me->is_fighting() )
                return notify_fail("「云龙三现」只能在战斗中使用。\n");
				
		if (me->query_temp("weapon"))
				return notify_fail("施展「云龙三现」必须空手。\n");
			
        if( (int)me->query_skill("yunlong-zhua", 1) < 100 )
                return notify_fail("你的「云龙三现」还未练成，不能使用！\n");

        if( (int)me->query("neili", 1) < 500 )
                return notify_fail("你现在内力不足，不能使用「云龙三现」！\n");

        if((int)me->query_skill("cangming-gong", 1) < 100 )
                return notify_fail("你的浩气苍冥功火候不够，不能使用云龙三现。\n");

    if( me->query("family/family_name")!=Menpai && me->query("chushi/last_family")!=Menpai 
        && !(me->query("tqt/old_family") && member_array(Menpai,me->query("tqt/old_family"))!=-1)
        && me->query_skill_mapped("force") != "cangming-gong" )
            return notify_fail("「云龙三现」这等阴毒武功，需配合浩气苍冥功施展，才能不伤自身。\n");                
   //门派大招影响
	if (me->query_temp("active_force_buffer/cangming-gong.zhengqi") && me->query_temp("cmg/zhengqi/times") < me->query_temp("cmg/zhengqi/point")&& !me->query_temp("cmg_zq_buff"))
	{
		hit_rate=1;
		me->add_temp("cmg/zhengqi/times",1);
		me->set_temp("cmg_zq_buff",1);
		me->add("neili",-200);
		msg = HIY "$N大气凛然，临战神勇！\n" NOR;
		message_vision(msg,me,target);
	}
	else
	{
		hit_rate=6;
	}
		
	msg = CYN "\n$N长吸一口气，攻势一变，身形疾如鬼魅一闪而过，「渊龙探爪」探手抓向$n。\n"NOR;
	
	dur = (int)me->query_skill("yunlong-zhua", 1);
	dur = 3 * dur + 2 * random(dur);
	dur /= 50;
	
	enemy = me->query_enemy();
	count = sizeof(enemy);
	tar = target;
	if (!tar)
		target = enemy[random(count)];

    if( F_KUNGFU->hit_rate( me->query_dex(), (int)target->query_dex(), hit_rate, me, target ) )
	{
        msg += HIW "$n顿觉呼吸一滞，全身气脉似乎都停顿了一下！\n"NOR;
		message_vision(msg, me, target);
		force = 200;
		times = target->query_temp("ningxue_poison/times");
		if (times>0)
		{
			damage = times * 10 + random( times * 100);
			target->add_temp("ningxue_poison/times", 1);
			msg += HIR "$n被这一击牵动体内的凝血毒，哇地吐出一口淤血。\n" NOR;
			F_KUNGFU->hit_wound("qi", damage, damage/4+random(damage/4), me, target);
		}
		F_POISON->poison_attack(me,target,"ningxue",dur);
		COMBAT_D->report_status(target);
	}
	 else
	{
        msg += HIY"$n急急往左一闪，勉强避过了这凌厉的一抓！\n" NOR;
		message_vision(msg, me, target);
		force = 50;
    }
	
	if (!tar)
		target = enemy[random(count)];
	msg = CYN "\n$N没有丝毫停顿，腾空而起，「龙骧游云」如同鹘鹰搏兔，倏地罩向$n！\n"NOR;
    if( F_KUNGFU->hit_rate( me->query_dex(), (int)target->query_dex(), hit_rate, me, target ) )
	{
        msg += HIW "$n被$N暗劲扫中，全身一阵麻酥，气力都消减了大半！\n\n"NOR;
		message_vision(msg, me, target);
		force += 200;
		if (target->query_condition("ningxue"))
		{
			msg += HIR "$n忽觉心脉一痛，就像被什么东西猛揪了一把，潜藏体内的剧毒都被激发了！\n" NOR;
			i = 1 + random(3);
			while (i--)
				target->update_condition();
		}		
		F_POISON->poison_attack(me,target,"ningxue",dur);
		COMBAT_D->report_status(target);
	}
	 else
	{
        msg += HIY"$n向后一个打滚，狼狈地避过了这一抓！\n" NOR;
		message_vision(msg, me, target);
		force += 50;
    }
	
	if (!tar)
		target = enemy[random(count)];
	msg = CYN "\n$N长笑一声，身影迅捷无伦的闪将过来，「龙吞日月」右手疾抓！\n"NOR;
    if( F_KUNGFU->hit_rate( me->query_dex(), (int)target->query_dex(), hit_rate, me, target ) )
	{
        msg += HIW "$n被一把抓个正着，顿觉得全身劲力都提不起来了！\n\n"NOR;
		message_vision(msg, me, target);
		force += 200;


		F_POISON->poison_attack(me,target,"ningxue",dur);
		COMBAT_D->report_status(target);
	}
	 else
	{
        msg += HIY"$n向下一顿，臀部着地，在地上直溜出数丈，艰难地避过了过去！\n" NOR;
		message_vision(msg, me, target);
		force += 50;
    }
	
	
	if (me->query_temp("cmg_zq_buff"))
	{
		me->delete_temp("cmg_zq_buff");
	}     
	me->add("neili", - force);
    return 1;
}

