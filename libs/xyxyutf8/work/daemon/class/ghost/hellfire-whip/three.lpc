//edit by yesi
//lestat modi for hell
#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int perform(object me, object target)
{
	object weapon;
	int damage,enhance;   
	string msg,str;        
	
	if( me->query_level()<10 )
		return notify_fail("你的人物等级不够。\n");
	if( !target ) target = offensive_target(me);
	if( !target
 	 || !target->is_character()
 	 || target->is_corpse()
 	 || target==me
 	 || !me->is_fighting(target) )
		return notify_fail("你要对谁施展这一招「神·人·鬼」？\n");
	if((int)me->query("force") < 800 )
        	return notify_fail("你的内力不够！\n");
	if( time()-(int)me->query_temp("hell_three") < 6 )
        	return notify_fail("绝招用多就不灵了！\n");
	if((int)me->query_skill("hellfire-whip", 1) < 100)
        	return notify_fail("你的烈火鞭级别还不够，使用这一招会有困难！\n");

	weapon=me->query_temp("weapon");
	message_vision(HIC"$N"HIC"双手划一大圆，猛然托天而举，伴着天上雷鸣电闪，祭出了「神·人·鬼」三招。\n"NOR,me,target);
	me->set_temp("hell_three",time());
	me->add("force",-150);

	//出掌
	weapon->set("use_apply_skill","unarmed");
	me->reset_action();
	if( me->query_skill("jinghun-zhang",1)>100
	 && me->query_skill("unarmed")>100 
	 && me->query_skill_mapped("unarmed")=="jinghun-zhang" )
	{
		message_combatd(YEL"但见幢幢鬼影四周飘浮，突然$N"YEL"鬼唱一声，无数鬼手抓向$n"YEL"。\n"NOR,me,target);
		COMBAT_D->do_attack(me,target,me->query_temp("weapon"),TYPE_PERFORM,0,0,0,me->query_skill("jinghun-zhang",1)/5);
	}
	else	COMBAT_D->do_attack(me,target,me->query_temp("weapon"),TYPE_PERFORM);
	
	//出剑
	weapon->set("use_apply_skill","sword");
	me->reset_action();
	if( me->query_skill("zhuihun-sword",1)>100
	 && me->query_skill("sword")>100 
	 && me->query_skill_mapped("sword")=="zhuihun-sword" )
	{
		message_combatd(HIR"$N"HIR"眸中红芒一闪，"+weapon->name()+HIR"上剑气冲天，直扑$n"HIR"。\n"NOR,me,target);
		COMBAT_D->do_attack(me,target,me->query_temp("weapon"),TYPE_PERFORM,0,0,0,me->query_skill("zhuihun-sword",1)/5);
	}
	else	COMBAT_D->do_attack(me,target,me->query_temp("weapon"),TYPE_PERFORM);	
	
	//出棍
	weapon->set("use_apply_skill","stick");
	me->reset_action();
	if( me->query_skill("kusang-bang",1)>100
	 && me->query_skill("stick")>100 
	 && me->query_skill_mapped("stick")=="kusang-bang" )
	{		
		message_combatd(HIM"$N"HIM"双手一抖，手中"+weapon->name()+NOR+HIM"顿时变的笔直，如同一根铁棍。\n"NOR,me);
		COMBAT_D->do_attack(me,target,me->query_temp("weapon"),TYPE_PERFORM,0,0,0,me->query_skill("kusang-bang",1)/5);
	}
	else	COMBAT_D->do_attack(me,target,me->query_temp("weapon"),TYPE_PERFORM);	

	weapon->delete("use_apply_skill");
	me->reset_action();
	
	if( me->query_skill("hellfire-whip",1)>350 
	 && me->query_skill("whip",1)>350 
	 && me->query_skill_mapped("whip")=="hellfire-whip" )
	{
	//出鞭
		message_combatd(HIB"四周磷光点点，$N"HIB"舞动"+weapon->name()+NOR+HIB"，咯咯一笑，扑向$n"HIB"。\n"NOR,me,target);
		COMBAT_D->do_attack(me,target,me->query_temp("weapon"),TYPE_PERFORM,0,0,0,me->query_skill("hellfire-whip",1)/4);
	}	
	return 1;
}

int help(object me)
{
string str;
if ( !me )      return 0;
str = @LONG
        外功名称：神·人·鬼
        外功所属：烈 火 鞭
        外功效果：分别以掌、棒、剑招式对敌连续攻击3次
        	  如果各招式激发为地府技能，则每次均带固定伤害
        	  如烈火鞭达到350级并激发，则追加一次带固定伤害的攻击
                  冷却 6 秒
        外功条件：
        	  人物等级10级	
                  烈火鞭100级
                  内力800点，消耗150点
                  不可与人·鬼·神连用
LONG;
me->start_more(str);
return 1;
}

