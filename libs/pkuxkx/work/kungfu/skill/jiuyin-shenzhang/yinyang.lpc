#include <ansi.h>
inherit F_SSERVER;
void attack_1();
void attack_2();
void attack_3();
void finish();
void finish_2();
int perform(object me, object target)
{
        string msg;
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("［阴阳双掌］只能对战斗中的对手使用。\n");

        if( (me->query_skill("jiuyin-shenzhang",1) < 150 )
        ||      (me->query_skill("jiuyin-zhengong",1) < 150 ) ) 
                return  notify_fail("你的功夫还不够娴熟，不会使用阴阳双掌。\n");

        if( me->query("neili") < 5000 )
                return notify_fail("你的内力不够。\n");
        if( me->query("jingli") < 1500 )
                return notify_fail("你的精力不够。\n");

        me->start_perform(20,"阴阳双掌");
        msg = HIG "$N使出阴阳双掌，两掌登时将$n两掌黏住！\n"NOR;

        me->start_busy(10);
        target->start_busy(10);
        message_vision(msg, me, target);
        call_out("attack_1",5);
        return 1;
}

void attack_1()
{
      object me = this_player();
      object target = offensive_target(me);
      if (!me || !target) return;
      message_vision(HIY"$N和$n身不由己，能以内力比拼！\n"NOR, me, target);
      me->add("neili",-(target->query_skill("force")));
      target->add("neili",-(me->query_skill("force")));
      if (me->query("neili")<=0||target->query("neili")<=0) {
      if (me->query("neili")<=0) 
      {
              message_vision(HIR"$N内力耗竭，闷哼一声！\n"NOR,me);
              me->set("neili",0);
              me->receive_wound("qi",target->query_skill("force"), "内力比拼气血耗竭"); 
              COMBAT_D->report_status(me);
      }
      if (target->query("neili")<=0) 
      {
              message_vision(HIR"$N内力耗竭，闷哼一声！\n"NOR,target);
              target->set("neili",0);
              target->receive_wound("qi",me->query_skill("force"), "内力比拼气血耗竭");
              COMBAT_D->report_status(target);
      }
      call_out("finish",1); } else
      call_out("attack_2",5);
}

void attack_2()
{
      object me = this_player();
      object target = offensive_target(me);
      if (!me || !target) return;
      if (objectp(me)&&!living(me)) return;
      message_vision(HIY"$N和$n都急谋脱身，各自加强了内力的施为！\n"NOR, me, target);
      me->add("neili",-(target->query_skill("force")*3));
      target->add("neili",-(me->query_skill("force")*3));
      if (me->query("neili")<=0||target->query("neili")<=0) {
      if (me->query("neili")<=0) 
      {
              message_vision(HIR"$N内力耗竭，闷哼一声！\n"NOR,me);
              me->set("neili",0);
              me->receive_wound("qi",target->query_skill("force"), "内力比拼气血耗竭");
              COMBAT_D->report_status(me);
      }
      if (target->query("neili")<=0) 
      {
              message_vision(HIR"$N内力耗竭，闷哼一声！\n"NOR,target);
              target->set("neili",0);
              target->receive_wound("qi",me->query_skill("force"), "内力比拼气血耗竭");
              COMBAT_D->report_status(target);
      }
      call_out("finish",1); } else
      call_out("attack_3",5);
}

void attack_3()
{
      object me = this_player();
      object target = offensive_target(me);
      if (!me || !target) return;
      if (objectp(me)&&!living(me)) return;
      message_vision(HIY"$N、$n两人头顶上冒出了水汽，想是两人正全力对攻！\n"NOR, me, target);
      me->add("neili",-(target->query_skill("force")*5));
      target->add("neili",-(me->query_skill("force")*5));
      if (me->query("neili")<=0||target->query("neili")<=0) {
      if (me->query("neili")<=0) 
      {
              message_vision(HIR"$N内力耗竭，闷哼一声！\n"NOR,me);
              me->set("neili",0);
              me->receive_wound("qi",target->query_skill("force"), "内力比拼气血耗竭");
              COMBAT_D->report_status(me);
      }
      if (target->query("neili")<=0) 
      {
              message_vision(HIR"$N内力耗竭，闷哼一声！\n"NOR,target);
              target->set("neili",0);
              target->receive_wound("qi",me->query_skill("force"), "内力比拼气血耗竭");
              COMBAT_D->report_status(target);
      }
      call_out("finish",1); } else
      call_out("finish_2",5);
}

void finish()
{
      object me = this_player();
      object target = offensive_target(me);
      if (!me || !target) return;
      message_vision(HIY"$N和$n内力不济，停止了对掌，喘气不止。\n"NOR, me,target);
}

void finish_2()
{
      object me = this_player();
      object target = offensive_target(me);
      message_vision(HIY"$N和$n各自大喝一声，停止了对掌，退开数尺。\n"NOR, me,target);
}

