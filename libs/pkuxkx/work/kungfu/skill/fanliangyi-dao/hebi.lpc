//玉女素心剑法 双剑合璧 hebi.c
//by vast 2003.3.22

#include <ansi.h>
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
	int extra, i, j;
	string *style = ({
                HIR"$N突然间双刀一交，攻势及守势飓然大盛，配合得天衣无缝！"NOR,
                MAG"$N灵犀暗通，$w随即劈出，$n只见眼前阵阵刀光，不知如何是好！"NOR,
	});
    mapping attack_val = ([
        "base" : ([ "weapon" : "blade", ]),//基本功夫类型
        "skill" : ([ "weapon" : "fanliangyi-dao", ]),//高级技能名称
        ]);

	object ob,*obs;

	if( !target ) target = offensive_target(me);

	if( !target || !target->is_character() || !me->is_fighting(target) )
         return notify_fail("［双刀合璧］只能对战斗中的对手使用。\n");

	if( !pointerp(obs=me->query_team()) )
		return notify_fail("必须两人组队才可以发动此式！\n");

	if( sizeof(obs) >2 )
        return notify_fail("［双刀合璧］只能两人同使！！\n");

	if ( me->is_team_leader() )
	{
		j = 1;
	}
	else
	{
		j = 0;
	}

    if(!obs[j]->query_skill("fanliangyi-dao",1))
        return notify_fail("你的同伴不会反两仪刀法。\n");

    if(environment(obs[j]) != environment(me))
        return notify_fail("你的同伴不在你身边。\n");

    if(me->query_skill("fanliangyi-dao",1) < 40)
        return notify_fail("你的反两仪刀法等级不够！\n");

    if(obs[j]->query_skill("fanliangyi-dao",1) < 40)
        return notify_fail("你同伴的反两仪刀法等级不够！\n");

    if( !objectp(ob=me->query_temp("weapon")) || ob->query("skill_type") != "blade" )
        return notify_fail("你没有用刀，无法使用［双刀合璧］！\n");

    for(i=0;i<sizeof(obs);i++)
	{
		if(!obs[i]) return notify_fail("你需重新组合队伍。\n");

		if(!objectp(ob=obs[i]->query_temp("weapon")) || ob->query("skill_type") != "blade" )
            return notify_fail("你的同伴没有用刀，无法使用［双刀合璧］！\n");
	}

//	message_vision(HIY+"\n\n$N高喝一声：－双－剑－合－壁－！！\n"+HIW+"--------------------------------------双剑合璧！！\n\n"NOR,me);

	ob = me->query_temp("weapon");
	msg = style[0];
    extra = me->query_skill("blade", "fanliangyi-dao");
    me->add_temp("apply/attack", 2*extra);
    me->add_temp("apply/damage", extra);
    me->set_temp("attack_val", attack_val);
	COMBAT_D->do_attack(me, target, ob, TYPE_SPECIAL, msg);
	me->add_temp("apply/attack", -2*extra);
	me->add_temp("apply/damage", -extra);
	me->start_busy(3);

	ob = obs[j]->query_temp("weapon");
	msg = style[1];
    extra = obs[j]->query_skill("blade", "fanliangyi-dao");
    obs[j]->add_temp("apply/attack", 2*extra);
    obs[j]->add_temp("apply/damage", extra);
    obs[j]->set_temp("attack_val", attack_val);
	COMBAT_D->do_attack(obs[j], target, ob, TYPE_SPECIAL, msg);
	obs[j]->add_temp("apply/attack", -2*extra);
	obs[j]->add_temp("apply/damage", -extra);
	obs[j]->start_busy(3);

	return 1;
}
