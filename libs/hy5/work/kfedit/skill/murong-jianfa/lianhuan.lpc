#include <ansi.h>
inherit F_SSERVER;
int perform(object me,object target)
{
 int i=me->query_skill("murong-jianfa",1)/5;
    int j=me->query_skill("canhe-zhi",1)/5;
    int d=me->query_skill("shenyuan-gong",1)/5;  
        object weapon = me->query_temp("weapon");
        if( !target ) target = offensive_target(me);
     
        if( !target || !me->is_fighting(target) )
                return notify_fail("七剑连环指只能对战斗中的对手使用。\n");                

        
        if( (int)me->query_skill("murong-jianfa", 1) < 100 )
                return notify_fail("你的剑法还未练成，不能使用七剑连环指！\n");        
        if (!weapon || weapon->query("skill_type") != "sword"
        || me->query_skill_mapped("sword") != "murong-jianfa")
                return notify_fail("你手里没有剑，无法使用七剑连环指！\n");
        if((int)me->query_skill("canhe-zhi", 1) < 100 )
                return notify_fail("你的指法还未练成，不能使用七剑连环指！\n");        
        if(me->query_skill_mapped("finger") != "canhe-zhi")
                return notify_fail("你没有用指，无法使用七剑连环指！\n");
        if((int)me->query("neili") < 500 )
                return notify_fail("你现在内力不足，不能使用七剑连环指！\n");
        if((int)me->query_temp("lianhuan"))
                return notify_fail("你正在使用七剑连环指！\n");      
        if (me->query_skill("shenyuan-gong", 1)<70)
                return notify_fail("你的本门内功火候未到，！\n");

        if((int)me->query_skill("sword", 1) < 100 )
                return notify_fail("你的基本剑法不够娴熟，不能在剑招中使用七剑连环指。\n");
        if((int)me->query_skill("finger", 1) < 100 )
                return notify_fail("你的基本指法不够娴熟，不能在剑招中使用七剑连环指。\n");
        message_vision(MAG"\n$N使出七剑连环指，剑锋一转，右手食指跟着弹出，只见剑花指风相辉相映，直袭$n！\n"NOR, me,target);
        me->add("neili", -50); 
        me->add("jing", -50);      
        me->set_temp("lianhuan", 2+me->query_skill("murong-jianfa", 1)/40);
   me->add_temp("apply/attack", (i+j)/3*2);
    me->add_temp("apply/damage", d);
    call_out("check_fight", 1, me);
        return 1;
}

void remove_effect(object me)
{
    int i=me->query_skill("murong-jianfa",1)/5;
    int j=me->query_skill("canhe-zhi",1)/5;
    int d=me->query_skill("shenyuan-gong",1)/5;   
    me->add_temp("apply/attack", -(i+j)/3*2);
    me->add_temp("apply/damage", -d);
    me->delete_temp("lianhuan");
      }

void check_fight(object me)
{
    object weapon;      

    if (!me) return;
    if (!me->is_fighting()||!me->query_temp("lianhuan")){
    tell_object(me, HIY"你的「七剑连环指」绝技运行完毕，气回丹田,缓缓收功");
    remove_effect(me);
    return;
    }
   if (me->query_skill_mapped("finger") != "canhe-zhi"
     ||me->query_skill_prepared("finger") != "canhe-zhi")
     {
   tell_object(me, HIR"你临时改换武功,决定不再使用「七剑连环指」绝技");
   remove_effect(me);
   return;
    }
    if(me->query_skill_mapped("parry") != "canhe-zhi")
      if(me->query_skill_mapped("parry") != "murong-jianfa")
     {
   tell_object(me, HIR"你临时改换武功,决定不再使用「七剑连环指」绝技");
   remove_effect(me);
   return;
    }
    call_out("check_fight", 1, me);
}
