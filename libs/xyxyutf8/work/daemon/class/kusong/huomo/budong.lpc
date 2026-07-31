//不动
//能将反 busy状态
 //snowtu
#include <ansi.h>
inherit F_CLEAN_UP;

string name()
{
return NOR"「"YEL"山之不动"NOR"」";
}        

int exert(object me)
{
	int time;
	if( me->query_level()<25 ) 
		return notify_fail("你的人物等级不够。\n");      
	if( me->query("family/family_name")!="火云洞")
        	return notify_fail(name()+"乃是火云洞不传之密。\n"); 
	if( me->query_skill("force",1)<250 
  	 || me->query_skill("huomoforce",1)<250 ) 
		return notify_fail("你内功修为不足 ，施展不了"+name()+"。\n");
	if( me->query("force")<200 )      
        	return notify_fail("你的内力不够了。\n");
	if( me->query("kee")<100 )
        	return notify_fail("你的气血不够，恐怕施展"+name()+"有些危险。\n");    
	if( time()<me->query_temp("hyd_budong/start")+me->query_temp("hyd_budong/time") )
        	return notify_fail("你已处于不动状态了。\n");
	if( time()<me->query_temp("kusong_budong")+6 )
		return notify_fail("你不能频繁进入不动状态。\n");                
	time = me->query_skill("force");
	time/= 81;
	time = time/2+random(time/2);
	if( time>15 )
		time = 15;
	if( wizardp(me) )  tell_object(me,"time=="+time+"\n");
	me->add("force", -200);
	me->receive_damage("kee",100);

	message_vision(HIY"$N"HIY"略一提气，运起"HIR+to_chinese("huomoforce")+HIY"，整个人身形立刻变得稳健起来。只见$N"HIY"足下深陷石中，整个人挑起了东岳泰山的气势！\n" NOR, me);
	me->set_temp("hyd_budong/start",time());
	me->set_temp("hyd_budong/time",time);
	call_out("check",3,me,time);
	return 1;
}

void check(object me, int time)
{
	if( !me )
        	return;
	time--;        
	if( time<=1 || me->query("force")<50 )
        {
        	message_vision(YEL"\n$N"YEL"周身内劲运作一周天，「不动」一式渐渐平息了下来。。。\n\n"NOR,me);   
        	me->delete_temp("hyd_budong");
        	me->set_temp("kusong_budong",time());
        	return;
        }
	if( me->is_fighting() 
  	 && living(me) 
  	 && me->is_busy() )
        {
        	message_vision(YEL"\n$N"YEL"大喝一声，周身内劲运作，动作立时变得顺畅起来！\n\n"NOR,me);
        	me->set_temp("kusong_budong",time());
        	me->add("force",-50);
       	        me->start_busy(1,10000);
	        me->interrupt_me(me,"不动");
        	me->reset_action();
        }
	call_out("check",3,me,time);
	return ;
}

int help(object me)
{
        string str;
        if( !me )  return 0;
        str = @STR

        内功名称：东岳不动诀 
        内功所属：火魔心法
        内功效果：战斗中每3秒清除自身的busy状态，并消耗内力50点
		  触发或结束后开始计算冷却，冷却时间6秒
        内功条件：
                  火云洞弟子
        	  人物等级 25 级
                  内力200点，消耗200点
                  气血100点，消耗100点
                  基本内功250级
                  火魔心法250级
STR;
        me->start_more(str);
        return 1;
}