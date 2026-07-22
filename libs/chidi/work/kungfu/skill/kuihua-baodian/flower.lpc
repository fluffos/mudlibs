// 向阳花
// by lonely
#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>
inherit F_SSERVER;
int perform(object me, object target)
{
        object weapon, ob;
    int count,skill;
    string msg;
        if( !me->is_fighting() )
           return notify_fail("「向阳花开」只能在战斗中使用。\n");
       if( !target ) target = offensive_target(me);
       if( !target
       ||      !target->is_character()
       ||      !me->is_fighting(target) )
           return notify_fail("「向阳花开」只能在战斗中使用。\n");
    if (me->query_temp("perform"))  return notify_fail("你上一个招式还没完成!\n");
      
         if((int)me->query_skill("kuihua-baodian",1) < 401)
               return notify_fail("你的葵花宝典的火候还不到家, 不能使用这一绝技 !\n");
      
         if( (int)me->query("neili") < 8000 )
                return notify_fail("你的真气不够！\n");
        if( (int)me->query("max_neili") < 2000 )
                return notify_fail("你的内力修为不够！\n");
    msg = 
 HIY "\n$N使出葵花宝典的绝技「向阳花开」！\n" NOR;
message_vision(msg,me,target); 
        me->clean_up_enemy();
    skill=me->query_skill("kuihua-baodian",1);
      ob = me->select_opponent();
    me->add("neili", -1000);
    if (weapon == me->query_temp("secondary_weapon"))
        me->set_temp("secondly_weapon",1);
     for (count=0;count<10;count++){
        me->add_temp("str",skill/10);
        COMBAT_D->do_attack(me, ob, weapon, 0);   
    }
    me->delete_temp("str");
    me->delete_temp("secondly_weapon");
    me->set_temp("perform",1);
    call_out("del_perform",3,me);
    return 1;
}

void del_perform(object me)
{
   if (!me) return;
   me->delete_temp("perform");
}

