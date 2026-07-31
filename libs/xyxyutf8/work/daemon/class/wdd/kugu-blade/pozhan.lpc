//Cracked by Roath
// pozhan.c         破绽百出
#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int perform(object me, object target)
{
	object weapon;
	string msg,succ_msg;
	int delay, myblade,damage;
	int succ;

	if( me->query_level()<10 )
		return notify_fail("你的人物等级不够。\n");
	if(me->query("family/family_name")!="陷空山无底洞")
    		return notify_fail("「破绽」只有无底洞门人才可以用！\n"); 
	if( me->query("force")<150 )
		return notify_fail("你内息不顺。\n");
	if( me->query("kee")<50 )
		return notify_fail("你气血不畅。\n");	    		
	myblade=(int)me->query_skill("kugu-blade",1);
	if(myblade<80) 
	    	return notify_fail("你的修为不够深，露「破绽」给人太危险了。\n");

	weapon = me->query_temp("weapon");
        if( !weapon 
	 || (weapon->query("skill_type")!="blade"
	  && weapon->query("use_apply_skill")!="blade") )
		return notify_fail("你手里都木有刀。\n");
	if((string)me->query_skill_mapped("blade")!="kugu-blade")
		return notify_fail("「破绽」乃是枯骨刀的精髓。\n");
		
	if( !target ) target = offensive_target(me);
        if( !target || !target->is_character()
         || target->is_corpse()
         || target==me
         || !me->is_fighting(target) )
		return notify_fail("不在战斗中，露什么破绽？\n");
	if( target->is_busy() )
    		return notify_fail(target->name() + "目前正自顾不暇，放胆攻击吧！\n");

	if(myblade>160) 
		myblade=160; // mon 12/7/98
	delay=myblade/16;
	
//胆识增加额外威力
	if( random((int)me->query("cor"))>25 )
        	delay += 1;        
	if( random((int)me->query_cor())>40 )
		delay += 1; 
	myblade = me->query_skill("blade")/10;
	
	me->add("force",-100);
	me->receive_damage("kee",30,me);
	msg = CYN "$N"CYN"的招式突然一变，$w"CYN"变得全无章法，浑身上下破绽百出，叫人不知道哪个破绽是真，哪个是假。\n"NOR;
	succ_msg = HIR"结果$n"HIR"被$N"HIR"攻了个措手不及！\n" NOR;
	me->add_temp("apply/attack",myblade);
	succ = COMBAT_D->attack_percent(me,target,TYPE_PERFORM);
	me->add_temp("apply/attack",-myblade);
	
	if( succ<1 )
	{
		message_combatd(HIC"可是$n"HIC"看破了$N"HIC"的企图，并没有上当。\n" NOR,me,target);
		me->start_busy(1);
	}
	else
	{
		message_combatd(succ_msg,me,target);
		target->start_busy(delay);
		me->add("force",-50);
	}	
	return 1;
}

int help(object me)
{
string str;
if( !me )      return 0;
str = @LONG
              外功名称：破绽百出
              外功所属：枯骨刀法 
              外功效果：扰乱敌方视线，使之僵直
              		如成功，消耗内力150点
              		否则消耗内力100点，自身busy 1 秒
              外功条件：
              		无底洞弟子
              		人物等级10级
              		枯骨刀法80级 
              		内力150点，消耗100-150点
              		气血50点，消耗30点
LONG;
me->start_more(str);
return 1;
}