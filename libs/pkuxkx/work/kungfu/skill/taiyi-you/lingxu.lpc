//太乙神游pfm凌虚飞渡，无门派强力dodge，但使用限制亦很多
// 2009.8.17 finished by zgbl

#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;

string* valid_weapon() 
{
    return ({ "all" });
}

int perform(object me, object target)
{
      string msg;                                   
      int improve;
      if( !target ) target = offensive_target(me);

	  if ((int)me->query("family"))
		  		return notify_fail("往矣，非曳尾涂中之士，如何领悟太乙正道？\n");

	  if (me->query_skill("hunyuan-yiqi",1) > 0)
		  		return notify_fail("往矣，非曳尾涂中之士，如何领悟太乙正道？\n");

	  if (me->query("betrayer") > 0)
		  		return notify_fail("往矣，非曳尾涂中之士，如何领悟太乙正道？\n");

	  if (me->query("family") || me->query("chushi/last_family"))
		  		return notify_fail("往矣，非曳尾涂中之士，如何领悟太乙正道？\n");
//有门派或者有过门派都无法使用，纯百姓技能
         
      if( me->query_skill("taiyi-you",1) < 150 )
                return notify_fail("你提起一口气，身子飘飘欲飞，却怎么都起不来！\n你的太乙神游不够娴熟，不能使用「凌虚飞渡」！\n");
      
      if( me->query_skill("taiyi-shengong",1) < 150 )
                return notify_fail("你提起一口气，身子飘飘离地，挣扎了片刻，重重的摔了下来！\n你的太乙神功等级不够，不能使用「凌虚飞渡」！\n");  
      
	  if( me->query_dex() < 30 )
                return notify_fail("你提起一口气，重重的一跺脚，跳起一尺……\n你的身法太低，不能使用「凌虚飞渡」！\n");

      if( me->query("qi") < ((me->query("max_qi"))/2) )
	            return notify_fail("你试着一提气，胸口顿时一阵剧痛！\n你的气血太低，不能使用「凌虚飞渡」！\n");

      if( time() < 5+(int)me->query_temp("taiyi-you-cd") )        
                return notify_fail("你刚被迫中断「凌虚飞渡」，一口气还没缓得过来！\n");   
	  //意外终止后，cd 5个心跳

      if( !me->is_fighting())
                return notify_fail("没战斗乱蹦什么，嫌内力多啊？\n");
	  
      if( me->query("neili") < me->query("max_neili")/4 )
                return notify_fail("你一口气提到一半，胸口一浊，又泄了出来！\n你的内力太少了，无法使用出「凌虚飞渡」！\n");   
    
      if (me->query_skill_mapped("dodge") != "taiyi-you")
                return notify_fail("不用太乙神游，谈何凌虚飞渡？\n");                                                                                 

	  if( me->query_temp("taiyi-you")   )
                return notify_fail("你正在凌虚飞渡，难道你想下来？\n");
       
      msg = HIC"$N缓缓地吸一口长气，袍袖一拂，衣袂飘飞处，身体仿佛轻若无物！\n$N向无尽的虚空中缓缓踏出一步，身体居然如有神助地飘了起来！\n" NOR;
      
      message_vision(msg, me, target); 
      improve = (int)me->query_skill("taiyi-you", 1)*2/5 + (int)me->query_dex() *10 - (int)me->query_skill("dodge", 1);
      me->add_temp("apply/dodge", improve);
      me->set_temp("taiyi-you",1);  
      me->add("neili", -(improve + 100));    
	  //提升系数为太乙神游*2.5+先天身法*10

      me->set_temp("active_buffer/family","百姓");
      me->set_temp("active_buffer/taiyi-you.lingxu/name", "凌虚飞渡");                      //buff名称
      me->set_temp("active_buffer/taiyi-you.lingxu/last_time", time() + me->query_skill("taiyi-you", 1)+1 );          //持续时间
      me->set_temp("active_buffer/taiyi-you.lingxu/effect1", "轻功技能+"+improve+"级");     //效果描述1
            
      call_out("remove_effect_lingxu_taiyiyou", 1, me, (int)me->query_skill("taiyi-you", 1),improve);

      return 1;
}

void remove_effect_lingxu_taiyiyou(object me, int count,int improve)
{
        if (!me) return;
        if( me->query_skill_mapped("dodge") != "taiyi-you" 
         || count < 1){
           me->add_temp("apply/dodge", - improve);
           me->delete_temp("taiyi-you");
           tell_object(me, HIC"你缓缓吐出一口浊气，飘飞的衣袂落了下来，双足轻轻点在地上。\n"NOR);
           me->delete_temp("active_buffer/taiyi-you.lingxu");
           if ( sizeof(me->query_temp("active_buffer"))==1 )
             me->delete_temp("active_buffer");
           tell_room(environment(me), HIC + me->name()+"缓缓吐出一口浊气，飘飞的衣袂落了下来，双足轻轻点在地上。\n" NOR,  ({ me }));
           return;
        }
		//持续时间为太乙神游等级，切换dodge后pfm停止，避免连续使用dodge型pfm重复提高有效dodge
		    if( me->query("qi") < ((me->query("max_qi"))/2) )
	      {
           me->add_temp("apply/dodge", - improve);
           me->delete_temp("taiyi-you");
           me->delete_temp("active_buffer/taiyi-you.lingxu");
           if ( sizeof(me->query_temp("active_buffer"))==1 )
             me->delete_temp("active_buffer");
           tell_object(me, HIR"你再也承受不住连续的打击，胸口的内气一散，不得不落了下来。\n"NOR);
           tell_room(environment(me), HIR + me->name()+"再也承受不住连续的打击，胸口的内气一散，不得不落了下来。\n" NOR,  ({ me }));
		       me->set_temp("taiyi-you-cd",time());
		       //意外终止后有cd时间
           return;
	      }
	//若受伤导致当前气血低于50%则效果停止
	      if( me->query("neili") < me->query("max_neili")/4 )
	      {
		       me->add_temp("apply/dodge", - improve);
           me->delete_temp("taiyi-you");
           me->delete_temp("active_buffer/taiyi-you.lingxu");
           if ( sizeof(me->query_temp("active_buffer"))==1 )
             me->delete_temp("active_buffer");
           tell_object(me, HIR"你内力逐渐枯竭，再也支撑不住飘飞的身体，不得不落了下来。\n"NOR);
           tell_room(environment(me), HIR + me->name()+"内力逐渐枯竭，再也支撑不住飘飞的身体，不得不落了下来。\n" NOR,  ({ me }));
		       me->set_temp("taiyi-you-cd",time());
		   //意外终止后有cd时间
           return;
	      }
	//内力消耗至最大内力1/4时效果停止
        call_out("remove_effect_lingxu_taiyiyou", 1 , me, count -1, improve);
 //循环调用，1s判定一次退出条件
}