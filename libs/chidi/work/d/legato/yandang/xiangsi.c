#include <ansi.h>
inherit SSERVER;

int perform(object me,object target)
{
  string msg;
object weapon;
  int lvl,power;
  if (!target) target=offensive_target(me);
  if (environment(me)->query("no_fight")==1)
    return notify_fail("此处不许战斗.\n");
  if (!target||!target->is_character()||!me->is_fighting(target))
    return notify_fail("[相思无用]只能对战斗对手使用.\n");
  if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword")
            return notify_fail("你应该用剑才能使出这招。\n");
  lvl=me->query_skill("changge-jianfa",1);
  lvl=(int)(lvl/50);
  if (lvl<1) return notify_fail("你的长歌剑法修炼不足.\n");
  if (lvl>9) lvl=9;
  if (me->query("force")<20*lvl)
    return notify_fail("你内力不足,无法使出这招.\n");
  msg=RED+"$N仰天大笑，笑意苍茫悲凉，手中$w却不停的旋转,幻出无数
道白光，心中似有无限怨气，正是一招[相思无用[剑带寒意向$n攻去.\n"+NOR;
  me->start_busy(1);
  if (random(me->query("kar"))>random(target->query("kar")/2))
 {
   power=(int)me->query_str()*lvl-target->query_str();
   if (power<0) power=10;
  msg+=RED+"$n仿佛也悲从中来,心神不定，顿时反应不及被剑刺中.流血不
止.\n"+NOR;
  target->receive_wound("kee",power);
  target->receive_damage("kee",power/2);
  me->add("force",-20*lvl);
 }
 else 
   msg+=CYN+"$n微微一笑摇了摇头，身形舒缓躲开了这招 .\n"+NOR;
 message_vision(msg, me, target);
 return 1;
 }

