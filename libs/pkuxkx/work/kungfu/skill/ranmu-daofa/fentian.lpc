// fentian.c 举火焚天

#include <ansi.h>
#include <char.h>
#include "/kungfu/skill/eff_msg.h";
inherit F_SSERVER;

object bingcanyi;
void remove_effect(object me);

int valid_target_arg(string target)
{
    if ( target == "version" ) return 2;
    return target=="null" || target=="other" ;
}

int perform(object me, int amount)
{
        string msg;
        object weapon, target;
        int skill, damage, p, ap, dp;
        weapon = me->query_temp("weapon");  
        skill= me->query_skill("ranmu-daofa",1);

        if( !target ) target = offensive_target(me);

        if( !objectp(target) || !target->is_character() || !me->is_fighting(target) )
                return notify_fail("「举火焚天」只能对战斗中的对手使用。\n");

        if ( !objectp(weapon) || weapon->query("skill_type") != "blade" )
/*         || me->query_skill_mapped("blade") != "ranmu-daofa") */
                return notify_fail("你没有木刀，使不出「举火焚天」绝技！\n");

        if (weapon->query("unique"))
                return notify_fail("你手中之刀过于锋利，影响你运功发火！\n");

        if (weapon->query("id") != "mu dao" && weapon->query("material") != "wood")
                return notify_fail("你没有木刀，使不出「举火焚天」绝技！\n");

        if((int)me->query_skill("ranmu-daofa", 1) < 150 )
                return notify_fail("你的燃木刀法火候不够，使不出「举火焚天」。\n");

        if((int)me->query_skill("blade", 1) < 150 )
                return notify_fail("你的基本刀法还不够娴熟，使不出「举火焚天」绝技。\n");

        if( (int)me->query_skill("yijin-jing", 1) < 150 )
                return notify_fail("你的易筋经修为不够，使不出「举火焚天」绝技。\n");

        if ((int)me->query_skill("strike",1) < 150)
                return notify_fail("你的掌法修为太差，使不出「举火焚天」绝技。\n");

        if ( !(me->query_temp("ignore_pfm_limit") & IGNORE_PFM_LIMIT_FORCE) && 
             me->query_skill_mapped("force") != "yijin-jing")
                return notify_fail("没有易筋经作为根基，是无法使出「举火焚天」绝技的！\n");

        if (me->query_temp("ryb_fumo"))
                return notify_fail("你现在正在使用「金刚伏魔圈」。\n");

        if (me->query_temp("ranmu"))
                return notify_fail("你现在正在使用「焚心」绝技。\n");

        if (me->query_temp("fentian"))
                return notify_fail("你正在使用「焚天」绝技！");

        if (me->query("max_neili") < 1500)
                return notify_fail("你的内力修为不够。\n");

        if (me->query("neili") < 500)
                return notify_fail("你的内力不够。\n");

        me->set_temp("fentian",1);
        me->start_busy(2);
        me->add("neili", -200-random(300));
        ap = ((int)me->query_skill("blade",1) + (int)me->query_skill("strike",1))/2;
        dp = (int)target->query_skill("dodge",1);       
        msg =HIR"\n$N猛然一声大喝，手中的"+weapon->name()+HIR"如一道流星腾空而起，一阵筚拨之声，洒下漫天火焰，\n"+
"刀头指处，一股烈焰熊熊而出。$N聚气于双掌，在间不容发之际，往空虚劈九九八十一掌。\n"NOR;
		
		bingcanyi = target->query_temp("armor/cloth");
		if(objectp(bingcanyi) && bingcanyi->query("id") == "bingcan yi"){
				msg += HIW"\n却见火光刚一触到$n，突然周围寒气大盛，燃木刀的威力顿时被化解的无影无踪。\n"NOR;
				target->start_busy(3+random(2));
                call_out("remove_effect", 5, me);
                me->start_perform(3, "举火焚天");
				message_vision(msg, me, target);
                return 1;
		}
        if( F_KUNGFU->hit_rate(me->query("combat_exp"), target->query("combat_exp"), 6, me, target) && 
        	  !F_KUNGFU->hit_rate(dp, ap, 18, me, target) ) {
                msg += HIR"\n$n见火焰扑面卷来，不免大惊失色，但躲闪无及，被熊熊大火围在当中。\n"NOR;
                damage = me->query_skill("blade", "ranmu-daofa")+me->query_skill("buddhism",1);
                damage += random(damage/2);
                if (damage > 3000) damage = 3000;
                F_KUNGFU->hit_wound("qi", damage*(1+random(4)), damage*(1+random(2)), me, target);
                me->start_perform(5, "举火焚天");
                call_out("remove_effect", 5+random(5), me);
                me->start_busy(2+random(2));
                message_vision(msg, me, target);
                COMBAT_D->report_status(target);
                return 1;
        }
        if(F_KUNGFU->hit_rate(me->query("combat_exp"), target->query("combat_exp"), 4, me, target)) {
                message_vision(HIR"\n$n虽早有防备，但乍见火光耀眼也不禁大吃一惊，急忙跃开规避，也已大是狼狈。\n"NOR,me,target);
                if ( !target->is_busy() )
                  target->start_busy(3+random(2));
                call_out("remove_effect", 5, me);
                me->start_perform(3, "举火焚天");
                return 1;
        }
		
        msg += HIR"\n$n成竹在胸，长袖拂出，一股疾风扑出，漫天火光顿时凝聚成一个火柱，倒卷向$N。\n"NOR;
        damage = skill;
        F_KUNGFU->hit_wound("qi", damage/2, damage/3, me, me);
        message_vision(msg, me, target);
        COMBAT_D->report_status(me);
        me->delete_temp("fentian");
        return 1;
}

void remove_effect(object me)
{
        if ( !objectp(me) )
        	return;
        
        if ( (int)me->query_temp("fentian") ) {
                me->delete_temp("fentian");
                tell_object(me, HIC"火光渐渐暗淡终于消失无踪了。\n"NOR);
        }
}
