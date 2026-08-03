//caoshu.c 草书
#include <ansi.h>
#include <combat.h>
#include "/kungfu/skill/eff_msg.h";

inherit F_SSERVER;

int perform(object me, object target)
{
      string msg; 
      int i,damage,p;
      object weapon = me->query_temp("weapon");

      if (!weapon || weapon->query("skill_type") != "brush")
         return notify_fail("你手里没有笔，无法写出草书！\n");

      if( !target ) target = offensive_target(me);
     
      if( !target || !me->is_fighting(target) )
         return notify_fail("草书只能在战斗中对对手使用。\n");
             
      if( (int)me->query_skill("yingou-bifa",1) < 120 )
         return notify_fail("你的银钩笔法还不够娴熟，不会写草书！\n");
      
      if( (int)me->query_skill("literate",1) < 120 )
         return notify_fail("你的读书写字等级不够，不能写出草书！\n");  
      
      if( (int)me->query_skill("guiyuan-tunafa",1) < 140 )
         return notify_fail("你的归元吐纳法等级不够，不能写出草书！\n");  

      if( (int)me->query("max_neili") < 1500 )
         return notify_fail("你的内力太弱，写不出龙飞凤舞的草书! \n");
      
      if( (int)me->query("neili") < 500 )
         return notify_fail("你的内力太少了，写出的草书无此意念！\n"); 
      
      if (me->query_skill_mapped("brush") != "yingou-bifa"
       || me->query_skill_mapped("parry") != "yingou-bifa")
         return notify_fail("你现在无法写出「草书」！\n");

      i = random((int)(me->query_skill("yingou-bifa",1)/15));
      if(i < 1) i = 1;
      if(i > 10) i = 10;
      msg = HIM"$N长袖飞舞，狂奔疾走，出招全然不依章法。只见其如疯如癫、如酒醉、如中邪，\n"+
               "笔意淋漓，笔走龙蛇！原来$N这时所书，正是唐代张旭的「自言帖」。张旭号称\n"+
               "「草圣」，乃草书之圣。\n" NOR;
      me->add("neili", - 250);
      me->add("jingli", -80);
      me->add_temp("apply/strength", i);
      me->add_temp("apply/attack", i);
      COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 1);  
      me->add_temp("apply/strength", -i);
      me->add_temp("apply/attack", -i);
      weapon->wield();
      if( random(me->query_skill("literate", 1)) > target->query_skill("literate", 1)/4
       && random(me->query_skill("force")) > target->query_skill("force")/2
       && me->is_fighting(target)
       && present(target,environment(me))){
          me->start_busy(2);
          target->start_busy(1);             
          damage = (int)me->query_skill("yingou-bifa", 1);               
          damage = damage/2 + random(damage);
          damage = damage * i * 2 / 3;
          if (damage > 1500 ) damage = 1500;
          target->receive_damage("qi", damage);
          target->receive_wound("qi", damage/3);  
          msg += HIB"突然$N笔锋锋芒暴增，写到「担夫争道」的那个「道」字，最后一笔钩将上来，直划\n"+
                    "上了$n身上，顿时鲜血直流，$n踉跄後退了好几步。\n"NOR;
          p = (int)target->query("qi")*100/(int)target->query("max_qi");
          msg += "( $n"+eff_status_msg(p)+" )\n";
      }
      else {
          me->start_busy(1);
          msg += HIG"$p当下发声长啸，右扇左袖，鼓起一阵疾风，急向$P扑去，劲风力道凌厉，令人不由\n"+
                    "自主地渐渐退後，只听$p口中不住有似霹雳般吆喝助威，$P奋袂低昂，高视阔步，和\n"+
                    "$p斗了个旗鼓相当。\n"NOR;
         if (!(target->query("neili")< 200)) target->add("neili",- 100);
       }
       message_vision(msg, me, target);
       me->start_perform(4,"「草书」");
       return 1;
}
