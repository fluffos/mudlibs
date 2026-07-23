
// tie@fengyun
#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;
int perform(object me, object target)
{
        int extra;
       if ( me->query_con()< 30 )
            return notify_fail(RED"你先天不足,强行运功会害了自己!\n"NOR);
    if (me->query("family/family_name") != "日月神教" )
        return notify_fail("你不是日月神教弟子，不能使用这项绝技！\n");
        
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("〖化身千万〗只能空手使用。\n");		

        extra = me->query_skill("tmzhang",1);
        if ( extra < 70) return notify_fail(RED"你的〖天魔掌〗还不够纯熟！\n"NOR);

        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail(HIR"〖化身千万〗"+NOR+"只能对战斗中的对手使用。\n"+NOR);
       if( me->query("tmzhang")<100 )
         {
                if(target->is_busy())
                        return notify_fail(target->name()+"已经手忙脚乱了！\n");
                message_vision(HIY"\n$N脚踩连环，如天魔狂舞，一时间，将$n包围在千百双掌影中！\n\n"+NOR,me,target);
                if(random((int)target->query("combat_exp")/3) < (int)me->query("combat_exp"))
                {
                        message_vision(HIR"只见"+target->query("name")+"四周就象有千百只"HIY"魔"HIC"影"HIM"在"HIG"飞"HIB"舞"HIY",\n
                              结果$N被扰得眼花潦乱，接应不暇！手脚顿时慢了下来.\n"NOR,target);
                        target->start_busy(5);
                }
                else
                {
                        message_vision(HIY"结果$N自己弄了个头晕眼花！手脚顿时慢了下来.\n"+NOR,me);
                        me->start_busy(2);
                  }
         }
      if( (me->query("tmzhang")<200)&&(me->query("tmzhang")>100) )            
         {
                if(target->is_busy())
                        return notify_fail(target->name()+"已经手忙脚乱了！\n");
                message_vision(HIY"\n$N脚踩连环，如天魔狂舞，一时间，将$n包围在千百双掌影中！\n\n"+NOR,me,target);
                if(random((int)target->query("combat_exp")/2) < (int)me->query("combat_exp"))
                {
                        message_vision(HIR"只见"+target->query("name")+"四周就象有千百只"HIY"魔"HIC"影"HIM"在"HIG"飞"HIB"舞"HIY",\n
                              结果$N被扰得眼花潦乱，接应不暇！手脚顿时慢了下来..\n"NOR,target);
                        target->start_busy(5);
                }
                else
                {
                        message_vision(HIY"结果$N自己弄了个头晕眼花！手脚顿时慢了下来..\n"+NOR,me);
                        me->start_busy(2);
               }
                 }
          if( me->query("tmzhang")>200 )            
         {
                if(target->is_busy())
                        return notify_fail(target->name()+"已经手忙脚乱了！\n");
                message_vision(HIY"\n$N脚踩连环，如天魔狂舞，一时间，将$n包围在千百双掌影中！\n\n"+NOR,me,target);
                if(random((int)target->query("combat_exp")) < (int)me->query("combat_exp"))

                {
                        message_vision(HIR"只见"+target->query("name")+"四周就象有千百只"HIY"魔"HIC"影"HIM"在"HIG"飞"HIB"舞"HIY",\n
                              结果$N被扰得眼花潦乱，接应不暇！手脚顿时慢了下来...\n"NOR,target);

                        target->start_busy(6);
                }
                else
                {
                        message_vision(HIY"结果$N自己弄了个头晕眼花！手脚顿时慢了下来...\n"+NOR,me);
                        me->start_busy(2);
               }
                 }

       me->receive_damage("jing", 100); 
       me->add("neili",-100);
        return 1;
}
