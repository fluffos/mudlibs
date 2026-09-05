//五毒神掌

#include <ansi.h>

inherit F_SSERVER;

int perform(object me, object target)
{
	string msg;
    object weapon;
	int dmg_temp,rate_level=10;
	if( !target ) target = offensive_target(me);

	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("你只能在站斗中才能使用『五毒神掌』。\n");

    if (!me->query("赤炼五毒"))
        return notify_fail("你没有得到李莫愁传授五毒神掌！\n");
	if( (int)me->query_skill("chilian-shenzhang",1) < 180)
        return notify_fail("你的赤炼神掌级别太浅，无法使用『五毒神掌』！\n");
    if ((int)me->query_skill("poison",1) < 50 )
		return notify_fail("你的基本毒技太浅，无法使用『五毒神掌』！\n");
    if (me->query("neili")<500)
        return notify_fail("你的内力太少，无法使用『五毒神掌』！\n");
    if( (objectp(weapon = me->query_temp("weapon"))))
                return notify_fail("你必须空手才能使用『五毒神掌』。\n");
	
    me->add_busy(1);
	msg = HIR+"$N默运内力，将毒质逼在掌上，掌心变得透红。\n"+NOR;
    if ( me->query("family/family_name")=="古墓派" && !me->query("chushi/done"))
		{
		rate_level=5;//B- 
		dmg_temp=(int)me->query_skill("chilian-shenzhang",1)*2+random((int)me->query_skill("chilian-shenzhang",1)/2);
		}
	else
		{//D+
		dmg_temp=(int)me->query_skill("chilian-shenzhang",1)+random((int)me->query_skill("chilian-shenzhang",1));
		}
	if  ( F_KUNGFU->hit_rate( me->query("combat_exp"), (int)target->query("combat_exp"), rate_level, me, target)
	    && random(me->query_skill("chilian-shenzhang",1)) >60 ) 
	{
		msg +=HIR+ "$p措不及防，被五毒神掌打了个正着。\n" NOR;
	  F_KUNGFU->hit_wound("qi", dmg_temp, 0, me, target);
    target->receive_wound("jing", 10, me);

    //target->set_temp("death_cond_origin/wudu_poison", me);
	F_POISON->poison_attack(me,target,"wudu_poison", random(me->query_skill("poison",1)/10) + 1 +target->query_condition("wudu_poison"));

    target->set("五毒伤害",(int)me->query_skill("poison",1));
		target->add_busy(1 + random(2)); 		
	} else {
		msg += "可是$p看破了$P的招式，侧身避开。\n" NOR;		
	}
	message_vision(msg, me, target);

	return 1;
}
