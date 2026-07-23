// bingdi.c 花开并蒂

#include <ansi.h>

inherit F_SSERVER;

int perform(object me, object target)
{
      int lvl,jiali;

      if(objectp(me->query_temp("weapon")))
           return notify_fail("「花开并蒂」只能空手使用。\n");

      lvl = (int)me->query_skill("wudang-mianzhang", 1);

      if( !target ) target = offensive_target(me);

      if( !target
       || !me->is_fighting(target) )
           return notify_fail("「花开并蒂」只能在战斗中对对手使用。\n");

      if( lvl < 120 )
           return notify_fail("你绵掌修为尚不纯熟,无法使用「花开并蒂」！\n");             

      if((int)me->query_skill("taiji-shengong",1) < 120 )
           return notify_fail("你的太级神功修为尚浅无法使用「花开并蒂」！\n");
 
      if((int)me->query_skill("strike",1) < 120 )
           return notify_fail("你的基本掌法等级不够，不能使用「花开并蒂」！\n");  

      if((int)me->query("max_neili") < 2000 )
           return notify_fail("你的内力修为太弱，不能使用「花开并蒂」！\n");
     
      if((int)me->query("neili") < 700 )
           return notify_fail("你的内力太少了，无法使用出「花开并蒂」！\n");   

      if((int)me->query("jing") < 500 )
           return notify_fail("你的精力太少了，无法使用出「花开并蒂」！\n");

      if(me->query_skill_mapped("parry") != "wudang-mianzhang"
       || me->query_skill_mapped("force") != "taiji-shengong")
           return notify_fail("你现在无法使用「花开并蒂」进行攻击。\n");



      message_vision(HIC"\n$N深深吸一口气，左手挥掌猛击$n右颊，右手出指疾点$n左肩“缺盆穴”，\n"
                       +"跟着右掌击$n左颊，左手食指点$n右肩后“缺盆穴”。连续三式，便如暴风\n"
                       +"骤雨般使出，这一招叫作“花开并蒂”，名称好听，招数却十分厉害。\n"NOR,me,target);

        jiali = (int)me->query("jiali");
        me->add("neili",-( 300 + random(jiali)));
        me->add("jing", -80);

        lvl /= 6;
        me->add_temp("apply/strike", lvl);
        me->add_temp("apply/attack", lvl);
        me->add_temp("apply/damage", 300);
        COMBAT_D->do_attack(me, target, 0, 1);  

        if (present(target,environment(me)) && me->is_fighting(target))
                COMBAT_D->do_attack(me, target, 0);  

        if(me->query_skill("zhenshan-mianzhang", 1) > 150
        && present(target,environment(me))
        && me->is_fighting(target))
                COMBAT_D->do_attack(me, target, 0);  

        me->start_busy(2);
        me->add_temp("apply/strike", -lvl);
        me->add_temp("apply/attack", -lvl);
me->add_temp("apply/damage", -300);
        lvl /= 2;
        if ( lvl < 4 ) lvl = 4;
        if ( lvl > 10 ) lvl = 10;
        return 1;
}

