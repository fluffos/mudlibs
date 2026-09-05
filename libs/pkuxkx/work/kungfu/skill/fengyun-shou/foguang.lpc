//fogang.c 佛光普照
// by dubei
// modify by notme 2004/3/17
#include <ansi.h>

inherit F_SSERVER;
#include "/kungfu/skill/eff_msg.h";

int valid_target_arg(string target)
{
    if ( target == "version" ) return 2;
    return target=="null" || target=="other" ;
}

int perform(object me, object target)
{
        int damage, ap, dp, p;
        float at;
        string dodge_skill, msg;
 
        if( !target ) target = offensive_target(me);

        if( !target || !target->is_character() || !me->is_fighting(target) || !living(target))
                return notify_fail("「佛光普照」只能在战斗中使用。\n");

        if( (int)me->query_skill("fengyun-shou", 1) < 180 )
                return notify_fail("你的风云手未成，不能使用「佛光普照」！\n");

        if( (int)me->query("neili") < 1000 )
                return notify_fail("你的内力修为不足，不能使用「佛光普照」！\n"); 

        if( (int)me->query_str() < 25)
                return notify_fail("你的膂力不足，无法发挥「佛光普照」的气势。\n");

        if( (int)me->query_con() < 25)
                return notify_fail("你的根骨欠佳，无法使用「佛光普照」。\n");

/*         if (me->query_skill_mapped("hand") != "fengyun-shou")
                  return notify_fail("你必须运用风云手，才能使用「佛光普照」。\n"); */

    msg = MAG "\n只见$N面显庄严，一式「"HIY"佛光普照"NOR MAG"」，提一口真气，飘身而上，半空中手掌交错，一股内劲狭带着热
浪，如风如火，似雷似电，这一招拍出，击向$n" NOR MAG "，招式平平淡淡，一成不变，但却挡无可挡，避无可避！\n"NOR;
        ap = (int)me->query_skill("fengyun-shou")/10 * (int)me->query("neili")/10 * (int)me->query_str()/10;
        dp = (int)target->query_skill("force", 1)/10 * (int)target->query("neili")/10 * (int)target->query_con()/10;
        ap += (int)me->query("combat_exp")/100;
        dp += (int)target->query("combat_exp")/100;

        me->start_busy(3);        
        if( F_KUNGFU->hit_rate(ap, dp, 9, me, target)){
                if ( !target->is_busy() )
                  target->start_busy(random(3));
                damage = me->query_skill("yijin-jing",1) + me->query_skill("fengyun-shou", 1);
                damage *= 3;
                if(target->query("neili") < 1) at = 5;
                else at = me->query("neili") / target->query("neili");
                if(at < 1){
                    if(at < 0.5) damage /= 2;
                    damage /= 2;
                    }
                else damage *= at;
                damage -= target->query_temp("apply/armor")*2;
                if (damage < 0) damage = 0;
                if (damage > 3000) damage = 3000;
                damage = damage + random(damage / 2);
                  if (target->query_skill_mapped("force") == "yijin-jing" 
                     && target->query_temp("fanzhen")) 
                        damage /= 2;
                F_KUNGFU->hit_wound("qi", damage, damage/3, me, target);
                target->add("neili", -damage/5);
//                me->add("neili", -damage/5);
//                me->add("combat_exp", (int)me->query_int()*2);
                msg += damage_msg(damage, "瘀伤");
                }
        else {
                dodge_skill = target->query_skill_mapped("dodge");
		if( !dodge_skill ) dodge_skill = "dodge";
                msg += SKILL_D(dodge_skill)->query_dodge_msg(target, 1);
        }
        me->add("neili", -400);
        me->add("jing", -100);
        message_vision(msg, me, target);
        COMBAT_D->report_status(target);
        return 1; 
}
