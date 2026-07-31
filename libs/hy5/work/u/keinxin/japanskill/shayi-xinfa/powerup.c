// powerup.c

#include <ansi.h>

inherit F_CLEAN_UP;

void remove_effect(object me, int amount);

int exert(object me, object target)
{
   int skill;
   if( target != me )
   return notify_fail("你只能用杀意心法来提升自己的战斗力。\n");
   if( (int)me->query("neili") < 150  )
   return notify_fail("你的内力不够。\n");
   if( (int)me->query_temp("powerup") )
   return notify_fail("你已经在运功中了。\n");

   skill = me->query_skill("force");
   me->add("neili", -50);
   me->receive_damage("qi", 0);
   message_combatd(
   HIY "$N眼神一变，像似变了一个人，杀气游遍全身。\n" NOR,me);
   me->add_temp("apply/attack", skill/4);
   me->add_temp("apply/dodge", skill/4);
   me->set_temp("powerup", 1);

   me->start_call_out((:call_other, __FILE__, "remove_effect", me, skill/3:), skill);
   if( me->is_fighting() ) me->start_busy(3);
   return 1;
}

void remove_effect(object me, int amount)
{
   int skill;
   skill = me->query_skill("force");
   me->add_temp("apply/attack", -skill/4);
   me->add_temp("apply/dodge", -skill/4);
   me->delete_temp("powerup");
   tell_object(me, "你的杀意心法运行完毕。回到了平常的样子。\n");
}

