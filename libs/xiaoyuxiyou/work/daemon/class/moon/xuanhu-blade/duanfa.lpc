#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int valid_perform(object me)
{
	if(me->query("family/family_name") != "月宫")
        	return notify_fail("「断发忘情」是月宫不传之密！\n");
	if( me->query_level()<20 )
		return notify_fail("你的人物等级不够。\n");
        if((int)me->query_skill("xuanhu-blade", 1) < 150)
                return notify_fail("你的「玄狐长恨刀」不够熟练，使用这一招会有困难！\n");
	if((int)me->query("max_force") < 2000 )
                return notify_fail("你的内力修为不够！\n");
	if((int)me->query("force") < 500 )
        	return notify_fail("你的内力不足！\n");
        if((int)me->query("sen") < 100 )
                return notify_fail("你的精神不足，没法子施用外功！\n");
	return 1;	
}

int perform(object me, object target)
{
        int damage,int_damage,int_attack;

	if( !valid_perform(me) )
		return 0;        
        
        if( !target ) target = offensive_target(me);
        if( !target
         || !target->is_character()
         || target->is_corpse()
         || target==me
         || !me->is_fighting(target) )
		return notify_fail("你要对谁施展这一招「断发忘情」？\n");
        if( time()<me->query_temp("no_duanfa")+4)
        	return notify_fail("看你香汗淋漓的样子，等会儿再用吧！\n");
        	
	message_vision(HIW"\n$N"HIW"手中刀势一缓，和着刀声唱起歌来！~~~\n"NOR,me,target);
	message_combatd(HIC"\n我已剪短了我的发，剪断了牵挂……\n"NOR,me,target);
	message_combatd(HIC"\n一刀两断，你的情话，你的慌话……\n"NOR,me,target);
	me->add("force",-50);
	me->receive_damage("sen", 10);
	
	if( !target->is_busy() )
		target->start_busy(1);
	me->set_temp("pfm_msg",1);	
	
	int_damage = me->query_temp("apply/combat_damage");
	int_attack = me->query_temp("apply/attack");
	if( me->query_temp("moon_huashen") && me->query_temp("moon_huashen")=="hu" )
	{
		me->add_temp("apply/combat_damage",int_damage);
		me->add_temp("apply/attack",int_attack);
	}	
	
	damage = COMBAT_D->do_attack(me,target,me->query_temp("weapon"),TYPE_PERFORM);
	if( damage>5 )
	{
		damage/= 2;
		damage = damage/2+random(damage/2);
		message_vision(HIW"\n$n"HIW"听着听着不由心底一酸，心神荡漾，三魂六魄都丢光了\n"NOR,me,target);
		target->receive_wound("sen",damage);
		COMBAT_D->report_sen_status(target,1);
	}
	else 
	{
             message_vision(HIG"\n$n冷哼一声，五音不全，跑调了都不知道？\n"NOR,me,target);
             me->receive_damage("sen", 20);
             me->add("force", -30);
        }
	me->set_temp("apply/combat_damage",int_damage);
	me->set_temp("apply/attack",int_attack);
	return 1;
}

int help(object me)
{
        string str;
        if( !me )  return 0;
        str = @STR

        外功名称：断发忘情
        外功所属：玄狐长恨刀
        外功效果：以歌声束缚对方行动顺势对敌进行伤及其精神的攻击
        	  化狐状态下使用，伤害和命中翻倍
                  使用后冷却4秒
        外功条件：
                  月宫弟子
        	  人物等级20级
                  内力500点，消耗50点，失败则消耗80点
                  精神100点，消耗10点，失败则消耗30点
                  玄狐长恨刀 150 级
                  内力修为二十年
                  
STR;
        me->start_more(str);
        return 1;
}