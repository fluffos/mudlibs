// jue.c 烈火三绝剑
// By Dream
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
 
    if( !me->is_fighting() )
        return notify_fail("「"+HIR"烈火三绝剑"NOR+"」只能在战斗中使用。\n");
    if (me->query_temp("perform")) return notify_fail("你上一招未使完！\n");
    if (!objectp(weapon = me->query_temp("weapon"))
    || (string)weapon->query("skill_type") != "sword")
    if (!objectp(weapon = me->query_temp("secondary_weapon"))
    || (string)weapon->query("skill_type") != "sword")
        return notify_fail("你使用的武器不对。\n");
    else me->set_temp("secondly_weapon",1);
    if( (int)me->query("neili") < 1000 )
        return notify_fail("你的真气不够！\n");
    if( (int)me->query_skill("sword") < 100 ||
        me->query_skill_mapped("sword") != "liehuo-jian")
        return notify_fail("你的「烈火剑」还不到家，无法使用「"+HIR"烈火三绝剑"NOR+"」！\n");
    msg = HIR "$N运起内力，顿时手中兵器火焰逼人，接着向对方连环刺去！\n" NOR;
    message_vision(msg, me);
    me->clean_up_enemy();
    ob = me->select_opponent();
    me->add("neili", -600);
    me->set_temp("perform",1);
    me->set_temp("perform_jue",1);
    for(i = 0; i < 3; i++)
        if (me->is_fighting(ob) && ob->is_fighting(me) && ob->query("eff_qi")>0){
              me->set_temp("action_msg","紧跟着");
                if (!weapon->query("equipped")) break;
              COMBAT_D->do_attack(me, ob,weapon, 0);
            }else break;
    me->delete_temp("perform_jue");
    me->delete_temp("secondly_weapon");
      me->start_call_out( (: call_other, __FILE__, "del_perform", me :), 5);;
    return 1;
}

void del_perform(object me)
{
   if (!me) return;
   me->delete_temp("perform");
}

