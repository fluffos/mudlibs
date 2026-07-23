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
                return notify_fail("［狂风快剑］只能对战斗中的对手使用。\n");

        if( (me->query_skill("kuangfeng-jian",1) < 150 )
        ||      (me->query_skill("huashan-neigong",1) < 150 ) ) 
                return  notify_fail("你的功夫还不够娴熟，不会使用狂风快剑。\n");

        if( !weapon 
        ||      weapon->query("skill_type") != "sword"
        ||      me->query_skill_mapped("sword") != "kuangfeng-jian" ) 
                return  notify_fail("你现在无法使用狂风快剑。\n");

        if( me->query("neili") < 1300 )
                return notify_fail("你的内力不够。\n");
        if( me->query("jing") < 500 )
                return notify_fail("你的精不够。\n");
      if( me->query_temp("kuangfeng"))
                return notify_fail("你正在运用狂风快剑了！\n"); 


        me->start_perform(7,"狂风快剑");
        msg = HIG "$N仰天一声清啸，斜行而前，" + weapon->name() + HIG"横削直击，迅捷无比，未到五六招，剑势中已发出隐隐风声。\n"NOR;

  me->set_temp("kuangfeng", 20);
// busy 在各个 callout 连续增加
        me->start_busy(2);
        message_vision(msg, me, target);
        call_out("attack_1",3);
        me->add("jing", -200);
        me->add("neili", -500);
        return 1;
}

void attack_1()
{
      object me = this_player();
      object target;
if (me)
      target = offensive_target(me);
if (!me) return;
if (!target) return;
      if (me->is_fighting()) {
        me->add("apply/attack",100);
        me->add("apply/parry",100);

      COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 3);
    COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 3);
    COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 3);
      me->add("apply/attack",-100);
      me->add("apply/parry",-100);

      message_vision(HIG"\n$N剑招一剑快似一剑，所激起的风声也越来越强！\n"NOR, me, target);
      me->start_busy(2);
      call_out("attack_2",3); } else
      call_out("finish",1);
}

void attack_2()
{
      object me = this_player();
      object target;
if (me)
      target = offensive_target(me);
if (!me) return;
if (!target) return;

      if (me->is_fighting()) {
        me->add("apply/attack",100);
        me->add("apply/parry",100);

  COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 3);
     COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 3);
       COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 3);
      me->add("apply/attack",-100);
      me->add("apply/parry",-100);

      message_vision(HIG"\n$N剑锋上所发出的一股劲气渐渐扩展！\n"NOR, me, target);
      me->start_busy(2);
      call_out("attack_3",3);} else
      call_out("finish",1);
}

void attack_3()
{
      object me = this_player();
      object target;
if (me)
      target = offensive_target(me);
if (!me) return;
if (!target) return;

      if (me->is_fighting()) {
        me->add("apply/attack",100);
        me->add("apply/parry",100);

  COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 3);
     COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 3);
       COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 3);
      me->add("apply/attack",-100);
      me->add("apply/parry",-100);

      message_vision(HIG"\n旁观众人只觉寒气逼人，脸上、手上被疾风刮得隐隐生疼，不由自主的后退！\n"NOR, me, target);
      me->start_busy(2);
      call_out("attack_4",3);} else
      call_out("finish",1);
}

void attack_4()
{
      object me = this_player();
      object target;
if (me)
      target = offensive_target(me);
if (!me) return;
if (!target) return;

      if (me->is_fighting()) {
        me->add("apply/attack",100);
        me->add("apply/parry",100);

  COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 3);
     COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 3);
       COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 3);
      me->add("apply/attack",-100);
      me->add("apply/parry",-100);

      message_vision(HIG"\n附近众人身上的衣带被剑气逼得向外飘扬，剑上所发的风声尚有渐渐增大之势。！\n"NOR, me, target);
      me->start_busy(2);
      call_out("attack_5",3);} else
      call_out("finish",1);
}

void attack_5()
{
      object me = this_player();
      object target;
if (me)
      target = offensive_target(me);
if (!me) return;
if (!target) return;

      if (me->is_fighting()) {
      me->add("apply/attack",100);
      me->add("apply/parry",100);

      COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 3);
 COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 3);
    COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 3);
      me->add("apply/attack",-100);
      me->add("apply/parry",-100);

         message_vision(HIG"旁观众人不由自主的后退，围在相斗两人身周的圈子渐渐扩大！\n"NOR, me, target);
      me->start_busy(1);
      call_out("finish",1);} else
      call_out("finish",1);
}

void finish()
{
      object me = this_player();
if (!me) return;

 me->delete_temp("kuangfeng");
      message_vision(HIY"$N这“狂风快剑”委实快极，一百零八招片刻间便已使完。\n"NOR, me);
}

