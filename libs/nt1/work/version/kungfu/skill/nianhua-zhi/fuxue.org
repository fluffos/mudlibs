// fuxue.c 拈花指 「拈花拂穴」
#include <ansi.h>
inherit F_SSERVER;
int perform(object me, object target)
{
    int busy_time;
    if ( (time()-me->query_temp("perform_time"))<5)
        return notify_fail("你积蓄真气，准备再次使用拈花拂穴。\n");
    if( !target ) target = offensive_target(me);
    if( !target ) return notify_fail("你想点谁的穴位？\n");
    if( !target->is_character() || target->is_corpse() )
        return notify_fail("看清楚一点，那并不是活物。\n");
    if((int)me->query_str() < 25)
        return notify_fail("你臂力不够,不能使用这一绝技!\n");
    if((int)me->query_skill("hunyuan-yiqi",1) < 100 )
    if((int)me->query_skill("yijingjin",1) < 100 )
        return 
        notify_fail("你内功修为不够，不能使用拈花拂穴!\n");
    if((int)me->query_skill("finger") < 120 || me->query_skill("nianhua-zhi",1) < 100 )
        return 
        notify_fail("你的指法修为不够,目前还不能使用拈花拂穴绝技!\n");
    if((int)me->query("neili") < 300)
        return notify_fail("你的内力不够, 不能使用拈花拂穴! \n");
    if( target->is_busy() )
        return notify_fail(target->name() + "目前正自顾不暇，放胆攻击吧，yeah\n");

    message("vision", CYN "你似乎听到一声似有似无的“嗤嗤”的声音！\n\n" NOR, environment(me), ({me}) );
    tell_object(me, "你使出拈花拂穴绝招，暗运内力，指端射出一股劲气直点"+target->name()+"的要穴！\n\n" NOR);
if (!wizardp(me)) 
{
 if( random(me->query("combat_exp")) > (int)target->query("combat_exp") / 4)
    {
        tell_object(target, HIW "你突然间觉得浑身上下不听使唤，动弹不得！\n" NOR);
        message("vision", CYN "只见"+target->name()+"突然间神色大变，动弹不得！\n\n" NOR, environment(me), ({target}) );
  busy_time=random( (int)me->query_skill("nianhua-zhi",1) / 10 )+1;
        target->start_busy( busy_time );
        me->add("neili", -100);
    }
    else
    {
    message("vision", CYN + target->name() + "好象突然觉得有一股劲气向自己的要穴射了过来，不及细想闪了一闪。\n" NOR,environment(me),({target}));
    tell_object(target, CYN "你好象突然觉得有一股劲气向自己的要穴射了过来，不及细想闪了一闪。\n" NOR);
    message_vision(CYN "$n从劲气来向看到原来是$N在点自己的穴位，不禁大怒：敢暗算我，看招！\n" NOR,me,target);
//  if (target->query("shen") < -100 ) target->kill_ob(me);
target->fight_ob(me);
    me->fight_ob(target);
    me->start_busy(3);
    }
    me->set_temp("perform_time",time());
    return 1;
}
else
{
 if( random(me->query("combat_exp")) > (int)target->query("combat_exp") / 400)
    {
        tell_object(target, HIW "你突然间觉得浑身上下不听使唤，动弹不得！\n" NOR);
        message("vision", CYN "只见"+target->name()+"突然间神色大变，动弹不得！\n\n" NOR, environment(me), ({target}) );
  busy_time=random( (int)me->query_skill("nianhua-zhi",1) / 5 )+1;
        target->start_busy( busy_time );
        me->add("neili", -100);
    }
    else
    {
    message("vision", CYN + target->name() + "好象突然觉得有一股劲气向自己的要穴射了过来，不及细想闪了一闪。\n" NOR,environment(me),({target}));
    tell_object(target, CYN "你好象突然觉得有一股劲气向自己的要穴射了过来，不及细想闪了一闪。\n" NOR);
    message_vision(CYN "$n从劲气来向看到原来是$N在点自己的穴位，不禁大怒：敢暗算我，看招！\n" NOR,me,target);
//  if (target->query("shen") < -100 ) target->kill_ob(me);
target->fight_ob(me);
    me->fight_ob(target);
       }
    me->set_temp("perform_time",time());
    return 1;
}
}

