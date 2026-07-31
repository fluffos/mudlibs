// break.c 五遁绝杀
// Modified by Venus Oct.1997
#include <ansi.h>
inherit F_SSERVER;
int perform(object me, object target)
{
string msg;
int count;
  if( !target ) target = offensive_target(me);
if( !me->is_fighting() )
      return notify_fail("「五遁绝杀」只能在战斗中使用。\n");
if( (int)me->query("qi") < 100 )
      return notify_fail("你的气不够！\n");
if( (int)me->query("max_neili") < 200 )
      return notify_fail("你的内力不够！\n");
if( (int)me->query("neili") < (int)me->query("max_neili")/2)
      return notify_fail("你的真气不够！\n");
    if ((int)me->query_skill("shayi-xinfa", 1) < 30)
   return notify_fail("你的杀意心法火候不够。\n");

	if((int)me->query_skill("wuxing-dun",1) < 50)
		return notify_fail("你的五行遁中的修为不够, 不能使用这一绝技 !\n");
	if((int)me->query_skill("dodge") < 50)
		return notify_fail("你的轻功修为不够， 目前不能使用! \n");

 	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("「五遁绝杀」只能对战斗中的对手使用。\n");

msg = HIC "$N使出五行遁中的「五遁绝杀」，身法陡然间变得变幻莫测！\n" NOR;
message_combatd(msg, me);
count = (int)me->query_skill("wuxing-dun") / 40 + 2;
   if( count > 5 ) count = 5;
   while( count-- )
 {
  object ob;
  me->clean_up_enemy();
  ob = me->select_opponent();
  if( !ob || (environment(ob) != environment(me))) {
  message_combatd(WHT "$N的身形倏地一转，收身停住了脚步。\n" NOR, me);
     break;
   }
  else

  message_combatd(WHT "$N的身影在$n身旁时隐时现 ...\n" NOR, me, ob);
  COMBAT_D->fight(me, ob); 
  COMBAT_D->fight(me, ob);      
  me->receive_damage("qi", 30);
  me->add("neili", -50);
 }
    me->start_busy(2);
    return 1;
}

