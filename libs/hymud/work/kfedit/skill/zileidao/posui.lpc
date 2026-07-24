//posui.c 破碎虚空
#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;
int perform(object me, object target)
{
        string msg;
        int damage, ap, dp;
        object weapon;
                int extra;
        object weapon1;
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
 return notify_fail("你要对谁施展「破碎虚空」？\n");
    


 if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("只能在战斗中使用。\n");

 if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "blade")
        return notify_fail(RED"开什么玩笑，武器不对？\n"NOR);

        if ( !wizardp(me) && me->query_skill_mapped("force") != "lengyue-shengong")
                return notify_fail("请使用冷月神功!\n");

        if((int)me->query_skill("lengyue-shengong",1) < 200)
                return notify_fail("你的冷月神功还不够。。。\n"); 
        if((int)me->query("neili") < 500 )
                return notify_fail(WHT"你的内力不足。\n"NOR);

            if(me->query("max_neili") < 1000 || me->query("neili")<500)
   return notify_fail("内力不足，根本无法发挥破碎虚空的威力。\n");
        if((int)me->query("qi") < 200 )
   return notify_fail("你身体太虚弱了，无法施展「破碎虚空」！\n");
      if((int)me->query_skill("zileidao", 1) <200)

   return notify_fail("你的紫雷刀法练得不够纯熟，无法使出这招「破碎虚空」！\n");
        me->add("neili", -150);
 msg = HIW
 "$N凝神一吼，手中兵刃由下而上翻将上来，如天幕倒垂般卷向将过去！ 

                ┏━┓ ┏━┓ ┏━┓ ┏━┓ 
                ┃倒┃ ┃转┃ ┃乾┃ ┃坤┃             
                ┗━┛ ┗━┛ ┗━┛ ┗━┛ 


                      破·碎·虚·空\n"NOR;

        ap = me->query_skill("zileidao", 1);
        ap = ( ap * ap * ap / (4 * 400) );
        ap = ap*250 + (int)me->query("combat_exp");
        dp = target->query_skill("parry");
   dp = ( dp * dp * dp / (7 * 400) );
   dp = dp*250 + target->query("combat_exp");
    if( random((ap + dp)/1000) <  dp/1000 ) {
  msg += HIY "$n慌忙中左躲右闪，逃过了铺天盖地的一击！\n\n"NOR;
           message_vision(msg, me, target);
   } else {
        if(!target->is_busy()) target->start_busy(2);
                damage = 500+(int)me->query_skill("zileidao",1) *2 +
        (int)me->query("qi") / 300 + random((int)me->query("qi") / 200 ) +
        (int)me->query("jing") / 300 + random((int)me->query("jing") / 200 );
  msg += HIR "\n$n顿时被包围在一片无际的天幕中！\n\n" NOR;
     damage +=random(10);
     if (damage > 36000) damage=36000;
                        target->receive_damage("qi", damage);
                        target->receive_damage("jing", damage);
       target->receive_wound("qi", damage/2);
                        me->improve_skill("zileidao", 1, 1);
           message_vision(msg, me, target);
                COMBAT_D->report_status(target);
}
 weapon1=me->query_temp("weapon"); 

        extra = me->query_skill("zileidao",1);
        me->add_temp("apply/attack",200);
        me->add_temp("apply/damage",3000);        
 
  if (extra >= 300)
{
  message_vision(HIR"\n
$N默运紫雷，体内先天罡气力贯右手，手中"+weapon1->query("name")+HIR"被内力逼的通红，
突然无数红光，如划破天际的闪电般直逼$n全身要害!\n"NOR, me, target);

        if(!target->is_busy()) target->start_busy(2);

        COMBAT_D->do_attack(me, target, me->query_temp("weapon")); 
        COMBAT_D->do_attack(me, target, me->query_temp("weapon")); 
        COMBAT_D->do_attack(me, target, me->query_temp("weapon")); 
COMBAT_D->do_attack(me, target, me->query_temp("weapon")); 
me->add("neili", -50);
}
if (extra>= 380)
{
   message_vision(HIR"\n
$n全身顿时被$N劈出无数的伤口，就在$n无力招架的时候，$N左手
一翻从腰间抽出一把无形的宝剑向$n刺去，$N双手飞舞，刀剑其施，
霎时间红光如雨般倾斜而至。"NOR, me, target);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon")); 
        COMBAT_D->do_attack(me, target, me->query_temp("weapon")); 
        COMBAT_D->do_attack(me, target, me->query_temp("weapon")); 
COMBAT_D->do_attack(me, target, me->query_temp("weapon")); 
me->add("neili", -50);
}

        me->add_temp("apply/damage",-3000);
        me->add_temp("apply/attack",-200);

        me->start_busy(3);

        return 1;
}
