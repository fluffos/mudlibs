// lian.c 「慈悲连环」
#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int perform(object me,object target)
{
	int skill,i,damage;
	string msg;
	mapping action;

	if( me->query_level()<20 )
		return notify_fail("你的人物等级不够。\n");
	if( me->query_skill("cibeidao",1)<200 )
        	return notify_fail("你的慈悲刀法不够娴熟，不会使用「慈悲连环」。\n");
	if( me->query("force")<2000 )
    		return notify_fail("你的真气不够，无法使用「慈悲连环」。\n");
	if( time()<(me->query_temp("putuo_lian")+6) )
    		return notify_fail("绝招用多就不灵了。\n");
	if( !target ) 
    		target = offensive_target(me);        
	if( !target        
 	 || !target->is_character()        
 	 || target->is_corpse()        
 	 || !me->is_fighting(target) )    
		return notify_fail("「慈悲连环」只能对战斗中的对手使用。\n");

	me->set_temp("putuo_lian",time());
    	me->add("force",-100);
	msg = HIY"$N"HIY"面带悲戚之色，手中$W"HIY"招式忽然间变得杂乱无章，刀刀之间仿佛带有一股「我不入地狱，谁入地狱」之意！\n"NOR;
	me->set_temp("pfm_msg",1);
	COMBAT_D->do_attack(me,target,me->query_temp("weapon"),TYPE_PERFORM,msg);
        me->set_temp("pfm_msg",0);
	skill = me->query_skill("cibeidao",1);
    	skill/= 100;
    	if( skill>4 ) skill = 4;
	me->add("force",-50*skill);
    	for(i=0;i<skill;i++)
    	{
    		if( !me || !target || !me->is_fighting(target) )
        		break;
        	if( me->query_skill("cibeidao",1)<(200+(i+1)*10) )
        		break;	
        	if( me->query("force")<100 )
        	{
        		message_combatd(HIW"\n$N"HIW"内力不济，停住了攻击。\n"NOR,me);
            		break;
		}
		damage = 10*(i+5);
		
		target->reset_action();   
		action = target->query("actions");
		if( action )
			msg = action["action"];
		me->set_temp("action_flag",1);
		me->set_temp("pfm_msg",1);
        	COMBAT_D->do_attack(me,target,me->query_temp("weapon"),TYPE_PERFORM,msg,0,0,damage);
        	me->reset_action();   
	}
    	me->set_temp("action_flag",0);
    	me->set_temp("pfm_msg",0);
	return 1;
}

int help(object me)
{
string str;
if( !me )      return 0;       

str = @LONG
        外功名称：慈悲连环
        外功所属：慈悲刀法
        外功效果：以莲台心法体会对方的招意，使出与对方相似的招式连续3次攻击
                  从第二击开始，附带固定伤害，固定伤害递增
                  内力足够的情况下每100击增加一击，内力消耗增加50点，共5击
                  使完冷却时间6秒
        外功条件：
        	  人物等级20级
                  内力2000点，消耗100点，每追加一击，增加消耗50点
                  慈悲刀法200级
LONG;
me->start_more(str);
return 1;
}
