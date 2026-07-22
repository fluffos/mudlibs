// fugu.c 金蛇游身掌-附骨缠身

#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>

inherit F_SSERVER;
int perform(object me, object target)
{
        object weapon;
        int damage;
        string msg;

        if( !target ) target = offensive_target(me);

        if( !target || !target->is_character() || !me->is_fighting(target) )
                return notify_fail("附骨缠身只能对战斗中的对手使用。\n");

        if( me->query_temp("weapon"))
                return notify_fail("你不是空手，不能使用附骨缠身。\n");

        if( (int)me->query_skill("jinshe-zhang", 1) < 100 )
                return notify_fail("你的金蛇掌不够娴熟，不会使用附骨缠身。\n");

        if( (int)me->query("neili", 1) < 300 )
                return notify_fail("你现在内力太弱，不能使用附骨缠身。\n");

        msg = YEL "$N大喝一声，缠身而上左手一探刁住$n手腕，右掌猛下杀手！"NOR;
              COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = YEL  "只见$N左手不停，如一条毒蛇串向$n！" NOR;
               COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = YEL  "$N脸目狰狞，略显痴呆，一招[引蛇出动]双掌疯狂地打向$n！" NOR;
               COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	me->start_busy(4);
        return 1;
}
