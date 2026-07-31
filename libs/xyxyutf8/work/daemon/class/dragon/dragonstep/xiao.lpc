// 龙啸九天 Xiao.c
// Cracked by 凌惊雪 12-15-2002
#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int perform(object me, object target)
{
	if( me->query_level()<8 )
		return notify_fail("你的人物等级不够。\n");
	if( me->query_skill("force", 1)<80 )
        	return notify_fail("以你现在的内功修为还使不出「龙啸九天」。\n");        
	if(me->query_skill("dodge", 1) <80)
		return notify_fail("以你现在的轻功修为还不能化身为龙。\n");        
	if( (int)me->query("force") < 500 )     
        	return notify_fail("你的内力不够。\n");
	if( time()-(int)me->query_temp("xiao_end") < 6 )
        	return notify_fail("绝招用多就不灵了！\n");
		
	if( !target )	
		target = offensive_target(me);
        if( !target || !target->is_character()
         || target->is_corpse()
         || target==me
         || !me->is_fighting(target) )
        	return notify_fail("「龙啸九天」只能在战斗中使用。\n");
	
	message_vision(HIC"$N"HIC"凝神运气，大喝一声，血肉之躯竟化为一条张牙舞爪的苍龙，端地杀气逼人。\n"NOR, me);
	me->set_temp("xiao_end",time());
	me->add("force", -100);
	COMBAT_D->do_attack(me,target,me->query_temp("weapon"),TYPE_PERFORM);
	COMBAT_D->do_attack(me,target,me->query_temp("weapon"),TYPE_PERFORM);
	if(me->query("family/family_name")=="东海龙宫")
		COMBAT_D->do_attack(me,target,me->query_temp("weapon"),TYPE_PERFORM,0,0,0,me->query_skill("dodge"));
	return 1;
}

int help(object me)
{
string str;
if ( !me )      return 0;
str = @LONG
        外功名称：龙啸九天
        外功所属：龙神身法
        外功效果：以龙形之姿连续攻击对方
                  冷却时间 6 秒
        外功条件：
		  人物等级8级
		  基本轻功80级
		  基本内功80级
                  内力500点，消耗100点
                  
LONG;
me->start_more(str);
return 1;
}


