// sanshen.c 华岳三神峰
#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>
inherit F_SSERVER;

void do_attack(object me,object target,int attack_time)
{
    int i;
    if (!me) return;
    me->delete_temp("perform");
    if (!living(me) || !target ) return;
    if (environment(me)!=environment(target)) return;
        for(i = 0; i < attack_time; i++)
            if (me->is_fighting(target) && target->is_fighting(me) && target->query("eff_qi")>0){
              me->set_temp("action_msg","紧接着");
              COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 0);
            }else break;
    me->start_call_out( (: call_other, __FILE__, "del_perform", me:), 1);
   
}

int perform(object me, object target)
{
    object weapon, ob;
    string msg;
 
    if( !me->is_fighting() )
        return notify_fail("「华岳三神峰」只能在战斗中使用。\n");
    if (me->query_temp("perform"))  return notify_fail("你上一个招式还没完成!\n");
    if (!objectp(weapon = me->query_temp("weapon"))
    || (string)weapon->query("skill_type") != "blade")
        return notify_fail("你使用的武器不对。\n");
    if( (int)me->query("neili") < 100 )
        return notify_fail("你的真气不够！\n");
    if( (int)me->query_skill("blade") < 50 ||
        me->query_skill_mapped("blade") != "fanliangyi-dao")
        return notify_fail("你的「反两仪刀法」还不到家，无法使用「华岳三神峰」！\n");
    msg = HIY "$N使出华山派绝技「华岳三神峰」，身法突地变得异常灵动飘忽！\n" NOR;
    message_vision(msg, me);
    me->clean_up_enemy();
    ob = me->select_opponent();
    me->add("neili", -100);
    me->start_call_out( (: call_other, __FILE__, "do_attack", me, ob,3 :), 2);
    me->set_temp("perform",1);
    call_out("del_perform",3,me);
    return 1;
}

