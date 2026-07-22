// Jiaoyang.c 天火直下
// Cracked by 凌惊雪 4-1-2003
#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int perform(object me, object target)
{
	object weapon;
        string msg;
      	int dodge,damage;
      	
      	if( me->query_level()<35 )
      		return notify_fail("你的人物等级不够。\n");

        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me
        || !me->is_fighting(target) )
                return notify_fail("你要对谁施展这一招「天火直下」？\n");
	if( !objectp(weapon=me->query_temp("weapon"))
	 || weapon->query("skill_type")!="sword" )
	 	return notify_fail("你的剑呢？\n");
        if( me->query_skill("lieyang-jian",1) < 350)
                return notify_fail("你的烈阳剑法等级不够, 不能使用「天火直下」！\n");
        if( me->query("force") < 800 )
                return notify_fail("你的内力不够，无法运用「"+HIR"天火直下"+HIY"」！\n");
	if( me->query("kee")<150 )
		return notify_fail("你体力有些不支。\n");
	
	me->add("force", -200);	
	me->receive_damage("kee",100);
	dodge = me->query_skill("dodge")/10;
	me->add_temp("apply/combat_succ",dodge);
	damage = me->query_skill("sword")/10;
	if( damage>500 )
		damage = 500;
	msg = HIR"$N"HIR"咬破舌尖，朝$w"HIR"猛吐一口鲜血，但见$w"HIR"顿时热气扑面，$N"HIR"顺势展开疯狂攻击！\n"NOR;
	me->set_temp("pfm_color","HIR");
	COMBAT_D->do_attack(me,target,me->query_temp("weapon"),TYPE_PERFORM,msg,0,0,damage);	    	
    	COMBAT_D->do_attack(me,target,me->query_temp("weapon"),TYPE_PERFORM,0,0,0,damage);
    	COMBAT_D->do_attack(me,target,me->query_temp("weapon"),TYPE_PERFORM,0,0,0,damage);
    	
    	me->add_temp("apply/combat_succ",-dodge);
    	me->delete_temp("pfm_color");
    	me->start_busy(2);
    	return 1;
}

int help(object me)
{ 
string str; 
if ( !me )      return 0; 
str = @LONG 
              外功名称：天火直下
              外功所属：烈阳剑法
              外功效果：连续攻击对方三次，最大固定伤害500
              		自身busy 2 秒
              外功条件：
              		人物等级35级
                        烈阳剑法350级
                        内力800点，消耗200点
                        气血150点，消耗100点
LONG; 
me->start_more(str); 
return 1; 
} 