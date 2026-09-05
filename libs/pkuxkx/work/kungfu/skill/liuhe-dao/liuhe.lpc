// 六合归虚

#include <ansi.h>
#include <char.h>
#include <combat.h>
inherit F_SSERVER;

int valid_target_arg(string target)
{
    if ( target == "version" ) return 2;
    return target=="null" || target=="other" ;
}

int perform(object me, object target)
{
	string msg;
	int pp,damage,mm,tt;
	object weapon;
	int i;
    int times;
    mapping attack_val = ([
        "base" : ([ "weapon" : "blade", ]),//基本功夫类型
        "skill" : ([ "weapon" : "liuhe-dao", ]),//高级技能名称
        ]);

	if( !target ) target = offensive_target(me);

	if( !target || !target->is_character() || !me->is_fighting(target) )
		return notify_fail("「六合归虚」只能对战斗中的对手使用。\n");

    if( !objectp(weapon = me->query_temp("weapon")) || weapon->query("skill_type") != "blade" )
            return notify_fail("你手中无刀，怎么使用「六合归虚」？\n");

	//if(!wizardp(me)) return notify_fail("目前只有神可以适用这一招\n");

/*	if( me->is_busy() )
	return notify_fail("你自顾不暇，哪有功夫施展绝技！\n"); */
	
	if( me->query_skill("liuhe-dao",1) < 1000 )
		return notify_fail("你六合刀法不太熟练，不能使出「六合归虚」一式。\n");

    if( !(me->query_temp("ignore_pfm_limit") & IGNORE_PFM_LIMIT_FAMILY) &&
        !me->query("liuhe-zhidian"))
        return notify_fail("你对「六合归虚」始终不得要领，也许需要有高人指点才能领悟。\n");

	if( me->query("neili") < 3000 )
		return notify_fail("你内力不够，不能使出『六合归虚』一式。\n");

	msg = HIG "$N" HIG "幽幽的叹口气，唱到：天地崩兮六道断绝，日月昏兮六合归虚。只见$N" HIG "手中的$w" HIG "散发出可怖的气势，以惊人的速度砍出六刀！" NOR;

	me->start_busy(3 + random(2));

	me->add_temp("apply/damage",me->query_skill("liuhe-dao",1)/2);
	me->add_temp("apply/attack",me->query_skill("liuhe-dao",1)/2);
    times = 6;
    if(me->query("betrayer") > 0)
    {
        times = times/(me->query("betrayer")+1);
    }
    if(times < 1) times = 1;

	for(i=0;i<times;i++)
	{
		if(target->query_skill("qiankun-danuoyi"))
		{
			message_vision("$N看出$n身负大挪移绝技，刀刀都留有余力，叫$n无力可借。\n$n一声惨嚎，中了一刀！\n",me,target);
			damage=random(me->query_skill("liuhe-dao",1));
			damage+=random(me->query_skill("liuhe-dao",1));
			if ( damage< 100 ) damage=100;
			if ( damage> 3000 ) damage=3000;
			damage+=random(me->query_skill("liuhe-dao",1));
			F_KUNGFU->hit_wound("qi", damage, damage/5, me, target);
            COMBAT_D->report_status(target);
		}
		else
		{
            if ( !objectp(me->query_temp("weapon")) ) break;
            me->set_temp("attack_val", attack_val);
			COMBAT_D->do_attack(me, target, weapon, TYPE_SPECIAL, msg);
		}
	}
	me->add_temp("apply/damage",-me->query_skill("liuhe-dao",1)/2);
	me->add_temp("apply/attack",-me->query_skill("liuhe-dao",1)/2);	
    me->add("neili",-2000);
	
	return 1;
}
