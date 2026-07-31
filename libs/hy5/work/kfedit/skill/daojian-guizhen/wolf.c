// This is player's own perform (Write by Lonely@nt2)
// Create by 胡骸骨(Mount) at Sun Apr  9 19:22:07 2006
// 雪域苍狼(wolf)

#include <ansi.h>
#include <combat.h>

#define PFM "「" HIW "雪域苍狼" NOR "」"

inherit F_SSERVER;


string *weapon_sk = ({
        "sword", "blade", "staff", "whip", "club", "hammer", "axe"
});

int perform(object me, object target)
{
        object weapon;
        string msg;
        int ap, dp;
        int count;
        int i, attack_time;



        if (! target)
        {
                me->clean_up_enemy();
                target = me->select_opponent();
        }

        if (! target || ! me->is_fighting(target))
                return notify_fail(PFM "只能对战斗中的对手使用。\n");

        if (member_array("blade", weapon_sk) != -1)
        {
        if (! objectp(weapon = me->query_temp("weapon"))
           || (string)weapon->query("skill_type") != "sword"
           && (string)weapon->query("skill_type") != "blade" )
                return notify_fail("你所使用的武器不对，难以施展" PFM "。\n");
        } else
        {
                if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                        return notify_fail(PFM "只能空手使用。\n");             
        }
        
        if ((int)me->query_skill("daojian-guizhen", 1) < 400)
                return notify_fail("你" + to_chinese("daojian-guizhen") + "不够娴熟，难以施展" PFM "。\n");

        if (member_array("blade", weapon_sk) == -1)
        {
                if (me->query_skill_prepared("blade") != "daojian-guizhen")
                        return notify_fail("你没有准备" + to_chinese("daojian-guizhen") + "，难以施展" PFM "。\n");
        }
        	if( me->is_busy() )
		return notify_fail("( 你上一个动作还没有完成，不能施用内功。)\n");
        if (me->query("neili") < 300)
                return notify_fail("你现在的真气不够，难以施展" PFM "。\n");

        if (! living(target))
                return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

        msg = HIW "$N手中武器寒气逼人，刀身撕裂空气，片片雪花飘落，竟然凝出「雪域苍狼」四个字！霎时间，四个字散去，变成千百万的碎粒飞射进$n的身体。" + "\n" + NOR;

        ap = me->query_skill("blade",1);
        dp = target->query_skill("parry",1);
        attack_time = 6;

        if (ap * 2 / 3 + random(ap * 2) > dp)
        {
                msg += HIM "只见$n一声惨叫，全身上下给射出数不清的血洞，鲜血汹涌喷出！" + "\n" NOR;
                count = ap / 10;

        } else
        {
                msg += NOR + CYN "$p见势不妙，抽身急退，险险避过$P的这记杀招！" + "\n" NOR;
                count = 0;
        }

        message_combatd(msg, me, target);

        attack_time += me->query("jieti/times") * 2;
        if (attack_time > 12)
                attack_time = 12;

        me->add("neili", -attack_time * 10);
                me->add_temp("apply/attack", count);
                me->add_temp("apply/damage", 1800);
        for (i = 0; i < attack_time; i++)
        {
                if (! me->is_fighting(target))
                        break;

                if (random(2) && ! target->is_busy()) target->start_busy(2);

                COMBAT_D->do_attack(me, target, (member_array("blade", weapon_sk) == -1 ? 0 : weapon), 0);
        }
        me->add_temp("apply/attack", -count);
        me->add_temp("apply/damage", -1800);
        me->start_busy(3 + random(attack_time/ 3));

        return 1;
}

