//Cracked by polybao
// yingzhua.c 鹰爪擒拿
//来源 倚天屠龙记
//殷天正右手斜翻，姿式妙到巅毫，正是对付敌人进攻的一招杀手，
//唐文亮已然无法自救，果然听得喀喀两响，唐文亮双臂已被殷天正施展“鹰爪擒拿手”折断，跟着又是喀喀两响，连两条大腿也折断了，呯的一响，摔在数尺之外。

#include <ansi.h>

inherit F_DBASE;
inherit F_SSERVER;

int perform(object me, object target)
{
	object weapon;
	int sp, dp, damage;
        string *limbs, limb, type, result, str, dodge_skill;

        type = "内伤";
	
	if( !me->is_fighting() ) 
		return notify_fail("你必须在战斗中才能使用鹰爪擒拿！\n");

	if( !target && me->is_fighting() ) target = offensive_target(me);

	if( environment(target)->query("no_fight") )
		return notify_fail("在这里你不能偷袭！\n");

	if( me->query_skill("yingzhua-qinna", 1) < 220 )
		return notify_fail("你的鹰爪擒拿手修炼还不够，不会鹰爪擒拿！\n");

	if( me->query_skill("shenghuo-xuanming", 1) < 200 )
		return notify_fail("你的内功修为火候未到，无法使用鹰爪擒拿！\n");

	if( me->query("max_neili") <= 3000 )
		return notify_fail("你的内力修为不足，无法使鹰爪擒拿！\n");

	sp = me->query_skill("dodge") + me->query_skill("parry") + me->query("combat_exp") /50;
	dp = target->query_skill("dodge") + target->query_skill("parry") +target->query("combat_exp") / 50;
	damage = me->query_skill("force")+me->query_skill("hand")+me->query("jiajin");
	damage = damage*(1+random(me->query("jiali")/30)); 

	if( sp/2 + random(sp/2) > dp/3 )
	{
		if (damage > target->query("qi"))
		{
			message_vision(HIW "\n$N右手斜翻，姿式妙到巅毫，正是对付敌人进攻的一招杀手，$n已然无法自救，\n果然听得喀喀两响，$n双臂已被$N施展“鹰爪擒拿手”折断，\n跟着又是喀喀两响，连两条大腿也折断了，呯的一响，摔在数尺之外。\n\n" NOR, me, target);
		}
		else message_vision(HIW "\n$N右手斜翻，姿式妙到巅毫，正是对付敌人进攻的一招杀手，$n已然无法自救，\n果然听得喀喀两响，$n已被$N施展“鹰爪擒拿手”重创，呯的一响，摔在数尺之外。\n\n" NOR, me, target);
                target->receive_damage("qi", damage,  me);
                target->receive_wound("qi", damage/2+random(damage/2), me);
                target->start_busy(1+random(2));                                                                        // target busy time > own busy time
                me->start_busy(2+random(2));
		me->add("neili", -300);
	            limbs = target->query("limbs");
	
	            result = COMBAT_D->damage_msg(damage, type);
	            result = replace_string( result, "$l", limbs[random(sizeof(limbs))]);
	            result = replace_string( result, "$p", target->name() );
	            message_vision(result, me, target);
	
	            str = COMBAT_D->status_msg((int)target->query("qi") * 100 /(int)target->query("max_qi"));
	            message_vision("($N"+str+")\n", target);
		
        }
	else
	{
		message_vision(HIR "\n$N右手斜翻，姿式妙到巅毫，正是对付敌人进攻的一招杀手，$n发觉不妙，极力向后避了开去！ \n" NOR, me, target);
                target->start_busy(1+random(2));                                                                        // target busy time > own busy time
                me->start_busy(1+random(2));
        }
        return 1;
}
