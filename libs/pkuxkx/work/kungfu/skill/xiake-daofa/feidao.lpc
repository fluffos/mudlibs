#include <ansi.h>
#include <combat.h>
inherit F_SSERVER; 

int perform(object me, object target)
{
        string msg;
        int damage;
        int mlvl,tlvl; //等级
        object weapon;

        weapon = me->query_temp("weapon");
        if( !target ) target = offensive_target(me);

        if( !target || !target->is_character())
                return notify_fail("你要对谁使「飞刀式」？\n");
        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "blade")
        if (!objectp(weapon = me->query_temp("secondary_weapon"))
        || (string)weapon->query("skill_type") != "blade")
                return notify_fail("你没拿刀，飞什么呀？\n");

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("「飞刀式」只能对战斗中的对手使用。\n");

        if( (int)me->query_skill("xiake-daofa", 1) < 100 )
                return notify_fail("你的侠客刀法不够娴熟，不会使用「飞刀式」。\n");
        if((int)me->query("neili") < 50)
                return notify_fail("你的内力不够呀!\n");

        msg = HIC "只见$N运起侠客刀法的「飞刀式」，" NOR + weapon->query("name") + HIC "飞旋而出，直砍$n。\n" NOR;

        //计算level
        if (userp(target))    tlvl  = target->query("level");
        else  tlvl  = to_int(pow(target->query("combat_exp")/400, 0.333)-random(5));
        if (userp(me))        mlvl = me->query("level");
        else  mlvl  = to_int(pow(me->query("combat_exp")/400, 0.333)-random(5));
        if (tlvl < 1) tlvl=1;
        if (mlvl < 1) mlvl=1;
        if (wizardp(me))
                tell_object(me,sprintf("mlvl:%d,tlvl:%d,mysword:%d,tdodge:%d\n",mlvl,tlvl,me->query_skill("sword"),target->query_skill("dodge")));

        me->start_busy(random(4));
        if( F_KUNGFU->hit_rate( me->query_skill("blade")*mlvl, (int)target->query_skill("dodge")*tlvl, 6, me, target) ) 
        {
                msg += "只听$p一声惨叫，被"+weapon->query("name")+"砍个正着。\n" NOR;
                message_vision(msg, me, target);
                target->kill_ob(me);
                
                damage = (int)me->query_skill("xiake-daofa");
                damage += (int)me->query_skill("xiake-shengong",1);

                F_KUNGFU->hit_wound("qi", damage, damage/3, me, target);
                COMBAT_D->report_status(target);
                me->add("neili", -damage/10);
        } else {
                me->start_busy(3);
                msg += HIG "可是$p看破了$P的企图，轻轻松松地躲了过去。\n" NOR;
                message_vision(msg, me, target);
                target->kill_ob(me);
        }

        return 1;
}

