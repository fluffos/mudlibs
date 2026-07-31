// tian.c 天旋地转

#include <ansi.h>

inherit F_SSERVER;
string query_name() { return "天旋"ZJBR"地转"; }
int perform(object me, object target)
{
        string msg;
        object weapon;
        int i;
        int skill;
        int count;

        if (! target)
        {
                me->clean_up_enemy();
                target = me->select_opponent();
        }

        if (userp(me) && !me->query("can_perform/tianmo-gun/tian"))
                return notify_fail("你还不会使用「天旋地转」这招。\n");

        if (! objectp(weapon = me->query_temp("weapon")) ||
           (string)weapon->query("skill_type") != "club")
                return notify_fail("你使用的武器不对！\n");

        if (! me->is_fighting(target))
                return notify_fail("「天旋地转」只能对战斗中的对手使用。\n");

        skill = me->query_skill("tianmo-gun", 1);

        if (userp(me) && skill < 100)
                return notify_fail("你的天魔棍修为太低，现在不能使用「天旋地转」！\n");

        if (me->query("neili") < 150)
                return notify_fail("你的真气不够，无法使出「天旋地转」！\n");

        msg = HIR "$N" HIR "默运真元，手中" + weapon->name() +
              HIR "斜起而上，携漫天尘土像一条灵蛇般向$n"
              HIR "迅速点出。\n" NOR;

        message_combatd(msg, me, target);
        count = skill / 3;
        me->add_temp("apply/attack", count);
        me->add_temp("apply/damage", count/2);

        for (i = 0; i < 5; i++)
        {
                if (! me->is_fighting(target))  break;
                COMBAT_D->do_attack(me, target, weapon, 0);
        }

        me->start_busy(2 + random(3));
        me->add_temp("apply/attack", -count);
        me->add_temp("apply/damage", -count/2);
        me->add("neili", -150);
        
        return 1;
}

