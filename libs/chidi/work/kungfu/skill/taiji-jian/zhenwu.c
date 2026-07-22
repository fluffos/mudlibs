#include <ansi.h>
#define ZHENWU "「" HIY "真武除邪" NOR "」"
#include <combat.h>
inherit F_SSERVER;
int perform(object me, object target)
{
      int damage, damage2;
        string msg;
        object weapon;

          if(me->query_skill_mapped("dodge") != "tiyunzong") 
               return notify_fail("你的梯云纵没激发在轻功上吧? \n");  
        if (!target ) target = offensive_target(me);
        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword")
        return notify_fail(RED"开什么玩笑，没装备剑就想使" ZHENWU "？\n"NOR);
      if (!target || !target->is_character() || !me->is_fighting(target) )
        return notify_fail("" ZHENWU "只能对战斗中的对手使用。\n");
      if ((int)me->query_skill("taiji-jian", 1) < 800 )
        return notify_fail(WHT"你的太极剑法不够娴熟，还使不出" ZHENWU "。\n"NOR);
      if ((int)me->query_skill("sword", 1) < 850 )
        return notify_fail(WHT"你连剑都拿不来，还妄想使出" ZHENWU "？\n"NOR);
      if ((int)me->query_skill("force", 1) < 1500 )
        return notify_fail(RED"你的内功基础不够，耍不出" ZHENWU "。\n"NOR);
      if ((int)me->query_skill("dodge", 1) < 1500 )
        return notify_fail(RED"你的身法不够灵活不够，领悟不到" ZHENWU "。\n"NOR);
      if ((int)me->query("max_neili")<50000)
        return notify_fail(RED"你的内力修为不足，无法运足" ZHENWU "的内力。\n"NOR);
      if ((int)me->query("neili")<2001)
        {
        return notify_fail(HIC"你现在内力不够，没能将" ZHENWU "使完！\n"NOR);
        }
     msg = HIY "$N收摄心神，以剑意运剑，手中长剑每剑均以弧形刺出，弧形收回，\n"NOR;
     msg += HIY"每发一招都似放出一条细丝，要去缠在$n。\n"NOR;
   if (random(me->query_skill("force"))>target->query_skill("force")/2)
        {
                me->start_busy(2);
                target->start_busy(random(3));
damage = (int)me->query_skill("taiji-jian", 1)+(int)me->query_skill("force",1)/2;
   damage = damage + random(damage);
if (damage<target->query("max_qi",1)/8 && me->query("max_neili",1) > target->query("max_neili",1)/2) damage = random (target->query("max_qi",1)/6);
if (damage>target->query("max_qi",1)/3) damage = random (target->query("max_qi",1)/4);


damage2 = (int)me->query_skill("taiji-jian", 1)+(int)me->query_skill("force",1)/2;
damage2 = damage2 + random(damage2);
                target->receive_damage("qi", damage/2);
                target->receive_wound("qi", damage);
      msg += HIC"结果$n却丝毫未把这招放在眼里，随手应了一招，却见$N剑势！\n"NOR;
      msg += HIC"忽然一变，气象万千，变幻无穷，极具王者风范！！\n"NOR;
       msg += HIC"$n顿时惊慌失措，被$P" HIC "这一剑击中要害，鲜血崩流,惨不忍睹！！\n"NOR;

        me->add("neili", -2000);
        } else
        {
            me->start_busy(random(3));
        msg += HIY"$p不禁大惊失色，急忙跃开数步，方才摆脱$P的力道。\n"NOR;
                me->add("neili", -1000);
        }
        message_vision(msg, me, target);
        if(!target->is_fighting(me)) target->fight_ob(me);
//      if(userp(target)) target->fight_ob(me);
//      else if( !target->is_killing(me) ) target->kill_ob(me);
        return 1;
}


