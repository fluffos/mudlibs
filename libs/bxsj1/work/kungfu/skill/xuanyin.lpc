#include <ansi.h>
inherit F_SSERVER;
int perform(object me, object target)
{
        int lvl, j,i;
	object weapon;
	lvl = me->query_skill("xuanyin-jian", 1);

	if( !target ) target = offensive_target(me);

	if( !objectp(target)
	|| !target->is_character()
	|| !me->is_fighting(target)
	|| !necessary(target) )
		return notify_fail("你只能对战斗中的对手使用玄阴诀。\n");

	if( me->query_skill("xuanyin-jian", 1) < 160 )
		return notify_fail("你的玄阴剑法不够娴熟，无法施展出玄阴诀。\n");

	weapon = me->query_temp("weapon");

	if ( ! weapon 
	|| weapon->query("skill_type") != "sword"
	|| me->query_skill_mapped("sword") != "xuanyin-jian"
	|| me->query_skill_mapped("parry") != "xuanyin-jian" )
		return notify_fail("你现在无法施展出玄阴诀。\n");

	if ( me->query_skill("jiuyin-zhengong", 1) < 160)
		return notify_fail("你的九阴真功火候不够，无法施展出玄阴诀。\n");

	if ( me->query_skill("jiuyin-shenfa", 1) < 160)
		return notify_fail("你的九阴身法火候不够，无法施展出玄阴诀。\n");

	if ( me->query("max_neili") < 2000)
		return notify_fail("你的内力不够，无法施展出玄阴诀。\n");

	if ( me->query("neili") < 1000)
		return notify_fail("你的真气不够，无法施展出玄阴诀。\n");

	if ( me->query("jingli") < 1000)
		return notify_fail("你的精气不够，无法施展出玄阴诀。\n");

	message_vision(HIB"$N使出九阴「玄阴诀」，迅捷无比的攻向$n！\n"NOR,me, target);

	j = lvl /3;

	if ( lvl > 200 )
		j = to_int(lvl/200.0 * lvl/3.0);

	me->add_temp("apply/attack", j);
	me->add_temp("apply/sword", j);
	me->add_temp("apply/damage", j/2);

        message_vision(HIB"$N连出数剑，一剑比一剑凌利！\n"NOR,me,target);
        i=0;
        if(random(me->query("combat_exp"))>target->query("combat_exp")/4)
        {
        	message_vision(HIB"$n连连後退，陷入一片混乱之中，更别说攻击了。\n"NOR,me,target);
        	i=1;
        }
        else
        message_vision(HIB"$n连连後退，防守尚有困难，更别说攻击了。\n"NOR,me,target);
        
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 1);
        
	if ( me->is_fighting(target))
		COMBAT_D->do_attack(me, target, me->query_temp("weapon"), random(2)?1:3);

	if ( me->is_fighting(target))
		COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 3);

        me->add_temp("apply/attack", -j );
        me->add_temp("apply/sword", -j);
        me->add_temp("apply/damage",-j/2);

        me->start_perform(3+random(2), "「玄阴诀」");
	me->add("neili", -400);
	me->add("jingli", -150);
	if(i==1) target->start_busy( lvl/50 ); 
	return 1;
}

string perform_name(){ return HIB"玄阴诀"NOR; }

int help(object me)
{
        write(HIB"\n玄阴剑法之「玄阴诀」："NOR"\n\n");
        write(@HELP
        要求：  当前内力 1000 以上；
                最大内力 2000 以上；
                当前精力 1000 以上；
                玄阴剑法等级 160 以上；
                九阴真功等级 160 以上；
                九阴身法等级 160 以上；
                激发剑法为玄阴剑法；
                激发招架为玄阴剑法；
                且手持兵器。

HELP
        );
        return 1;
}
