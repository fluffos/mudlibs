#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>
inherit F_SSERVER;
 
int perform(object me, object target)
{
    object weapon, ob;
    string msg;
    int i;
 
 ob = me->select_opponent();

    if( !me->is_fighting() )
        return notify_fail("「雷电闪」只能在战斗时使用。\n");
     if (me->query_temp("perform")>time()) return notify_fail("你上一招未使完！\n");
    if (!objectp(weapon = me->query_temp("weapon"))
    || (string)weapon->query("skill_type") != "sword")
    if (!objectp(weapon = me->query_temp("secondary_weapon"))
    || (string)weapon->query("skill_type") != "sword")
        return notify_fail("你使用的武器不对。\n");
    else me->set_temp("secondly_weapon",1);
    if( (int)me->query("neili") < 200 )
        return notify_fail("你的真气不够！\n");
    if( (int)me->query_skill("sword") < 100 ||
        me->query_skill_mapped("sword") != "xunlei-sword")
        return notify_fail("你的「迅雷剑」还不够精纯，无法使用「雷电闪」！\n");
msg = HIY "$N捏剑决走剑势，凝下心神施展出迅雷剑之「雷电闪」，顿时数道剑光向前闪去！！\n" NOR;
    message_vision(msg, me);
    me->clean_up_enemy();
    me->add("neili", -150);
    me->set_temp("perform",time()+3);
    me->set_temp("perform_lei",1);
    for(i = 0; i < 3; i++)
        if (me->is_fighting(ob) && ob->is_fighting(me) && ob->query("eff_qi")>0){
              me->set_temp("action_msg",HIC"电光再现\n"NOR);
                if (!weapon->query("equipped")) break;
              COMBAT_D->do_attack(me, ob,weapon, 0);
            }else break;
    me->delete_temp("perform_lei");
    me->delete_temp("secondly_weapon");
    return 1;
}

