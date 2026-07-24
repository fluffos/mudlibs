#include <ansi.h>

inherit F_SSERVER;
int perform(object me, object target)
{
        int damage;
        string msg;
        object weapon;

        if (!target ) target = offensive_target(me);
        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "club")
                return notify_fail(RED"开什么玩笑，没装备怎么使「碧波浪涌」？\n"NOR);
        if (!target || !target->is_character() || !me->is_fighting(target) )
                return notify_fail("「碧波浪涌」只能对战斗中的对手使用。\n");
        if ((int)me->query_skill("fengbo-cha", 1) < 150 )
                return notify_fail(WHT"你风波十二叉不够娴熟，使不出「碧波浪涌」。\n"NOR);
        
  if( !target ) target = offensive_target(me);
        
       
        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("你要对谁施展？\n");

        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "club")
        return notify_fail(RED"开什么玩笑，武器不对？\n"NOR);
  
     
        
    if( (string)me->query_skill_mapped("force")!= "jinghai-force")
     return notify_fail("必须靖海神功才行。\n");

      if( (int)me->query_skill("jinghai-force", 1) < 60 )
                return notify_fail("你的靖海神功还差些火候。\n");          
        
        
        if ((int)me->query("max_neili")<800)
                return notify_fail(RED"你的内力修为不足，无法运足「碧波浪涌」的内力。\n"NOR);
  
        if ((int)me->query("neili")<400)        
                return notify_fail(HIC"你现在内力不够，没能将「碧波浪涌」使完！\n"NOR);
    
        msg = HIC "$N作龙吟之声，踏碧波而来，$n只看到$N化做数团身影,\n"NOR;
        msg += HIC"漫天叉影席卷而来，$n奋力一架，但$N叉分数路，$n只架住一叉！\n"NOR;
        message_vision(msg, me, target);

        me->clean_up_enemy();
        target = me->select_opponent();
me->add_temp("apply/attack", 80);
me->add_temp("apply/damage", 2200);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 0);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 0);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 0);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 0);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 0);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 0);
me->add_temp("apply/attack", -80);
me->add_temp("apply/damage", -2200);        
        
        me->add("neili", -50);
        //me->set_temp("bibo_busy",6);
        me->start_busy(1+random(1));
        //target->kill_ob(me);
        //call_out("remove_effect",3+random(5),me);
    
        return 1;
}
/*
void remove_effect(object me) 
{
        if (!me) return;
        me->delete_temp("bibo_busy");
}
*/


