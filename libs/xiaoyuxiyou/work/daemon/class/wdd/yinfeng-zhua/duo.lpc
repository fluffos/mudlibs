//Cracked by Roath
// duo.c 空手入白刃
//pudding 99.12 
#include <ansi.h>
#include <combat.h> 
inherit SSERVER;

void remove_weapon(object weapon)
{
	if( weapon && !environment(weapon)->is_character() )
	{
		tell_object(environment(weapon),"一阵微风吹过，"+weapon->name()+"化为片片尘土，消失不见了。\n");
		destruct(weapon);
	}
}
 
int perform(object me,object target)
{
        string msg,succ_msg;
        object weapon;
        int p,succ;

	if( me->query_level()<10 )
		return notify_fail("你的人物等级不够。\n");
	if(me->query("family/family_name")!="陷空山无底洞")
        	return notify_fail("你不是老鼠家族的，不能用「空手入白刃」。\n");
        if( me->query_skill("yinfeng-zhua",1)<100 )
        	return notify_fail("你的阴风爪不够娴熟。\n");
	if( me->query("force") <500 )
                return notify_fail("你的内力不够，无法空手入白刃！\n");        	
        weapon = me->query_temp("weapon");
        if( weapon )
        	return notify_fail("「空手入白刃」必须是空手。\n");
        if( !target ) target = offensive_target(me);
        if( !target || !target->is_character()
         || target->is_corpse()
         || target==me
         || !me->is_fighting(target) )
		return notify_fail("你要对谁施展「空手入白刃」？\n");
	weapon = target->query_temp("weapon");
	if( !weapon )
		return notify_fail("对方没有兵器，放手攻击吧。\n");
	
	msg = HIB"\n$N"HIB"闪步冲向$n"HIB"，左手曲爪如钩，迅雷不及掩耳间抓向$p！\n"NOR;
	message_vision(msg,me,target);
	me->add("force",-200);
	p = me->query_skill("unarmed")/50;
	me->add_temp("apply/attack",p);	
	succ = COMBAT_D->attack_percent(me,target,TYPE_PERFORM);
	me->add_temp("apply/attack",-p);
	
	if( succ>0 && objectp(weapon=target->query_temp("weapon")) )
 	{
		msg = HIB"\n一击得手，$N"HIB"乘二人身形交错之际，突然右臂暴涨，$n"HIB"顿时觉得手腕一麻，手中"HIC+weapon->name();
 		weapon->unequip();
 		target->reset_action();
 		if( weapon->is_zhaohuan() )
			msg+= HIB"拿捏不住，虽未落地，却也脱手！\n"NOR;
		else
 		{
 			msg+= HIB"脱手而出！\n"NOR;
 			if( !weapon->move(environment(me)) )
 				destruct(weapon);
			else	call_out("remove_weapon",15+random(15),weapon);	
		}
 		message_vision(msg,me,target);
		me->start_busy(2);
        }
        else
        {
        	message_vision(HIC"结果被$N"HIC"看破了招式，纵身闪开了。\n"NOR,target);
        	me->start_busy(4);
        }
        return 1;
}

int help(object me)
{
string str;     
if ( !me )      return 0;
str = @LONG
        外功名称：空手入白刃
        外功所属：阴风爪
        外功效果：夺取对方的武器，对空手类对手无效
                  使用后自身busy 2 秒
                  若不中则自身busy 4 秒
        外功条件：
                  无底洞(出师)弟子
        	  人物等级10级	
                  内力500点，消耗200点
                  阴风爪100级
LONG;
me->start_more(str);
return 1;
} 