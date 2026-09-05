// shendao.c  血刀经 [神刀]
// changed by emnil@sj  2/5/2000

#include <ansi.h>
#include <char.h>
#include <skill.h>
#include <combat.h>
#include <weapon.h>
inherit F_SSERVER;

int valid_target_arg(string target)
{
    if ( target == "version" ) return 2;
    return target=="null" || target=="other" ;
}

int perform(object me, object target)
{
        object weapon, ob;
        string msg, weaname;
        int lvl,damage;
        mapping attack_val = ([
            "base" : ([ "weapon" : "blade", ]),//基本功夫类型
            "skill" : ([ "weapon" : "xuedao-jing", ]),//高级技能名称
            ]);

        if( !target ) target = offensive_target(me);

        if( !objectp(target) || !target->is_character() || !me->is_fighting(target) )
                return notify_fail("「神刀穿心」只能在战斗中使用。\n");

        if (!objectp(weapon = me->query_temp("weapon")) || (string)weapon->query("skill_type") != "blade")
                return notify_fail("你需要装备刀类武器才能使用「神刀穿心」。\n");

        if((int)me->query_dex() < 28)
                return notify_fail("你的身法不够, 目前还不能使用这项绝技! \n");

        if((int)me->query_skill("dodge") < 110)
                return notify_fail("你的轻功修为不够, 不能使用「神刀穿心」！\n");

        if((int)me->query_skill("xuedao-jing",1) < 100)
                return notify_fail("你的刀法修为不够， 目前不能使用「神刀穿心」! \n");

        if((int)me->query_skill("longxiang-boruo",1) < 100)
                return notify_fail("你的龙象般若功修为不够， 目前不能使用「神刀穿心」! \n");

/*        if( me->query_skill_mapped("blade") != "xuedao-jing")
                return notify_fail("你必须使用血刀经，才能使用「神刀穿心」的绝技！\n"); */

        if( !(me->query_temp("ignore_pfm_limit") & IGNORE_PFM_LIMIT_FORCE) &&
            me->query_skill_mapped("force") != "longxiang-boruo")
                return notify_fail("你现在所使用的内功同「龙象般若功」相抵触，不能使出「神刀穿心」的绝技！\n");

        if( (int)me->query("max_neili") < 1300 )
                return notify_fail("你的内力修为不够！\n");

        if((int)me->query("neili")<600)
                return notify_fail("你的真气不够！\n");

        lvl = me->query_skill("xuedao-jing",1);
        weapon = me->query_temp("weapon");
        weaname = weapon->query("name");
        msg = HIR "\n$N狂啸声中，运起「神刀穿心」秘诀，刹时身法如电，"NOR+weaname+HIR"一分为四，劈将出去！\n"NOR;
        message_vision(msg, me);

        if(me->query_temp("xs/longxiang")) 
        {
            damage = me->query_skill("longxiang-boruo",1)/3;
            if(damage > lvl/10) damage = lvl/10;
            me->add_temp("apply/damage", damage);
            message_vision(MAG"$N更把龙象内劲附于兵刃之上，"+weaname+MAG"通体流淌着异样的紫色光芒！\n"NOR, me,target);
        }
        me->add_temp("apply/blade", lvl/5);
        if ( objectp(weapon = me->query_temp("weapon")) )
        {
            me->set_temp("attack_val", attack_val);
            COMBAT_D->do_attack(me, target, me->query_temp("weapon"), TYPE_SPECIAL);
        }
        if ( objectp(weapon = me->query_temp("weapon")) )
        {
            me->set_temp("attack_val", attack_val);
            COMBAT_D->do_attack(me, target, me->query_temp("weapon"), TYPE_SPECIAL);
        }
        if(lvl >150)
            if ( objectp(weapon = me->query_temp("weapon")) )
            {
                me->set_temp("attack_val", attack_val);
                COMBAT_D->do_attack(me, target, me->query_temp("weapon"), TYPE_SPECIAL);
            }
        if(lvl >180)
            if ( objectp(weapon = me->query_temp("weapon")) )
            {
                me->set_temp("attack_val", attack_val);
                COMBAT_D->do_attack(me, target, me->query_temp("weapon"), TYPE_SPECIAL);
            }

        me->add("neili", -100-random(200));
        if(me->query("neili")<0) me->set("neili",0);
        me->start_busy(random(2)+ 2);
        me->start_perform(4,"神刀穿心");
        me->add_temp("apply/blade", -lvl/5);
        if(me->query_temp("xs/longxiang")) {
            me->add_temp("apply/damage", -damage);
        }
        return 1;
}

