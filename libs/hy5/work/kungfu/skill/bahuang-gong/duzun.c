// wuwo.c

#include <ansi.h>
int exert(object me)
{       

        int nh=me->query_skill("bahuang-gong");

        if ((int)me->query_skill("bahuang-gong", 1) < 160)
                return notify_fail("你的八荒六合唯我独尊功修为还不够。\n");

        if( (int)me->query("neili") < 400 )
                return notify_fail("你的真气不够。\n");
        
      if( me->query_temp("yun_wuwo")   )
                return notify_fail("你正在运用唯我独尊！\n");

        write(MAG"你潜运唯我独尊字决，只觉得天地之间唯我独尊，心里充满了自信。\n"NOR);

        message_vision(HIW"只见$N深深吸了一口气，脸上露出一丝笑容。\n"NOR, me);
        me->add_temp("apply/armor", nh/2);
        me->add_temp("apply/defense", nh/2);
        me->add_temp("apply/attack", nh/2);
        me->add_temp("apply/sword", nh/2);
        me->add_temp("apply/parry", nh/2);
        me->add_temp("apply/strength", 10);
        me->add_temp("apply/dexerity",10);
        me->add_temp("apply/intelligence",10);
        me->add_temp("apply/percao",10);
        me->set_temp("yun_wuwo", 1);  
        me->add("neili", - 300);    
        me->start_call_out( (: call_other, __FILE__, "remove_effect", me, nh :), nh * 3/2 );
        return 1;
}
void remove_effect(object me, int nh)
{
      me->add_temp("apply/strength", -10);
      me->add_temp("apply/dexerity",-10);
      me->add_temp("apply/intelligence",-10);
      me->add_temp("apply/percao",-10);
      me->add_temp("apply/armor", -nh/2);
      me->add_temp("apply/defense", -nh/2);
      me->add_temp("apply/parry", -nh/2);
       me->add_temp("apply/attack", -nh/2);
        me->add_temp("apply/sword", -nh/2);
      me->delete_temp("yun_wuwo");
      tell_object(me, HIR"你散去了「唯我独尊」心法，你又恢复了原来的你。\n"NOR);
}
