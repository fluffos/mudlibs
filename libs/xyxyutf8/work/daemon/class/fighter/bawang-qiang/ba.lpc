#include <ansi.h>
inherit F_CLEAN_UP;

void remove_effect(object me,int attack_amount);

int perform(object me, object target)
{
	int skill_force,attack_amount;
	object weapon;
        
        if( me->query_level()<8 )
        	return notify_fail("你的人物等级不够。\n");
        
        skill_force=me->query_skill("lengquan-force",1);
	if(skill_force < 60) 
        	return notify_fail("你的冷泉神功修为不够，运行不了霸字诀。\n");
	if( me->query_temp("powerup") )
		return notify_fail("你现在不能运行霸字诀。\n");
	if( time()-(int)me->query_temp("jjf_ba_end") < 10 )
		return notify_fail("你现在真气不纯。\n");
	if(me->query_skill_mapped("force")!="lengquan-force")
        	return notify_fail("霸字诀必须配合冷泉神功才能使用。\n");
	if((int)me->query_skill("bawang-qiang", 1) < 80)
        	return notify_fail("你的霸王枪法级别还不够，运行不了霸字诀。\n");
	if( (int)me->query("force") < 500 )      
		return notify_fail("你的内力不够。\n");
	weapon=me->query_temp("weapon");
	if( !weapon
	 || ( weapon->query("skill_type")!="spear"
	   && weapon->query("use_apply_skill")!="spear" ) )
		return notify_fail("难道你已达手中无枪心中有枪的境界？！\n");	
		
	attack_amount=skill_force/5;

	me->add("force", -200);
	message_vision(HIR"$N"HIR"力贯双臂，运行起冷泉神功，手中"+weapon->name()+HIR"发出一阵龙吟！\n" NOR, me);
	me->set_temp("powerup",1);
	me->add_temp("apply/combat_damage",attack_amount);  
	me->add_temp("apply/spear",attack_amount);
	me->set_temp("jjf_ba",attack_amount);
	me->add_temp("apply/courage",30);
	me->start_call_out( (: call_other, __FILE__, "remove_effect", me, attack_amount:),skill_force);
	return 1;
}

void remove_effect(object me,int attack_amount)
{       
	if( !me )
        	return;
	me->add_temp("apply/combat_damage", -attack_amount);
	me->add_temp("apply/spear",-attack_amount);
	me->add_temp("apply/courage",-30);
	me->delete_temp("powerup");
	me->delete_temp("jjf_ba");
	tell_object(me, "你将冷泉神功收回丹田。\n");
	me->set_temp("jjf_ba_end",time());
}

int help(object me)
{
string str;
if( !me )      return 0;
str = @LONG
        外功名称：霸字诀
        外功所属：霸王枪法
        外功效果：在一定时间内提高自身的物理攻击、枪法有效等级、后天体格
                  状态消失后冷却10秒
                  不能与其他增益类状态叠加
        外功条件：
        	  人物等级8级
        	  
                  激发冷泉神功
                  内力500点，消耗200点
                  冷泉神功80级，并激发
                  霸王枪法80级，并激发
                  
LONG;
me->start_more(str);
return 1;
}

void remove()
{
	int attack_amount,i;
	object me,*usr = users();
	if( i=sizeof(usr)>0 )
	{
		while(i--)
		{
			if( !usr[i] || !environment(usr[i])
			 || !objectp(usr[i]) )
				continue;
			if( usr[i]->query_temp("jjf_ba") )
			{
				me = usr[i];
				attack_amount = me->query_temp("jjf_ba"); 
				me->add_temp("apply/combat_damage", -attack_amount);
				me->add_temp("apply/spear",-attack_amount);
				me->add_temp("apply/courage",-30);
				me->delete_temp("powerup");
				me->delete_temp("jjf_ba");
				tell_object(me, "你将冷泉神功收回丹田。\n");
				me->set_temp("jjf_ba_end",time());
			}
		}
	}
} 

