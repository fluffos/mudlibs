// sanhuan.c

#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;

string perform_name(){ return HIG"三环套月"NOR; }

int valid_target_arg(string target)
{
    if ( target == "version" ) return 2;
    return target=="null" || target=="other" ;
}

int perform(object me, object target)
{
        string msg;
        object weapon;
        int i = me->query_skill("taiji-jian", 1)/8;
        mapping attack_val = ([
            "base": ([ "weapon" : "sword" ]),//基本功夫类型
            "skill" : ([ "weapon" : "taiji-jian" ]),//高级技能名称
            ]);

        if( !target ) target = offensive_target(me);

        if( !target || !target->is_character() || !me->is_fighting(target) || !living(target))
                return notify_fail("「三环套月」只能对战斗中的对手使用！\n");

        if( (int)me->query_skill("taiji-jian", 1) < 120 )
                return notify_fail("你的太极剑法等级不够，使不出「三环套月」！\n");

        if( (int)me->query_skill("taiji-shengong", 1) < 120 )
                return notify_fail("你的太极神功修为不够，使不出「三环套月」！\n");

        if( (int)me->query("max_neili") < 1500 )
                return notify_fail("你的内力修为不够，使不出「三环套月」！\n");

        if( (int)me->query("neili") < 500 )
                return notify_fail("你的内力不够，使不出「三环套月」！\n");

        if( me->query_skill_mapped("force") != "taiji-shengong" )
                return notify_fail("「三环套月」只能运用太极神功驱动！\n");

        if( !objectp(weapon = me->query_temp("weapon")) 
            || weapon->query("skill_type") != "sword" )
/*         || me->query_skill_mapped("sword") != "taiji-jian") */
                return notify_fail("你需要装备sword类武器才能使用三环套月！\n");

        me->add("neili", -100-random(200));
        me->start_perform(4, "「三环套月」");
        msg = HIB "\n$N一式「三环套月」，"+ weapon->name() + HIB"划出三个圆圈";
        if( me->query("taiji") ){
                i *= 2;
                msg += "，剑法吞吐开合、阴阳动静，已到太极剑法的绝诣。\n" NOR;
        }
        else    msg += "。\n" NOR;
		if (me->query_temp("taiji_xuli")>0)
		{
			msg+=HIR  "$N"HIR"积蓄起来的太极劲力猛地爆发了出来。\n";
			me->add_temp("apply/damage",me->query_temp("taiji_xuli"));
		}


        message_vision(msg, me, target);

        me->add_temp("apply/attack", i);
        me->add_temp("apply/damage", i);
        me->set_temp("attack_val", attack_val);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), TYPE_SPECIAL);
        if(me->is_fighting(target))
        {
            me->set_temp("attack_val", attack_val);
            COMBAT_D->do_attack(me, target, me->query_temp("weapon"), TYPE_SPECIAL);
        }
        if(me->is_fighting(target))
        {
            me->set_temp("attack_val", attack_val);
            COMBAT_D->do_attack(me, target, me->query_temp("weapon"), TYPE_SPECIAL);
        }
        me->add_temp("apply/attack", -i);
        me->add_temp("apply/damage", -i);
		if (me->query_temp("taiji_xuli")>0)
		{
			me->add_temp("apply/damage",-me->query_temp("taiji_xuli"));
			me->set_temp("taiji_xuli",0);
		}


        me->start_busy(2+random(2));

        return 1;
}

