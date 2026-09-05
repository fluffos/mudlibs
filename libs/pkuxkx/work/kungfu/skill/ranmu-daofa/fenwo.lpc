// renmu-daofa 燃木刀法

#include <ansi.h>
#include <char.h>
#include <weapon.h>
#include <skill.h>
#include <combat.h>
inherit F_SSERVER;

int valid_target_arg(string target)
{
    if ( target == "version" ) return 2;
    return target=="null" || target=="other" ;
}

int perform(object me, object target)
{
        object weapon;
        int i;
        mapping attack_val = ([
            "base": ([ "weapon" : "blade" ]),//基本功夫类型
            "skill" : ([ "weapon" : "ranmu-daofa" ]),//高级技能名称
            ]);

        weapon = me->query_temp("weapon");

        if( !target ) target = offensive_target(me);

        if( !objectp(target) || !target->is_character() || !me->is_fighting(target) )
                return notify_fail("「焚我」攻击只能对战斗中的对手使用。\n");

        if ( !objectp(weapon) || weapon->query("skill_type") != "blade" )
/*           || me->query_skill_mapped("blade") != "ranmu-daofa") */
                return notify_fail("你没有木刀，使不出「焚我」绝技！\n");

        if (weapon->query("unique"))
                return notify_fail("你手中之刀已是锋利之极，使用「焚我」绝技没有什么作用！\n");

        if (weapon->query("id") != "mu dao" && weapon->query("material") != "wood")
                return notify_fail("你没有木刀，使不出「焚我」绝技！\n");

        if(me->query_skill("ranmu-daofa", 1) < 150 )
                return notify_fail("你的燃木刀法火候不够，使不出「焚我」绝技。\n");

        if(me->query_skill("blade", 1) < 150 )
                return notify_fail("你的基本功还不够娴熟，使不出「焚我」绝技。\n");

        if( (int)me->query_skill("yijin-jing", 1) < 150 )
                return notify_fail("你的易筋经等级不够，使不出「焚我」绝技。\n");

        if( (int)me->query_str() < 40)
                return notify_fail("你的膂力还不够强劲，使不出「焚我」绝技。\n");

        if( (int)me->query_int() < 40)
                return notify_fail("没有大智慧大般若，是使不出「焚我」绝技的。\n");

        if ( !(me->query_temp("ignore_pfm_limit") & IGNORE_PFM_LIMIT_FORCE) &&
             me->query_skill_mapped("force") != "yijin-jing")
                return notify_fail("没有易筋经作为根基，是无法使出「焚我」绝技的！\n");

        if (me->query_temp("ryb_fumo"))
                return notify_fail("你现在正在使用「金刚伏魔圈」。\n");

        if(me->query_temp("ranmu"))
                return notify_fail("你现在正在使用「焚心」绝技。\n");

        if(me->query_temp("zuida"))
                return notify_fail("你正在使用「醉打」绝技。\n");

        if (me->query("max_neili") < 2000)
                return notify_fail("你的内力修为不够。\n");

        if (me->query("neili") < 1000)
                return notify_fail("你的内力不够。\n");

        me->start_perform(3,"焚我");

        //fenwo's damage depends on how many times u pfmd
        i = me->query("fenwo");
        if (i > me->query_skill("blade", "ranmu-daofa")*2/3) i = me->query_skill("blade", "ranmu-daofa")*2/3;
        me->add("neili", -i/3);
        //and it will not be over ur enable blade skill
        me->add_temp("apply/damage", i);
        me->add_temp("apply/attack", i);
        me->set_temp("fenwo_hit", 1);
        me->set_temp("attack_val", attack_val);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), TYPE_SPECIAL);

        if ( (me->query_skill("ranmu-daofa", 1) > 300) && objectp(me->query_temp("weapon")) )
        {
            me->set_temp("attack_val", attack_val);
            COMBAT_D->do_attack(me, target, me->query_temp("weapon"), TYPE_SPECIAL);
        }

        if ( (me->query_skill("ranmu-daofa", 1) > 600) && objectp(me->query_temp("weapon")) )
        {
            me->set_temp("attack_val", attack_val);
            COMBAT_D->do_attack(me, target, me->query_temp("weapon"), TYPE_SPECIAL);
        }

        me->add_temp("apply/damage", -i);
        me->add_temp("apply/attack", -i);
        me->delete_temp("fenwo_hit");
        if ( objectp(weapon = me->query_temp("weapon")) )
        {
            weapon->add("fenwo", 1);
            if ( weapon->query("fenwo") >= 20)
            {
                message_vision(HIY"\n只听“咔咔”几声，$N手中的$n"HIY"在熊熊火焰中裂成了碎片！\n"NOR,me,weapon);
                weapon->unequip();
                if ( !weapon->is_gems() )
                {
                    weapon->set("name", "碎裂的" + weapon->query("name"));
                    weapon->set("value", 49);
                    weapon->set("weapon_prop", 0);
                }
                weapon->move(environment(me));
                me->reset_action();
            }
        }
        me->start_busy(2+random(2));

        if ( me->query("fenwo")+1 > 0)
        {
            me->add("fenwo", 1);
        }

        return 1;
}

