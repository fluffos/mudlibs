// 夺命金花 - 满天花雨
// By River@SJ 

inherit F_SSERVER;
#include <ansi.h>
#include "/kungfu/skill/eff_msg.h";

int perform(object me, object target)
{
        int num,p,damage;
        string msg;
        object weapon = me->query_temp("weapon");

        if( !target ) target = offensive_target(me);
        if( !target
         || !target->is_character()
         || !me->is_fighting(target) )
              return notify_fail("你只能对战斗中的对手使用。\n");
        if((int)me->query_skill("duoming-jinhua", 1) < 120 )
              return notify_fail("你的夺命金花不够娴熟，还不能使用满天花雨。\n");
        if((int)me->query_skill("shenghuo-shengong", 1) < 100 )
              return notify_fail("你的圣火神功等级不够，不能使用满天花雨。\n");
        if((int)me->query("neili", 1) < 500 
         ||(int)me->query("jingli", 1) < 200 )
              return notify_fail("你现在的体力不能施展满天花雨的绝技！\n");
        if( (int)me->query_str() < 35 )
              return notify_fail("你的身法太低，无法施展满天花雨的绝技。\n");
        if ( !weapon
         || weapon->query("skill_type") != "throwing"
         || me->query_skill_mapped("throwing") != "duoming-jinhua")
              return notify_fail("你现在无法使用满天花雨。\n");
        num = random(me->query_skill("duoming-jinhua", 1) / 20) + 10;
        if (me->query("gender") =="男性")
            num = num/2;
        if ((weapon->query_amount()) < num)
             return notify_fail("你身上的暗器不够，无法使出满天花雨。\n");         
        me->add("neili", -100);
        me->add("jingli", -50);
        me->start_busy(1);
        msg = HIW"\n$N清叱一声，长袖飘飘，只见"+chinese_number(num)+"道寒光呈满天花雨之势，从四面八方向$n飞射而去。\n"NOR;
        if(random(me->query("combat_exp")) > (int)target->query("combat_exp")/2
          && (int)me->query_dex() > random(target->query_dex())){
          weapon->add_amount(-num);
          msg += HIR"只见$n躲闪不及，痛苦的大叫一声，"+weapon->name()+HIR"已全部击中其全身要穴。\n"NOR;
          me->add("neili", -200);
          damage = me->query_skill("duoming-jinhua", 1);
          damage +=me->query_skill("throwing", 1);
          damage = damage * num /10;
          damage = damage + random(damage);
          if (damage>1500) damage=1500;
          target->receive_damage("qi", damage);
          target->receive_wound("qi", damage/3);
          target->start_busy(3);
          if(!target->is_killing(me->query("id"))) target->kill_ob(me);
          p = (int)target->query("qi")*100/(int)target->query("max_qi");
          msg += "( $n"+eff_status_msg(p)+" )\n";
         }
         else {
          msg += CYN"$n抱头缩颈一个滚翻，堪堪然躲开了"+weapon->name()+CYN"的攻击。\n"NOR;
          weapon->add_amount(-num);
          me->start_busy(3);
          me->add("neili",-100);
         }
         message_vision(msg, me, target);
         me->start_perform(4,"满天花雨");
         return 1;
}
