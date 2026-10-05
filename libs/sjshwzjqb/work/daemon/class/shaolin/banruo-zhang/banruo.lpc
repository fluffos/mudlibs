// banruo.c

#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>

inherit SSERVER;

int perform(object me, object target)
{
        int damage, ap, dp, p;
        float at;
        string dodge_skill, msg;

        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) || !living(target))
                return notify_fail("「般若无相」只能在战斗中使用。\n");

        if( objectp(me->query_temp("weapon")) )
                return notify_fail("你必须空手才能使用「般若无相」！\n");

        if( (int)me->query_skill("banruo-zhang", 1) < 60 )
                return notify_fail("你的般若掌未成，不能使用「般若无相」！\n");

        if( (int)me->query_skill("yijinjing", 1) < 60 )
                return notify_fail("你的易筋经未成，不能使用「般若无相」！\n");

        if( (int)me->query("force") < 800 )
                return notify_fail("你的内力修为不足，不能使用「般若无相」！\n"); 

        if( (int)me->query_str() < 20)
                return notify_fail("你的膂力不足，无法发挥「般若无相」的气势。\n");
        if( (int)me->query_con() < 20)
                return notify_fail("你的根骨欠佳，无法使用「般若无相」。\n");

msg = MAG "\n只见$N面显庄严，一式「"HIY"般若无相"MAG"」，提一口真气，飘身而上，半空中手掌交错，一股内劲狭带着热
浪，如风如火，似雷似电，这一招拍出，击向$n，招式平平淡淡，一成不变，但却挡无可挡，避无可避！\n"NOR;

ap = (int)me->query_skill("banruo-zhang") * (int)me->query("force") * (int)me->query_str();
dp = (int)target->query_skill("force", 1) * (int)target->query("force") * (int)target->query_con();

        ap *= (int)me->query("combat_exp")/200;
        dp *= (int)target->query("combat_exp")/200;    
        ap /= 1000;
        dp /= 1000;

        me->start_busy(3);        
        if(random(ap) > dp/2){
                target->start_busy(random(3));
                damage = me->query_skill("yijinjing",1) + me->query_skill("banruo-zhang", 1);
                damage *= 3;
                if(target->query("force") < 1) at = 5;
                else at = me->query("force") / target->query("force");
                if(at < 1){
                    if(at < 0.5) damage /= 2;
                    damage /= 2;
                    }
                else damage *= at;
                damage -= target->query_temp("apply/armor")*2;
                if (damage < 0) damage = 0;
                if (damage > 1500) damage = 1500;
                damage = damage + random(damage / 2);
                if (target->query_skill_mapped("force") == "wuji-force" &&
                    target->query_skill("wuji-force", 1) > 200){
                      tell_object(me, HIY"\n哪知你一掌打在"+target->name()+"身上，却犹如江河入海，又如水乳交融，劲力登时无影无踪！\n"NOR);
                      msg += "猛听得砰然一声大响，$N已打中在$n胸口，只道$p定然全身骨骼粉碎。哪知一掌过去，$n脸露讶色，竟好端端的站着，$N却是脸如死灰，手掌微微发抖！\n";
                      target->start_busy(2);
                      message_vision(msg, me, target);
                      me->add("force", -500);
                      me->add("mana", -100);
                      return 1;
                      }

                if ((target->query_skill_mapped("force") == "yijinjing" ))
                        damage /= 2;
                target->add("kee", -100);
                target->receive_wound("kee", damage/3);
                target->add("force", -damage/5);
                me->add("force", -damage/3);
                me->add("combat_exp", (int)me->query_int()*2);
                p = (int)target->query("kee")*100/(int)target->query("max_kee");
                msg += HIR"$n登时眼前一花，两耳轰鸣,哇的喷出一口鲜血！！\n"NOR;
                }
        else {
              msg += CYN"\n$p急忙飞身向后跃出数丈，才勉强躲闪过这致命一击！\n"NOR;
                dodge_skill = target->query_skill_mapped("dodge");
		if( !dodge_skill ) dodge_skill = "dodge";
                msg += SKILL_D(dodge_skill)->query_dodge_msg(target, 1);
        }
        me->add("force", -400);
        me->add("mana", -100);
        message_vision(msg, me, target);
        return 1; 
}

