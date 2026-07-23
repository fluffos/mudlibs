#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;

int perform(object me, object target)
{
        object weapon;
        int damage;
        int ap, dp;
        string msg;

        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail("「火麒蚀月」只能对战斗中的对手使用。\n");

        if (! objectp(weapon = me->query_temp("weapon")) ||
            (string)weapon->query("skill_type") != "blade")
                return notify_fail("你使用的武器不对。\n");

        if ((int)me->query_skill("ranmu-daofa", 1) < 180)
                return notify_fail("你的燃木刀法不够娴熟，不能使用火麒蚀月。\n");

        if ((int)me->query_skill("force") < 150)
                return notify_fail("你的内功火候不够，不能使用火麒蚀月。\n");

        if ((int)me->query("max_neili") < 2000 )
                return notify_fail("你的内力修为太弱，不能使用火麒蚀月。\n");

        if ((int)me->query("neili") < 500 )
                return notify_fail("你现在内力太弱，不能使用火麒蚀月。\n");

        if (me->query_skill_mapped("blade") != "ranmu-daofa")
                return notify_fail("你没有激发燃木刀法，不能施展火麒蚀月。\n");

        if( (int)me->query_skill("yijinjing", 1) < 120 )
                return notify_fail("你的易筋经等级不够，使不出「火麒蚀月」绝技。\n");

        if( (int)me->query_int() < 26)
                return notify_fail("没有大智慧大般若，是使不出「火麒蚀月」绝技的。\n");
 
        if ( me->query_skill_mapped("force") != "yijinjing")
                return notify_fail("没有易筋经作为根基，是无法使出「焚我」绝技的！\n"); 


        msg = HIR "只见$N" HIR "手中" + weapon->name() + HIR "一抖，刀身登时腾起"
                        "滔天烈焰，如浴火麒麟一般席卷$n" HIR "全身！\n"NOR;

        me->start_busy(2 + random(2));
        ap = me->query_skill("ranmu-daofa", 1) + me->query_skill("force");
        dp = target->query_skill("force");

        if (ap / 4 + random(ap) > dp)
        {
                target->start_busy(1);
                damage = ap / 3 + random(ap / 4);
                me->add("neili", -400);


	 COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIR "滔天烈焰，天火燎原！\n"NOR;
	 COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	msg = HIR "滔天烈焰，烈焰焚心！\n"NOR;
	 COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	msg = HIR "滔天烈焰，烈火腾云！\n"NOR;
	 COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIR "滔天烈焰，烈火烧身！\n"NOR;
	 COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	msg += RED "只闻一股焦臭从$n" RED "处传来，已被"
                                           "$P" RED "这精深奥妙的一"
                                           "刀击中，鲜血飞溅而出！\n"NOR;     
target->add("qi",-damage*2);
target->add("eff_qi",-damage);

        } else
        {
                msg += CYN "$p" CYN "见$P" CYN "来势汹汹，不敢抵挡，急忙斜跃避开。\n"NOR;
                me->add("neili", -200);
                      me->start_busy(2);
        }
        message_combatd(msg, me, target);

        return 1;
}

