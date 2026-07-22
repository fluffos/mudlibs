// Jiaoyang.c 骄阳似火
// Cracked by 凌惊雪 4-1-2003
#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int perform(object me, object target)
{
	object weapon;
        string msg;
      	int dodge,damage;
      	
      	if( me->query_level()<30 )
      		return notify_fail("你的人物等级不够。\n");

        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me
        || !me->is_fighting(target) )
                return notify_fail("你要对谁施展这一招「骄阳似火」？\n");
	if( !objectp(weapon=me->query_temp("weapon"))
	 || weapon->query("skill_type")!="sword" )
	 	return notify_fail("你的剑呢？\n");
        if( me->query_skill("lieyang-jian",1) < 300)
                return notify_fail("你的烈阳剑法等级不够, 不能使用「骄阳似火」！\n");
        if( me->query("force") < 500 )
                return notify_fail("你的内力不够，无法运用「"+HIR"骄阳似火"+HIY"」！\n");
    	if( time()-(int)me->query_temp("public_jiaoyang")<5 )
		return notify_fail("绝招用多就不灵了！\n");
    	
    	msg = HIY"$N"HIY"清啸一声,使出「烈阳剑」中的绝技「娇阳似火」发魔般地向$n"HIY"刺出两剑！\n" NOR;
    	message_vision(msg, me, target);
    	me->add("force", -150);
    	me->set_temp("public_jiaoyang",time());
    	me->set_temp("PERFORM_LIEYANG",8);
	dodge = me->query_skill("dodge")/10;
	me->add_temp("apply/combat_succ",dodge);
	damage = me->query_skill("sword");
	if( damage>1000 )
		damage = 1000;

    	msg = HIR"●"+HIY"烈日"+HIR"●"NOR;
    	COMBAT_D->do_attack(me,target,me->query_temp("weapon"),TYPE_PERFORM,msg,0,0,damage);
    	
    	msg =  HIR"●"+HIY"娇阳"+HIR"●"NOR;
    	COMBAT_D->do_attack(me,target,me->query_temp("weapon"),TYPE_PERFORM,msg,0,0,damage);
    	
    	me->add_temp("apply/combat_succ",-dodge);
    	me->delete_temp("PERFORM_LIEYANG");
    	return 1;
}

int help(object me)
{ 
string str; 
if ( !me )      return 0; 
str = @LONG 
              外功名称：骄阳似火
              外功所属：烈阳剑法
              外功效果：连续攻击对方两次，最大固定伤害1000
              		冷却时间6秒
              外功条件：
              		人物等级30级
                        烈阳剑法300级
                        内力500点，消耗150点
LONG; 
me->start_more(str); 
return 1; 
} 