//飞龙探云手	铜钱镖	15
#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int perform(object me, object target)
{
	int damage,p;
	string msg,succ_msg;
	
	if( me->query_level()<15 )
    		return notify_fail("你的人物等级不够。\n");
	if((int)me->query_skill("feilong-shou",1) < 150
	 || me->query_skill_mapped("unarmed") != "feilong-shou" )
        	return notify_fail("你的『飞龙探云手』还不纯熟！\n");
	if((int)me->query("force") < 300 )
        	return notify_fail("你体内的内力不足。\n");
	if((int)me->query_skill("dodge") < 220)
        	return notify_fail("你的身法还不纯熟！\n");
        if( time()<me->query_temp("shushan_biao")+5 )
        	return notify_fail("你不能频繁丢镖。\n");	
        	
	if( !target ) target = offensive_target(me);
        if( !target || !target->is_character()
         || target->is_corpse()
         || target==me
         || !me->is_fighting(target) )
        	return notify_fail("你要对谁施展这一招『铜钱镖』？\n");

	if( !me->check_pay(50) )
		return notify_fail("你身上的铜钱不够了。\n");
	
	msg = HIY"$N"HIY"反手在身上一抹，抽出数枚铜钱，口中念叨真言，顿时金光灿灿，数枚铜钱带着道道金光，飞速旋转着射向$n"HIY"$l！\n"NOR;
	succ_msg = HIR"结果$n"HIR"闪避不及，给打了正着，顿时血花四溅，留下一地血沫！\n"NOR;
	p = me->query_skill("dodge")/10;
	p+= me->query_skill("stealing",1)/10;
	me->add_temp("apply/attack",p);
	me->set_temp("pfm_msg",1);
	me->add("force",-100);
	me->money_add(-50);
	me->save(1);
	damage = COMBAT_D->do_attack(me,target,me->query_temp("weapon"),TYPE_PERFORM,msg,succ_msg,0,800);
	me->set_temp("shushan_biao",time());
	me->add_temp("apply/attack",-p);
	me->delete_temp("pfm_msg");
	if( damage<1 )
		message_combatd(HIC"结果皆被$n"HIC"闪开，平白浪费了一些铜钱。\n"NOR,me,target);
	return 1;		
}

int help(object me)
{
string str;     
if ( !me )      return 0;
str = @LONG
        外功名称：铜钱镖
        外功所属：飞龙探云手
        外功效果：将金钱当做暗器对敌进行固定伤害的攻击
        	  一次消耗50文钱 
		  冷却时间 5 秒
        外功条件：
        	  人物等级15级	
                  内力200点，消耗100点
                  飞龙探云手150级并激发
		  有效轻功220级	
LONG;
me->start_more(str);
return 1;
} 
