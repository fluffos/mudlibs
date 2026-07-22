#include <ansi.h> 
#include <combat.h>
inherit SSERVER;

int perform(object me,object target)
{
	string succ_msg,msg;
	int damage,skill;

	if(me->query("family/family_name") != "阎罗地府")
        	return notify_fail(HIG"「青面獠牙」"+NOR"是地府不传之密！\n");
	if( me->query_level()<20 )
		return notify_fail("你的人物等级不够。\n");        	
	if( !target ) target = offensive_target(me);
	if( !target
 	 || !target->is_character()
 	 || target->is_corpse()
 	 || target==me
 	 || !me->is_fighting(target) )
        	return notify_fail("「青面獠牙」只能对战斗中的对手使用。\n");
	skill = me->query_skill("kusang-bang",1);                
	if(  skill<150)
        	return notify_fail("你的「哭丧棒」等级不够, 不能使用「青面獠牙」！\n");
	if(  me->query_skill("tonsillit",1)<150 )
        	return notify_fail("你的摄气诀等级不够, 不能使用「青面獠牙」！\n");     
	if(  me->query("force")<500 )
        	return notify_fail("你的内力不够，无法运用「青面獠牙」！\n");  
        
	msg = HIC"$N"HIC"忽然将$w"HIC"一分，现出"NOR RED"青面獠牙"NOR HIC"的原形，欺近$n"HIC"的身前，张嘴便向$p的咽喉咬去！\n"NOR;
	succ_msg = HIC "$n"HIC"只觉得咽喉一阵剧痛，$N"HIC"正在狂吸$p的鲜血！\n"NOR;
	me->add("force",-150);
	me->set_temp("pfm_msg",1);
	damage = COMBAT_D->do_attack(me,target,me->query_temp("weapon"),TYPE_PERFORM,msg,succ_msg);
	me->set_temp("pfm_msg",0);	
	if( damage<1 )
	{
		message_combatd(HIC "只见$n"HIC"不慌不忙，轻轻一闪，躲过了$P的利齿！\n"NOR,me,target);
		me->start_busy(4);
	}
	else
	{
		target->receive_wound("kee",(1+damage/20),me,TYPE_PERFORM);
        	me->receive_heal("kee",1+damage/10);
        	me->receive_curing("kee",1+damage/20);
		me->start_busy(2);	
	}	
	return 1;
}

int help(object me)
{
string str;
if(  !me )      return 0;
str = @LONG
        外功名称：青面獠牙
        外功所属：苦 丧 棒
        外功效果：战斗中对对手造成气血的损伤，
                  并将伤害的5%转化为自身的气血疗伤
                  将伤害的10%转化为自身的气血增加
                  使用后自身busy 2 秒，不命中则busy 4 秒 
        外功条件：
        	  地府弟子
        	  人物等级20级
                  苦 丧 棒150级
                  摄 气 诀150级
                  内力500点，消耗150点
               
LONG;
me->start_more(str);
return 1;
}

