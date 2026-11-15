// chan.c 天魔缠身



inherit F_SSERVER;
string query_name() { return "天魔缠身"; }
int perform(object me, object target)
{
        object weapon;
        int level, b;
        string msg;

        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail("「天魔缠身」只能对战斗中的对手使用。\n");

        if (! objectp(weapon = me->query_temp("weapon")) ||
            (string)weapon->query("skill_type") != "sword")
                return notify_fail("你使用的武器不对。\n");

        if (target->is_busy())
                return notify_fail(target->name() + "目前正自顾不暇，放胆攻击吧！\n");

        if (!living(target))
                return notify_fail("对方已经不能战斗了！\n");

        if (userp(me) && (level = me->query_skill("tianmo-jian", 1)) < 120)
                return notify_fail("你的天魔剑法不够娴熟，不会使用「天魔缠身」。\n");

        if (me->query("neili") < 80)
                return notify_fail("你现在真气不够，无法使用「天魔缠身」。\n");

        msg = HIM "$N" HIM "使出天魔剑法「天魔缠身」，默运口诀，将手中"
              + weapon->name() + HIM "一抖，立时发出一阵摄人心魂的声音。\n" NOR;

        me->add("neili", -60);
        if (random(level) > (int)target->query_skill("parry", 1) / 2)
        {
                msg += HIR "结果$p" HIR "顿觉神智不定，心燥意乱，"
                       "全然不知身在何处，呆立当场！\n" NOR;
                b = level / 20;
                if (b > 8)   b = 8;
                target->start_busy(b);
                me->start_busy(1);
        } else
        {
                msg += CYN "可是$p" CYN "看破了$P" CYN "的企图，连忙"
                       "运功将心神护住。\n" NOR;
                me->start_busy(2);
        }
        message_combatd(msg, me, target);
        return 1;
}

