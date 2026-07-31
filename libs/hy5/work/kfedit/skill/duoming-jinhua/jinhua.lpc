
#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;
#include "/kungfu/skill/eff_msg.h";
int perform(object me, object target)
{
    int damage,extra,num,p;
    string msg;
    object weapon;

    if (!target ) target = offensive_target(me);
    if (!objectp(weapon = me->query_temp("weapon"))
       || (string)weapon->query("skill_type") != "throwing")
               return notify_fail("你使用的武器不对。\n");
    if (!target || !target->is_character() || !me->is_fighting(target) )
        return notify_fail("「漫天金花」只能对战斗中的对手使用。\n");
    if ((int)me->query_skill("duoming-jinhua", 1) < 80 )
        return notify_fail("你夺命金花不够娴熟，使不出「漫天金花」。\n");
    if ((int)me->query_skill("jiuyang-shengong", 1) < 40 )
        return notify_fail("你本门内功火候不够，使不出「漫天金花」。\n");

    if ((int)me->query("max_neili")<400)
        return notify_fail("你内力修为不足，无法运足内力。\n");
    if ((int)me->query("neili")<200)
    {
        return notify_fail("你现在内力不够，没能将「漫天花雨」使完！\n");
    }
	extra = me->query_skill("jiuyang-shengong",1) / 20;
	extra += me->query_skill("duoming-jinhua",1) /20;
	me->add_temp("apply/attack", (extra*2));	
	me->add_temp("apply/damage", 400);

    msg = HIR "$N左右手各抓三枚暗器，似乎分左右射向$n，\n"NOR;
    msg += HIY"金光灿烂\n"NOR;
       COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
    msg =  HIY"满天花雨\n"NOR;
       COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
    msg = HIY"风花雪月\n"NOR;
       COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
    msg = HIY"天女散花\n"NOR;
       COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
    msg = HIY"夺命金花\n"NOR;
       COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	me->add_temp("apply/attack", -(extra*2));
	me->add_temp("apply/damage", -400);

	me->start_busy(2);
        me->add("neili", -300);
        num=random(11)+1;
        msg = HIW"\n$N清叱一声，长袖飘飘，只见"+chinese_number(num)+"道寒光呈满天花雨之势，从四面八方向$n飞射而去。\n"NOR;
        if(random(me->query("combat_exp")) > (int)target->query("combat_exp")/3
         ){
          msg += HIR"只见$n躲闪不及，痛苦的大叫一声，"+weapon->name()+HIR"已全部击中其全身要穴。\n"NOR;
          me->add("neili", -200);
          damage = me->query_skill("duoming-jinhua", 1);
          damage +=me->query_skill("throwing", 1);
          damage = damage * num /10;
          damage = damage + random(damage);
          target->receive_damage("qi", damage);
          target->receive_wound("qi", damage/2);
          if (!target->is_busy())
          target->start_busy(3);
          p = (int)target->query("qi")*100/(int)target->query("max_qi");
          msg += "( $n"+eff_status_msg(p)+" )\n";
         }
         else {
          msg += CYN"$n抱头缩颈一个滚翻，堪堪然躲开了"+weapon->name()+CYN"的攻击。\n"NOR;
          me->start_busy(2);
         }
         message_vision(msg, me, target);

    return 1;
}
