// pikong.c by Jpei
#include <ansi.h>
#include <char.h>
#define Menpai "桃花岛"
inherit F_SSERVER;

int valid_target_arg(string target)
{
    if ( target == "version" ) return 2;
    return target=="null" || target=="other" ;
}

int perform(object me, object target)
{
    int damage, p;
    string msg;

    if( !target ) target = offensive_target(me);

    if( !objectp(target) ) return notify_fail("你想劈谁？\n");

    if( !target->is_character() || !me->is_fighting(target) )
        return notify_fail("劈空掌只能对战斗中的对手使用。\n");

    if (wiz_level(me) < wiz_level(target))
            return notify_fail("你不能攻击巫师等级比你高的对手。\n");

    if( (int)me->query_skill("bihai-shengong", 1) < 200 )
            return notify_fail("你的碧海神功修为不够，使不出劈空掌。\n");

    if( (int)me->query_skill("luoying-zhang",1) < 200 )
            return notify_fail("你的掌法修为不足，使不出劈空掌。\n");

    if( (int)me->query("neili") < 1000 )
            return notify_fail("你现在内力太弱，使不出劈空掌。\n");

    if( (int)me->query("jiali") < 100 )
            return notify_fail("你现在加力太弱，使不出劈空掌。\n");

    if( (!(me->query_temp("ignore_pfm_limit") & IGNORE_PFM_LIMIT_FAMILY) && me->query("thd/lyz") != 3)
/*        || me->query_skill_prepared("strike") != "luoying-zhang"
        || me->query_skill_mapped("strike") != "luoying-zhang"
        || me->query_skill_mapped("parry") != "luoying-zhang" */
        || (!(me->query_temp("ignore_pfm_limit") & IGNORE_PFM_LIMIT_FORCE) && 
            me->query_skill_mapped("force") != "bihai-shengong") )
        return notify_fail("你现在无法使用劈空掌进行攻击！\n");

    if( !(me->query_temp("ignore_pfm_limit") & IGNORE_PFM_LIMIT_FAMILY) &&
        me->query("family/family_name")!=Menpai && me->query("chushi/last_family")!=Menpai 
        && !(me->query("tqt/old_family") && member_array(Menpai,me->query("tqt/old_family"))!=-1))
        return notify_fail("劈空掌是桃花岛不传之密！\n");

    me->add("neili", -200);
    msg = HIB "\n$N长啸一声，一式劈空掌向$n击到，落英神剑掌风挟带著澎湃汹涌的碧海神功蜂拥而至，其势殊不可挡！\n"NOR;
    if ( F_KUNGFU->hit_rate( me->query_skill("dodge"), target->query_skill("dodge"), 6, me, target)
     && !F_KUNGFU->hit_rate( target->query("combat_exp")/3, me->query("combat_exp"), 18, me, target) ) 
    {
        if (!target->is_busy()) target->start_busy(1+random(2));
        damage = (int)me->query_skill("bihai-shengong", 1) + (int)me->query_skill("luoying-zhang");
        damage = damage + random(me->query("jiali") * 8);
        if (damage > me->query_skill("bihai-shengong", 1)*8) damage = me->query_skill("bihai-shengong", 1)*8;
        F_KUNGFU->hit_wound("qi", damage, damage/3, me, target);
        me->add("neili", -me->query("jiali"));
        if (me->query("neili") < 0)  me->set("neili",0);
        msg += HIR"结果劈空掌重重的打在$n的胸口，$n登时鲜血狂喷。\n"NOR;
    }
    else 
    {
        msg += CYN"$n见掌势猛烈，急忙向旁一让，$N这一掌便即落空。\n"NOR;
    }
    message_vision(msg, me, target);
    COMBAT_D->report_status(target);
    me->start_busy(3+random(2));

    return 1;
}

