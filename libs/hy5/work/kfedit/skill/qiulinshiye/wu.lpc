#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;

void remove_effect(object me, int improve);

int perform(object me, object target)
{
      string msg;                                   
      int improve;
      if( !target ) target = offensive_target(me);

        if( !target || !target->is_character() || !me->is_fighting(target) )
                return notify_fail("只有在站斗中才能使用！\n");


	if( (int)me->query_skill("qiulinshiye", 1) < 60 )
                return notify_fail("你的秋林拾叶不够高。\n");

	if( (int)me->query_skill("biyun-xinfa", 1) < 60 )
                return notify_fail("你的碧云心法不够高。\n");

        if( (int)me->query("neili", 1) < 300 )
                return notify_fail("你现在内力太弱。\n");

        if((int)me->query("neili") < 400)
                return notify_fail(HIY "你现在真气不足。\n" HIY);
    
        if (me->query_skill_mapped("dodge") != "qiulinshiye")
                return notify_fail("你现在激发的轻身不是秋林拾叶。\n");                                                                                 
      if( me->query_temp("tmwu")   )
      return notify_fail("你正在使用秋林拾叶的特殊防御「雾」！\n");
       
     msg = HIW"$N身形如竹叶飞舞，随风绕着圈出招飘动，" +
               "好象要击中，却若无物。身法如梦如雾！\n" NOR;
      
      me->start_busy(1);
      message_vision(msg, me, target); 
      improve = (int)me->query_dex() * 2;
      me->add_temp("apply/dodge", improve);
      me->add_temp("apply/defense", improve);
      
      me->set_temp("tmwu",1);  
      me->add("neili", -(350-(int)me->query_skill("qiulinshiye",1)/10));    
            
      me->start_call_out( (: call_other, __FILE__, "remove_effect", me, improve :), me->query_skill("qiulinshiye") * 2/3 );
      return 1;
}

void remove_effect(object me, int improve)
{
      me->add_temp("apply/dodge", - improve);
      me->add_temp("apply/defense", - improve);
      
      me->delete_temp("tmwu");
      tell_object(me, HIC"你散去丹田凝聚的内力，混身经脉真气流动，气定神闲，精神弈弈。\n"NOR);
      tell_room(environment(me), HIG + me->name()+"全身骨头一阵轻响，散去了混身的功力。\n" NOR,  ({ me }));
    
}
