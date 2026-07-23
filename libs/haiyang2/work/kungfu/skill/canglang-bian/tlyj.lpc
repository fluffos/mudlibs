// tie@fengyun
#include <ansi.h>
#include <combat.h> 
         
inherit F_SSERVER; 
int perform(object me, object target)
{
	string msg;
	int extra,count,i;
	object weapon;
	if( !target ) target = offensive_target(me);

	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("［天雷一击］只能对战斗中的对手使用。\n");
	weapon = me->query_temp("weapon");
	extra = me->query_skill("canglang-bian",1) / 5;
	if( extra <=10) return notify_fail("你的天雷破还不够熟练！\n");

      if (! objectp(weapon = me->query_temp("weapon")) ||
              (string)weapon->query("skill_type") != "whip")
                return notify_fail("你使用的武器不对。\n");


        if (me->query_skill("force") < 150)
                return notify_fail("你的内功的修为不够，不能使用「天雷一击」！\n");

        if (me->query_skill("canglang-bian", 1) < 300)  
                return notify_fail("你的「沧浪鞭法 」未臻高妙境界，无法施出「天雷一击」！\n");  

        if (me->query_skill("bibo-shengong", 1) < 150)  
                return notify_fail("你的碧涛玄功修为不够，无法施出「天雷一击」！\n");  

        if (me->query_skill_mapped("whip") != "canglang-bian")  
                return notify_fail("你所用的并非「沧浪鞭法 」，施展不出「天雷一击」！\n");  

        if (me->query("neili") < 500)
                return notify_fail("你的真气不够，无法使用「天雷一击」！\n");
if (extra> 200) extra=200;

	me->add_temp("apply/attack", extra);	
	me->add_temp("apply/damage", extra);
	msg = HIR  "$N力灌鞭梢，手中的"+weapon->query("name")+"＂叭＂的一声，象条毒龙般向$n钻去！" NOR;
	COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
	me->add_temp("apply/attack", -extra);
	me->add_temp("apply/damage", -extra);
	msg = HIR "突然间$N" HIR "猛的猱身扑上，手中" + weapon->name() +
              HIR "急转，便似不要命般地向$n" HIR "猛攻过去。\n" NOR;

        if (random(me->query_skill("whip")) > target->query_skill("parry") / 2)
        {
                msg += HIR "$n" HIR "卒不及防，登时手忙脚乱，招架疏"
                       "散，慌忙中难以抵挡。\n" NOR;
                count = me->query_skill("whip") / 20;
        } else
        {
                msg += HIC "$n" HIC "心底一惊，连忙全神应对，不敢有"
                       "丝毫大意。\n" NOR;
                count = 0;
        }

	message_combatd(msg, me, target);
	me->add("neili", -180);
        me->add_temp("apply/attack", 80);

        for (i = 0; i < 6; i++)
        {

                if (random(3) == 1 && ! target->is_busy())
                        target->start_busy(1);
        	COMBAT_D->do_attack(me, target, weapon, 0);
        }

        me->add_temp("apply/attack", -80);
	me->start_busy(3);
	me->add("neili",-300);
	return 1;
}
