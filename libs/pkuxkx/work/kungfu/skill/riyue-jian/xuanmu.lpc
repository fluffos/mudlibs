// 眩目 - 日月剑法 

#include <ansi.h>
#include <char.h>
inherit F_SSERVER;

int valid_target_arg(string target)
{
    if ( target == "version" ) return 2;
    return target=="null" || target=="other" ;
}

int perform(object me, object target)
{
	string msg;
	int damage,jian;
	object weapon;
	int busy_time;
    int my_busy;

	if( !target ) target = offensive_target(me);

	if( !target || !target->is_character() || !me->is_fighting(target) )
		return notify_fail("「眩目」只能对战斗中的对手使用。\n");

    if (!objectp(weapon = me->query_temp("weapon")) || weapon->query("skill_type") != "sword")
        return notify_fail("你右手没拿剑,还想使剑法的绝招?别作梦了!\n");

/*    if (!objectp(weapon = me->query_temp("weapon")) || (string)weapon->query("skill_type") != "sword")
    if (!objectp(weapon = me->query_temp("secondary_weapon")) || (string)weapon->query("skill_type") != "sword")
        return notify_fail("你没拿剑,还想使剑法的绝招?别作梦了!\n"); */

    if( target->is_busy() )
        return notify_fail(target->name() + "忙得不可开交，你炫给谁看啊?\n");

    if(me->query_skill("riyue-jian",1)<100)
        return notify_fail("你日月剑法不太熟练，不能使出「眩目目」一式。\n");

    if(me->query("neili")<200)
        return notify_fail("你内力不够，不能使出「眩目」一式。\n");

	me->delete_temp("riyue/usingjian");

    if ( objectp(weapon = me->query_temp("weapon")) 
         && ( weapon->query("id") == "riyue jian" || me->query("riyuepfm/jian") 
              && ((me->query_temp("ignore_pfm_limit") & IGNORE_PFM_LIMIT_FAMILY) || me->query("family/family_name")=="日月神教")
              && me->query_skill("riyue-jian",1) > 1000*me->query("int")/me->query("str") ) )
        me->add_temp("riyue/usingjian",1);
        
	if ( objectp(weapon = me->query_temp("secondary_weapon"))
         && ( weapon->query("id") == "riyue jian" || me->query("riyuepfm/jian") 
             && ((me->query_temp("ignore_pfm_limit") & IGNORE_PFM_LIMIT_FAMILY) || me->query("family/family_name")=="日月神教")
             && me->query_skill("riyue-jian",1) > 1000*me->query("int")/me->query("str") ) )
		me->add_temp("riyue/usingjian",1);
    
	jian = (int)me->query_temp("riyue/usingjian");
    busy_time=(int)me->query_skill("riyue-jian",1) * (jian + 1)/50;
    my_busy=random(600 / (int)me->query_skill("riyue-jian",1)+1);
    if (my_busy<=1) my_busy=1;
    if (busy_time<=1) busy_time=1;
	msg = HIG "$N使出日月剑法的「眩目」一式，剑式突然加快，映出点点剑光。\n";
          me->start_busy(my_busy);
          me->add("neili",-100);
	if( F_KUNGFU->hit_rate(me->query("combat_exp"), (int)target->query("combat_exp"), 12-3*jian, me, target) ) 
	{
		msg += HIG "$p眼前出现千万支剑影，如道道电光，吓得不知该从何处进攻才好。\n" NOR;     
		F_KUNGFU->hit_busy( "confuse", busy_time, target );
	}
	else
    {
	    msg += HIG "可是$p看破了$P的企图，并没有上当。\n" NOR;
        if (me->query("riyuepfm/jian")&&me->query("family/family_name")=="日月神教"&&!random(5))
        {
            msg+=HIW+"谁知$P竟还有后招，剑光布满$p全身。\n"NOR;
            target->add_busy(1+random(5));
        }
    }
	message_vision(msg, me, target);
	return 1;
}

