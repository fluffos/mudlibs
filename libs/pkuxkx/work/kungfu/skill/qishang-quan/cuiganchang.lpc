// cuiganchang.c 摧肝肠诀

#include <ansi.h>

inherit F_SSERVER;

int perform(object me)
{
        string msg;
        object weapon, target;
        int skill, ap, dp, qi_wound, wound_me;

        me->clean_up_enemy();
        target = me->select_opponent();

        skill = me->query_skill("qishang-quan",1) + me->query_skill("jiuyang-shengong",1);

        if( !me->is_fighting() )
                return notify_fail("「摧肝肠诀」只能在战斗中使用。\n");

        if( (int)me->query("neili") < 700 )
                return notify_fail("你的内力还不够高！\n");

        if( (int)me->query_skill("cuff") < 120 )
                return notify_fail("你的拳法还不到家，无法体现七伤拳的各种总诀！\n");

        if( (int)me->query_skill("qishang-quan", 1) < 90)
                return notify_fail("你七伤拳的修为不够，不能够体会摧肝肠诀! \n");

        if( (int)me->query_skill("jiuyin-shengong", 1) < 120)
                return notify_fail(HIM "你的九阴神功修为不足，不能随便使用摧肝肠诀! \n" NOR);

        if( me->query_skill_mapped("cuff") != "qishang-quan")
                return notify_fail("你没有激发七伤拳，无法运用摧肝肠诀！\n");

        msg = HIY "$N凝神定气，使出七伤拳总诀中的「" HIR "摧肝肠诀" HIY "」，双拳势如雷霆，向$n击去。\n"NOR;
        message_combatd(msg, me, target);

        ap = me->query("combat_exp") + skill * 500;
        dp = target->query("combat_exp");
        if( dp < 1 )
                dp = 1;
        msg = HIY "$N一拳挥出，却感觉自己的肝部一疼。\n" NOR;
        if( F_KUNGFU->hit_rate( ap, dp, 9, me, target) )
        {
                if(userp(me))
                        me->add("neili",-200);
                msg = msg + HIG "$n前胸中了$N全力一击，只觉一阵剧痛，“哇”的一声喷出一口鲜血！\n"NOR;
                qi_wound = 250 + random(skill);
                wound_me = 400 - random(skill);
                if(qi_wound > target->query("qi"))
                        qi_wound = target->query("qi");

                F_KUNGFU->hit_wound("qi", qi_wound, 0, me, target);
                target->add_busy(2);
                me->start_busy(2+random(2));
        }
        else
        {
                msg = msg + HIG "只见$n不慌不忙，轻轻一闪，躲过了$N的必杀一击！\n"NOR;
                if(userp(me))
                        me->add("neili",-100);
                me->start_busy(1);
                wound_me = (int)(200-random(skill)/2);
        }
        message_combatd(msg, me, target);
        COMBAT_D->report_status(target);
        if (wound_me < 10) wound_me=10;
        me->receive_wound("qi",wound_me, "七伤拳反噬");
        COMBAT_D->report_status(me);
        return 1;
}

