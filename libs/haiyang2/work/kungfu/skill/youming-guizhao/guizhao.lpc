// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.
// guizhao.c  亡魂鬼爪

#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;


int perform(object me, object target)
{
        int skill, ap, dp, damage;
        string msg, pmsg;
        object weapon;
        int extra,i;
        int p;
        int lv, cost_neili;

        if (! target)
        {
                me->clean_up_enemy();
                target = me->select_opponent();
        }

        if (! target || ! me->is_fighting(target))
                return notify_fail("「亡魂鬼爪」只能在战斗中使用。\n");

        //if ((string)me->query("gender") != "女性")
        //        return notify_fail("你身为男子，难以领会「亡魂鬼爪」其中的奥妙。\n");

        //if ((int)me->query("shen", 1) > 0)
        //        return notify_fail("你是侠义道人士，怎麽能用「亡魂鬼爪」这种阴毒武功。\n");

        if ((int)me->query_skill("youming-guizhao", 1) < 180)
                return notify_fail("你的幽冥鬼爪等级不够，不能使用「亡魂鬼爪」。\n");    

        if ((int)me->query_skill("claw", 1) < 180)
                return notify_fail("你的基本爪法极不够娴熟，不能使用「亡魂鬼爪」。\n");    

        if ((int)me->query_skill("force", 1) < 180)
                return notify_fail("你的基本内功火候不够，强行使用「亡魂鬼爪」会震伤自己的经脉。\n");

        
        if ((int)me->query_skill("xiaowuxiang", 1) < 180
                && (int)me->query_skill("bahuang-gong", 1) < 180
                && (int)me->query_skill("beiming-shengong", 1) < 180)
                return notify_fail("你的逍遥派内功火候不够。\n");

        if (me->query_skill_mapped("force") != "xiaowuxiang"
                && me->query_skill_mapped("force") != "bahuang-gong"
                && me->query_skill_mapped("force") != "beiming-shengong")
                return notify_fail("你没有运用逍遥派内功！\n");	
        

        if ((int)me->query("neili") < 800)
                return notify_fail("你现在真气太弱，不能使用「亡魂鬼爪」。\n");

        if ((int)me->query("max_neili") < 1000)
                return notify_fail("你现在内力太弱，不能使用「亡魂鬼爪」。\n");

        if (me->query_temp("gz_pfmed") == 1)
                return notify_fail("你刚使过这一招，不能聚集足够的元气。\n");

        if (! me->query("jiali"))
                return notify_fail("你爪上带力不足，不能使用「亡魂鬼爪」。\n");

        skill = (int)me->query_skill("youming-guizhao", 1);

        message_combatd(HIB "\n突然$N" HIB "将双掌变爪合于胸前，象风车般急转数圈，而后双爪向外一翻\n"
                        "绕着$n" HIB "疾转数圈，五根手指向着$n顶门直下插落。\n\n" NOR, me, target);

	me->add("neili", -400);
	me->set_temp("gz_pfmed", 1);
	
        call_out("recover", 1800 / skill, me);
	

        ap =  me->query_skill("claw");
        dp =  target->query_skill("dodge");
        
        if (ap / 2 + random(ap) > dp)
        {
                me->add("neili", -100);
                damage =  me->query_skill("claw");
   target->add("qi",-damage*2);
		target->add("eff_qi",-damage*2);
                msg = HIR "$n" HIR "只觉得头顶一阵麻痒，$N"
                       HIR "的手爪已在$n" HIR "头顶留下五个整整齐齐的指洞！\n" NOR;

               // pmsg = HIR "$n" HIR "只觉得头顶一阵麻痒，$N"
               //        HIR "的手爪已在$n" HIR "头顶留下五个整整齐齐的指洞！\n" NOR; 
//                msg = COMBAT_D->do_damage(me, target, UNARMED_ATTACK, damage, 90, pmsg);
                me->start_busy(4);                
	} else
	{
	        msg = CYN "可是$p" CYN"见此招来势凌厉，闪身护头向后闪躲，虽是堪堪避过$P"
	              CYN "的攻击，但已惊出了一身冷汗。\n\n" NOR;
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
	if (random(3)==0) target->start_busy(3);
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

int recover(object me)
{
        if (! me) return 0;
        
        me->delete_temp("gz_pfmed");
        return 1;
}
