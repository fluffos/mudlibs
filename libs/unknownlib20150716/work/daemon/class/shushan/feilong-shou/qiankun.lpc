//乾坤一掷	使用金钱镖攻击，一次消耗1gold 敌方全体 60 
#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int perform(object me, object target)
{
	int i,damage,p;
	string msg,succ_msg;
	object *enemy;
		
	if( me->query_level()<60 )
    		return notify_fail("你的人物等级不够。\n");
	if((int)me->query_skill("feilong-shou",1) < 600
	 || me->query_skill_mapped("unarmed") != "feilong-shou" )
        	return notify_fail("你的『飞龙探云手』还不纯熟！\n");
	if((int)me->query("force") < 800 )
        	return notify_fail("你体内的内力不足。\n");
	if((int)me->query_skill("dodge") < 800)
        	return notify_fail("你的身法还不纯熟！\n");
	if( !me->check_pay(10000) )
		return notify_fail("你身上的铜钱不够。\n");
	me->clean_up_enemy();                
 	if( !me->is_fighting() ) 
                return notify_fail("「乾坤一掷」只能在战斗中使用。\n");
	enemy = me->query_enemy();
	if( !intp(i=sizeof(enemy)) 
	 || i<1 )
		return notify_fail("「乾坤一掷」只能战斗中使用。\n");
	msg = HIW"$N"HIW"返身掐了个剑诀，将手一指，但见金光闪闪，无数铜钱大小的光团铺天盖地飞起，在半空呼啸穿行了一圈，瞬如雨下！\n"NOR;
	message_vision(msg,me);
	me->add("force",-200);
	me->set_temp("pfm_msg",1);
	me->money_add(-10000);
	me->save(1);	
	
	succ_msg = HIR"$n"HIR"被打得浑身爆出一阵血雾，连连踉跄后退！\n"NOR;
	for(i=0;i<sizeof(enemy);i++)
	{
		target = enemy[i];
		if( !target || !target->is_character()
         	  || target->is_corpse()
         	  || target==me
         	  || !me->is_fighting(target) )
			continue;
		damage = COMBAT_D->do_attack(me,target,me->query_temp("weapon"),TYPE_PERFORM,0,succ_msg,0,2000);
		if( damage<1 )
			message_combatd(HIC"$n"HIC"慌忙运气护身劲气，堪堪挡住了这阵光雨。\n"NOR,me,target);
		else if( me->query("force_factor")>0 )
		{
			if( COMBAT_D->query_message_type(me,target)==2 )
				message_vision("结果造成了"HIR+damage+NOR"点气血损伤。\n",me,target);
			target->receive_wound("kee",damage,me,TYPE_PERFORM);
			COMBAT_D->report_status(target,1);
		}
	}
	me->delete_temp("pfm_msg");
	me->start_busy(2);	
	return 1;		
}

int help(object me)
{
string str;     
if ( !me )      return 0;
str = @LONG
        外功名称：乾坤一掷
        外功所属：飞龙探云手
        外功效果：将金钱当做暗器对敌进行高固定伤害的攻击
        	  当内功加力>0的情况下会追加对方气血损伤
        	  一次消耗10000文钱 
		  自身busy 2 秒
        外功条件：
        	  人物等级60级	
                  内力800点，消耗200点
                  飞龙探云手600级并激发
		  有效轻功800级	
LONG;
me->start_more(str);
return 1;
} 
