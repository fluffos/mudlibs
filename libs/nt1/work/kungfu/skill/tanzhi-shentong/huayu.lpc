// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.
// huayu.c 漫天花雨

#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;
#include <balance.h>

int perform(object me, object target)
{
        string msg;
        object weapon;
        int damage, num, lvl, p, ap, dp;

        if (! target) target = offensive_target(me);

        if (! target || ! target->is_character() || ! me->is_fighting(target))
                return notify_fail("漫天花雨只能对战斗中的对手使用。\n");

        if (userp(me) && ! me->query("can_perform/tanzhi-shentong/huayu"))
                return notify_fail("你虽然听说过“漫天花雨”这一招，可是却未获传授。\n");

        lvl = (int)me->query_skill("tanzhi-shentong", 1);
         
        if (lvl < 120) return notify_fail("你的弹指神通不够娴熟，无法使用漫天花雨。\n");

        if (! objectp(weapon = me->query_temp("handing"))
           || (string)weapon->query("skill_type") != "throwing")
                return notify_fail("你手中没有拿着暗器，难以施展漫天花雨。\n");
                 
        if ((num = weapon->query_amount()) < lvl / 20) 
                return notify_fail("你掏了掏背囊，发现里面的暗器已经不够使用漫天花雨的要求了！\n");

        if ((int)me->query("neili") < 450)
                return notify_fail("你的内力不够，无法使用漫天花雨。\n");

        msg = CYN "$N双手在背囊里一抓，抓出" + CHINESE_D->chinese_number(lvl / 20) + 
              weapon->query("base_unit") + weapon->query("name") + 
              "来，\n运用指力漫天地弹了出去，$n只觉眼前似乎在下一场暗器雨！\n";
        
        ap = ap_power(me,"finger");
        dp = dp_power(target,"dodge");
        
        if (ap / 2 + random(ap) > dp) 
        {
                damage = da_power(me, "finger");
                me->add("neili", 350);

                msg += COMBAT_D->do_damage(me, target, WEAPON_ATTACK, damage, 80, 
                                           HIR "$n躲闪不及，“噗噗”地几声，被几道暗器击中！\n顿时鲜血飞溅！\n" NOR);
                me->start_busy(2); 
        } else 
        {
                me->add("neili", -100);
                msg += WHT "$n吓得赶忙抱头团身，万分狼狈地向旁边一滚，方才堪堪地躲了过去。\n" NOR;
                me->start_busy(3); 
        }
        message_combatd(msg, me, target);

        weapon->add_amount(-(lvl/20));
        me->reset_action();

        return 1;
}

