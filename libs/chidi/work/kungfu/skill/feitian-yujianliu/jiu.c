// tie@fengyun
#include <skill.h>
#include <weapon.h>
#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;
int perform(object me, object target)
{
	string msg;
	int extra;
	int i,lmt;
	object weapon;
	if( !target ) target = offensive_target(me);

	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("九头龍闪只能对战斗中的对手使用。\n");
	weapon = me->query_temp("weapon");
	if (!weapon) return notify_fail("你没装兵器怎么打！\n");
	if( (string)weapon->query("skill_type") != "sword" )
	return notify_fail("你使用的兵器不对！\n");
      
	if ( (string) me->query_skill_mapped("sword") != "feitian-yujianliu")
	return notify_fail("你不是使用的飞天御剑流使用不出来！\n");
        
       if( (int)me->query_skill("feitian-yujianliu", 1) < 150 )
		return notify_fail("你的飞天御剑流不够熟练，使不出九头龍閃。\n");

       if( (int)me->query_skill("shayi-xinfa", 1) < 150 )
		return notify_fail("你的杀意心法不够熟练，使不出九头龍閃。\n");
     
       if (!(me->query("feitian/jiu") & 1))
              return notify_fail("你虽然听说过“九头龍闪”这一招，可是却未获传授。\n");
       
       if(me->query("family/family_name") != "飞天御剑流")
              return notify_fail("你并非飞天御剑流传人，无法体会到绝招。\n");

            me->add("neili",-250);
extra+=me->query_skill("shayi",1)/10;
        weapon = me->query_temp("weapon"); 
        msg = HIR "$N脚下速度突增，同时使出［飞天御剑流］的精髓－－九头龙闪，手中的"+ weapon->name() +"划出一道道长虹，闪电般的刺向$n！" NOR; 
        message_vision(msg,me,target); 
        me->add_temp("apply/attack",extra*5); 
        me->add_temp("apply/damage",extra*5); 
       
       lmt=me->query_skill("feitian-yujianliu",1) /60;
       if (lmt > 10) lmt=10;
for(i=1;i<=lmt;i++)
       {
	msg = HIR "你身形急转刺出第"BLINK + HIW ""+chinese_number(i)+""NOR""HIR"剑！" NOR; 
COMBAT_D->do_attack(me,target,me->query_temp("weapon"),TYPE_REGULAR,msg); 
} 
me->add_temp("apply/attack",-extra*5); 
me->add_temp("apply/damage",-extra*5); 
me->start_busy(2); 
return 1; 
} 
