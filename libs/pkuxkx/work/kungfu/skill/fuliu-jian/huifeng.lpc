// huifeng.c 回风诀

#include <ansi.h>
#include <char.h>
#include <combat.h>
#define Menpai "峨嵋派"
inherit F_SSERVER;

int valid_target_arg(string target)
{
    if ( target == "version" ) return 2;
    return target=="null" || target=="other" ;
}

int perform(object me, object target)
{
    int lvl;
    object weapon;
    string name;
    mapping attack_val = ([
        "base" : ([ "weapon" : "sword", ]),//基本功夫类型
        "skill" : ([ "weapon" : "fuliu-jian", ]),//高级技能名称
        ]);

    if( !target ) target = offensive_target(me);

    if( !objectp(target) || !me->is_fighting(target) )
        return notify_fail("「回风诀」只能在战斗中对对手使用。\n");

    weapon = me->query_temp("weapon");
    if( !objectp(weapon) || weapon->query("skill_type") != "sword" )
        return notify_fail("你手里没有剑，无法使用「回风诀」！\n");
    name = weapon->query("name");

    if( me->check_hand() >=2 )
        return notify_fail("你必须空出一只手才能使用「回风诀」！\n");

    if( (int)me->query_skill("fuliu-jian",1) < 120 )
        return notify_fail("你的回风拂柳剑不够娴熟，不能使用「回风诀」！\n");

    if( (int)me->query_skill("sword",1) < 120 )
        return notify_fail("你的基本剑法等级不够，不能使用「回风诀」！\n");

    if( (int)me->query_skill("jieshou-jiushi", 1) < 120 )
        return notify_fail("你的等级不够，不能使用「回风诀」！\n");

    if( (int)me->query_skill("linji-zhuang", 1) < 120 )
        return notify_fail("你的临济十二庄等级不够，不能使用「回风诀」！\n");

    if( !(me->query_temp("ignore_pfm_limit") & IGNORE_PFM_LIMIT_FORCE) && 
        me->query("family/family_name")!=Menpai && me->query("chushi/last_family")!=Menpai 
        && !(me->query("tqt/old_family") && member_array(Menpai,me->query("tqt/old_family"))!=-1)
        && me->query_skill_mapped("force") != "linji-zhuang" )
            return notify_fail("你不使用临济十二庄，怎么能使用「佛光普照」？\n");

    if( (int)me->query("max_neili") < 1000 )
            return notify_fail("你的内力太弱，不能使用「回风诀」！\n");

    if( (int)me->query("neili") < 500 )
            return notify_fail("你的内力太少了，无法使出「回风诀」！\n");

/*    if( me->query_skill_prepared("hand") != "jieshou-jiushi"
     || me->query_skill_mapped("hand") != "jieshou-jiushi")
            return notify_fail("你不使用截手九式，现在无法加强「回风诀」攻击。\n"); */

    lvl = ((int)me->query_skill("fuliu-jian", 1) + (int)me->query_skill("jieshou-jiushi", 1))/10;

    message_vision(HIW"\n$N长啸一声，身子似回风而起，右手"+name+HIW"刹那间随风抚向$n。\n"NOR, me,target);
    message_vision(HIW"左手截手九式一旋，威力陡然加强！\n"NOR, me,target);

    me->start_busy(2);
    me->add("neili", -lvl);

    me->add_temp("apply/strength", lvl/2);
    me->add_temp("apply/damage", lvl);
    me->add_temp("apply/attack", lvl);

    me->set_temp("attack_val", attack_val);
    COMBAT_D->do_attack(me, target, me->query_temp("weapon"), TYPE_SPECIAL);

    if ( objectp(me->query_temp("weapon")) )
    {
        me->set_temp("attack_val", attack_val);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), TYPE_SPECIAL);
    }

    if ( objectp(me->query_temp("weapon")) )
    {
        me->set_temp("attack_val", attack_val);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), TYPE_SPECIAL);
    }

    if ( objectp(me->query_temp("weapon")) )
    {
        me->set_temp("attack_val", attack_val);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), TYPE_SPECIAL);
    }

    me->add_temp("apply/strength", -lvl/2);
    me->add_temp("apply/damage", -lvl);
    me->add_temp("apply/attack", -lvl);

    return 1;
}

