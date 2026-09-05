
//醉卧沙场
#include <ansi.h>

inherit F_SSERVER;


int valid_target_arg(string target)
{
    if (target == "version") return 2;
    return target == "null" || target == "other";
}

int perform(object me, object target)
{
        string msg;
	int skill,limit;
   int damage;
    int coefficient;
   int delay;
if(me->query("zuiquanpf")!=5) return notify_fail("你不会这一招!\n");

        if( objectp(me->query_temp("weapon")) )
                 return notify_fail("使用醉卧沙场,必须空手!\n");
        limit = (me->query("con") + (int)me->query("max_neili") / 50) * 2;

        if( !target ) target = offensive_target(me);
			

        if( !target || !target->is_character() || !me->is_fighting(target) )
                return notify_fail("醉卧沙场只能对战斗中的对手使用。\n");

/*
        if( me->query_temp("zuiquan"))
                return notify_fail("你正在施展「醉卧沙场」。\n");
*/
    delay=time();
 if(delay-me->query_temp("end_zuiquan")<8)
                return notify_fail("你刚用过「醉卧沙场」!\n");




        if( (int)me->query("max_neili") < 900 || (int)me->query("neili") < 200 )
                return notify_fail("你的内力不足，无法使用醉卧沙场。\n");
   me->set_temp("end_zuiquan",time());

        if( !(int)me->query_condition("drunk"))
       {
            msg = HIC"$N故作醉态使出「醉卧沙场」，步走乾坤,眼中杀气纵横,只见$n周身遍布拳影!\n"NOR;
              coefficient=1;
             }
     else
        {
               msg = HIC"$N拳借酒势，使出「醉卧沙场」，步走乾坤,眼中杀气纵横,只见$n周身遍布拳影!\n" NOR;
          coefficient=2;
          }

        me->add("neili", - 200);
        skill=(int)me->query_skill("zui-quan", 1);
     msg+=HIR"$N使出「醉卧沙场」第一招:醉生梦死, 一侧身,以肘部袭人!\n"NOR;
        message_vision(msg, me, target);

//        me->set_temp("zuiquan", 1);
     target->start_busy(20);
    me->start_busy(20);
   if( F_KUNGFU->hit_rate( me->query("combat_exp"), (int)target->query("combat_exp"), 10-coefficient*4, me, target) )
  {
  message_vision(HIB"\n$n哪里见过这种怪招?纳闷之时已中了一招!\n\n"NOR,me,target);
   damage=skill*(100+me->query_condition("drunk")*100/limit)/200;
   F_KUNGFU->hit_wound("qi", damage, damage/3, me, target);
   COMBAT_D->report_status(target);
 }
else
 {
    message_vision(HIB"\n$n双手平推,推开了$N的肘部!\n\n"NOR,me,target);
    target->start_busy(1);
    me->start_busy(1);
//        me->delete_temp("zuiquan");
  return 1;
}
        remove_call_out("second_attack");
     call_out("second_attack",4,me,coefficient,skill,limit);

        return 1;
}

void second_attack(object me,int coefficient,int skill,int limit)
{
 int damage;
 object target;
 target=offensive_target(me);
        if( !target || !target->is_character() || !me->is_fighting(target)||!living(target))
 {
  target->start_busy(1);
  me->start_busy(1);
//        me->delete_temp("zuiquan");
  return ;
}
  if(me->query("neili")<300)
  {
   message_vision(HIY"\n$N由于内力不支,无法使出「醉卧沙场」的第二招'醉笑红尘'!\n\n"NOR,me,target);
  target->start_busy(1);
   me->start_busy(1);
//        me->delete_temp("zuiquan");
  return;
}
 me->add("neili",-300);
  message_vision(HIR"\n$N使出「醉卧沙场」的第二招'醉笑红尘',突然仰天一笑,双手突然变换手形,让$n感到变换莫测!\n\n"NOR,me,target);
if( F_KUNGFU->hit_rate( me->query("combat_exp"), (int)target->query("combat_exp"), 14-coefficient*5, me, target) )
 {
   message_vision(HIB"\n霎那间,$n已感到胸前已中了一下,只感觉到$N双手亦拳亦掌,十分怪异!\n\n"NOR,me,target);
     damage=skill*(100+me->query_condition("drunk")*50/limit)/100;
   F_KUNGFU->hit_wound("qi", damage, damage/3, me, target);
   COMBAT_D->report_status(target);
 }
else
{
    message_vision(MAG"\n$n一闪,躲开了$N的怪招!\n\n"NOR,me,target);
   target->start_busy(1);
   me->start_busy(1);
//        me->delete_temp("zuiquan");
  return;
}
        remove_call_out("third_attack");
     call_out("third_attack",4,me,coefficient,skill,limit);
}
void third_attack(object me,int coefficient,int skill,int limit)
{
 int damage;
object target;
 target=offensive_target(me);
    if((int)me->query("shaqi")<1)
  {
  target->start_busy(1);
  me->start_busy(1);
   message_vision(HIY"\n$N由于由于心中没有半点杀气,无法使出「醉卧沙场」的第三招'杀气纵横'!\n\n"NOR,me,target);
return ;
}
        if( !target || !target->is_character() || !me->is_fighting(target)||!living(target))
{
  me->start_busy(1);
//        me->delete_temp("zuiquan");
  return ;
}
  if(me->query("neili")<400)
{
   message_vision(HIY"\n$N由于内力不支,无法使出「醉卧沙场」的第三招'杀气纵横'!\n\n"NOR,me,target);
   target->start_busy(1);
   me->start_busy(1);
//        me->delete_temp("zuiquan");
  return;
}
me->add("neili",-400);
 message_vision(HIR"\n$N使出「醉卧沙场」的第三招'杀气纵横',仰天狂笑一番,忽然间眼中布满血丝,双手从身下缓缓升起\n,$n已分不清$N是拳是掌抑或是爪,只见$N双手从不同的角度向自己袭来!\n\n"NOR,me,target);
me->kill_ob(target);
target->kill_ob(me);
if( F_KUNGFU->hit_rate( me->query("combat_exp"), (int)target->query("combat_exp"), 27-coefficient*9, me, target) )
{
    message_vision(HIB"\n霎那间,$n感到周身全是$N的身影,已避无可避,被$N打得吐了一口鲜血!\n\n"NOR,me,target);
    damage=skill*(200+me->query_condition("drunk")*50/limit)/100;
    F_KUNGFU->hit_wound("qi", damage, damage/3, me, target);
    COMBAT_D->report_status(target);
 if(target->query("qi")<500)
 {
 target->receive_damage("qi", 0, me);
 target->die();
 me->start_busy(1);
//        me->delete_temp("zuiquan");
 message_vision(HIR"\n$N看到对方的身影在自己眼前慢慢倒下去,忽然感到浑身松软\n\n"NOR,me);
 me->receive_damage("qi", 0, target);
me->unconcious();
 return;
}
target->start_busy(1);
me->start_busy(1);
//        me->delete_temp("zuiquan");
return;
}
else
{
message_vision(HIB"\n$n见势不对,一个就地十八滚,躲了开去!\n\n"NOR,me,target);
target->start_busy(1);
me->start_busy(1);
//        me->delete_temp("zuiquan");
return;
}
}
