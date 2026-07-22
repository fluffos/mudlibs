#include <ansi.h>

inherit F_SSERVER;
int perform(object me, object target)
{
      int damage, damage2;
        string msg;
        object weapon;

if ( (string)me->query("family/family_name") != "古墓派") 
      return notify_fail("只有古墓派才能使用大江东去。\n");


        if (!target ) target = offensive_target(me);
        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword")
        return notify_fail(RED"开什么玩笑，没装备剑就想使「大江东去」？\n"NOR);
      if (!target || !target->is_character() || !me->is_fighting(target) )
        return notify_fail("「大江东去」只能对战斗中的对手使用。\n");
      if ((int)me->query_skill("xuantie-jianfa", 1) < 800 )
                return notify_fail("你的玄铁剑法不够，不能施展大江东去。\n");
      if ((int)me->query_skill("sword", 1) < 850 )
        return notify_fail(WHT"你连剑都拿不来，还妄想使出「大江东去」？\n"NOR);
      if ((int)me->query_skill("force", 1) < 1500 )
        return notify_fail(RED"你的内功基础不够，耍不出「大江东去」。\n"NOR);
      if ((int)me->query_skill("dodge", 1) < 1500 )
        return notify_fail(RED"你的身法不够灵活不够，领悟不到「大江东去」。\n"NOR);
      if ((int)me->query("max_neili")<10000)
        return notify_fail(RED"你的内力修为不足，无法运足「大江东去」的内力。\n"NOR);
      if ((int)me->query("neili")<2000)
        {
        return notify_fail(HIC"你现在内力不够，没能将「大江东去」使完！\n"NOR);
        }
        msg = HIB"骤然间，$N手中"NOR+weapon->query("name")+HIB"发出一阵轰鸣，带着隆隆" +
              "的风雷之声，挟雷霆万均之势，\n一式「"NOR+BLINK+RED"大江东去"NOR+HIB"」，" +
              "手中"NOR+weapon->query("name")+HIB"朝$n当头直压下去！\n";
   if (random(me->query_skill("force"))>target->query_skill("force")/2)
        {
                me->start_busy(2);
                target->start_busy(random(3));
damage = (int)me->query_skill("xuantie-jianfa", 1)*5+(int)me->query_skill("force",1)*2;
   damage = damage + random(damage);
if (damage<target->query("max_qi",1)/8 && me->query("max_neili",1) > target->query("max_neili",1)/2) damage = random (target->query("max_qi",1)/6);
if (damage>target->query("max_qi",1)/3) damage = random (target->query("max_qi",1)/4);


damage2 = (int)me->query_skill("xuantie-jianfa", 1)*5+(int)me->query_skill("force",1)*2;
damage2 = damage2 + random(damage2);
                target->receive_damage("qi", damage/2);
                target->receive_wound("qi", damage);
      msg += HIR "$n无力招架，登时被$N这记重招压得气血翻腾，禁不住「哇」地吐出一口鲜血！\n" NOR;
        me->add("neili", -200);
        } else
        {
            me->start_busy(random(3));
                msg += HIW"$p连忙全力一挡，「砰」地一声巨响，$P这记重招居然被$p接了下来！\n" NOR;
                me->add("neili", -200);
        }
        message_vision(msg, me, target);
        if(!target->is_fighting(me)) target->fight_ob(me);
//      if(userp(target)) target->fight_ob(me);
//      else if( !target->is_killing(me) ) target->kill_ob(me);
        return 1;
}

