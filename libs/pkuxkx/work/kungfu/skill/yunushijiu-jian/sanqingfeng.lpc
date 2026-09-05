// sanqingfeng.c 太岳三青峰

#include <ansi.h>
#include <combat.h>
inherit F_DBASE;
inherit F_SSERVER;

int valid_target_arg(string target)
{
    if ( target == "version" ) return 2;
    return target=="null" || target=="other" ;
}

int perform(object me, object target)
{
        int skill, damage, bt;
        mapping attack_val = ([
            "base" : ([ "weapon" : "sword", ]),//基本功夫类型
            "skill" : ([ "weapon" : "yunushijiu-jian", ]),//高级技能名称
            ]);
        object weapon = me->query_temp("weapon");

        if ( !me->query("huashan_newskills/qizong") ||
              me->query("family/family_name")!="华山派" )
			{
			if (!me->query("safari_skill/hs_jq"))
                return notify_fail("这是华山气宗的秘传绝学，你无法在实战中运用「太岳三青峰」。\n");
			}

        if( !target ) target = offensive_target(me);
        if( !objectp(target) || !target->is_character() || !me->is_fighting(target) )
                return notify_fail("「太岳三青峰」只能对战斗中的对手使用。\n");

        if ( !objectp(weapon) || weapon->query("skill_type") != "sword" )
                return notify_fail("你手中无剑怎能使用太岳三青峰？！\n");

        if( (int)me->query_skill("zixia-shengong", 1) < 120 && 
            (int)me->query_skill("yunushijiu-jian", 1) < 120 )
                return notify_fail("你的内功火候未到，无法施展太岳三青峰！\n");

        if( me->query_skill("dodge") < 120 )
                return notify_fail("太岳三青峰需要超绝的轻功配合，方能有效施展！\n");

        if( me->query_skill("sword", "yunushijiu-jian") < 120 )
                return notify_fail("你玉女十九剑未到炉火纯青之境，还不会使用太岳三青峰！\n");

        if( me->query("neili") <= 400 )
                return notify_fail("你的内力不够使用太岳三青峰！\n");

        if( me->query("max_neili") <= 1000 )
                return notify_fail("你的内力修为不够使用太岳三青峰！\n");

        message_vision(HIC "\n突然间$N聚集全身功力，"NOR + weapon->name() + HIC "挟着风雷之声，嗤嗤嗤向$n连攻三剑！\n" NOR, me, target);

        me->add("neili", -200);
        skill = me->query_skill("yunushijiu-jian", 1);
		if ( !me->query("huashan_newskills/qizong"))
			{
			skill = skill*3/4;
			}

        me->add_temp("apply/attack", skill/2);
        me->add_temp("apply/damage", skill/2);
        me->set_temp("attack_val", attack_val);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), TYPE_SPECIAL);
        if (me->is_fighting(target))
        {
            me->set_temp("attack_val", attack_val);
            COMBAT_D->do_attack(me, target, me->query_temp("weapon"), TYPE_SPECIAL);
        }
        if (me->is_fighting(target))
        {
            me->set_temp("attack_val", attack_val);
            COMBAT_D->do_attack(me, target, me->query_temp("weapon"), TYPE_SPECIAL);
        }
        me->add_temp("apply/attack", -skill/2);
        me->add_temp("apply/damage", -skill/2);

        if( F_KUNGFU->hit_rate( me->query_int(), target->query_int(), 9, me, target )
         && me->query_skill("dugu-jiujian", 1) > 400
         && me->query_skill_mapped("parry") == "dugu-jiujian"
         && me->query("betrayer") <= 0
         && me->is_fighting(target) )
        {
                message_vision(HIC "\n$N默念独孤九剑要诀，顺势随手几剑刺出，剑剑不离$n要害！\n$n要害受限，一口真气提不起来，哇的吐出一口鲜血，真气方才顺畅。\n" NOR, me, target);
                damage =  me->query_skill("dugu-jiujian", 1) + me->query_skill("sword", 1);
                F_KUNGFU->hit_wound("qi", damage, damage/2, me, target);
                COMBAT_D->report_status(target);
        }
        if( (int)me->query("neili") < 0 ) me->set("neili", 0);
        me->start_busy(3);

        return 1;
}

