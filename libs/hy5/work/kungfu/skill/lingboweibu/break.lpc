// break.c 神光离合
// Modified by Venus Oct.1997
#include <ansi.h>
inherit F_SSERVER;
int perform(object me, object target)
{
string msg;
int count;
  if( !target ) target = offensive_target(me);
if( !me->is_fighting() )
      return notify_fail("「神光离合」只能在战斗中使用。\n");
if( (int)me->query("qi") < 100 )
      return notify_fail("你的气不够！\n");
if( (int)me->query("max_neili") < 200 )
      return notify_fail("你的内力不够！\n");
if( (int)me->query("neili") < (int)me->query("max_neili")/2)
      return notify_fail("你的真气不够！\n");
        if((int)me->query_skill("beiming-shengong",1) < 100 && (int)me->query_skill("bahuang-gong", 1)<100)
                return notify_fail(HIY "你的北冥神功或八荒六合唯我独尊功修为不够。\n" NOR);

	if((int)me->query_skill("lingboweibu",1) < 50)
		return notify_fail("你的凌波微步的修为不够, 不能使用这一绝技 !\n");
	
	if((int)me->query_skill("dodge") < 50)
		return notify_fail("你的轻功修为不够， 目前不能使用! \n");

 	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("「神光离合」只能对战斗中的对手使用。\n");




        if( me->query("gender") == "女性")
               msg = HIW "\n$N" HIW "提起真气，依照先天伏羲六十"
                     "四卦，将凌波微步由头到尾迅速无比的走了一次。 "
                     "$N" HIW "仿如洛神再生，身形顿时轻盈无比，"
                     "微步凌波，真个将逍遥二字发挥得淋漓尽至。\n" NOR;

        else   msg = HIC "\n$N" HIC "提起真气，依照先天伏羲六十"
                     "四卦，将凌波微步由头到尾迅速无比的走了一次。                    "
                     "只见$N" HIC "意态飘逸，影子乱飞，身形顿时轻"
                     "盈无比，真个将逍遥二字发挥得淋漓尽至。\n" NOR;

        message_combatd(msg, me, target);

count = (int)me->query_skill("lingboweibu") / 40 + 2;
   if( count > 6 ) count = 6;
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
  message_combatd( MAG "\n$N" MAG "提起真气，施展神光离合，身形虚晃，神光交错!\n" NOR, me, ob);
  COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);
if (!me->query("double_attack"))
  COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);
  me->receive_damage("qi", 30);
  me->add("neili", -30);
 }
    me->start_busy(2);
    return 1;
}

