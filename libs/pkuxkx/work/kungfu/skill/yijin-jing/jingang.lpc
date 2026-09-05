//snowman 04/01/99

#include <ansi.h>
void remove_effect(object me);

int exert(object me)
{    
      if ((string)me->query("class")!="bonze"&&(string)me->query("chushi/last_family")!="少林派")
                return notify_fail("你又不是佛门中人，根本无法使用「金刚不坏体神功」！\n");
      if( (int)me->query_skill("yijin-jing", 1) < 199 )
                return notify_fail("你的易筋经内功修为不够，无法使用「金刚不坏体神功」！\n");

      if (me->query_skill_mapped("force") != "yijin-jing")
                return notify_fail("其它内功有「金刚不坏体神功」吗？\n");

      if( (int)me->query_con() < 25 )
                return notify_fail("你的根骨太低，根本无法使用「金刚不坏体神功」！\n");
 
      if( (int)me->query("neili") < 1000 )
                return notify_fail("你目前的内力太少了，无法使用「金刚不坏体神功」！\n");   
    
      if( (int)me->query("max_neili") < 3800 )
                return notify_fail("你的内力修为这么差，还想使用「金刚不坏体神功」？\n");   
                                                                                
      if( me->query_temp("fanzhen")   )
                return notify_fail("你正在运用「金刚不坏体神功」！\n");
       
      message_vision(HIY"\n$N突然深吸一口气，目露慈光，面带微笑，内力运转，竟使全身上下宝光流动，是「金刚不坏体神功」！\n\n" NOR, me);
      me->start_busy(1);
//      me->set_temp("tjj_jie", 1);
      me->set_temp("fanzhen",1); 
      me->add_temp("apply/armor", me->query_skill("yijin-jing", 1)/4); 
      me->add_temp("apply/armor", me->query_skill("buddhism", 1)/4); 
      if ( me->query_skill("buddhism")>=400 &&
      	   me->query_skill("family/family_name")=="少林派" )
        me->set_temp("apply/cant_busy_fenjin",1);
      me->add("neili", -500);    
      me->set_temp("active_force_buffer/yijin-jing.jingang/name", "金刚不坏体神功");                                  //buff名称
      me->set_temp("active_force_buffer/yijin-jing.jingang/last_time", time() + me->query_skill("yijin-jing", 1)/2+20 );              //持续时间
      me->set_temp("active_force_buffer/yijin-jing.jingang/effect1", "护甲防御+"+(me->query_skill("yijin-jing", 1)/4+me->query_skill("buddhism", 1)/4)+"点");       //效果描述1   
      me->set_temp("active_force_buffer/yijin-jing.jingang/effect2", "分筋错骨免疫");                   //效果描述1

      call_out("remove_effect", me->query_skill("yijin-jing", 1)/2+20, me);
      me->start_exert(me->query_skill("yijin-jing", 1)/4+10, "「金刚不坏体神功」");
      return 1;
}

void remove_effect(object me)
{
      if(me){
//      me->delete_temp("tjj_jie",1); 
      me->delete_temp("fanzhen");
      me->add_temp("apply/armor", -me->query_skill("yijin-jing", 1)/4); 
      me->add_temp("apply/armor", -me->query_skill("buddhism", 1)/4);
      me->delete_temp("apply/cant_busy_fenjin");
      me->delete_temp("active_force_buffer/yijin-jing.jingang"); 
      message_vision(HIR"\n$N双手合十，散去了凝聚于全身上下的「金刚不坏体神功」。\n"NOR, me);    
      }
}
