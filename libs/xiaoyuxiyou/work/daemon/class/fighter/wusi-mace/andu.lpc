// /daemon/class/fighter/wusi-mace/andu
// 陈仓暗渡
// 不要自己学什么，完全用对方的武功攻击对方
// 慕容绝学？呵呵。。。
// editted by God 2005-6
#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int perform(object me,object target)
{
	string msg;
	mapping action;
	
	if( me->query_level()<10 )
		return notify_fail("你的人物等级不够。\n");
	if( me->query("family/family_name") != "将军府" )
        	return notify_fail("你是哪儿偷学来的武功，也想用「陈仓暗渡」?\n");
	if( (int)me->query_skill("literate",1)<100)
        	return notify_fail("你的读书识字差，怎么晓得行军韬略，用不了「陈仓暗渡」。\n");
	if( (int)me->query_skill("wusi-mace",1)<100)
        	return notify_fail("你的无私锏法不够娴熟，不会使用「陈仓暗渡」。\n");
	if( (int)me->query_skill("lengquan-force",1)<100)
        	return notify_fail("你的冷泉神功不够深厚，不会使用「陈仓暗渡」。\n");
	if( (int)me->query("force")<800)
        	return notify_fail("你现在内力太弱，不能使用「陈仓暗渡」。\n");

	if( !target ) target = offensive_target(me);
	if( !target
 	|| !target->is_character()
 	|| target->is_corpse()
 	|| target==me
 	|| !me->is_fighting(target) )
        	return notify_fail("陈仓暗渡只能对战斗中的对手使用。\n");

	action = target->query("actions");
	if( !action || !mapp(action) )
        	return notify_fail("对方是个什么也不会的菜鸟，看来使这招有点大材小用。\n");
                    
	msg = HIY"$N"HIY"略一凝神，计上心来，「陈仓暗渡」神功妙计斗然施展！\n"NOR;
	message_vision(msg,me);
	me->add("force",-200);
	
	msg = YEL"$N"YEL"施施然递出$n"YEL"所学，好象行军打仗，攻韬守略，居然法度不乱！\n"NOR;
	message_combatd(msg,me,target);
	me->set("actions",action);
	COMBAT_D->do_attack(me,target,me->query_temp("weapon"),TYPE_PERFORM);
	
	msg = YEL"\n$N"YEL"招式未老,紧接着又递出两招「运筹帷幄，决胜于千里之外」。\n"NOR;
	message_combatd(msg,me,target);
	action = target->query("actions");
	me->set("actions",action);
	COMBAT_D->do_attack(me,target,me->query_temp("weapon"),TYPE_PERFORM);
	
	action = target->query("actions");
	me->set("actions",action);
	COMBAT_D->do_attack(me,target,me->query_temp("weapon"),TYPE_PERFORM);	

	msg = HIY"\n$n"HIY"没料自己毕生所学竟然被对手瞬间使出，顿时心灰意冷！\n"NOR;
	message_combatd(msg,me,target);
	me->reset_action();
	me->start_busy(2);
	return 1;
}

int help(object me)
{
string str;     
if ( !me )      return 0;
str = @LONG
        外功名称：陈仓暗渡
        外功所属：无私锏法
        外功效果：使出对方的招式对对方进行连续3次攻击
                  使用后自身busy 2 秒
        外功条件：
        	  将军府弟子
        	  人物等级10级	
                  内力800点，消耗200点
                  读书识字100级
                  无私锏法100级
                  冷泉神功100级
                 
LONG;
me->start_more(str);
return 1;
}

