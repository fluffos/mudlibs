#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>

inherit F_SSERVER;
int perform(object me, object target)
{
        object weapon;
object ob;
        string msg;
        int i, attack_time;

        me->clean_up_enemy();
    ob = me->select_opponent();
if (me->is_fighting())
{
if  (environment(me)!=environment(ob) ) 
     return notify_fail("对方已经不在了。\n");
}

        if( !target ) target = offensive_target(me);

        if( !me->is_fighting() )
        return notify_fail("五虎断门刀「断」字决只能在战斗中使用。\n");


        if (!objectp(weapon = me->query_temp("weapon"))
                || (string)weapon->query("skill_type") != "blade")
                return notify_fail("你使用的武器不对。\n");


    if( (int)me->query_skill("blade") < 60 ||
        me->query_skill_mapped("blade") != "wuhu-duanmendao")
        return notify_fail("你的「五虎断门刀」还不到家，无法使用「断」字决！\n");


     if (me->query_temp("perform")>time()) return notify_fail("你上一招未使完！\n");

        if( (int)me->query("neili") < 500 )
                return notify_fail("你的真气不够！\n");

    msg = HIY "$N猛然伏地，使出地堂刀断字决，顿时一片白光直向前滚去！\n" NOR;


    message_vision(msg, me);
    me->clean_up_enemy();
    ob = me->select_opponent();
    me->add("neili", -150);
    me->set_temp("perform",time()+3);
    me->set_temp("perform_duan",1);
     for(i = 0; i < 3; i++)
        if (me->is_fighting(ob) && ob->is_fighting(me) && ob->query("eff_qi")>0){
              me->set_temp("action_msg",HIR"紧接着"NOR);
                if (!weapon->query("equipped")) break;
              COMBAT_D->do_attack(me, ob,weapon, 0);
            }else break;
    me->delete_temp("perform_duan");
    me->delete_temp("secondly_weapon");
    return 1;
}

