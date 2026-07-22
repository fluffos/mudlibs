// force.c
inherit SKILL;
#include <combat.h>

//内力反震
mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
	int damage,ap,dp;

	if( me->query_temp("weapon") 
	 || !me || !victim || !me->is_fighting(victim)
	 || !living(victim) )
		return 0;
	if( victim->query("force_factor") )
		return 0;
	if( victim->query("force")<victim->query("force_factor")/5 )
		return 0;
		
	ap = COMBAT_D->skill_power(me,"force",SKILL_USAGE_DEFENSE);
	dp = COMBAT_D->skill_power(victim,"force",SKILL_USAGE_ATTACK);
	if( random(ap+dp)>dp )
		return 0;
	if( COMBAT_D->check_level(me,victim)==1 )
		return 0;
	
	damage = (int)me->query("force")/20 + factor- (int)victim->query("force")/25;
	damage-= victim->query_temp("apply/armor_vs_force")/4000;
	
	if( damage<0 )
	{	
		damage = -damage;
		victim->add("force",victim->query("force_factor")/5 );
		me->receive_damage( "kee", damage,victim,TYPE_EXERT );
		if( damage>2 )
			me->receive_wound( "kee", damage/2,victim,TYPE_EXERT );
		if( damage < 10 ) return "$N受到$n的内力反震，闷哼一声。\n";
		else if( damage < 20 ) return "$N被$n以内力反震，「嘿」地一声退了两步。\n";
		else if( damage < 40 ) return "$N被$n以内力一震，胸口有如受到一记重击，连退了五六步！\n";
		else return "$N被$n的内力一震，眼前一黑，身子向后飞出丈许！！\n";
	}
	else	return 0;	
}
