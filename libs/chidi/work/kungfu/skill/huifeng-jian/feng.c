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
if ( (string)me->query("family/family_name") != "峨嵋派") 
     return notify_fail("只有峨嵋派弟子才能使用该PFM。\n");


    if( !me->is_fighting() )
        return notify_fail("回风剑法「风」字决只能在战斗中使用。\n");
     if (me->query_temp("perform")>time()) return notify_fail("你上一招未使完！\n");
    if (!objectp(weapon = me->query_temp("weapon"))
    || (string)weapon->query("skill_type") != "sword")
    if (!objectp(weapon = me->query_temp("secondary_weapon"))
    || (string)weapon->query("skill_type") != "sword")
        return notify_fail("你使用的武器不对。\n");
    else me->set_temp("secondly_weapon",1);
    if( (int)me->query("neili") < 200 )
        return notify_fail("你的真气不够！\n");
    if( (int)me->query_skill("sword") < 1000 ||
     me->query_skill_mapped("sword") != "huifeng-jian")
        return notify_fail("你的「回风剑法」还不到家，无法使用「风」字决！\n");
msg = HIC "$N一声长啸，手中兵器一化成千，将九九八十一手"HIW"回风剑法"HIC"加以快剑快速使出，$n顿时陷入死境！\n" NOR;
    message_vision(msg, me, ob);
    me->clean_up_enemy();
    ob = me->select_opponent();
    me->add("neili", -150);
    me->set_temp("perform",time()+3);
    me->set_temp("perform_feng",1);
    for(i = 0; i < 8; i++)
        if (me->is_fighting(ob) && ob->is_fighting(me) && ob->query("eff_qi")>0){
              me->set_temp("action_msg","紧接着");
                if (!weapon->query("equipped")) break;
              COMBAT_D->do_attack(me, ob,weapon, 0);
            }else break;
    me->delete_temp("perform_feng");
    me->delete_temp("secondly_weapon");
    return 1;
}
