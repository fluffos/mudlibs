#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;

#define JIU "「" HIW "剑荡九霄" NOR "」"

string query_name() { return "剑荡"ZJBR"九霄"; }

void remove_effect(object me, int amount);

int perform(object me, object target)
{
        string msg;
        int count;
        int lvl, damage;
        int i, ap, dp;

        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail(JIU "只能对战斗中的对手使用。\n");

        if ((int)me->query("neili") < 5000)
                return notify_fail("你的真气不够，无法施展" JIU "！\n");

        if (me->query("max_neili") < 5000)
                return notify_fail("你的最大内力还不足以使出" JIU "。\n");
			
        if ((int)me->query("qi") < 1000)
                return notify_fail("你的气血不够，无法施展" JIU "！\n");

        if (me->query("max_qi") < 1000)
                return notify_fail("你的最大气血还不足以使出" JIU "。\n");			

        if ((int)me->query_skill("force") < 600)
                return notify_fail("你的内功火候不够，难以施展" JIU "！\n");

        if ((int)me->query_skill("sword") < 600)
                return notify_fail("你的剑法火候不够，难以施展" JIU "！\n");

        if ((lvl = (int)me->query_skill("wushang-jianjing", 1)) < 600)
                return notify_fail("你的无上剑经还不够熟练，无法使用" JIU "！\n");

        if (! living(target))
                return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

        message_sort(HIM "\n$N" HIM "运起无上剑经，天地间万物仿佛皆化作剑刃，"
                     HIM "正是无上剑修绝学" JIU HIM "！\n" NOR, me, target);

        ap = me->query_skill("sword") * 3 + me->query_skill("wushang-jianjing", 1) + me->query_skill("sword-cognize", 1);
        dp = target->query_skill("dodge") + target->query_skill("sword-cognize");

        for (i = 0; i < 9; i++)
        {
                if (! me->is_fighting(target))
                        break;

                message_sort(HIW "\n$N" HIW "身若游龙，挟风雷之力，从空中向$n"
                             HIW "猛扑下来！\n" NOR, me, target);

                if (ap * 8 / 2 + random(ap) > dp)
                {
                        damage = me->query_skill("sword") * 17 ;
                        if (me->query_temp("weapon"))
                        {
                                msg = COMBAT_D->do_damage(me, target, WEAPON_ATTACK, damage, (i + 1) * 7,
                                                          HIR "结果$n" HIR "躲闪不及，$N" HIR
                                                          "的剑气已破体而入，$n喉头一甜，喷出一大"
                                                          "口鲜血。\n" NOR);
                        } else
                        {
                                msg = COMBAT_D->do_damage(me, target, UNARMED_ATTACK, damage, (i + 1) * 7,
                                                          HIR "结果$n" HIR "躲闪不及，$N" HIR
                                                          "的剑气已破体而入，$n喉头一甜，喷出一大"
                                                          "口鲜血。\n" NOR);
                        }
                } else
                {
                        msg = CYN "$n" CYN "气凝双臂，奋力招架，将"
                              "$N" CYN "的内劲卸掉。\n" NOR;
                }

                message_sort(msg, me, target);

                if (random(2) == 1 && ! target->is_busy())
                        target->start_busy(1);
        }

        me->start_busy(6 + random(1));
        me->add("neili", -4500 - random(500));
        me->add("qi", -500 - random(500));
        return 1;
}


