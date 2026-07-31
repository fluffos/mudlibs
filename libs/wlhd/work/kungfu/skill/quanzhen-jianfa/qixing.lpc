#include <ansi.h>

inherit F_SSERVER;
int perform(object me, object target)
{
      int damage, damage2;
        string msg;
        object weapon;

if ( (string)me->query("family/family_name") != "全真教") 
      return notify_fail("只有全真教弟子才能使用该PFM。\n");


        if (!target ) target = offensive_target(me);
        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword")
        return notify_fail(RED"开什么玩笑，没装备剑就想使「七星绝命剑」？\n"NOR);
      if (!target || !target->is_character() || !me->is_fighting(target) )
        return notify_fail("「七星绝命剑」只能对战斗中的对手使用。\n");
      if ((int)me->query_skill("quanzhen-jianfa", 1) < 800 )
         return notify_fail(WHT"你的全真剑法不够娴熟，还使不出「七星绝命剑」。\n"NOR);
      if ((int)me->query_skill("sword", 1) < 850 )
        return notify_fail(WHT"你连剑都拿不来，还妄想使出「七星绝命剑」？\n"NOR);
      if ((int)me->query_skill("force", 1) < 1500 )
        return notify_fail(RED"你的内功基础不够，耍不出「七星绝命剑」。\n"NOR);
      if ((int)me->query_skill("dodge", 1) < 1500 )
        return notify_fail(RED"你的身法不够灵活不够，领悟不到「七星绝命剑」。\n"NOR);
      if ((int)me->query("max_neili")<50000)
        return notify_fail(RED"你的内力修为不足，无法运足「七星绝命剑」的内力。\n"NOR);
      if ((int)me->query("neili")<200)
        {
        return notify_fail(HIC"你现在内力不够，没能将「七星绝命剑」使完！\n"NOR);
        }
     msg = HIC "$N一声长啸，一抖手中剑，顿时形成一道剑幕，狂风暴雨般压向$n\n"NOR;
     msg += HIC"就在$n慌乱之间，剑幕中飞出七朵寒星，如流星般射向$n。\n"NOR;
    msg += HIR"忽然剑光消失，$n只觉得剑已刺入自己胸口！\n"NOR;
   if (random(me->query_skill("force"))>target->query_skill("force")/2)
        {
                me->start_busy(2);
                target->start_busy(random(3));
damage = (int)me->query_skill("quanzhen-jianfa", 1)*5+(int)me->query_skill("force",1)*2;
   damage = damage + random(damage);
if (damage<target->query("max_qi",1)/8 && me->query("max_neili",1) > target->query("max_neili",1)/2) damage = random (target->query("max_qi",1)/6);
if (damage>target->query("max_qi",1)/3) damage = random (target->query("max_qi",1)/4);


damage2 = (int)me->query_skill("quanzhen-jianfa", 1)*5+(int)me->query_skill("force",1)*2;
damage2 = damage2 + random(damage2);
                target->receive_damage("qi", damage/2);
                target->receive_wound("qi", damage);
      msg += HIC"$n“哇”的狂叫一声，身上喷出七道血剑！\n"NOR;
      msg += HIC"$N缓缓抽回长剑道：这就是全真的「七星绝命剑」！\n"NOR;
        me->add("neili", -2000);
        } else
        {
            me->start_busy(random(3));
        msg += HIY"可是$n情急之中向后激飞，随机趴下，堪堪躲过了这致命一击\n"NOR;
                me->add("neili", -200);
        }
        message_vision(msg, me, target);
        if(!target->is_fighting(me)) target->fight_ob(me);
//      if(userp(target)) target->fight_ob(me);
//      else if( !target->is_killing(me) ) target->kill_ob(me);
        return 1;
}
