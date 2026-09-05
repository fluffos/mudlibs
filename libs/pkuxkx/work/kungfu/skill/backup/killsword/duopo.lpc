// 勾魂夺魄
// bye dream
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
            return notify_fail("「勾魂夺魄」只能在战斗中使用。\n");
        if((int)me->query_str() < 100)
                return notify_fail("你的臂力不够, 还不能使用这项绝技! \n");

        if (!objectp(weapon = me->query_temp("weapon")) || ((string)weapon->query("skill_type") != "sword"  &&  (string)weapon->query("skill_type") != "spear" )) 
 							return notify_fail("你使用的武器不对。\n");

        if((int)me->query_skill("sword",1) < 700)
                return notify_fail("你的基本剑法的火候还不到家, 不能使用这一绝技 !\n");
        if((int)me->query_skill("killsword",1) < 700)
                return notify_fail("你的杀手剑的火候还不到家, 不能使用这一绝技 !\n");
        if( (int)me->query("neili") < 5000 )
                return notify_fail("你的真气不够！\n");
        if( (int)me->query("max_neili") < 10000 )
                return notify_fail("你的内力修为不够！\n");
      msg = MAG "$N手中兵器发出鬼哭神嚎般的声响，顿时剑芒暴长，\n"NOR;
      msg += MAG"时而幻出千万杀气，向对方当头罩下，只见漫天红雾\n"NOR;
      msg += MAG"阴风阵阵，随着无穷内力的注入，变的越来越强！\n"NOR;
        message_vision(msg, me);
        me->clean_up_enemy();
        ob = me->select_opponent();
        COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);
        COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);
        COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);
        COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);
        COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);
        COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);
        COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);
        me->add("neili",-random(750)-150);
                  me->start_busy(1+random(2));

    return 1;
}


