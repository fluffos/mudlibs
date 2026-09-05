// suo.c 锁剑诀

#include <ansi.h>

inherit F_SSERVER;

int perform(object me)
{
        string msg;
        object weapon, weapon2, target;
        int skill, ap, dp, damage;

        if (!objectp(weapon = me->query_temp("weapon"))
            || (string)weapon->query("id") != "jinshe jian")
           return notify_fail("你没用金蛇剑，不能使用绝招！\n");

        if( me->query_dex() < 50 || me->query_str() < 50 )
            return notify_fail("你的先天膂力身法孱弱, 不能使用「锁剑诀」！\n");

       skill = me->query_skill("jinshe-jian",1);
        if( !target ) target = offensive_target(me);

        if( !(me->is_fighting() ))
            return notify_fail("「锁剑诀」只能对战斗中的对手使用。\n");

        if (!objectp(weapon2 = target->query_temp("weapon")))
            return notify_fail("对方没有使用兵器，你用不了「锁剑诀」。\n");

        if( skill < 150)
            return notify_fail("你的金蛇剑法等级不够, 不能使用「锁剑诀」！\n");

        if( me->query("neili") < 300 )
            return notify_fail("你的内力不够，无法运用「锁剑诀」！\n");

        msg = HIC "$N手中"YEL"金蛇剑"HIC"画出一道金光，斜刺一拉，「锁剑诀」！
"YEL"金蛇剑"HIC"剑尖倒钩正好挂在$n的"+weapon2->name()+"上。\n";
        message_combatd(msg, me, target);

        damage = 10 + random(skill / 2);
        ap = me->query_skill("sword")/3 + skill;
        dp = target->query_skill("dodge");
        if( dp < 1 )
            dp = 1;
        if( F_KUNGFU->hit_rate( ap, dp, 4, me, target) )
        {
            if(userp(me))
                 me->add("neili",-50);
            msg = "$n顿时觉得眼前金光一闪，手腕一振，手中";
            msg += weapon2->name();
            msg += "脱手飞出！\n" NOR;
            me->start_busy(2);
            F_KUNGFU->hit_wound("qi", damage, 0, me, target);
            weapon2->move(environment(me));
        }
        else
        {
            if(userp(me))
                 me->add("neili",-30);
            msg = "$n急运内力，将手中" + weapon2->name()+ "斜斜顺势一送一搭，抽了回来。\n"NOR;
            me->start_busy(2);
        }
        message_combatd(msg, me, target);
        COMBAT_D->report_status(target);

        return 1;
}
