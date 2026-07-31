// jingang-zhang

#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;
int perform(object me, object target)
{
      string *limbs;
        int count, damage = 0;
        int arg=(int)(me->query_skill("xinyue-gong", 1) / 300);

        if( !target ) target = offensive_target(me);

        if( !target || !target->is_character() || !me->is_fighting(target) )
                return notify_fail("「星月」只能在战斗中对对手使用。\n");

        if( (int)me->query_skill("xinyue-gong", 1) < 150 )
                return notify_fail("你的星月功不够娴熟，不会使用「星月」。\n");

        if( (int)me->query_skill("force", 1) < 90 )
                return notify_fail("你的内功等级不够，不能使用「星月」。\n");

        if( (int)me->query_str() < 35 )
                return notify_fail("你的膂力不够强，不能使用「星月」。\n");

        if( arg <= 1 )
                return notify_fail("至少要有两招才可组成「星月」。\n");

        if( (int)me->query("neili", 1) < 1200 )
                return notify_fail("你现在内力太弱，不能使用「星月」。\n");

        if( (int)me->query("neili", 1) < 100 * arg )
                return notify_fail("你现在的内力施展不了那么多招。\n");

        if( (int)me->query_skill("xinyue-gong", 1) < arg * 30 )
                return notify_fail("你的星月功还没有修练到那种境界！\n");
//              return notify_fail("你的星月功还没有修练到那种境界！\n");

        message_vision(HIG"突然星辰漫天，月光生辉，$N身随影行，奔行愈速，左手轻轻一挥"+ chinese_number(arg) +"掌。\n\n"NOR,  
                      me, target);

        limbs = target->query("limbs");
        for(count = 0; count < arg; count++)
        {
          message_vision(
                replace_string(
          SKILL_D("xinyue-gong")->query_action(me, me->query_temp("weapon"))["action"],
                "$l", limbs[random(sizeof(limbs))]) + "！\n\n", me, target);
          damage = damage+250+random(250);
        }    

        damage = (1 + me->query("jiali")/250) * damage;
        if( arg*(random(me->query("combat_exp"))) > target->query("combat_exp") / 3 )
        {
                target->receive_damage("qi", damage);
                target->receive_wound("qi", damage/3);
                COMBAT_D->report_status(target, 1);
                COMBAT_D->report_status(target, 0);
        }

        me->add("neili", -100 * arg);
   me->start_busy(3);

        return 1;
}

