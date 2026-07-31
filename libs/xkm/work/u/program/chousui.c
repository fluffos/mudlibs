#include <ansi.h>

inherit F_DBASE;
inherit F_SSERVER;

int perform(object me, object target)
{
        string weapon;
        int skill, enfor, amount, sp, dp, dmg;

        enfor = me->query("jiali");

        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("抽髓三掌只能对战斗中的对手使用。\n");

        if( objectp(me->query_temp("weapon")) )
                return notify_fail("抽髓掌只能空手运用。\n");

        if( me->query_str() < 30 )
                return notify_fail("你的臂力不足以施展！\n");

        if( me->query_skill_mapped("force") != "huagong-dafa" )
                   return notify_fail("你没有用化功大法用不出这么狠毒的招式！\n");

          if ( me->query("neili", 1) < 500 )
                  return notify_fail("你内力不足以施展抽髓三掌！\n");

        message_vision(HIR "\n$N眼光一闪，暗运化功大法，掌心凹陷向$n拍去，悄无声息的逼向$p！\n\n" NOR, me, target);

        sp = me->query_skill("force") + me->query_skill("dodge") + me->query_con();
       dp = target->query_skill("force") + target->query_skill("parry") + target->query_con();

        if( random(sp+dp) > dp )
        {

        skill = me->query_skill("force") + me->query_skill("strike");
        amount = skill/3;

        me->add_temp("apply/attack", amount);
        me->add_temp("apply/strike", amount/3);
        me->add_temp("apply/damage", amount/2);

                message_vision(
                        HIR "$N感到次招用意不在伤人，忙凝聚全身功力，却阻挡不住内力飞泄而出！\n\n" NOR,
                        target );
                target->add("neili", -1*(int)me->query_skill("force") );

                me->add("neili", 1*((int)me->query_skill("force")));

                me->start_busy(1+random(1));
                target->start_busy(1);
       message_vision(HIR "\n$N大喜，聚起全身功力，掌心凸出向$n狠命拍去，一股排山倒海的力量打向$p！\n\n" NOR, me, target);
            me->set("jiali",(int)me->query_skill("force")/2);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
       message_vision(HIR "\n$N第二招得手，力贯双臂，双掌交错攻向$n，第三招连环而至！\n\n" NOR, me, target);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
        me->add("neili", -amount*4);
        me->add("jingli", -amount);

        me->add_temp("apply/attack", -amount);
       me->add_temp("apply/damage", -amount/2);
        me->add_temp("apply/strike", -amount/3);

       me->start_busy(2+random(1));
        }
        else
        {
                 call_out("fail_hit",1,me,target);
          }
        return 1;
}

  int fail_hit(object me, object target){
    int damage;
        damage=-me->query("shen")/500;
        if (damage>800) damage=800;
        if (damage<400) damage=400;

       if (present("huo yan", environment(me)) && me->is_fighting() && me->query_skill("strike")>180 && me->query_skill("force")>160){

           me->add("neili", -100);
                   me->add("jingli", -50);

         message_vision(HIY "\n\n$N见前招不成，忙潜运内力撩动火焰，激起的火焰向$n激射而去......。\n"NOR, me, target);
                 if((me->query("combat_exp")/2*3)>random(target->query("combat_exp"))){
                          message_vision(HIR "\n$n正要乘机进攻，忽见团团火焰逼向自己，$n躲闪不及，被火焰烧个正着。\n"NOR,me,target);
                  target->add("qi", -damage);
                          target->add("eff_qi", -random(damage));
                       target->receive_wound("eff_qi", random(5*damage), me);
                   } else {
                  if((me->query_neili())<(target->query_neili())){
                          message_vision(HIR "\n$n忙劈掌后退，激起的掌风催动火焰凡蚀$N。\n"NOR,me,target);
                         target->add("neili", -100);
                          me->add("qi", -damage);
                          me->add("eff_qi", -random(damage));
                   }
                          message_vision(HIY "\n$n看出其中有诈，忙向后跃开。\n"NOR,me,target);
               }

      return 1;
     }
}
