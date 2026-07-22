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
                return notify_fail("你要对谁施展这一招「天火燎原」？\n");
	if( !objectp(weapon=me->query_temp("weapon"))
	 || weapon->query("skill_type")!="spear" )
	 	return notify_fail("你的枪呢？\n");
        if( me->query_skill("shenghuo-spear",1) < 300)
                return notify_fail("你的圣火枪法等级不够, 不能使用「天火燎原」！\n");
        if( me->query("force") < 500 )
                return notify_fail("你的内力不够，无法运用「"+HIR"天火燎原"+HIY"」！\n");
    	if( time()-(int)me->query_temp("public_liaoyuan")<6 )
		return notify_fail("绝招用多就不灵了！\n");
    	
    	me->add("force", -150);
    	me->set_temp("public_liaoyuan",time());
    	me->set_temp("pfm-shenghuo",1);
	dodge = me->query_skill("dodge")/10;
	me->add_temp("apply/combat_succ",dodge);
	damage = me->query_skill("spear");
	if( damage>1800 )
		damage = 1800;
	me->set_temp("pfm_color","HBRED");		
    	COMBAT_D->do_attack(me,target,me->query_temp("weapon"),TYPE_PERFORM,0,0,0,damage,"both");
    	me->delete_temp("pfm_color");
    	me->add_temp("apply/combat_succ",-dodge);
    	me->delete_temp("pfm-shenghuo");
    	return 1;
}

int help(object me)
{ 
string str; 
if ( !me )      return 0; 
str = @LONG 
              外功名称：天火燎原
              外功所属：圣火枪法
              外功效果：攻击对方一次，最大固定伤害1200
              		冷却时间6秒
              外功条件：
              		人物等级30级
                        圣火枪法300级
                        内力500点，消耗150点
LONG; 
me->start_more(str); 
return 1; 
} 