#include <ansi.h>
inherit F_SSERVER;
void attack_1();
void attack_2();
void attack_3();
void finish();
int perform(object me, object target)
{
        string msg;
        object weapon = me->query_temp("weapon");
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("［飞龙］只能对战斗中的对手使用。\n");

        if( (me->query_skill("yinlong-bian",1) < 150 )
        ||      (me->query_skill("jiuyin-zhengong",1) < 150 ) ) 
                return  notify_fail("你的功夫还不够娴熟，不会使用飞龙。\n");

        if( !weapon 
        ||      weapon->query("skill_type") != "whip"
        ||      me->query_skill_mapped("whip") != "yinlong-bian" ) 
                return  notify_fail("你现在无法使用飞龙。\n");

        if( me->query("neili") < 2000 )
                return notify_fail("你的内力不够。\n");
        if( me->query("jingli") < 1500 )
                return notify_fail("你的精力不够。\n");

        me->start_perform(8,"飞龙");
        msg = HIG "$N使出九阴银龙鞭的「飞龙」，将一条鞭子使的滴水不漏。\n"NOR;

        me->add("apply/parry",1000);
// busy 在各个 callout 连续增加
        me->start_busy(2);
        message_vision(msg, me, target);
        call_out("attack_1",3);
        me->add("jingli", -1000);
        me->add("neili", -2000);
        return 1;
}

void attack_1()
{
      object me = this_player();
      object target = offensive_target(me);
      if (me->is_fighting()) {
      COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 3);
      message_vision(HIY"$N突然抽空挥鞭向$n攻去！\n"NOR, me, target);
      me->start_busy(2);
      call_out("attack_2",3); } else
      call_out("finish",1);
}

void attack_2()
{
      object me = this_player();
      object target = offensive_target(me);
      if (me->is_fighting()) {
      COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 3);
      message_vision(HIY"$N突然抽空挥鞭向$n攻去！\n"NOR, me, target);
      me->start_busy(2);
      call_out("attack_3",3);} else
      call_out("finish",1);
}

void attack_3()
{
      object me = this_player();
      object target = offensive_target(me);
      if (me->is_fighting()) {
      COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 3);
      message_vision(HIY"$N突然抽空挥鞭向$n攻去！\n"NOR, me, target);
      me->start_busy(1);
      call_out("finish",1);} else
      call_out("finish",1);
}

void finish()
{
      object me = this_player();
      message_vision(HIY"$N力气不济，鞭法缓了下来。\n"NOR, me);
      me->add("apply/parry",-1000);
}

