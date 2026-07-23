//杀意 exert shayi

#include <ansi.h>
void remove_effect(object me);

int exert(object me)
{    
      if( (int)me->query_skill("shayi-xinfa", 1) < 180 )
                return notify_fail("你的杀意心法修为不够，无法使用「杀意」！\n");

      if (me->query_skill_mapped("force") != "shayi-xinfa")
                return notify_fail("其它内功有「杀意」？\n");
        if( (int)me->query_temp("shayi") ) 
                return notify_fail(HIR"你已经在使用杀意了。\n");

        if( (int)me->query_temp("qzj_tong") ) 
                return notify_fail("你已经在运同归剑了。\n");
      if( me->query_temp("fumo")   )
      return notify_fail("你正在使用大金刚拳的特殊攻击「金刚伏魔」！\n");
      if( me->query_temp("jingang")   )
      return notify_fail("你正在使用大金刚拳的特殊攻击「大金刚神通」！\n");
      if( me->query_temp("fanzhen")   )
                return notify_fail("你正在运用「金刚不坏体神功」！\n");

        if( me->query_temp("yuxiao/tianwu") )
                return notify_fail("你正在运用「凤凰天舞」心法！\n");

        if((int)me->query_temp("tzzf") ) 
                return notify_fail("你已经在掌刀的运功中。\n");
        if ((int)me->query_temp("shield"))
                return notify_fail("你已经在运护体神功中了。\n");
       if(me->query_temp("wdpowerup") )
       return notify_fail("你现在正在使用「五毒神功」的绝技。\n"); 
       if(me->query_temp("zhuihun/lpf")) 
       return notify_fail("你正在使用五毒追魂钩之「乱披风」\n"); 

       if(me->query_temp("anran")) 
       return notify_fail("你现在正在使用「黯然」绝技。\n"); 

 
      if( (int)me->query("neili") < 600 )
                return notify_fail("你的内力太少了，无法使用出杀意！\n");   
    
      if( (int)me->query("max_neili") < 2000 )
                return notify_fail("你的内力修为这么差，还想使用杀意？\n");   
                                                                                
      if( me->query_temp("shenzu")   )
                return notify_fail("你正在运用神足了！\n");
        if( (int)me->query_temp("shayi") ) 
                return notify_fail(HIR"你已经在使用杀意了。\n");

      message_vision(HIR"\n$N眼神变得凌厉，四周杀意四起！尽像变了一个人似的！！\n\n" NOR, me);
      me->start_busy(2);
      me->set_temp("shayi",1); 
      me->add_temp("apply/attack", me->query_skill("shayi-xinfa", 1)/3); 
      me->add_temp("apply/damage", me->query_skill("shayi-xinfa", 1)/3);
      me->add("neili", -600);    
   call_out("remove_effect", me->query_skill("shayi-xinfa", 1)/2+10, me);
      return 1;
}

void remove_effect(object me)
{
      if(me){
      me->delete_temp("shayi");
      me->add_temp("apply/attack", -me->query_skill("shayi-xinfa", 1)/3); 
      me->add_temp("apply/damage", -me->query_skill("shayi-xinfa", 1)/3);
      message_vision(HIG"\n$N眼神不在那么凌厉了，恢复了原来的样子。\n"NOR, me);    
      }
}
