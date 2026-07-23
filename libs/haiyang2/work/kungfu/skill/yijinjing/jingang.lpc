//snowman 04/01/99

#include <ansi.h>
void remove_effect(object me);

int exert(object me)
{    
      if( (int)me->query_skill("yijinjing", 1) < 199 )
                return notify_fail("你的易筋经内功修为不够，无法使用「金刚不坏体神功」！\n");

      if (me->query_skill_mapped("force") != "yijinjing")
                return notify_fail("其它内功有「金刚不坏体神功」吗？\n");

      if( (int)me->query_con() < 25 )
                return notify_fail("你的根骨太低，根本无法使用「金刚不坏体神功」！\n");
 
      if( (int)me->query("neili") < 1000 )
                return notify_fail("你目前的内力太少了，无法使用「金刚不坏体神功」！\n");   
    
      if( (int)me->query("neili") < 3800 )
                return notify_fail("你的内力修为这么差，还想使用「金刚不坏体神功」？\n");   
        if( (int)me->query_temp("liuyun") ) 
                return notify_fail(HIG"你已经在默运流云水袖神功了。\n");

        if( (int)me->query_temp("qzj_tong") ) 
                return notify_fail("你已经在运同归剑了。\n");

       if(me->query_temp("anran")) 
       return notify_fail("你现在正在使用「黯然」绝技。\n"); 
       if(me->query_temp("wdpowerup") )
       return notify_fail("你现在正在使用「五毒神功」的绝技。\n"); 
       if(me->query_temp("zhuihun/lpf")) 
       return notify_fail("你正在使用五毒追魂钩之「乱披风」\n"); 

        if((int)me->query_temp("tzzf") ) 
                return notify_fail("你已经在掌刀的运功中。\n");
        if( me->query_temp("yuxiao/tianwu") )
                return notify_fail("你正在运用「凤凰天舞」心法！\n");

      if( me->query_temp("fumo")   )
      return notify_fail("你正在使用大金刚拳的特殊攻击「金刚伏魔」！\n");
      if( me->query_temp("jingang")   )
      return notify_fail("你正在使用大金刚拳的特殊攻击「大金刚神通」！\n");
	if( (int)me->query_temp("zuida") ) 
		return notify_fail(HIG"你内息翻滚在八仙醉打中，一时提不起易筋经神功。\n"NOR);
        if ((int)me->query_temp("shield"))
                return notify_fail("你已经在运护体神功中了。\n");
        if( me->query_temp("yuxiao/tianwu") )
                return notify_fail("你正在运用「凤凰天舞」心法！\n");

        if( (int)me->query_temp("jiuyin/powerup") )
        	return notify_fail("你已经在运九阴真功中了。\n");
        if( (int)me->query_temp("hslj/powerup") )
        	return notify_fail("你已经在运万法归宗中了。\n");
       if(me->query_temp("anran")) 
       return notify_fail("你现在正在使用「黯然」绝技。\n"); 
                                                                                
      if( me->query_temp("fanzhen")   )
                return notify_fail("你正在运用「金刚不坏体神功」！\n");
       
      message_vision(HIY"\n$N突然深吸一口气，目露慈光，面带微笑，内力运转，竟使全身上下宝光流动，是「金刚不坏体神功」！\n\n" NOR, me);
      me->start_busy(1);
//      me->set_temp("tjj_jie", 1);
      me->set_temp("fanzhen",1); 
      me->add_temp("apply/armor", me->query_skill("yijinjing", 1)/2); 
      me->add_temp("apply/attack", me->query_skill("yijinjing", 1)/3);
      me->add_temp("apply/damage", me->query_skill("yijinjing", 1)/2);
      me->add("neili", -500);    
      call_out("remove_effect", me->query_skill("yijinjing", 1)/2+20, me);
//      me->start_exert(me->query_skill("yijinjing", 1)/4+10, "「金刚不坏体神功」");
      return 1;
}

void remove_effect(object me)
{
      if(me){
//      me->delete_temp("tjj_jie",1); 
      me->delete_temp("fanzhen");
      me->add_temp("apply/armor", -me->query_skill("yijinjing", 1)/2);
      me->add_temp("apply/attack",-me->query_skill("yijinjing", 1)/3);
      me->add_temp("apply/damage",-me->query_skill("yijinjing", 1)/2);
      message_vision(HIR"\n$N双手合十，散去了凝聚于全身上下的「金刚不坏体神功」。\n"NOR, me);    
      }
}
