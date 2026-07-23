//来去若无形 wuying.c
// by godzilla 99.03.06

#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>

//inherit F_CLEAN_UP;

void remove_effect(object me, int a_amount, int d_amount);

inherit F_SSERVER;
int perform(object me, object target)
{
        object weapon,ob;
        int skill;
	int extra;
        string msg;

        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("「分身无影」只能在战斗中使用。\n");

	if (!objectp(weapon = me->query_temp("weapon"))
		|| (string)weapon->query("skill_type") != "sword")
                return notify_fail("「分身无影」必须用剑才能施展。\n");

        if( (int)me->query_skill("wuying-jian", 1) < 150 )
                return notify_fail("你的「少林无影剑」不够娴熟，不会使用「分身无影」。\n");

//        if (me->query_skill_mapped("force") != "yijinjing")
//                return notify_fail("你的内功中无易筋经。\n");

	if( (int)me->query_skill("yijinjing", 1) < 100 )
		return notify_fail("你的易筋经不够娴熟。\n");

        if( (int)me->query("neili") < 400  ) 
                return notify_fail("你的内力不够。\n");

        skill = me->query_skill("wuying-jian");
	extra = me->query_skill("wuying-jian",1) / 10;
	extra += me->query_skill("wuying-jian",1) /10;
	me->add_temp("apply/attack", 80);	
	me->add_temp("apply/damage", (extra*5));

        msg = HIG "$N身行突变，瞬间犹如分出无数身影闪电般的向$n攻去！\n"NOR;
        message_vision(msg, me, target);

        me->add("neili", -200);

        msg = HIR"VV来字决！\n"NOR;
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), TYPE_REGULAR,msg);
        msg = HIY"VVVV去字决！\n"NOR;
        
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), TYPE_REGULAR,msg);
        msg = HIG"VVVVVV若字决！\n"NOR;
        
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), TYPE_REGULAR,msg);
        msg = HIB"VVVVVVVV无字决！\n"NOR;
        
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), TYPE_REGULAR,msg);
        msg = HIW"VVVVVVVVVV形字决！\n"NOR;
       
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), TYPE_REGULAR,msg);


        me->start_busy(2);
	me->add_temp("apply/attack", -80);
	me->add_temp("apply/damage", -(extra*5));

        return 1;
}
