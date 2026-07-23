// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.

#include <ansi.h>
#include <combat.h>
#include "/kungfu/skill/eff_msg.h";

#define HUA "「" HIR "化妖功" NOR "」"

inherit F_SSERVER;


int perform(object me, object target)
{
        object weapon;
        int damage,extra,i;
        string msg;
        int ap, dp, p;
        int lv, cost_neili;


        if (! target)
        {
                me->clean_up_enemy();
                target = me->select_opponent();
        }
        if (! target || ! me->is_fighting(target))
                return notify_fail(HUA "只能对战斗中的对手使用。\n");

        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail(HUA "只能空手施展。\n");

        if ((int)me->query_skill("beiming-shengong", 1) < 220
        &&  (int)me->query_skill("xiaowuxiang", 1) < 220
        &&  (int)me->query_skill("bahuang-gong", 1) < 220)
                return notify_fail("你的北冥神功火候不够，难以施展" HUA "。\n");

        if (lv = (int)me->query_skill("zhemei-shou", 1) < 220)
                return notify_fail("你逍遥折梅手等级不够，难以施展" HUA "。\n");

        if (me->query("max_neili") < 4000)
                return notify_fail("你的内力修为不足，难以施展" HUA "。\n");

        if (me->query("neili") < 800)
                return notify_fail("你现在真气不足，难以施展" HUA "。\n");

        if (! living(target))
                return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

       if ((int)me->query_skill("zhougong-jian", 1) < 150)
               return notify_fail("你的周公剑火候不够。\n");
       if ((int)me->query_skill("wuliang-jian", 1) < 150)
               return notify_fail("你的无量剑法火候不够。\n");   

       if ((int)me->query_skill("pidi-shenzhen", 1) < 150)
               return notify_fail("你的辟地神针火候不够。\n");
       if ((int)me->query_skill("wudoumi-shengong", 1) < 150)
               return notify_fail("你的五斗米神功火候不够。\n");

        msg = HIM "$N" HIM "深深吸进一口气，单手挥出，掌缘顿时霞光万道，漾出"
              "七色虹彩向$n" HIM "席卷而至。\n" NOR;

        ap = me->query_skill("hand") + me->query_skill("dodge");
        dp = target->query_skill("parry") + target->query_skill("dodge");

        if (target->query("shen") < 0 || ! userp(target))
                ap += ap / 10;

        if (ap *2 / 3 + random(ap) > dp)
        {
                damage = 0;
                lv = me->query_skill("zhemei-shou", 1);
                if (lv >= 220)cost_neili = -500;
                if (lv >= 240)cost_neili = -470;
                if (lv >= 260)cost_neili = -440;
                if (lv >= 280)cost_neili = -400;
                if (lv >= 300)cost_neili = -360;
                if (lv >= 320)cost_neili = -320;
                if (lv >= 340)cost_neili = -300;
                if (lv >= 360)cost_neili = -270;
                if (lv >= 400)cost_neili = -200; 
                if (me->query("max_neili") > target->query("max_neili") * 2)
                {
                        msg += HIM "只听$n" HIM "一声尖啸，$N" HIM "的七色掌"
                               "劲已尽数注入$p" HIM "体内，顿时将$p" HIM "化"
                               "为一滩血水。\n" NOR "( $n" RED "受伤过重，已"
                               "经有如风中残烛，随时都可能断气。" NOR ")\n";
                        damage = -1;
                        me->add("neili", cost_neili);
                        me->start_busy(1);
                } else
                {
                        damage = me->query_skill("hand");
                        damage += me->query_temp("apply/unarmed_damage");

                        target->receive_damage("qi", damage*2+200);
                        target->receive_wound("qi", damage*2+200);
                        target->receive_damage("jing", damage / 4);
                        target->receive_wound("jing", damage / 8);
                        p = (int)target->query("qi") * 100 / (int)target->query("max_qi");

                        msg += HIM "$n" HIM "只是微微一愣，$N" HIM "的七色掌劲已破体而"
                               "入，$p" HIM "便犹如身置洪炉一般，连呕数口鲜血。\n" NOR;
                        msg += "( $n" + eff_status_msg(p) + " )\n";
                        
                        me->add("neili", cost_neili);
                        me->start_busy(2);
                }
        } else
        {
                msg += CYN "$p" CYN "见状大惊失色，完全勘破不透$P"
                       CYN "招中奥秘，当即飞身跃起丈许，躲闪开来。\n" NOR;
                me->add("neili", -200);
                me->start_busy(4);
        }
        message_combatd(msg, me, target);

	msg = HIY "$N於咆哮声中纵身而起，一个翻腾後双手化掌为爪扑面而至，势要把$n撕开两半！\n" NOR;
	message_combatd(msg, me, target);
	extra=100;
	extra=100;
	me->add_temp("apply/attack", 100);	
	me->add_temp("apply/damage", 800);
for (i=0; i< 7 ;i++){	
	msg = HIR  "$N双手呈鹰爪状，全身腾空，左右掌穿插翻飞，疾向$n抓去！" NOR;
	COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
}
	me->add_temp("apply/attack", -100);
	me->add_temp("apply/damage", -800);
   msg = HIW "$n面色变得惨白如纸，双手提起，指尖发出莹莹的光芒。 
$n忽然化作一丝飘云般闪到$N面前，双爪电击而下抓向$N心口！ \n"NOR;
        
       
//  give bonus to NPC kill

    if( random((int)me->query("combat_exp"))> (int)target->query("combat_exp")/4) {
        msg += RED"\n\n$N"RED"用不可置信的眼光看着自己心口的血洞，身子一晃，倒在地上。 \n" NOR;
        target->receive_damage("qi",damage*2);
        target->receive_wound("qi",damage);
    }
    else msg += HIC"\n\n$N连忙收招封住$n手腕，在森森爪影下旋身急退，躲开了$n的致命一击。 \n" NOR; 
    message_vision(msg, target, me);
        return 1;
}

