//write by yesi
#include <ansi.h>
inherit SSERVER;
inherit F_CLEAN_UP;

void remove_effect(object me);

int perform(object me, object target)
{
	object weapon;
	int i,j,time;

	if(me->query_temp("ldlh")) 
        	return notify_fail("你已走入六道轮回。\n");
	if( me->query_level()<30 )
		return notify_fail("你的人物等级不够。\n");
        	
	if( !target ) target = me;
	if( target!=me )
		return notify_fail("你只能自己进入「六道轮回」？\n");
	if(time()-(int)me->query_temp("ldlh_end") < 10) 
        	return notify_fail("不能频繁出入「六道轮回」！\n");
	if(me->query("family/family_name") != "阎罗地府")
        	return notify_fail("「六道轮回」是阎罗地府不传之密！\n");
	if((int)me->query("force") < 1000 )
        	return notify_fail("你的内力不够！\n");
	if((int)me->query("kee") < 300 )
        	return notify_fail("你的气血不足，没法子施用外功！\n");
	if( me->query_skill_mapped("force")!="tonsillit")
        	return notify_fail("「六道轮回」必须配合摄气诀才能使用。\n");
	if( me->query_skill_mapped("spells")!="gouhunshu")
        	return notify_fail("「六道轮回」必须配合勾魂术才能使用。\n");
	if((int)me->query_skill("hellfire-whip", 1) < 250)
        	return notify_fail("你的烈火鞭级别还不够，使用这一招会有困难！\n");
	if((int)me->query_skill("gouhunshu", 1) < 250)
        	return notify_fail("你的勾魂术级别还不够，布不了「六道轮回」迷阵！\n");
	weapon=me->query_temp("weapon");
//////////六道轮回时间做出修正        
	time = 30+random((me->query_skill("force")+me->query_skill("whip"))/10);
	time+= (int)me->query_cor()/3;
    
	message_vision(HIW"$N"HIW"口中念念有词：般若波罗密，般若波罗密，苦难众生与我共堕六道，再渡轮回。\n"NOR,me);
	me->add("force",-200);
	me->receive_damage("kee",50,me);
	me->set_temp("lunhui",0);
	me->set_temp("ldlh",1);
	me->set_temp("ldlh_time",time);
	me->start_call_out( (: call_other, __FILE__, "remove_effect",me :),time); 
	return 1;
}

void remove_effect(object me)
{
	if(  !me || !me->query_temp("ldlh") )
        	return;
	me->delete_temp("ldlh");
	me->delete_temp("lunhui");
	me->delete_temp("ldlh_time");
	message_vision(HIW"$N"HIW"从「六道轮回」走了出来。\n"NOR, me);
	me->set_temp("ldlh_end", time() );
}

int help(object me)
{
string str;
if(  !me )      return 0;
str = @LONG
        外功名称：六道轮回
        外功所属：烈 火 鞭
        外功效果：使自身堕入「六道轮回」的状态
        	  战斗中每次攻击带有法术伤害附加
		  不能叠加	
                  状态消失后冷却 10 秒
        外功条件：
        	  人物等级30级
        	  地府弟子
                  烈 火 鞭250级
                  勾 魂 术250级
                  激发摄气诀
                  激发勾魂术
                  内力1000点，消耗200点
                  气血300点，消耗50点 
               
LONG;
me->start_more(str);
return 1;
}
      
void remove()
{
	int i;
	object me,*usr = users();
	if( i=sizeof(usr)>0 )
	{
		while(i--)
		{
			if( !usr[i] || !environment(usr[i])
			 || !objectp(usr[i]) )
				continue;
			if( usr[i]->query_temp("ldlh") )
			{
				me = usr[i];
				me->delete_temp("ldlh");
				me->delete_temp("lunhui");
				me->delete_temp("ldlh_time");
				message_vision(HIW"$N"HIW"从「六道轮回」走了出来。\n"NOR, me);
				me->set_temp("ldlh_end", time() );
			}
		}
	}
} 
