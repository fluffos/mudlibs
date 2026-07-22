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
                return notify_fail("你要对谁施展这一招「祝融怀焰」？\n");
	if( !objectp(weapon=me->query_temp("weapon"))
	 || weapon->query("skill_type")!="spear" )
	 	return notify_fail("你的枪呢？\n");
        if( me->query_skill("shenghuo-spear",1) < 350)
                return notify_fail("你的圣火枪法等级不够, 不能使用「祝融怀焰」！\n");
        if( me->query("force") < 500 )
                return notify_fail("你的内力不够，无法运用「"+HIR"祝融怀焰"+HIY"」！\n");
    	
    	me->add("force", -200);
    	dodge = me->query_skill("dodge")/25;
	me->add_temp("apply/attack",dodge);
	damage = me->query_skill("spear");
	me->add_temp("apply/combat_damage",damage);
	me->set_temp("pfm_color","HBRED");		
	me->set_temp("pfm-shenghuo",6);
    	COMBAT_D->do_attack(me,target,me->query_temp("weapon"),TYPE_PERFORM);
    	me->set_temp("pfm-shenghuo",7);
    	COMBAT_D->do_attack(me,target,me->query_temp("weapon"),TYPE_PERFORM);
    	me->set_temp("pfm-shenghuo",8);
    	COMBAT_D->do_attack(me,target,me->query_temp("weapon"),TYPE_PERFORM);
    	me->delete_temp("pfm_color");
    	me->add_temp("apply/attack",-dodge);
    	me->add_temp("apply/combat_damage",-damage);
    	me->delete_temp("pfm-shenghuo");
    	me->start_busy(3);
    	return 1;
}

int help(object me)
{ 
string str; 
if ( !me )      return 0; 
str = @LONG 
              外功名称：祝融怀焰
              外功所属：圣火枪法
              外功效果：攻击对方三次
              		自身busy 3 秒
              外功条件：
              		人物等级35级
                        圣火枪法350级
                        内力500点，消耗200点
LONG; 
me->start_more(str); 
return 1; 
} 