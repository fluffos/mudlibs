// 
// nx.c 凝血神抓
// by secret
 
#include <ansi.h>
 
inherit F_SSERVER;
 
int perform(object me)
{
	string msg;
	object weapon, target;
        int skill;
        int neili_wound, qi_wound ;

	me->clean_up_enemy();
	target = me->select_opponent();

        skill = me->query_skill("unarmed",1);

	if( !(me->is_fighting() ))
                return notify_fail("「凝血神抓」只能对战斗中的对手使用。\n");
 

	if (objectp(weapon = me->query_temp("weapon")))
                return notify_fail("凝血神抓必须空手使用。\n");


        if( skill < 150)
                return notify_fail("你的「凝血神抓」等级不够, 不能使出「凝血神抓」！\n");

        if( me->query("neili") < 1000 )
                return notify_fail("你的内力不够，无法使用凝血神抓！\n");
 
        msg = HIC "$N凝神聚气，使出一招「凝血神抓」，向$n的胸口抓去。\n"NOR;

	message_vision(msg, me, target);

	{
		if(userp(me))
                        me->add("neili",-800);

        if( random(me->query("combat_exp")) > (int)target->query("combat_exp")/3 )
         {
                msg = HIG "$n只觉得眼前一黑，“哇”的一声喷出一口鲜血！\n"NOR;

                neili_wound = 1000 + random(skill);
		if(neili_wound > target->query("neili"))
			neili_wound = target->query("neili");


                qi_wound = neili_wound;
if (qi_wound <100) qi_wound=100;
if (neili_wound <100) neili_wound=100;
if (qi_wound <10) qi_wound=10;
if (qi_wound >100000) qi_wound=100000;
if (neili_wound <10) neili_wound=10;
if (neili_wound >100000) neili_wound=100000;
		target->add("neili", -neili_wound);
		target->add("qi", -qi_wound);
	        target->add("eff_qi",-qi_wound);
                me->start_busy(random(4)+1);
        } else {
                msg += "可是$p看破了$P的企图，逃出了$P的一抓。\n" NOR;
                me->start_busy(3);
        }
	}
	message_vision(msg, me, target);

	return 1;
}
