#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>

inherit F_SSERVER;
int perform(object me, object target)
{
        object weapon;
        string msg;
        int i, attack_time;

        if( !target ) target = offensive_target(me);
        
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("「移弦连环诛」只能在战斗中使用。\n");

      if (me->query_temp("perform")>time()) return notify_fail("你上一招未使完！\n"); 

        if (!objectp(weapon = me->query_temp("weapon"))
                || (string)weapon->query("skill_type") != "sword")
                return notify_fail("你使用的武器不对。\n");

        if((int)me->query_skill("dodge") < 600)
                return notify_fail("你的轻功修为不够, 不能使用弦连环诛！\n");

        if ( (string)me->query("family/family_name") != "梅庄") 
           return notify_fail("只有梅庄的人才能使用「移弦连环诛」。\n");
 
        if((int)me->query_skill("sword") < 600)
                return notify_fail("你的剑法修为不够， 目前不能使用弦连环诛! \n");

        if( (int)me->query("neili") < 10000 )
                return notify_fail("你的真气不够！\n");

        msg = HIC "$N以雄厚的内力激射出数股道体无形剑气,使一招「六丁开山」，数道剑气一齐射向对手！\n";

        message_vision(msg, me);
                         COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 1);
                         COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 1);
                         COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 1);
        me->add("neili",-random(4500)-150);
      me->set_temp("perform",time()+3); 
    return 1;
}

