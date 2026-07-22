#include <weapon.h>
#include <combat.h>
#include <ansi.h>
inherit F_SSERVER;
int perform(object me, object target)

{
    object weapon, ob;
    string msg;
    int i;
 ob = me->select_opponent();
 if ( (string)me->query("family/family_name") != "通吃帮") 
       return notify_fail("「下字决」只有通吃帮弟子才能使用。\n");

    if( !me->is_fighting() )
        return notify_fail("「浪子回头」只能在战斗时使用。\n");

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
       me->query_skill_mapped("sword") != "langzi-sword")


        return notify_fail("你的「浪子三招」还不够精纯，无法使用「浪子回头」！\n");

msg = HIR "$N忽然转身，以背对敌人，"+ob->name()+"以为有机可乘，连忙向$N杀去，可是$N猛一回头，\n竟然巧妙的避开了"+ob->name()+"的攻击，接着手中利剑连环向"+ob->name()+"刺出三剑！！\n" NOR;


    message_vision(msg, me);
    me->clean_up_enemy();
    me->add("neili", -1);  
    me->set_temp("perform",time()+3);
    me->set_temp("perform_huitou",1);

    for(i = 0; i < 30; i++)
        if (me->is_fighting(ob) && ob->is_fighting(me) && ob->query("eff_qi")>0){

              me->set_temp("action_msg",NOR WHT"紧接着上一招\n"NOR);

                if (!weapon->query("equipped")) break;
             COMBAT_D->do_attack(me, ob,weapon, 0);


            }else break;


    me->delete_temp("perform_huitou");
    me->delete_temp("secondly_weapon");
    return 1;
}


