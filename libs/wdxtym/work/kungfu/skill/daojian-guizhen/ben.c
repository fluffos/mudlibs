#include <combat.h>
#include  <ansi.h>

string name() { return HIM "万马奔腾" NOR; }
string query_name() { return "万马"ZJBR"奔腾"; }
string final1(object me, object target, int damage);

inherit F_SSERVER;

int perform(object me, object target)
{
        int damage;
        string msg, type1, type2;
        int ap, dp, lvl;
        object weapon1, weapon2;
        int attack_type;
        mapping prepare;
        int i;
        string* key_pre;

        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail(name() + "只能对战斗中的对手使用。\n");

        if ((int)me->query("max_neili") < 10000)
                return notify_fail("你内力修为不够，难以施展" + name() + "。\n");

        if ((lvl = me->query_skill("daojian-guizhen", 1)) < 200)
                return notify_fail("你刀剑归真修为不足200级，无法施展" + name() + "。\n");

        weapon1 = me->query_temp("weapon");
        weapon2 = me->query_temp("secondary_weapon") || me->query_temp("handing");

        if (! objectp(weapon1) || ! objectp(weapon2))
                return notify_fail("你没有同时装备刀剑，难以施展" + name() + "。\n");

        if (weapon2->query("consistence") <= 0)
                return notify_fail("你的" + weapon2->name() + "已经严重"
                                   "损坏，无法继续使用了。\n");

        type1 = weapon1->query("skill_type");
        type2 = weapon2->query("skill_type");

        if ((type1 != "sword" && type1 != "blade")
           || (type2 != "sword" && type2 != "blade"))
                return notify_fail("你所使用的武器不对，难以施展" + name() + "。\n");

        if ((type1 == "sword" && type2 != "blade")
           || (type1 == "blade" && type2 != "sword"))
                return notify_fail("你没有同时装备刀剑，难以施展" + name() + "。\n");

        if (me->query_skill_mapped("sword") != "daojian-guizhen"
           || me->query_skill_mapped("blade") != "daojian-guizhen")
                return notify_fail("你没有激发刀剑归真，难以施展" + name() + "。\n");

        if (me->query("neili") < 3000)
                return notify_fail("你现在的真气不够，难以施展" + name() + "。\n");
			if( me->query_skill("lengyue-shengong")<500 )
                return notify_fail("你现在的内功不够，难以施展" + name() + "。\n");

        if (! living(target))
                return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

        me->add("neili", -3000);

        ap = me->query_skill("sword", 1) + me->query_skill("blade", 1);
        dp = target->query_skill("dodge", 1) + target->query_skill("parry", 1);

        message_combatd(HIY "$N" HIY "双目微闭，衣裳无风自起，刹那间，杀气充斥 ……\n"
                     HIC "一束刀光，" HIM "一道剑影，" HIY "一招「万马奔腾」毫无征兆地使出，刀光剑气就犹如地\n"
                     "狱幽灵般地呼啸而出，将$n" HIY "笼罩……\n" NOR, me, target);

        if (ap / 2 + random(ap / 2) > dp)
        {
                damage = me->query_skill("sword", 1);
                damage += me->query_skill("blade", 1);
                damage += me->query("jiali");

                message_combatd(HIC "$N" HIC "被两道飞驰而来的强光笼罩着，毫无思考的余地，只得拼死抵抗……\n" NOR, target);

                msg = COMBAT_D->do_damage(me, target, attack_type, damage, 500 + 200 * (userp(me)?0:1),
                                          (: final1, me, target, damage :));
                message_combatd(msg, me, target);
        }
        else
        {
                message_combatd(HIM "$N" HIM "惊骇不已，却硬着头皮施展轻功闪避，竟无意间躲过此招。\n" NOR, target);
        }

        // 20%几率无BUSY
        if (random(5) < 4) me->start_busy(3);
        target->start_busy(3);

        return 1;
}

string final1(object me, object target, int damage)
{
       if (! target->query_temp("daojian_cimu"))
       {
               target->set_temp("block_msg/all", 1);
               target->apply_condition("no_perform", 5);
               target->set_temp("daojian_cimu", 1);
               call_out("cimu_end", 20 + random(31), me, target);
               return HIR "$n" HIR "只觉双目被一阵强光略过，眼前一黑，就什么"
                       "也看不见了，心中无限恐惧。\n" NOR;
        }
        else
                return "";
}

void cimu_end(object me, object target)
{
        if (target && target->query_temp("daojian_cimu"))
        {
                if (living(target))
                {
                        tell_object(target, HIR "忽然间，眼前慢慢明亮了起来，能看见了。\n" NOR);
                }
                target->delete_temp("block_msg/all");
                target->clear_condition("no_perform");
                target->delete_temp("daojian_cimu");
        }
        return;
}
