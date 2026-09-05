//kuang.c -「狂风二十一式」
// Modified by Venus Oct.1997
// Updated by Jpei Dec.2008 
//左手刀 Changed by Zine 2013
#include <ansi.h>
#include <combat.h>
#include "/kungfu/skill/eff_msg.h";

inherit F_SSERVER;
int perform(object me, object target)
{
        int damage, p, time;
        object weapon;
        string msg;
    
        if( !target ) target = offensive_target(me);
        if( !target||!target->is_character()||!me->is_fighting(target) )
                return notify_fail("你只能对战斗中的对手使用「左手刀」。\n");
        if (!(weapon = me->query_temp("weapon")) || weapon->query("skill_type") != "blade")
                return notify_fail("你必须拿刀才能施展「左手刀」。\n");
        if( (int)me->query_skill("pojun-daofa",1) < 180)
                return notify_fail("你目前功力还使不出「左手刀」。\n");
        if( (int)me->query("neili") < 200 )
                return notify_fail("你的内力不够。\n");
                
        me->add("neili", - 200);
        msg = HIC"$N"+HIC+"冷然看了$n"+HIC+"一眼，突然刀交左手！刹那之间，\n" + "$N"+HIC+"使出战场上令胡人闻风丧胆的『小青左手刀』！\n"NOR;
        time = (int)me->query_skill("pojun-daofa",1) / 20;
        if (time > 10)  time = 10;
        if( F_KUNGFU->hit_rate(me->query("combat_exp"), (int)target->query("combat_exp"), 6, me, target) ){
                if( F_KUNGFU->hit_rate(100, 100, 8, me, target) ){
                       msg += HIC"$n霎时被刀气所逼，只觉十死无生，不得不放弃抵抗\n"NOR;
                       F_KUNGFU->hit_busy( "confuse", time, target );
                }
                damage = (int)me->query_skill("pojun-daofa",1) + (int)me->query_skill("blade", 1) + me->query("jiali");
                damage += random(damage/2);
                if (wizardp(me)) tell_object(me, "damage = " + damage +"\n");
                msg += RED"只见$n已被$N左手刀切得体无完肤，血如箭般由全身喷射而出！\n"NOR;                                                
                F_KUNGFU->hit_wound("qi", damage, damage/2, me, target);
				p = (int)target->query("qi")*100/(int)target->query("max_qi");
                msg += "( $n"+eff_status_msg(p)+" )\n";  
                me->add("neili", -me->query("jiali")/2);
				COMBAT_D->report_status(target);
        } 
        else{
                msg += HIC "可是$p急忙抽身躲开，$P这招没有得逞。\n" NOR;
                me->start_busy( time / 2 );
        }
        message_combatd(msg, me, target); 
        me->start_busy(2);

        return 1;
}

