
// diansha.c  点杀
//关元,檀中,肩井,太阳,气海,百汇,腹结,涌泉,大椎
#include <ansi.h>

inherit F_SSERVER;
int perform(object me, object target)
{
        int ap,dp,damage;
        object ob;
        string msg;
        string *order = ({"关元穴", "檀中穴", "肩井穴", "太阳穴", "气海穴", "百汇穴","腹结穴","涌泉穴","大椎穴"});
        if( !target ) target = offensive_target(me);

        if( !target || !target->is_character() || !me->is_fighting(target) )
        return notify_fail(RED"〖点杀〗只能在战斗中使用。\n"NOR);

    if (me->query("family/family_name") != "日月神教" )
        return notify_fail("你不是日月神教弟子，不能使用这项绝技！\n");
        
        if( !(ob = me->query_temp("weapon"))
        ||      (string)ob->query("skill_type") != "sword" )
        return notify_fail("你手中没有装备剑类武器！\n");

        if ( (int)me->query_int() < 30 )
        return notify_fail("你的先天不足，不能领悟天魔剑的精髓招式"RED"〖点杀〗！\n"NOR);

        if( (int)me->query_skill("tmjian",1)<199)
        return notify_fail("你的天魔剑法不够娴熟，还无发领会"RED"〖点杀〗！\n"NOR);
                                
        if( (int)me->query_skill("tmdafa", 1)<70)
        return notify_fail("你的天魔大法功力不够，无法使用"RED"〖点杀〗！\n"NOR);

        if( (int)me->query("neili")<500)
        return notify_fail("你现在内力太弱，不能使用"RED"〖点杀〗！\n"NOR);

        if( (time()-(int)me->query_temp("last_perform_time"))<
                me->query_temp("last_perform_busy") )
                return notify_fail("你的内力运转的没有这么快。\n");     

        me->set_temp("last_perform_time",time());
        me->set_temp("last_perform_busy",2);
        me->set_temp("last_perform_busy",4);

        msg=YEL"\n\n只见$N双目一滞，面上闪过一阵异彩，身法突然加快，如影随形，蹂身而上！\n"NOR;

        msg+=YEL"随着一声凄厉的长啸，$N手中宝剑绽开朵朵剑花，猛地罩向$n全身各处命门大穴！\n\n"NOR;

        me->add("neili",-random(500));

        ap=me->query_skill("tmjian")+me->query_skill("strike");
        dp=target->query_skill("parry")+target->query_skill("dodge");
        if(random(ap)+10>random(dp))   
           {
  target->start_busy(random(2));
                me->set_busy(1);
            damage=(me->query_str()-target->query_str()+10);
            damage=damage*random(me->query_cor());
/* */ damage=me->query("str")+me->query_skill("unarmed",1)/10;
/* */ damage=damage*(20+random(20))+800;

      if(damage<0)    damage=300;
      if(damage>6600) damage=6600;
      msg+=RED"$n惊叫一声，"+HIY+(order[random(7)])+NOR+RED+"部位血花飞溅,\n"NOR;
      switch(random(2))
      {
         case 1:
           {
               msg+=RED"$n“哇”地一口鲜血从口中喷出！\n"NOR;
               target->reset_action();
 break;
           }
         default:
      msg+=RED"$n身形一震, 一股鲜血从口中喷出,直喷向$N,但见$N头一歪,轻松的躲了过去！！\n"NOR;
               target->reset_action();
      }
         switch(random(2))
     {
         case 1:
         { 
             target->receive_wound("qi",damage);
             target->receive_damage("qi",damage);
     if(wizardp(me)) tell_object(me,sprintf("damage: %d\n",damage));
     break;
         }
      default:   
         { 
           target->receive_wound("qi",damage*2/3);
           target->receive_damage("qi",damage*5/4);
 if(wizardp(me)) tell_object(me,sprintf("damage: %d\n",damage*5/4));
                      }

                  }            
           }
        else 
           {
  me->start_busy(3);
                msg+=CYN"$p冷笑一声，身形虚晃几下闪了开去！\n"NOR;
           }

        message_vision(msg, me, target);

        return 1;
}
