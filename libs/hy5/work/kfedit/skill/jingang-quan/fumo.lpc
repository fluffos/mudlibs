// fumo.c 大金刚拳 perform 金刚伏魔

#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;

int perform(object me, string arg)
{
           object target;
      string msg;                                   
      int i,z;
           i = (int) (me->query_skill("jingang-quan",1) / 3);
           z = (int)me->query_skill("yijinjing",1)/5+(int)me->query_skill("jingang-quan",1)/4;
      if( !target ) target = offensive_target(me);
     
      if( !target || !me->is_fighting(target) )
      return notify_fail("「金刚伏魔」只能在战斗中对对手使用。\n");
             
      if( objectp(me->query_temp("weapon")) )
      return notify_fail("你必须空手使用「金刚伏魔」！\n");
      
      if( (int)me->query_skill("jingang-quan",1) < 180 )
      return notify_fail("你的大金刚拳不够娴熟，不会使用「金刚伏魔」！\n");
      
      if( (int)me->query_skill("yijinjing",1) < 180 )
      return notify_fail("你的易筋经等级不够，不能使用「金刚伏魔」！\n");  
      
      if(me->query_skill_mapped("force") != "yijinjing")
                return notify_fail("你没有运用易筋经内功，无法使用「金刚伏魔」进行攻击。\n"); 

      if( (int)me->query_str() < 25 )
      return notify_fail("你的臂力不够强，不能使用「金刚伏魔」！\n");
      
      if( (int)me->query("neili") < 1000 )
      return notify_fail("你的内力太弱，不能使用「金刚伏魔」！\n");
        if( me->query_temp("yuxiao/tianwu") )
                return notify_fail("你正在运用「凤凰天舞」心法！\n");
       if(me->query_temp("anran")) 
       return notify_fail("你现在正在使用「黯然」绝技。\n"); 
       if(me->query_temp("wdpowerup") )
       return notify_fail("你现在正在使用「五毒神功」的绝技。\n"); 
       if(me->query_temp("zhuihun/lpf")) 
       return notify_fail("你正在使用五毒追魂钩之「乱披风」\n"); 
        
        if( (int)me->query_temp("liuyun") ) 
                return notify_fail(HIG"你已经在默运流云水袖神功了。\n");

        if( (int)me->query_temp("qzj_tong") ) 
                return notify_fail("你已经在运同归剑了。\n");

        if((int)me->query_temp("tzzf") ) 
                return notify_fail("你已经在掌刀的运功中。\n");

      if( me->query_temp("fumo")   )
      return notify_fail("你正在使用大金刚拳的特殊攻击「金刚伏魔」！\n");
      if( me->query_temp("jingang")   )
      return notify_fail("你正在使用大金刚拳的特殊攻击「大金刚神通」！\n");
      if( me->query_temp("fanzhen")   )
                return notify_fail("你正在运用「金刚不坏体神功」！\n");
	if( (int)me->query_temp("zuida") ) 
		return notify_fail(HIG"你内息翻滚在八仙醉打中，一时提不起易筋经神功。\n"NOR);
        if ((int)me->query_temp("shield"))
                return notify_fail("你已经在运护体神功中了。\n");
        if( me->query_temp("yuxiao/tianwu") )
                return notify_fail("你正在运用「凤凰天舞」心法！\n");

       if(me->query_temp("anran")) 
       return notify_fail("你现在正在使用「黯然」绝技。\n"); 

     if( (int)me->query_temp("jingang") ) 
	return notify_fail(HIG"你已经在大金刚神通运功中了。\n");
      
      if( me->query_temp("fumo")   )
      return notify_fail("你正在使用大金刚拳的特殊攻击「金刚伏魔」！\n");
       
      msg = HIR"$N突然全身骨骼作响，口中默念「金刚伏魔」,运起易筋" +
               "经神功，脸上一阵红色，全身好象有使不完的力量一样！\n" NOR;
      
      message_vision(msg, me, target); 
      me->add_temp("apply/strength", i);
      me->set_temp("fumo",1);  
      me->add("neili", - 600);
      me->add("jingli", - 250);  
            
      call_out("check_fight", 1, me, i, z);
        me->start_busy(1);
      return 1;
}
void remove_effect(object me, int i)
{
    i = (int) (me->query_skill("jingang-quan",1) / 3);
    if(me->query_temp("fumo")){
    me->add_temp("apply/strength", -i);
    me->delete_temp("fumo");
    tell_object(me,HIR"你的「金刚伏魔」运功完毕，你的脸色好看多了。\n"NOR);
     }
//    else tell_object(me, "。\n" NOR);
}
void check_fight(object me, int i, int z)
{
  

    if (!me) return;
    if (me->query_temp("weapon")
       || me->query_temp("secondary_weapon")
       || me->query_skill_mapped("cuff"!="jingang-quan"))
    {
        remove_effect(me, i);
        return;
    }
    if (z < 1 || !me->is_fighting()) {
        remove_effect(me, i);
        return;
    }
    call_out("check_fight", 1, me, i, z-1);
}

