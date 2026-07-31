
#include <ansi.h>

#include <combat.h>
inherit F_SSERVER;
string* buwei = ({
        "右手肘部",
        "手腕",
        "左手关节",
        "颈部",
        "肩部关节",
        "背心要穴",
        "膝关节",
        "命门"
});
int perform(object me, object target)
{
        object weapon;
        string msg;
       int extra;
        int i, attack_time;
        string bw;
        
        
        bw = buwei[random(sizeof(buwei))];

        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("合气道.擒只能对战斗中的对手使用。\n");
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("合气道.擒必须空手。\n");
       if( (int)me->query("max_neili") < 200 )
      return notify_fail("你的内力不够！\n");
	extra = me->query_skill("aikido",1)/10;
	if(extra <= 3 ) return notify_fail("你的［合气道］不够熟练！\n");
     if ((int)me->query_skill("shayi-xinfa", 1) < 30)
   return notify_fail("你的杀意心法火候不够。\n");
               
	if( (int)me->query("neili") < 200  ) 
		return notify_fail("你的内力不够。\n");

        msg = HIG "$N双眉一扬，一错身用斗然间抓住了$n的"+bw+"然后对"+bw+"死命的一扭！!\n";

        if( random(me->query("combat_exp")) > (int)target->query("combat_exp")/2 ) {
                msg += HIR " 结果$p被$P扭的惨叫不止，看来伤的不清！\n" NOR;
if (userp(target))
                target->add("qi",-target->query("qi")/10);
else            target->add("qi",-extra*20);
        } else {
                msg += HIC"可是$p看破了$P的企图，挣开了$P的擒拿。\n"NOR NOR;
        }
        message_combatd(msg, me, target);
                me->start_busy(2);
	me->add("neili", - 100);
        if(!target->is_fighting(me)) target->fight_ob(me);

        return 1;
}

