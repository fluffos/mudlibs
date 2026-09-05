//fuxue.c
//modified by iszt@pkuxkx, 2007-02-08

#include <ansi.h>
#include "/kungfu/skill/eff_msg.h"
inherit F_SSERVER;

int valid_target_arg(string target)
{
    if ( target == "version" ) return 2;
    return target=="null" || target=="other" ;
}

string *xue_name = ({
	"曲池穴",
	"冲阳穴",
	"臂儒穴",
	"白海穴",
	"灵台穴",
	"风府穴",
	"神风穴",
	"玉书穴",
}); 

int perform(object me, object target)
{
	string msg, name;
	int pflv, ap, dp, cp;
	int rate_fix,k;

	if( !target ) target = offensive_target(me);

	if( !objectp(target) || !living(target) || !me->is_fighting(target) )
		return notify_fail("「兰花拂穴」只能在战斗中对对手使用。\n");

	if( (int)me->query_skill("hand",1) < 100 )
		return notify_fail("你的基本手法还不够娴熟，恐怕做不到「兰花拂穴」的「准」字。\n");

    if( (int)me->query_skill("dodge",1) < 100 )
        return notify_fail("你的基本身法还不够娴熟，恐怕做不到「兰花拂穴」的「快」字。\n");

	if( (int)me->query_skill("fuxue-shou",1) < 100 )
		return notify_fail("你的兰花拂穴手还不够娴熟，恐怕做不到「兰花拂穴」的「奇」字。\n");

    if( (int)me->query_skill("bihai-shengong",1) < 100 )
        return notify_fail("你的碧海神功等级不够，恐怕难以驱动「兰花拂穴」。\n");

/*	if (me->query_skill_prepared("hand") != "fuxue-shou"
		|| me->query_skill_mapped("hand") != "fuxue-shou")
		return notify_fail("你必须使用兰花拂穴手，才能以「兰花拂穴」进行攻击。\n");	*/

	if( (int)me->query("max_neili") < 300 || (int)me->query("neili") < 300 )
		return notify_fail("你的内力不足，无法使用兰花拂穴手。\n");

	if( target->is_busy() )
		return notify_fail("对方正忙着呢，放胆攻击吧。\n");

	pflv = (int)me->query("purefamily/level");
	if (pflv>0 && me->query("purefamily/family_name") != "桃花岛")
		pflv = 0;

	if( me->query("eff_qi") > me->query("max_qi")/2 )
		msg = HIC"\n$N右手挥出，拇指与食指扣起，余下三指略张，手指如一枝兰花般伸出，拂向$n，姿势美妙已极。\n"NOR;
	else
		msg = HIC"\n$N右手挥出，拇指与食指扣起，余下三指略张，手指歪歪斜斜地拂向$n。\n" NOR;

	me->add("neili",-100);
	if( pflv<3 && !target->is_killing(me->query("id")) ) target->kill_ob(me);
	if( !me->is_fight(target) ) me->fight_ob(target);

	me->start_busy(random(4));

	ap = me->query_skill("force", "bihai-shengong")/10 + me->query_skill("dodge")/10 + me->query_skill("hand", "fuxue-shou")/10 + me->query_per();
	cp = me->query_skill("force", "bihai-shengong") + me->query_skill("dodge") + me->query_skill("hand", "fuxue-shou") + me->query_per()*10;
	dp = target->query_skill("force")/10 + target->query_skill("dodge")/10 + me->query_skill("parry")/10+target->query_skill("literate")/10;
	ap *= (me->query("combat_exp")/1000);
	dp *= (target->query("combat_exp")/1000);

	if(me->query("eff_qi") > me->query("max_qi") / 2)
		cp = cp * 3 / 2;
	if (cp > 1000)
		cp = cp/3 + 500;
	name = xue_name[random(sizeof(xue_name))];

	rate_fix=9;
	k=me->query_temp("active_buff/qimen-baguazhen.buzhen/cengshu");
	if (k>0)
	{
		if (me->query("safari_skill/thd_huoxin"))
		{	
			if (!me->query_temp("qmbgz.huoxin_done"))
			{
				if (k<18)
				{
					rate_fix -= (int)(k>>1);
				}
				me->set_temp("qmbgz.huoxin_done",1);
		        message_vision(HIG"\n$N在奇门八卦阵的影响下，越战越有灵性！\n"NOR,me,target);
			}
		}
	}


	if( F_KUNGFU->hit_rate( ap, dp, rate_fix, me, target) )
	{
		msg += CYN"$n只感「"RED + name + CYN"」上一麻，被$N拂中穴道。\n"NOR;
		F_KUNGFU->hit_wound("qi", random(cp), 0, me, target);
		msg += damage_msg(me->query_skill("hand", "fuxue-shou"), "内伤");
		F_KUNGFU->hit_busy( "dianxue", (int)me->query_skill("fuxue-shou") /25, target );
        message_vision(msg, me, target);   
        COMBAT_D->report_status(target);
	} 
    else 
    {
		msg += CYN"$n只感「"RED + name + CYN"」上一麻，手臂疾缩，总算变招迅速，没给$N拂中穴道。\n"NOR;
        message_vision(msg, me, target);   
	}
	return 1;
}

int help(object me)
//added by iszt@pkuxkx, 2007-02-08
{
	write(HIC"\n兰花拂穴手之「兰花拂穴」\n\n"NOR);
	write(@HELP
	拇指与食指扣起，余下三指略张，手指如一枝兰花般伸出，姿势美妙已
	极。讲究「快、准、奇、清」。尤以「清」字诀最难，需出手优雅，气
	度闲逸，轻描淡写，行若无事。伤害和命中与双方的内功、轻功、手法、
	招架、读书写字、容貌、经验等因素有关。

        要求：  「快」：基本身法等级 100 以上；
		「准」：基本手法等级 100 以上；
		「奇」：兰花拂穴手等级 100 以上；
		「清」：受伤不超过50%；
                碧海神功100级，最大内力与内力 300 以上；
		激发手法为兰花拂穴手；
		且使用兰花拂穴手。
HELP
	);
	return 1;
}
