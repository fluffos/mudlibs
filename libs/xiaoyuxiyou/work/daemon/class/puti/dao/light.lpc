//light.c
#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int cast(object me, object target)
{
	int damage;
	string msg,succ_msg;

	if( me->query_level()<40 )
		return notify_fail("你的人物等级不够。\n");
				
	if( !target ) target = offensive_target(me);
	if( !target
 	|| !target->is_character()
 	|| target->is_corpse()
 	|| target==me 
 	|| !me->is_fighting(target) )
		return notify_fail("你要对谁施展苍灵箭？\n");
	if(me->query("family/family_name") != "方寸山三星洞")
        	return notify_fail("你不是方寸山三星洞弟子用不出这一招！\n");
	if((int)me->query("mana") < 600 )
		return notify_fail("你的法力不够！\n");
	if((int)me->query("sen") < 100 )
		return notify_fail("你无法集中精力！\n");
	if( time()<me->query_temp("puti_light")+8 )
		return notify_fail("你不能频繁念咒。\n");
		
	me->add("mana", -100);
	me->set_temp("puti_light",time());
	me->receive_damage("sen", 50);
	if( random(me->query("max_mana")) < 50 ) 
	{
		write("看来电母今天没空。\n");
		return 1;
	}
	
	msg = HIC "$N"HIC"口中念了句咒文，半空走出一位容貌秀雅的电母，双手各持一枚铜镜。铜镜相转，忽的闪出一道金光射向$n"HIC"$l！\n" NOR;
	succ_msg = HIR "结果「嗤」地一声，金光从$n"HIR"身上透体而过，拖出一条长长的血箭，直射到两三丈外的地下！\n" NOR;
	damage = COMBAT_D->do_attack(me,target,me->query_temp("weapon"),TYPE_CAST,msg,succ_msg);
	if( damage>0 )
		target->start_busy(target->query_busy()+1+random(2));
	else	message_combatd(HIC "结果嗤！地一声$n"HIC"闻到了一股焦味。还好只烧掉了几根头发。\n" NOR,me,target);
	return 1;
}

int help(object me)
{
	string str;
	if( !me )      
		return 0;
str = @LONG
        法术名称：苍灵箭
        法术所属：道家仙法
        法术效果：对敌进行带麻痹效果的法术攻击
                  冷却时间8秒
        法术条件：
        	  人物等级40级
        	  方寸弟子	
                  精神100点，消耗50点
                  法力600点，消耗100点 

LONG;
	me->start_more(str);
	return 1;
} 