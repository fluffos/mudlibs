// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.

#include <ansi.h>
#include <combat.h>

#define HUI "「" HIR "灭龙一击" NOR "」"

inherit F_SSERVER;
void remove_effect(object me, object target, int lvl);
void msg_display(object me, object target, int lvl);

int perform(object me, object target)
{
        int damage;
        string msg;
        int ap, dp,lvl;



        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail(HUI "只能对战斗中的对手使用。\n");

        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail(HUI "只能空手使用。\n");

        if ((int)me->query_skill("force") < 260)
                return notify_fail("你内功修为不够，难以施展" HUI "。\n");

        if ((int)me->query("max_neili") < 5000)
                return notify_fail("你内力修为不够，难以施展" HUI "。\n");

        if ((int)me->query_skill("xianglong-zhang", 1) < 300)
                return notify_fail("你降龙十八掌火候不够，难以施展" HUI "。\n");

        if (me->query_skill_mapped("strike") != "xianglong-zhang")
                return notify_fail("你没有激发降龙十八掌，难以施展" HUI "。\n");

if ((int)me->query_skill("huntian-qigong",1) < 120)
                return notify_fail("你的混天气功修为不够。\n");
       if (((int)me->query_skill("liuhe-zhang", 1)) < 150)
               return notify_fail("你的六合掌法太低了。\n");
       if (((int)me->query_skill("fengmo-zhang", 1)) < 150)
               return notify_fail("你的疯魔杖法太低了。\n");
       if (((int)me->query_skill("xiaoyaoyou", 1)) < 150)
               return notify_fail("你的逍遥游太低了。\n");
       if (((int)me->query_skill("dagou-bang", 1)) < 150)
               return notify_fail("你的打狗棒太低了。\n");
       if (((int)me->query_skill("chansi-shou", 1)) < 150)
               return notify_fail("你的锁喉功太低了。\n");
       if (((int)me->query_skill("suohou-gong", 1)) < 150)
               return notify_fail("你的缠丝擒拿手太低了。\n");

        if ((int)me->query("neili") < 1000)
                return notify_fail("你现在真气不够，难以施展" HUI "。\n");

        if (! living(target))
                return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

        // 第一掌
        ap = me->query_skill("strike") + me->query("str") * 10;
        dp = target->query_skill("dodge") + target->query("dex") * 10;
        
        message_vision(HIW "\n忽然间$N" HIW "身形激进，左手一划，右手呼的一掌，便"
                     "向$n" HIW "击去，正是降龙十八掌「" NOR + HIY "亢龙有悔" NOR
                     + HIW "」一招，力自掌生之际说到便到，以排山倒海之势向$n" HIW
                     "狂涌而去，当真石破天惊，威力无比。\n" NOR, me, target);
        if (ap * 3 / 5 + random(ap) > dp)
        {
                damage = me->query_skill("strike");
target->add("qi",-damage*2);
target->add("eff_qi",-damage);
                       msg =HIR "$p" HIR "一楞，只见$P" HIR "身形"
                                          "一闪，已晃至自己跟前，躲闪不及，被击"
                                          "个正中。\n" NOR;

                message_vision(msg, me, target);

        } else
        {
                msg = HIC "$p" HIC "气贯双臂，凝神应对，游刃有余，$P"
                      HIC "掌力如泥牛入海，尽数卸去。\n" NOR;
                message_vision(msg, me, target);
        }

        // 第二掌
        ap = me->query_skill("strike") + me->query("str") * 10;
        dp = target->query_skill("parry") + target->query("int") * 10;

        message_vision(HIW "\n$N" HIW "一掌既出，身子已然抢到离$n" HIW "三四丈之外"
                     "，后掌推前掌，两股掌力道合并，又是一招「" NOR + HIY "亢龙有"
                     "悔" NOR + HIW "」攻出，掌力犹如怒潮狂涌，势不可当。霎时$n"
                     HIW "便觉气息窒滞，立足不稳。\n" NOR, me, target);
        if (ap * 3 / 5 + random(ap) > dp)
        {
                damage = me->query_skill("strike");
target->add("qi",-damage*2);
target->add("eff_qi",-damage);

                        msg =HIR "只听$p" HIR "一声惨嚎，被$P" HIR
                                           "一掌击中胸前，“喀嚓喀嚓”断了几根肋"
                                           "骨。\n" NOR;

                message_vision(msg, me, target);
        } else
        {
                msg = HIC "$p" HIC "气贯双臂，凝神应对，游刃有余，$P"
                      HIC "掌力如泥牛入海，尽数卸去。\n" NOR;
                message_vision(msg, me, target);
        }

        // 第三掌
        ap = me->query_skill("strike") + me->query("str") * 10;
        dp = target->query_skill("force") + target->query("con") * 10;

        message_vision(HIW "\n紧跟着$N" HIW "一声暴喝，右掌斜斜挥出，前招掌力未消"
                     "，此招掌力又到，竟然又攻出一招「" NOR + HIY "亢龙有悔" NOR
                     + HIW "」，掌夹风势，势如破竹，便如一堵无形气墙，向前疾冲而"
                     "去。$n" HIW "只觉气血翻涌，气息沉浊。\n" NOR, me, target);

        if (ap * 3 / 5 + random(ap) > dp)
        {
                damage = me->query_skill("force");
target->add("qi",-damage*2);
target->add("eff_qi",-damage);

                        msg =HIR "结果$p" HIR "躲闪不及，$P" HIR
                                           "的掌劲顿时穿胸而过，“哇”的喷出一大"
                                           "口鲜血。\n" NOR;


                message_vision(msg, me, target);
                me->start_busy(5);
                me->add("neili", -500);
               // return 1;
        } else
        {
                msg = HIC "$p" HIC "见这招来势凶猛，身形疾退，瞬间飘出三"
                      "丈，脱出$P" HIC "掌力之外。\n" NOR;
                message_vision(msg, me, target);
                me->start_busy(5);
                me->add("neili", -500);
                //return 1;
        }
        //message_combatd(msg, me, target);

        me->set_temp("xianglong",1);
        message_vision(HIR "$N气聚丹田，双掌自外向里转了个圆圈，缓缓的凝聚全身功力。\n\n" NOR, me,target);

        lvl = (int)(lvl / 5);

        me->add_temp("apply/dodge", 100);


        call_out("msg_display",3,me,target,lvl);
        
        return 1;
}




void msg_display(object me, object target, int lvl)
{
        string *circle, msg;
        object weapon;
        int ap,dp;
        if (!me) return;
        
        if (!target ||
            !target->is_character() ||
            !me->is_fighting(target) ||
            !living(me))
        {
                me->delete_temp("xianglong");
                me->add_temp("apply/dodge",-100);
                return;
        }
        if ( objectp(weapon = target->query_temp("weapon")))
{
       msg = HIR "$N" HIR "暴喝一声，全身内劲迸发，气贯右臂奋力外扯，企图将$n"
              HIR "的" + weapon->name() + HIR "吸入掌中。\n" NOR;

        ap = me->query_skill("strike") + me->query("str") * 10;
        dp = target->query_skill("parry") + target->query("int") * 10;

        if (ap / 3 + random(ap) > dp)
        {
                me->add("neili", -300);
                msg += HIR "$n" HIR "只觉周围气流涌动，手中" + weapon->name()
                       + HIR "竟然拿捏不住，向$N" HIR "掌心脱手飞去。\n" NOR;
                me->start_busy(2);
                weapon->move(environment(target));
        } else
        {
                me->add("neili", -200);
                msg += CYN "$n" CYN "只觉周围气流涌动，慌忙中连将手中"
                       + weapon->name() + CYN "挥舞得密不透风，使得$N"
                       CYN "无从下手。\n" NOR;
                me->start_busy(3);
        }
        message_combatd(msg, me, target);
 }      
        circle = ({
                YEL"$N突然大喝一声，双掌齐出，向$p当胸猛击过去。\n"NOR,
                HIG"$N大步迈出，左手一划，右手呼的一掌，猛向$p击去。\n"NOR
        });

        msg = HIG"\n"+ circle[random(sizeof(circle))] +"\n" NOR;

        circle = ({
                HIC"掌力未到，$p已感胸口呼吸不畅，顷刻之间，$N的掌力如怒潮般汹涌而至。"NOR,
                HIM"只一瞬之间，$p便觉气息窒滞，$N掌力竟如怒潮狂涌，势不可当，又如是一堵无形的高墙，向$p身前疾冲。"NOR
        });

        msg += HIG"\n"+ circle[random(sizeof(circle))] +"\n" NOR;

        if( target
            &&  target->is_character()
            &&  me->is_fighting(target) ) {
                message_vision(msg, me, target);
                call_out("remove_effect",2,me,target,lvl);
        } else {
                me->delete_temp("xianglong");
                me->add_temp("apply/dodge",-100);
        }
        return 0;
}

void remove_effect(object me, object target, int lvl)
{
        int jiali, jianu, ap, dp, pp,dmg,damage;
        object weapon;
        string *limbs, limb, result, str, type;
string msg;
        if (!me) return;
        
        if (!target ||
            !target->is_character() ||
            !me->is_fighting(target) ||
            !living(me))
        {
                me->delete_temp("xianglong");
                me->add_temp("apply/dodge",-100);
                return;
        }

        weapon=target->query_temp("weapon");
        jiali = me->query("jiali");
        jianu = me->query("jianu")*5;
        ap = me->query_skill("strike");
        ap += (jiali + jianu)/4;
        ap *= 2;
        if (living(target))
        {
            pp = target->query_skill("parry");
            dp = target->query_skill("dodge");
        }  else
        {
            pp = 0;
            dp = 0;
        }
        type = "内伤";
        
        if( target
        &&      target->is_character()
        &&      me->is_fighting(target) ) {
        
        if (wizardp(me))
                printf("ap = %d , pp = %d , dp = %d , me->query_temp(apply/parry) = %d , lvl = %d .\n",ap,pp,dp,me->query_temp("apply/parry"),lvl);

        if( ap/2 + random(ap) > dp + pp ) {
            message_vision(HIM"$N的双掌已跟着击到，砰的一声呼，重重打中$p胸口，跟着喀喇喇几声，肋骨断了几根。\n"NOR, me, target);
            dmg = ap;
            dmg += jiali + jianu*5;
            dmg += random(dmg/2);
dmg=dmg+me->query_skill("strike")+100;
        if (wizardp(me))
                printf("damage = %d\n",dmg);
           

            target->receive_damage("qi", dmg);
            target->receive_wound("qi", dmg+random(dmg/2));
            target->start_busy(1+random(2));
        
            //me->add("neili", -dmg/3);
            //me->add("jing", -dmg/6);

            limbs = target->query("limbs");

            result = COMBAT_D->damage_msg(dmg, type);
            result = replace_string( result, "$l", limbs[random(sizeof(limbs))]);
            result = replace_string( result, "$p", target->name() );
            message_vision(result, me, target);

            str = COMBAT_D->status_msg((int)target->query("qi") * 100 /(int)target->query("max_qi"));
            message_vision("($N"+str+")\n", target);
        } else {
            if ( objectp(weapon) )
            {
                message_vision(HIC "$n大惊之下，$p连划三个半圆护住身前，同时足尖着力，飘身后退，避开了$N的一掌。\n" NOR, me, target, weapon);
            }
            else {
                message_vision(HIC "$n大惊之下，双掌连划三个半圆护住身前，同时足尖着力，飘身后退，避开了$N的一掌。\n" NOR, me, target);
            }
        }
        }
        me->start_busy(3);
        me->delete_temp("xianglong");
        me->add_temp("apply/dodge",-100);
        msg = WHT "$N" WHT "施出降龙十八掌之「" HIW "排山倒海" NOR +
              WHT "」，全身真气鼓动，双掌如排山倒海般压向$n" WHT "。\n"NOR;  
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);      
        msg = HIY "$N" HIY "深吸一口气，跨前一步，双掌猛然翻滚，"
              "缤纷而出，宛如一条神龙攀蜒于九天之上！\n\n" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);  
        
                msg = HIC "$N" HIC "默运内功，施展出" HIY "雷霆一击" NOR "，全身急速转动起来，"
              "越来越快，就\n犹如一股旋风，骤然间，$N" HIC "已卷向正看"
              "得发呆的" HIC "$n。\n"NOR;  
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);  

        msg = YEL  "$N脚下一转，突然欺到$n身前，一式「龙战于野」直拍向$n面门" NOR;
             	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIW "$N突然飞起，双掌居高临下最后一式「龙啸九天」全力拍向$n！" NOR;
          COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        return 0;
}
