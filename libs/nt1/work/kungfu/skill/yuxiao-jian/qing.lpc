// qing.c 天地情长

#include <ansi.h>

inherit F_SSERVER;

int perform(object me)
{
        string msg;
        object weapon, target;
        int skill, ap, dp;
        int cost;

        if (! me->query("can_perform/yuxiao-jian/qing"))
                return notify_fail("你还不会使用「天地情长」这一绝技。\n");

        if (! target)
        {
	        me->clean_up_enemy();
	        target = me->select_opponent();
        }

	if (! target || ! me->is_fighting(target))
                return notify_fail("「天地情长」只能对战斗中的对手使用。\n");

        if (! objectp(weapon = me->query_temp("weapon")) ||
            (string)weapon->query("skill_type") != "sword")
                return notify_fail("你使用的武器不对。\n");

        if (target->query("neili") < 300)
                return notify_fail("看上去对方真气现在并不充沛，你无需运用「天地情长」。\n");

        skill = me->query_skill("yuxiao-jian",1);

        if (skill < 120)
                return notify_fail("你的玉箫剑法等级不够, 不能使用「天地情长」！\n");

        if (me->query("neili") < 1000)
                return notify_fail("你的真气不够，难以运用「天地情长」！\n");

        msg = HIC "$N" HIC "手中的" + weapon->name() +
              HIC "倏的刺出，卷起一阵阵气旋，不住的往里收缩。\n" NOR;
        message_combatd(msg, me, target);

        ap = me->query_skill("sword") + me->query_skill("force") +
             me->query_skill("chuixiao-jiafa", 1);
        dp = target->query_skill("force") * 2;
        if (ap > dp && ap / 2 + random(ap) > dp)
        {
                me->add("neili", -500);
                msg = HIM "$p" HIM "觉得$P" HIM "的内力隐藏在一个个气旋"
                      "中，难以捉摸去处，只能强运内力抵消。\n" NOR;
                cost = 500 + (ap - dp) * 3 / 2;
                if (cost > target->query("neili"))
                        cost = target->query("neili");
                target->add("neili", -cost);
                me->start_busy(1 + random(3));
        } else
        {
                me->add("neili", -120);
                msg = HIG "可是$p" HIG "心神安定，没有收到半天困惑。\n"NOR;
                me->start_busy(2);
        }
        message_combatd(msg, me, target);
        return 1;
}
