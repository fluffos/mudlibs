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
        HIM"$N缓缓使动玉女素心剑法，探出手中$w刺向$n，端的是柔肠百转，缠绵相思！"NOR,
        MAG"$N灵犀暗通，施展出全真剑法，$w纵横是宾，分进合击，$n眼花缭乱，不知剑招从何处攻来！"NOR,
    });
    mapping attack_val_1 = ([
        "base": ([ "weapon" : "sword" ]),//基本功夫类型
        "skill" : ([ "weapon" : "yunu-jianfa" ]),//高级技能名称
        ]);
    mapping attack_val_2 = ([
        "base": ([ "weapon" : "sword" ]),//基本功夫类型
        "skill" : ([ "weapon" : "quanzhen-jian" ]),//高级技能名称
        ]);

    object *obs, weapon;

    if( !target ) target = offensive_target(me);

    if( !objectp(target) || !target->is_character() || !me->is_fighting(target) )
        return notify_fail("［双剑合璧］只能对战斗中的对手使用。\n");

    if ( !objectp(weapon = me->query_temp("weapon")) || (string)weapon->query("skill_type") != "sword")
            return notify_fail("你需要装备sword类武器才能使用双剑合璧的绝招。\n");

    if( !pointerp(obs=me->query_team()) )
        return notify_fail("必须两人组队才可以发动此式！\n");

    if( sizeof(obs) >2 )
        return notify_fail("［双剑合璧］只能两人同使！！\n");

    if ( me->is_team_leader() ) 
    {
        j = 1;
    }
    else
    {
        j = 0;
    }

    if((me->query_skill_mapped("force") != "yunu-xinfa" && me->query_skill_mapped("force") != "jiuyin-shengong") || 
        (obs[j]->query_skill_mapped("force") != "yunu-xinfa" && obs[j]->query_skill_mapped("force") != "jiuyin-shengong"))
            return notify_fail("［双剑合璧］需要两人都运用古墓派的心法！\n");

    if(!obs[j]->query_skill("quanzhen-jian",1)) 
        return notify_fail("你的同伴不会全真剑法。\n");

/*    if(obs[j]->query_skill_mapped("sword") != "quanzhen-jian") 
        return notify_fail("你的同伴没有使用全真剑法！\n"); */

    if(environment(obs[j]) != environment(me)) 
        return notify_fail("你的同伴不在你身边。\n");

    if(me->query_skill("yunu-jianfa",1) < 150)
        return notify_fail("你的玉女剑法等级不够！\n");

    if(obs[j]->query_skill("quanzhen-jian",1) < 150)
        return notify_fail("你同伴的全真剑法等级不够！\n");

    for(i=0;i<sizeof(obs);i++)
    {
        if(!obs[i]) return notify_fail("你需重新组合队伍。\n");

        if( !objectp(weapon = obs[i]->query_temp("weapon")) ) 
            return notify_fail("你的同伴没有兵器无法使用［双剑合璧］！\n");
        if( weapon->query("skill_type") != "sword" ) 
            return notify_fail("［双剑合璧］当然要你的同伴也用剑才行！\n");
    }


    //	message_vision(HIY+"\n\n$N高喝一声：－双－剑－合－壁－！！\n"+HIW+"--------------------------------------双剑合璧！！\n\n"NOR,me);

    weapon = me->query_temp("weapon");
    msg = style[0];
    extra = me->query_skill("sword", "yunu-jianfa");
    me->add_temp("apply/attack", 2*extra);
    me->add_temp("apply/damage", extra);
    me->set_temp("attack_val", attack_val_1);
    COMBAT_D->do_attack(me, target, weapon, TYPE_SPECIAL, msg);
    me->add_temp("apply/attack", -2*extra);
    me->add_temp("apply/damage", -extra);
    me->start_busy(3);

    weapon = obs[j]->query_temp("weapon");
    msg = style[1];
    extra = obs[j]->query_skill("sword", "quanzhen-jian");
    obs[j]->add_temp("apply/attack", 2*extra);
    obs[j]->add_temp("apply/damage", extra);
    obs[j]->set_temp("attack_val", attack_val_2);
    COMBAT_D->do_attack(obs[j], target, weapon, TYPE_SPECIAL, msg);
    obs[j]->add_temp("apply/attack", -2*extra);
    obs[j]->add_temp("apply/damage", -extra);
    obs[j]->start_busy(3);

    return 1;
}
