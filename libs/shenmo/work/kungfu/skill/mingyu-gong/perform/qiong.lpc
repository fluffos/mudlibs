// Copyright (C) 2003, by www.chinesemud.org. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.
// qiong.c 琼楼玉宇

#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;

int perform(object me, object target)
{
        int bonus, hits;
        object weapon;


        if (! target)
        {
                me->clean_up_enemy();
                target = me->select_opponent();
        }

        if (! target || ! me->is_fighting(target))
                return notify_fail("「琼楼玉宇」只能对战斗中的对手使用。\n");

        if ( me->query_temp("weapon"))
                return notify_fail("空手才能施展「琼楼玉宇」。\n");

        if ( me->query("neili") < 400 )
                return notify_fail("你的内力所剩无几，无法施展「琼楼玉宇」。\n");

        if ( me->query("max_neili") < 1000 )
                return notify_fail("你的内力修为不足，无法施展「琼楼玉宇」。\n");

        if ( me->query_skill("mingyu-gong", 1) < 200 )
                return notify_fail("你的明玉神功不够娴熟，不能使用「琼楼玉宇」。\n");

        if ( me->query_skill("unarmed", 1) < 200 )
                return notify_fail("你的基本拳脚不够娴熟，不能使用「琼楼玉宇」。\n");

        if ( me->query("jiali") < 1 )
                return notify_fail("你加力太少，无法使用「琼楼玉宇」。\n");

        if ( me->query_skill_mapped("force") != "mingyu-gong" )
                return notify_fail("你的内功没有使用明玉功，无法使用「琼楼玉宇」绝技。\n");
        if ( me->query_skill_mapped("parry") != "mingyu-gong" )
                return notify_fail("你的招架没有使用明玉功，无法使用「琼楼玉宇」绝技。\n");
        if ( me->query_skill_mapped("unarmed") != "mingyu-gong" )
                return notify_fail("你的拳脚没有使用明玉功，无法使用「琼楼玉宇」绝技。\n");

        if ( me->query_temp("mingyu_pfm/qiong") )
                return notify_fail("你正在使用「琼楼玉宇」。\n");

        if ( me->query_temp("mingyu_pfm/qiong_over") )
                return notify_fail("你刚刚使用过「琼楼玉宇」，此时气血不调，还是等一下再用吧。\n");

        bonus = me->query_skill("mingyu-gong", 1) / 30;
        bonus += me->query_skill("unarmed", 1) /30;
        bonus += me->query_skill("force", 1) /35;

if (bonus>200) bonus=200;
        me->add_temp("apply/attack", bonus);
        me->add_temp("apply/damage", bonus);
        me->add_temp("apply/defense", bonus);
         
         message_combatd(WHT"〖"HIY"琼楼玉宇"WHT"〗\n\n"HIG"只见$N分光劲势再抖，像蛟龙出海，大鹏展翅，
先是一团光芒，光芒蓦然爆开，化作一片光雨，漫天遍地向$n刺来！\n" NOR, me, target);

        me->set_temp("mingyu_pfm/qiong", bonus);
        me->add("neili", -200);

        remove_call_out("check_fight");
        // call_out("check_fight", 1, me, target, bonus);
	 me->start_call_out((: call_other, __FILE__, "remove_effect",
                              me, bonus :), bonus/4);

        return 1;
}

void remove_effect(object me, int bonus)
{
        me->add_temp("apply/attack", -bonus);
        me->add_temp("apply/damage", -bonus);
        me->add_temp("apply/defense", -bonus);
        me->delete_temp("mingyu_pfm/qiong");
        me->set_temp("mingyu_pfm/qiong_over", 1);
        if ( me->is_fighting() )
                me->start_busy(1);

        remove_call_out("qiong_done");
        call_out("qiong_done", 8, me);
}

void qiong_done(object me)
{
        if ( !me )
                return;

        tell_object(me, HIY"经过一段时间的休息，你又可以使用「琼楼玉宇」了！\n"NOR);

        me->delete_temp("mingyu_pfm/qiong_over");
}

void check_fight(object me, object target, int bonus)
{
        if ( !me )
                return;

        if ( !me->is_fighting() || !me->query_temp("mingyu_pfm/qiong") || me->query_temp("mingyu_pfm/qiong") < 1
             || !target || !living(target) )
        {
                message_combatd(WHT"\n$N长舒了一口气，手中的无形劲气也以不似先前一般凌厉了。\n"NOR, me);
                remove_effect(me, bonus);
                return;
        }

        if ( me->query("neili") < 300 )
        {
                message_combatd(HIR"\n$N额头冒汗，看来是内力不随，手上的劲道一下消失不见了。\n"NOR, me);
                remove_effect(me, bonus);
                return;
        }

        if ( me->query_skill_mapped("unarmed") != "mingyu-gong" )
        {
                message_combatd(HIR"\n$N忽然招式一边，手上的劲道顿时消失得无影无踪。\n"NOR, me);
                remove_effect(me, bonus);
                return;
        }

        if ( me->query_temp("weapon") )
        {
                tell_object(me, HIR"\n你装备上兵器，无法继续使用「琼楼玉宇」了。\n"NOR, me);
                remove_effect(me, bonus);
                return;
        }

        remove_call_out("check_fight");
        call_out("check_fight", 1, me, target, bonus);
}


