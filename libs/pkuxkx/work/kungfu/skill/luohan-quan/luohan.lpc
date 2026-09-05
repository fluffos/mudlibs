//luohan-quan.luohan

#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;
#include "/kungfu/skill/eff_msg.h";

int valid_target_arg(string target)
{
    if ( target == "version" ) return 2;
    return target=="null" || target=="other" ;
}

int perform(object me, object target)
{
        string msg;
        int extra;
        int damage, p;
        mapping attack_val = ([
            "base" : ([ "no_weapon" : "cuff", ]),//基本功夫类型
            "skill" : ([ "no_weapon" : "luohan-quan", ]),//高级技能名称
            ]);

        if( !target ) target = offensive_target(me);

        if( !objectp(target) || !target->is_character() || !me->is_fighting(target) )
                return notify_fail("「罗汉」只能对战斗中的对手使用。\n");

        if( (int)me->query_skill("luohan-quan", 1) < 150 )
                return notify_fail("你的罗汉拳不够娴熟!\n");

        if ( me->check_hand() >= 1 )
                return notify_fail("「罗汉」只能双手空手使用。\n");

        if( me->query_skill("hunyuan-yiqi", 1) < 150)
                return notify_fail("你的内功修为未到，不能施展「罗汉」！\n");

        if ( me->query("max_neili", 1) < 2000)
                return notify_fail("你的内力修为不够，无法施展「罗汉」！\n");

        if ( me->query("neili", 1) < 1000 )
                return notify_fail("你内力不足以施展「罗汉」！\n");

        extra = me->query_skill("cuff", "luohan-quan")/2;
        if (extra > 500 && me->query_skill("hunyuan-yiqi", 1) > 500)  // 500级飞跃
                extra = 2*extra;
        else    extra -= random(extra);

        msg = HIY  "$N两足足跟不动，足尖左磨，身子随之右转，成右引左箭步，一式罗汉拳打出！\n" NOR;
        message_vision(msg,me,target);

        me->add_temp("apply/attack",extra);
        me->add_temp("apply/damage",extra);

        if(!target->is_busy())  target->start_busy(2);

        msg = YEL  "$N使出独步天下的续上步，一式「黄莺落架」，左右手分靠，变拳为掌，击向$n的$l" NOR;
        me->set_temp("attack_val", attack_val);
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"), TYPE_SPECIAL, msg);

        msg = HIC  "$N使一招「苦海回头」，上身前探，双手划了个半圈，击向$n的$l" NOR;
        me->set_temp("attack_val", attack_val);
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"), TYPE_SPECIAL, msg);

        msg = HIB  "$N左脚内扣，右腿曲坐，一式「三入地狱」，双手齐齐按向$n的$l" NOR;
        me->set_temp("attack_val", attack_val);
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"), TYPE_SPECIAL, msg);

        me->add("neili",-100-random(100));
        me->add_temp("apply/attack",-extra);
        me->add_temp("apply/damage",-extra);

        if ( F_KUNGFU->hit_rate(me->query_skill("force", "hunyuan-yiqi"), target->query_skill("force"), 6, me, target)
         && me->query_skill("luohan-quan", 1) > 500
         && me->query_skill("hunyuan-yiqi", 1) > 500)
        {
                msg = HIR"\n$N全身骨骼发出轻微爆裂之声，双臂灌满内劲直击$n胸口，招式平平淡淡，一成不变，但却挡无可挡，避无可避！\n"NOR;
                damage = me->query_skill("cuff", "luohan-quan") + me->query_skill("buddhism",1) + 4*me->query("jiali");
                damage +=random(damage/4);
                F_KUNGFU->hit_wound("qi", damage, damage/4, me, target);
                p = (int)target->query("qi")*100/(int)target->query("max_qi");
                msg += damage_msg(damage, "内伤");
                message_vision(msg, me, target);
                COMBAT_D->report_status(target);
                me->add("neili", -200-random(200));
        }

        if (me->query("neili") < 0) me->set("neili",0);
        me->start_busy(2+random(3));

        return 1;
}

