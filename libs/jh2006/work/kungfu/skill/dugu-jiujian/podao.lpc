#include <ansi.h>
inherit F_SSERVER;
int perform(object me, object target)
{
        string msg;
        object weapon;
        int skill;

        if( !target ) target = offensive_target(me);

        if( !target
        ||  !target->is_character()
        ||  !me->is_fighting(target) )
                return notify_fail("「破刀式」只能对战斗中的对手使用。\n");

        if (!objectp(weapon = me->query_temp("weapon"))
         || (string)weapon->query("skill_type") != "sword")
                return notify_fail("你使用的武器不对。\n");

        weapon = target->query_temp("weapon");
        if (!weapon || weapon->query("skill_type") != "blade")
                return notify_fail("对手的武功不能用此式破解。\n");

        if((int)me->query_skill("dugu-jiujian",1) < 150 )
                return notify_fail("你的独孤九剑还不够火候。\n");

        if((string)me->query_skill_mapped("sword") != "dugu-jiujian" && userp(me))
                  return notify_fail("你现在无法使用「破刀式」！\n");

        if((string)me->query_skill_mapped("parry") != "dugu-jiujian" && userp(me))
                  return notify_fail("你现在无法使用「破刀式」！\n");

        if((string)me->query_skill_mapped("dodge") != "dugu-jiujian" && userp(me))
                  return notify_fail("你现在无法使用「破刀式」！\n");

        if((int)me->query("jingli")<2000)
                return notify_fail("你的精力不够！\n"); 
        
        msg = HIW"\n$N剑上完全不出内力，剑随意行，毫无章法！\n"NOR;
        skill = me->query_skill("sword");
        me->start_perform(3,"「破刀式」");
        me->add("jingli", -1000);
        if (random(me->query_int()) > target->query_int()/2){
        msg+= HIG"\n$n只觉得$N每一招中，将自己的刀法克制的毫无还手之余！\n"NOR;
        target->add_temp("apply/blade",-skill);
        me->set("jiali",0);
        call_out("remove_effect",me->query_skill("sword")/10,target, skill);
        } else
        msg+= HIG"\n但是$N剑法一滞，无法连贯，$n的压力登时减轻了。\n"NOR;
        message_vision(msg,me,target);
        return 1;
}

void remove_effect(object target, int skill)
{
     if (!target) return;
     target->add_temp("apply/blade",skill);
     message_vision(HIW"$N的刀法运使恢复正常了。", target);
}
