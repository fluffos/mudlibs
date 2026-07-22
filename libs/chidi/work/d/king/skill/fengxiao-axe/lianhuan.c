// lianhuan.c 连环斧
#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>
inherit F_SSERVER;
 
int perform(object me, object target)
{
    object weapon, ob;
        string msg;
 
    if( !me->is_fighting() )
        return notify_fail("「连环斧」只能在战斗中使用。\n");
 
    if (!objectp(weapon = me->query_temp("weapon"))
    || (string)weapon->query("skill_type") != "axe")
        return notify_fail("「连环斧」开始时必须拿着一把剑！\n");
   if (me->query_temp("perform"))   return notify_fail("你上一个招式还没完成!\n");

    if( (int)me->query("neili") < 100 )
        return notify_fail("你的真气不够！\n");
    if( (int)me->query_skill("axe") < 50 ||
        me->query_skill_mapped("axe") != "fengxiao-axe")
        return notify_fail("你的风啸斧还不到家，无法使用连环斧！\n");
    msg = HIY "$N使出风啸楼绝技「连环斧」，身法越来越快！\n" NOR;
    message_vision(msg, me);
    me->clean_up_enemy();
    ob = me->select_opponent();
    COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);
    COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);
    COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);
    COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);
    COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);
    me->add("neili", -100);
    me->set_temp("perform",1);
    call_out("del_perform",3,me);
    return 1;
}
void del_perform(object me)
{
   if (!me) return;
   me->delete_temp("perform");
}
