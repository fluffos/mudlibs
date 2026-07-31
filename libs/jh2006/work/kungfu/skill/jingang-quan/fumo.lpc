// fumo.c 大金刚拳 perform 金刚伏魔

#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;

void check_fight(object me,int count);

int perform(object me, object target)
{
      string msg;                                   
      int improve,skill;
      if( !target ) target = offensive_target(me);
     
      if( !target || !me->is_fighting(target) )
         return notify_fail("「金刚伏魔」只能在战斗中对对手使用。\n");
             
      if( objectp(me->query_temp("weapon")) )
         return notify_fail("你必须空手使用「金刚伏魔」！\n");
      
      if( skill=(int)me->query_skill("jingang-quan",1) < 120 )
         return notify_fail("你的大金刚拳不够娴熟，不会使用「金刚伏魔」！\n");
      
      if( (int)me->query_skill("yijin-jing",1) < 120 )
         return notify_fail("你的易筋经内功等级不够，不能使用「金刚伏魔」！\n");  
      
      if( (int)me->query_str() < 28 )
         return notify_fail("你的臂力不够强，不能使用「金刚伏魔」！\n");
      
      if( (int)me->query("max_neili") < 700 )
         return notify_fail("你的内力太弱，不能使用「金刚伏魔」！\n");
      
      if( (int)me->query("neili") < 600 )
         return notify_fail("你的内力太少了，无法使用出「金刚伏魔」！\n");   
                                                                                 
      if (me->query_skill_prepared("cuff") != "jingang-quan"
        || me->query_skill_mapped("cuff") != "jingang-quan")
                return notify_fail("你现在无法使用「金刚伏魔」进行攻击。\n");                                                                                 
      
      if( me->query_temp("fumo"))
          return notify_fail("你正在使用大金刚拳的特殊攻击「金刚伏魔」！\n");
       
      msg = HIR"$N突然全身骨骼作响，口中默念「金刚伏魔」，运起" +
               "易筋功，脸上一阵红色，全身好象有使不完的力量一样！\n" NOR;
      
      message_vision(msg, me, target); 
      skill = me->query_skill("jingang-quan");
      improve = skill/5 + random(skill/5);
      if ( improve > 100 ) improve = 100 + random(improve-100) / 5;
      me->add_temp("apply/strength", improve);
      me->set_temp("fumo", improve);  
      me->add("neili", - 300+ random(300));
      me->add("jingli", - 250);  
      call_out("check_fight", 1, me, skill/3);
      me->start_busy(2);
      return 1;
}

void check_fight(object me,int count)
{
      int j;
      if (!me) return;
      if (me->query_temp("weapon")
       || me->query_temp("secondary_weapon")
       || me->query_skill_prepared("cuff") !="jingang-quan"){
        j = me->query_temp("fumo");
        me->add_temp("apply/strength", - j);
        me->delete_temp("fumo");
        tell_object(me, HIR"你的「金刚伏魔」运功完毕，你的脸色好看多了。\n"NOR);
        return;
      }
      if (count < 1 || !me->is_fighting()) {
        j = me->query_temp("fumo");
        me->add_temp("apply/strength", - j);
        me->delete_temp("fumo");
        tell_object(me, HIR"你的「金刚伏魔」运功完毕，你的脸色好看多了。\n"NOR);
        return;
      }
      else {
//        me->start_perform(1,"「金刚伏魔」");
        call_out("check_fight", 1, me, count-1);
      }
}

