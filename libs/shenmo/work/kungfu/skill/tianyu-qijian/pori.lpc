// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.
// pori.c 九弧破日

#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;

int perform(object me, object target)
{
        object weapon;
        int damage, p, i, wadd, at, df;
        string msg;

        weapon = me->query_temp("weapon");

                
        if ( ! target )
        {
                me->clean_up_enemy();
                target = me->select_opponent();
        }

        if ( ! target || ! me->is_fighting(target) )
                return notify_fail("「九弧破日」只能对战斗中的对手使用。\n");

        if ( !weapon || weapon->query("skill_type") != "sword" )
                return notify_fail("你手里没有剑，无法使用「九弧破日」绝技！\n");

        if ( me->query_skill_mapped("sword") != "tianyu-qijian"
                || me->query_skill_mapped("parry") != "tianyu-qijian" )
                return notify_fail("你没有用天羽奇剑，怎么施展「九弧破日」绝技？\n");

        //if ( weapon->query("unique", 1) )
        //        return notify_fail("你手中乃是一柄宝剑，无法用内力震碎！\n");

        if ( me->query_skill("tianyu-qijian", 1) < 160 )
                return notify_fail("你的天羽奇剑火候不足，使不出「九弧破日」绝技。\n");

        if ( me->query_skill("sword", 1) < 140 )
                return notify_fail("你的基本剑法还不够娴熟，使不出「九弧破日」绝技。\n");
       if ((int)me->query_skill("zhougong-jian", 1) < 50)
               return notify_fail("你的周公剑火候不够。\n");
       if ((int)me->query_skill("wuliang-jian", 1) < 50)
               return notify_fail("你的无量剑法火候不够。\n");   

       if ((int)me->query_skill("pidi-shenzhen", 1) < 50)
               return notify_fail("你的辟地神针火候不够。\n");
       if ((int)me->query_skill("wudoumi-shengong", 1) < 50)
               return notify_fail("你的五斗米神功火候不够。\n");
        if ( me->query("09g/ring") == "li" )
        {
                if ( me->query_skill("xiaowuxiang", 1) < 140 )
                        return notify_fail("你的小无相功修为不足，使不出「九弧破日」绝技。\n");
                if ( me->query_skill_mapped("force") != "bahuang-gong" )
                        return notify_fail("你没有使用小无相功，无法使用「九弧破日」绝技。\n");
        }

        else
        {
                if ( me->query_skill("bahuang-gong", 1) < 140 )
                        return notify_fail("你的八荒六合惟我独尊功修为不足，使不出「九弧破日」绝技。\n");
                if ( me->query_skill_mapped("force") != "bahuang-gong" )
                        return notify_fail("你没有使用八荒六合惟我独尊功，无法使用「九弧破日」绝技。\n");
        }

        if ( me->query_str() < 28 )
                return notify_fail("你的膂力还不够强劲，使不出「九弧破日」绝技。\n");

        if ( me->query_dex() < 30 )
                return notify_fail("你的身法还不够轻灵，无法施展「九弧破日」绝技。\n");
 
        if ( me->query("max_neili") < 2000 )
                return notify_fail("你的内力修为不足，无法使用「九弧破日」绝技。\n");

        if ( me->query("neili") < 1000 )
                return notify_fail("你的内力不够，无法震碎手中长剑。\n");


        msg = HIY"\n$N手腕一抖，手中"+weapon->name()+HIY"射出数道剑气，化为无数星光如雨点般激射向$n！\n"NOR;      

        //Damage is also decided by how many times the player used this perform
        i = me->query("09g/pori");

        if ( i > me->query_skill("tianyu-qijian") )
                i = me->query_skill("tianyu-qijian");

        i -= me->query("age");


        //Damage Target
        if ( (at=random(me->query("combat_exp"))) > (df=target->query("combat_exp")/3) )
        {                
                me->start_busy(1);
                target->start_busy(1);
                me->add("neili", -300);
                damage = me->query_skill("tianyu-qijian", 1)+me->query_skill("sword", 1)+
                        random(me->query_skill("sword", 1))+me->query_skill("bahuang-gong", 1)-
                        random(target->query_skill("parry", 1));
                damage = damage*2+i*2;

                //Damage is also decided by how strong the weapon is
                wadd = (weapon->query("weapon_prop/damage")+1);
                damage = damage+(random(wadd)+wadd)*2;

                if ( me->query("neili") > target->query("neili")*2 )
                        damage += random(damage);

                if ( damage > 2000 )
                        damage = damage+random(me->query_skill("sword", 1));

                if ( damage < 200 )
                        damage = damage-random(target->query_skill("dodge", 1)/2);

                target->receive_damage("qi", damage);
                target->receive_wound("qi", damage/2);

                msg += HIR"\n结果$N手中射出的"+weapon->name()+
                       HIR"剑气尽数钉在了$n身上，一屡屡鲜血从伤口处涌出！\n"NOR;

                p = target->query("qi")*100/target->query("max_qi");
                msg = replace_string(msg, "$w", "剑气");
                msg = replace_string(msg, "$l", "周身多处");

                if ( me->query_skill("tianyu-qijian", 1) > 140
                && me->query_skill("sword") > 140 )
                        call_out("perform2", 0, me, target);
        }

        else
        {
                me->add("neili", -100);
        
                me->start_busy(3);
                msg += HIC"\n$n眼见"+weapon->name()+
                       HIC"剑气已射至眼前，只得铤而走险，运劲鼓起袍袖将剑气拨了开！\n"NOR;
        }

        message_combatd(msg, me, target);

        //weapon->unequip();
        //weapon->move(environment(me));
        //weapon->set("name", "碎裂的" + weapon->query("name"));
        //weapon->set("value", 1);
        //weapon->set("weapon_prop", 0);
        me->reset_action();
        me->add("09g/pfm_pori", 1);

        return 1;
}

//If possible, also busy target
int perform2(object me, object target)
{
        string msg;

        if ( !me || !target || !living(target) )
                return 0;

        msg = MAG "\n不料，$N射出的剑气竟运上了阴柔内力，钉向了$n的周身要穴！\n\n"NOR;

        if ( me->query("max_neili") > target->query("max_neili")*2/3 && random(3) ==0 )
        {
                msg += HIR "结果$n只觉伤处气血闭塞，真气已经无法流转，登时倒抽一口冷气！\n" NOR;
                me->start_busy(3);
                target->start_busy(me->query_skill("force",1)/50+1);
                me->add("neili", -(me->query_skill("force",1)/5));
        }

        else
        {
                me->add("neili", -10);
                target->add("neili", -10);
                me->start_busy(3);
                msg += HIC "\n$p只觉剑气上运有阴柔内力，意欲打穴封脉。幸而早有准备，没有上当。\n" NOR;
        }

        message_combatd(msg, me, target);

        return 1;
}

int help(object me)
{
        write(WHT"\n「九弧破日」\n\n"CYN+
                 " 　　这一式九弧破日乃是天羽奇剑的厉害招式，系以深厚内功使用自己的\n"+
                 " 兵器，并以满天花雨的手法发出剑气，实是厉害不过。然而，此招需有深\n"+
                 " 厚内功作基础，并需相当的剑法造诣才能得以施展。也正因手上劲道不好\n"+
                 " 掌握，因此这一招的威力及命中率需靠"HIY"经常地使用"CYN"来提高，招式的威力与\n"+
                 " 所使用的武器质量也有很大关系。不仅如此，当剑法的造诣达到一定境界\n"+
                 " 之时还会出现"HIG"附加功效"CYN"。\n\n"+

              WHT" 要求：八荒六合唯我独尊功　"HIR"140"WHT" 级\n"+
              WHT" 　　　小无相功          　"HIR"140"WHT" 级\n"+
              WHT" 　　　天羽奇剑  　　　　　"HIR"160"WHT" 级\n"+
              WHT" 　　　基本剑法　　　　　　"HIR"140"WHT" 级\n"+
              WHT" 　　　缥缈心法  　　　　　"HIR" 80"WHT" 级\n"+
              WHT" 　　　后天膂力  　　　　  "HIR" 28"WHT" 点\n"+
              WHT" 　　　后天身法  　　　　  "HIR" 30"WHT" 点\n"+
              WHT" 　　　当前精力  　　　　 "HIR" 200"WHT" 点\n"+
              WHT" 　　　当前内力  　　　　 "HIR"1000"WHT" 点\n"+
              WHT" 　　　最大内力　　　　　 "HIR"2000"WHT" 点\n\n"+
                
              WHT" 战斗中使用。\n"NOR);

        return 1;
}
